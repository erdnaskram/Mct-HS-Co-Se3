; ========================================================================================
; | Modulname:   main.s                                   | Prozessor:  STM32G474        |
; |--------------------------------------------------------------------------------------|
; | Ersteller:   Christoph Marks - Antonia Baumann        | Datum:  23.12.2021           |
; |--------------------------------------------------------------------------------------|
; | Version:     V3.0            | Projekt: Stoppuhr      | Assembler:  ARM-ASM          |
; |--------------------------------------------------------------------------------------|
; | Aufgabe:     Stoppuhr                                                                |
; |                                                                                      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Bemerkungen:                                                                         |
; |     Aktuelle Version nicht laufaehig/bricht nach kurzer zeit bei der Anzeige ab      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Aenderungen:                                                                         |
; |     02.12.2021     CM-AB             Initial version                                 |
; |     02.12.2021     CM-AB             Umsetzung Anforderungen 2-1                     |
; |     10.12.2021     CM-AB             Umsetzung Anforderungen 2-2                     |
; |     16.12.2021     CM-AB             Umsetzung Anforderungen 2-3                     |
; |     23.12.2021     CM-AB             Umsetzung Anforderungen 2-3                     |
; |                                                                                      |
; ========================================================================================

; ------------------------------- includierte Dateien ------------------------------------
    INCLUDE STM32G4xx_REG_ASM.inc

; ------------------------------- exportierte Variablen ------------------------------------


; ------------------------------- importierte Variablen ------------------------------------		
		

; ------------------------------- exportierte Funktionen -----------------------------------		
	EXPORT  main
	EXPORT  TIM6_IRQHandler
	EXPORT  TIM7_IRQHandler
			
; ------------------------------- importierte Funktionen -----------------------------------


; ------------------------------- symbolische Konstanten ------------------------------------


; ------------------------------ Datensection / Variablen -----------------------------------
	AREA daten, data, readonly
array 	DCB 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F

	AREA variables, DATA
counter DCB 0x0

; ------------------------------- Codesection / Programm ------------------------------------
	AREA	main_s,code
	


			
; -----------------------------------  Einsprungpunkt - --------------------------------------

main PROC

	ldr R0, =RCC_AHB2ENR
	ldr R1, =5
	str R1, [R0]
	ldr R0, =RCC_APB1ENR1
	ldr R1, =0x30
	str R1, [R0]
	
	;Counter INIT
	ldr R0, =counter
	ldr R1, =0
	strb R1, [R0]
	
	; 6 Timerkonfiguration
	; loest alle 100ms aus
	; wird fuer das hochzaehlen der Variable "counter" benoetigt
	ldr R0, = TIM6_PSC
	ldr R1, =0x3E7F
	str R1, [R0]
	ldr R0, = TIM6_ARR
	ldr R1, =0x63
	str R1, [R0]
	ldr R0, = TIM6_CR1
	ldr R1, =0x01
	str R1, [R0]
	ldr R0, =TIM6_DIER
	mov R1, #1 		;interrupt enable 
	str R1, [R0]
	
	; 7 Timerkonfiguration
	; loest alle 10ms aus
	; wird fuer das Delay zwischen den Displayanzeigen benoetigt
	ldr R0, = TIM7_PSC
	ldr R1, =0x3E7F
	str R1, [R0]
	ldr R0, = TIM7_ARR
	ldr R1, =0x09
	str R1, [R0]
	ldr R0, = TIM7_CR1
	ldr R1, =0x01
	str R1, [R0]
	ldr R0, =TIM7_DIER
	mov R1, #1 		;interrupt enable 
	str R1, [R0]
	
	; Konfiguration der Timer 6 & 7
	ldr R0, =NVIC_ICPR1
	mov R1, #(3<<22)
	str R1, [R0] 
	ldr R0, =NVIC_ISER1
	mov R1, #(3<<22)
	str R1, [R0]
	
	
	; GPIO Konfig
	; Konfiguration zur Nutzung der 7-Segmentanzeige
	ldr R0, =GPIOA_MODER
	ldr R1, [R0]
	ldr R2, =0xFFFF0000
	and R1, R1, R2
	ldr R2, =0x00005555
	orr R1, R2
	str R1, [R0]
	; Konfiguration zur Nutzung der Schalter S0-S2
	ldr R0, =GPIOC_MODER
	ldr R1, =0x55555540
	str R1, [R0]

	
	mov R2, #0x00


; --------------------------  VARIABLEN  ------------------------------------------

	ldr R6, =1	;Var fuer Links/Rechts Display
	ldr R7, =0	;var Einer
	ldr R8, =0 	;var Zehner
	ldr R12, =1 ;var counterStopp - value 1 bedeutet dass der Counter gestoppt ist
	

; --------------------------  HAUPTTEIL  ------------------------------------------

;Prueft ob Taste Px.0-Px.2 gedrueckt ist
taster_loop 
	ldr R1, =GPIOC_IDR
	ldr R10, [R1]
	b start
	
;wenn Taster Px.0 gedrueckt dann starte Stoppuhr
start	
	and R2, R10, #0x1
	cmp R2, #0x1
	beq stopp
	ldr R12, =0
	b taster_loop

;wenn Taster Px.1 gedrueckt dann stoppe Stoppuhr
stopp
	ldr R10, [R1]
	and R2, R10, #0x2
	cmp R2, #0x2
	beq reset
	ldr R12, =1
	b taster_loop

;wenn Taster Px.3 gedrueckt und Stoppuhr nicht laeuft dann resette Stoppuhr
reset
	ldr R10, [R1]
	and R2, R10, #0x4
	cmp R2, #0x4
	beq taster_loop
	cmp R12, #1
	bne taster_loop
	ldr R7, =0
	ldr R8, =0
	b taster_loop
	
	ENDP	
		
; -----------------------------------  UP_CONVERT  -------------------------------------
;konvertiert die Zahl in "counter" in Einer & Zehner
;und schreibt sie in die vorgesehenen Register
;(R1) ist der aktuelle Wert von "counter"
;(R7) ist fuer die Einer
;(R8) ist fuer die Zehner
up_convert PROC
	PUSH {R7, R8, LR}
        ; FEHLER-1: Da in der aktuellen Version (R6)-(R8) in anderen Teilen des Programms definiert werden
        ; und Veraenderungen dann auch ueberall "sichtbar" sein sollten, duerfte man nur "LR" pushen & poppen
        ; Da in diesem Abschnitt schreibende Zugriffe statt finden und diese am Ende durch POP "verworfen"
        ; werden hat das zur Folge dass in (R7) & (R8) dauerhaft der Wert 0 steht.

	mov R5, #10
	ldr R2, =counter
	ldrb R1, [R2]
	
	UDIV R8, R1, R5
	mul R0, R0, R5
	SUB R7, R1, R0
	
	POP {R7, R8, LR}
	BX lr
	
	
	ENDP
		
		
		
		
; -----------------------------------  UP_DISPLAY  -------------------------------------
;gibt Ziffer (0-9) auf den zwei 7-Segmentanzeigen aus
;"up_convert" wird aufgerufen um "counter" in Einer & Zehner zu trennen
;(R6) gibt an auf welchem der beiden 7-Segmentanzeigen die Zahl angezeigt wird,
;     (R6)= 0 fuer rechte Seite,
;     (R6) = 1 fuer linke Seite
;(R7) ist fuer die Einer
;(R8) ist fuer die Zehner
up_display PROC
	PUSH {R6, R7, R8, LR}
        ; FEHLER-2: Da in der aktuellen Version (R6)-(R8) in anderen Teilen des Programms definiert werden
        ; und Veraenderungen dann auch ueberall "sichtbar" sein sollten, duerfte man nur "LR" pushen & poppen
        ; Da in diesem Abschnitt aber nur lesende Zugriffe statt finden hat es keinen Effekt
        ; Es sollten aber das Register (R2) in PSUH & POP stehen um Ueberschneidungen mit dem Hauptprogramm zu vermeiden.
        ; Weitere Ueberschneidungen sind nicht moeglich da (R4) & (R11) nur hier und (R3) nur in anderen Handlern/
        ; deren Unterprogrammen verwendet wird.
	
	bl up_convert
	
	LDR R11, =array
	
	ldr R2, =GPIOA_ODR
	
	CMP R6, #0x0
	beq dispEiner
	
	;Anzeige links - zehner
	ldrb R3,[R11, R8]
	ldr R4, =0x80
	orr R3, R3, R4
	b continue

dispEiner
	;Anzeige rechts - einer
	ldrb R3,[R11, R7]


continue
	str R3, [R2]
	
	POP {R6, R7, R8, LR}
	BX lr
	
	
	ENDP




; -----------------------------------  Interrupt Handler TIM6  -------------------------
; Wird alle 100ms getriggert
; Wenn die Stoppuhr laeuft wird "counter" um 1 erhöht & bei 100 auf 0 zurückgesetzt
TIM6_IRQHandler PROC
	PUSH {LR}
	; zuruecksetzen des Timers
	ldr R1, =TIM6_SR
	mov R3, #0
	str R3, [R1]

    ; Wenn die Stoppuhr laeuft ( (R12) = 0 ) dann gehe zu "sprung", sonst gehe zu sprung2
	cmp R12, #0
	beq sprung
	b sprung2

sprung
    ; lade "counter" in (R1) und zaehle um 1 hoch
	ldr R0, =counter
	ldrb R1, [R0]
	add R1, R1, #1

	; Wenn (R1) = 110 dann setze (R1) = 0 sonst gehe zu "sprung2"
	cmp R1, #100
	bne sprung2
	mov R1, #0

sprung2
	strb R1, [R0]
        ; FEHLER-3: Die darueberlegende Zeile "strb R1, [R0]" ist vermutlich die Fehlerquelle
        ; sie muesste noch vor der Sprungmarke "sprung2" stehen da aktuell, falls R12=1 (counter Stopp) ist,
        ; versucht wird die Adresse von TIM6_SR in ein Register zu schreiben, dessen Adresse
        ; die aktuelle Zahl in R0 ist (diese ist ohne Debugger leider nicht konkret voraussehbar).
        ; Moegliche Werte von R0 in diesem Moment: die Adresse von NVIC_ISER1, GPIOA_MODER oder GPIOC_MODER
        ; oder im spaeteren Verlauf dann die Adresse von "counter" oder einen Zahlenwert aus den Befehlen in UP_Convert.
        ; Die eigentliche Aufgabe dieses Codestuecks waere es gewesen die neue zahl in die Variable "counter" zu laden.
	POP {LR}
	bx LR	
	ENDP




; -----------------------------------  Interrupt Handler TIM7  -------------------------
; Wird alle 10ms getriggert
; Wechselt den Wert von (R0) immer von 0 nach 1 bzw 1 nach 0 und ruft anschließend
; "up_display" auf.
; Somit wechselt die Anzeige alle 10ms von der rechten zur linke 7-Segmentanzeige.
TIM7_IRQHandler PROC
	PUSH {LR}
	; zuruecksetzen des Timers
	ldr R1, =TIM7_SR
	mov R3, #0
	str R3, [R1]


	cmp R6, #1
	beq dispLinks
	b dispRechts
	
dispLinks
	ldr R6, =0x0
	bl up_display
	b end_tim7handler

dispRechts
	ldr R6, =0x1
	bl up_display
	

end_tim7handler
	POP {LR}
	bx LR	
	ENDP







	END