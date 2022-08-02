;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Raunac Bhuiyan
; Email: rbhui001@ucr.edu
; 
; Assignment name: Assignment 3
; Lab section: 025
; TA:Kaustubh
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=========================================================================

.ORIG x3000			; Program begins here
;-------------
;Instructions
;-------------
LD R6, Value_ptr		; R6 <-- pointer to value to be displayed as binary
LDR R1, R6, #0			; R1 <-- value to be displayed as binary 
;-------------------------------
;INSERT CODE STARTING FROM HERE
;--------------------------------
	BRn LOOP1
	BRzp LOOP2
	;THE FIRST TWO LOOPS WILL CHECK IF THE FIRST BIT IS POSITIVE OR NEGATIVE
	LOOP1
		LD R0, HEX_31
		TRAP x21
		BR COUNTER_LOOP1
	LOOP2
		LD R0, HEX_30
		TRAP x21
		BR COUNTER_LOOP1
	COUNTER_LOOP1
		ADD R2, R2, #4	;SETTING R2 with #4 as a counter
		ADD R3, R3, #4	;SETTING R3 with #4 as a counter (USED TO MAKE SURE NOT TO PRINT SPACE AFTER LAST BIT)
		BR LOOP3

	COUNTER_LOOP2
		ADD R2, R2, #5	;SETTING R2 as a counter
		
	LOOP3;---------------------------------------------(BITS 15-1)
		ADD R2, R2, #-1
		BRz LOOP6	;WHEN 4 BITS have BEEN PRINTED MOVE TO LOOP6 FOR SPACE
		ADD R1, R1, R1
		BRn LOOP4
		BRzp LOOP5
	LOOP4
		LD R0, HEX_31
		TRAP x21
		BR LOOP3
	LOOP5
		LD R0, HEX_30
		TRAP x21
		BR LOOP3
	LOOP6
		ADD R3, R3, #-1
		BRZ END_PROGRAM	;R3 = 0 INDICATES THAT THE LAST BIT HAS BEEN PRINTED SO NO NEED FOR SPACE
		LD R0, HEX_20	;PRINTING SPACE
		TRAP x21
		BR COUNTER_LOOP2
	;---------------------------------------------(BITS 15-1)
	END_PROGRAM
		LD R0, newline
		TRAP x21

HALT
;---------------	
;Data
;---------------
Value_ptr	.FILL xCA00	; The address where value to be displayed is stored

HEX_30	.FILL	x30	;'0'
HEX_31	.FILL	x31	;'1'
HEX_20	.FILL	x20	;space
newline	.FILL	'\n'

.ORIG xCA00					; Remote data
Value .FILL xABCD			; <----!!!NUMBER TO BE DISPLAYED AS BINARY!!! Note: label is redundant.
;---------------	
;END of PROGRAM
;---------------	
.END
