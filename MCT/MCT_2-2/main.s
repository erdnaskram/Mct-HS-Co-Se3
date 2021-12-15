; ========================================================================================
; | Modulname:   main.s                                   | Prozessor:  STM32G474        |
; |--------------------------------------------------------------------------------------|
; | Ersteller:   Peter Raab                               | Datum:  03.09.2021           |
; |--------------------------------------------------------------------------------------|
; | Version:     V1.0            | Projekt:               | Assembler:  ARM-ASM          |
; |--------------------------------------------------------------------------------------|
; | Aufgabe:     Basisprojekt                                                            |
; |                                                                                      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Bemerkungen:                                                                         |
; |                                                                                      |
; |                                                                                      |
; |--------------------------------------------------------------------------------------|
; | Aenderungen:                                                                         |
; |     03.09.2021     Peter Raab        Initial version                                 |
; |                                                                                      |
; ========================================================================================

; ------------------------------- includierte Dateien ------------------------------------
    INCLUDE STM32G4xx_REG_ASM.inc

; ------------------------------- exportierte Variablen ------------------------------------


; ------------------------------- importierte Variablen ------------------------------------		
		

; ------------------------------- exportierte Funktionen -----------------------------------		
	EXPORT  main

			
; ------------------------------- importierte Funktionen -----------------------------------


; ------------------------------- symbolische Konstanten ------------------------------------


; ------------------------------ Datensection / Variablen -----------------------------------
	AREA daten, data, readonly
array 	DCB 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F

; ------------------------------- Codesection / Programm ------------------------------------
	AREA	main_s,code
	


			
; -----------------------------------  Einsprungpunkt - --------------------------------------

main PROC

	ldr R0, =RCC_AHB2ENR
	ldr R1, =5
	str R1, [R0]
	
	ldr R0, =GPIOA_MODER
	ldr R1, [R0]
	ldr R2, =0xFFFF0000
	and R1, R1, R2
	ldr R2, =0x00005555
	orr R1, R2
	str R1, [R0]
	ldr R0, =GPIOC_MODER
	ldr R1, =0x55555540
	str R1, [R0]
	
	mov R2, #0x00


; --------------------------  VARIABLEN  ---------------------------------------------
	ldr R6, =1	;const Eins zum Zählen
	ldr R7, =10 ;const Zehn zum Zählen
	ldr R5, =0	;var Einer
	ldr R8, =0 	;var Zehner
	ldr R9, =0 	;var Schleifencounter - zählt bis 4
	ldr R12, =1 ;var counterStopp - value 1 bedeutet dass der Counter gestoppt ist
	

; --------------------------  HAUPTTEIL  ---------------------------------------------
;Prüft ob Taste Px.0-Px.2 gedrückt ist
taster_loop 
	ldr R1, =GPIOC_IDR
	ldr R10, [R1]
	b start
	
;wenn Taster Px.0 gedrückt dann starte Stoppuhr
start	
	and R2, R10, #0x1
	cmp R2, #0x1
	beq stopp
	ldr R9, =0
	ldr R12, =0
	b display

;wenn Taster Px.1 gedrückt dann stoppe Stoppuhr
stopp
	ldr R10, [R1]
	and R2, R10, #0x2
	cmp R2, #0x2
	beq reset
	ldr R9, =7
	ldr R12, =1
	b display

;wenn Taster Px.3 gedrückt und Stoppuhr nicht läuft dann resette Stoppuhr
reset
	ldr R10, [R1]
	and R2, R10, #0x4
	cmp R2, #0x4
	beq display
	cmp R12, #1
	bne display
	ldr R5, =0
	ldr R8, =0
	b display


;------- DISPLAY_LOOP  -----------------------------------
;Anzeige der aktuellen Zahl
display
	mov R0, R5
	ldr R1, =0x0
	bl up_display
	
	mov R0, #10
	bl up_delay
	
	mov R0, R8
	ldr R1, =0x1
	bl up_display
	
	
	mov R0, #10
	bl up_delay
	
	;wenn Stoppuhr läuft und Schleifencounter(R9) kleiner 4 ist dann zähle Schleifencounter(R9) eins hoch
	;wenn Schleifencounter(R9) größergleich 4 ist dann gehe zu count_up
	cmp R12, #1
	beq taster_loop
	cmp R9, #4
	bcs count_up
	add R9, R9, #1
	b taster_loop
	
	
;------- COUNTER  ----------------------------------------	
count_up
	ldr R9, =0
	add R5, R5, R6
	;wenn Einer(R5) gleich 10 dann setze Einer(R5) gleich 0 und zähle Zehner(R8) eins hoch
	cmp R5, R7
	bne con1
	ldr R5, =0
	add R8, R8, R6
	;wenn Zehner(R8) gleich 10 dann setze Zehner(R8) gleich 0
	cmp R8, R7
	bne con1
	ldr R8, =0
	
con1
	b display

	ENDP
		
		
		
		
; -----------------------------------  UP_DELAY  ---------------------------------------------
;Warteschleife - wartet so viele Millisekunden wie in (R0) definiert
up_delay PROC
	PUSH {R0, R1}
	
	MOV R1, #3200
	MUL R0, R0, R1

loop_delay
	SUB R0, R0, #1
	CMP R0, #0
	BNE loop_delay
	NOP
	
	POP {R0, R1}
	BX 	lr
	
	
	ENDP
		
		
		
		
; -----------------------------------  UP_DISPLAY  -------------------------------------------
;gibt Ziffer (0-9) auf den zwei 7-Segmentanzeigen aus
;(R0) ist die anzuzeigende Zahl
;(R1) gibt an auf welchem der beiden 7-Segmentanzeigen die Zahl angezeigt wird
;(R1) = 0 für rechte Seite, (R1) = 1 für linke Seite
up_display PROC
	PUSH {R0, R1}
	
	LDR R11, =array
	LDRB R3,[R11, R0]
	ldr R2, =GPIOA_ODR
	
	CMP R1, #0x0
	beq continue
	ldr R4, =0x80
	orr R3, R3, R4
	
continue
	str R3, [R2]
	
	POP {R0, R1}
	BX lr
	
	
	ENDP





	END