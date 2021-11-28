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
	ldr R1, =0x55555550
	str R1, [R0]
	
	mov R2, #0x00
		

;----------- Eigentliches Programm ----------------------------------------------


taster_loop
	ldr R4, =GPIOC_IDR
	ldr R6, =0x5
	ldr R5, [R4]
	b IF_1
	
IF_1	
	and R9, R5, #0x1
	cmp R9, #0x1
	beq ELSE_1
	ldr R9, =0x1
	b funf
	
ELSE_1
	and R9, R5, #0x2
	cmp R9, #0x2
	beq ELSE_2
	ldr R9, =0x2
	b funf

ELSE_2
	and R9, R5, #0x3
	cmp R9, #0x3
	beq taster_loop
	ldr R9, =0x3
	b funf


funf
	sub R6, R6, #1
	cmp R6, #0
	blt taster_loop
	b loop



;------- Blinker_LOOP ------------------------------------
loop
	ldr R0, =GPIOA_ODR
	
	cmp R9, #0x1
	beq right
	cmp R9, #0x2
	beq left
	b warn
	
right
	lsl R2, R2, #1
	add R2, R2, #1
	cmp R2, #0x100
	
	blt weiter
	mov R2, #0x00
	ldr R3, =0xC3500
	b pause_z
	
left
	lsr R2, R2, #1
	add R2, R2, #0x80
	cmp R2, #0xFF
	
	blt weiter
	str R2, [R0]
	mov R2, #0x00
	ldr R3, =0xC3500
	b pause_z
	
warn
	and R11, R2, #0xF0
	lsl R11, R11, #1
	add R11, R11, #10

	and R11, R2, #0xF
	lsr R2, R2, #1
	add R2, R2, #0x8
	
	orr R2, R11, R12
	cmp R2, #0xFF
	
	blt weiter
	str R2, [R0]
	mov R2, #0x00
	ldr R3, =0xC3500
	b pause_z



weiter ;Für 100ms zwischenpause
	ldr R3, =0x61A80
	align 4 ;um nachfolgenden Befehl auf durch 4 teilbaren Index zu rücken

pause_e
	sub R3, R3, #1
	cmp R3, #0
	bgt pause_e
	str R2, [R0]
	b loop
	
pause_z
	sub R3, R3, #1
	cmp R3, #0
	bgt pause_z
	str R2, [R0]
	b funf


	