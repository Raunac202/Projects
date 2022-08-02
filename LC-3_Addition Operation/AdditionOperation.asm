;=========================================================================
; Name & Email must be EXACTLY as in Gradescope roster!
; Name: Raunac Bhuiyan
; Email: rbhui001@ucr.edu
; 
; Assignment name: Assignment 4
; Lab section: 024
; TA: Shirin Haji Amin Shirazi
; 
; I hereby certify that I have not received assistance on this assignment,
; or used code, from ANY outside source other than the instruction team
; (apart from what was provided in the starter file).
;
;=================================================================================
;THE BINARY REPRESENTATION OF THE USER-ENTERED DECIMAL NUMBER MUST BE STORED IN R1
;=================================================================================

					.ORIG x3000		
;-------------
;Instructions
;-------------

; output intro prompt
						
; Set up flags, counters, accumulators as needed

; Get first character, test for '\n', '+', '-', digit/non-digit 	
					
					; is very first character = '\n'? if so, just quit (no message)!

					; is it = '+'? if so, ignore it, go get digits

					; is it = '-'? if so, set neg flag, go get digits
					
					; is it < '0'? if so, it is not a digit	- o/p error message, start over

					; is it > '9'? if so, it is not a digit	- o/p error message, start over
				
					; if none of the above, first character is first numeric digit - convert it to number & store in target register!
					
; Now get remaining digits from user in a loop (max 5), testing each to see if it is a digit, and build up number in accumulator

					; remember to end with a newline!

START_PROGRAM
	LD R0, introPromptPtr
	PUTS
	AND R1, R1, #0
	AND R2, R2, #0
	LD R3, max_input
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0
	GETC
	OUT
	ST R0, storing_input
	LD R2, minus_enter
	ADD R0, R0, R2
	BRz FINISH_PROGRAM
	LD R0, storing_input
	LD R2, minus_plus
	ADD R0, R0, R2
	BRz TRUE
	LD R0, storing_input
	LD R2, minus_minus
	ADD R0, R0, R2
	BRz TRUE
	
	STILL_CHECKING
	LD R2, minus_enter
	LD R0, storing_input
	LD R6, FIRST_SUB		;check the validity of the input
	JSRR R6
	ADD R4, R4, #0
	BRn FINISH_PROGRAM
	BRz ERROR_MESSAGE
	LD R2, minus_hex30
	ADD R1, R0, R2		;FIRST INPUT IN R1
	
	TRUE	;AT THIS POINT THE FIRST INPUT HAS BEEN VALID
		ADD R3, R3, #0
		BRz PROGRAM_TERMINATED
		LD R2, minus_enter
		GETC
		OUT
		LD R6, FIRST_SUB
		JSRR R6
		ADD R4, R4, #0
		BRn FINISH_PROGRAM
		BRz ERROR_MESSAGE
		LD R6, SECOND_SUB
		JSRR R6
		BR TRUE
		
	ERROR_MESSAGE
	LD R0, newline
	OUT
	LD R0, errorMessagePtr
	PUTS
	BR START_PROGRAM
		
	NEGATIVE
		NOT R1, R1
		ADD R1, R1, #1
		HALT
	NEGATIVE2
		NOT R1, R1
		ADD R1, R1, #1
		LD R0, newline
		OUT
		HALT
	PROGRAM_TERMINATED	;5 maxmium inputs have been detected
		LD R0, storing_input
		LD R2, minus_minus
		ADD R0, R0, R2
		BRz NEGATIVE2
		LD R0, newline
		OUT
		HALT
	FINISH_PROGRAM
		LD R0, storing_input
		LD R2, minus_minus
		ADD R0, R0, R2
		BRz NEGATIVE
		
					HALT

;---------------	
; Program Data
;---------------
FIRST_SUB			.FILL	x3200
SECOND_SUB			.FILL	x3400
introPromptPtr		.FILL xB000
errorMessagePtr		.FILL xB200
minus_enter			.FILL	#-10
minus_plus			.FILL	#-43
minus_minus			.FILL	#-45
minus_hex30			.FILL	-x30
storing_input		.BLKW	#1
max_input			.FILL	#5
newline				.FILL	'\n'
HEX_43				.FILL	x43

;------------
; Remote data
;------------
					.ORIG xB000			; intro prompt
					.STRINGZ	"Input a positive or negative decimal number (max 5 digits), followed by ENTER\n"
					
					
					.ORIG xB200			; error message
					.STRINGZ	"ERROR: invalid input\n"
;=======================================================================
; Subroutine: FIRST_SUB
; Parameter: R0 and R2 with neg newline
; Postcondition: 
; Return Value: R4 with n z or p
;=======================================================================
.orig x3200
;(1) backup affected registers
ST R7, backup_R7_3200
ST R2, backup_R2_3200
ST R0, backup_R0_3200
;(2) subroutine algorithim
	AND R4, R4, #0
	ADD R0, R0, R2
	BRz NEWLINE_DETECTED
	LD R0, backup_R0_3200
	LD R2, HEX_30
	ADD R0, R0, R2
	BRn STOP_FIRSTSUB
	LD R0, backup_R0_3200
	LD R2, HEX_39
	ADD R0, R0, R2
	BRnz VALID_INPUT
	BR STOP_FIRSTSUB
	
	VALID_INPUT
		ADD R4, R4, #1
		BR STOP_FIRSTSUB
	NEWLINE_DETECTED
		ADD R4, R4, #-1
	STOP_FIRSTSUB
		ADD R3, R3, #-1
;(3) restore backed up registers
LD R7, backup_R7_3200
LD R2, backup_R2_3200
LD R0, backup_R0_3200
;(4) Return:
RET
; Local data for FIRST_SUB
backup_R7_3200	.BLKW	#1
backup_R2_3200	.BLKW	#1
backup_R0_3200	.BLKW	#1
HEX_30			.FILL	-x30
HEX_39			.FILL	-x39

;=======================================================================
; Subroutine: SECOND_SUB
; Parameter: R0 
; Postcondition: 
; Return Value: R1 (updated)
;=======================================================================
.orig x3400
;(1) backup affected registers
ST R7, backup_R7_3400
ST R2, backup_R2_3400
ST R4, backup_R4_3400
;(2) subroutine algorithim
LD R2, incrementer
ADD R4, R1, #0
WHILE_LOOP
	ADD R1, R1, R4
	ADD R2, R2, #-1
	BRp WHILE_LOOP
LD R2, minus_hex30cpy
ADD R0, R0, R2
ADD R1, R1, R0

;(3) restore backed up registers
LD R7, backup_R7_3400
LD R2, backup_R2_3400
LD R4, backup_R4_3400
;(4) Return:
RET
; Local data for SECOND_SUB
backup_R7_3400	.BLKW	#1
backup_R2_3400	.BLKW	#1
backup_R4_3400	.BLKW	#1
incrementer		.FILL	#9
minus_hex30cpy	.FILL	-x30
;---------------
; END of PROGRAM
;---------------
					.END

;-------------------
; PURPOSE of PROGRAM
;-------------------
; Convert a sequence of up to 5 user-entered ascii numeric digits into a 16-bit two's complement binary representation of the number.
; if the input sequence is less than 5 digits, it will be user-terminated with a newline (ENTER).
; Otherwise, the program will emit its own newline after 5 input digits.
; The program must end with a *single* newline, entered either by the user (< 5 digits), or by the program (5 digits)
; Input validation is performed on the individual characters as they are input, but not on the magnitude of the number.
