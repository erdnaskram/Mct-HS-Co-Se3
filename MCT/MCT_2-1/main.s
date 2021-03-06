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
	
	mov R2, #0x00


; --------------------------  HAUPTTEIL  ----------------------------
	ldr R5, =0
	ldr R6, =1
	ldr R7, =10
	ldr R8, =0

loop
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
	
	
	add R5, R5, R6
	cmp R5, R7
	bne con1
	ldr R5, =0
	add R8, R8, R6
	
con1
	
	
	b loop


	ENDP
		
		
		
		
; -----------------------------------  UP_DELAY  ---------------------------------------------		
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