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
		

taster_loop
	ldr R4, =GPIOC_IDR
	ldr R6, =0x5
	ldr R5, [R4]
	and R5, R5, #0x1
	cmp R5, #0x1
	beq taster_loop
	b funf
	
funf
	sub R6, R6, #1
	cmp R6, #0
	bge loop
	b taster_loop



loop
	ldr R0, =GPIOA_ODR
	
	
	lsl R2, R2, #1
	add R2, R2, #1
	;str R2, [R0]
	cmp R2, #0x100
	
	blt weiter
	mov R2, #0x00
	ldr R3, =0xC3500
	b pause_z
	
	
weiter ;F?r 100ms zwischenpause
	ldr R3, =0x61A80
	align 4 ;um nachfolgenden Befehl auf durch 4 teilbaren Index zu r?cken

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


	