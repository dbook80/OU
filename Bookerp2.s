      .data
      
; Memory Mapped I/O area
;
; Address of CONTROL and DATA registers
;
; Set CONTROL = 1, Set DATA to Unsigned Integer to be output
; Set CONTROL = 2, Set DATA to Signed Integer to be output
; Set CONTROL = 3, Set DATA to Floating Point to be output
; Set CONTROL = 4, Set DATA to address of string to be output
; Set CONTROL = 5, Set DATA+5 to x coordinate, DATA+4 to y coordinate, and DATA to RGB colour to be output
; Set CONTROL = 6, Clears the terminal screen
; Set CONTROL = 7, Clears the graphics screen
; Set CONTROL = 8, read the DATA (either an integer or a floating-point) from the keyboard
; Set CONTROL = 9, read one byte from DATA, no character echo.
;

CR:    .word32 0x10000
DR:    .word32 0x10008
mes:   .asciiz "Enter the number of fibonacci numbers > 2:\n"		; the message
mes2:   .asciiz "The numbers are:\n" ; the message2
X:	.word 0
Y:	.word 1
Z:	.word 0
count:	.word 2

       .text
main:
	lwu $t8,DR($zero)	; $t8 = address of DATA register
	lwu $t9,CR($zero)	; $t9 = address of CONTROL register
	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,mes
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	daddi $v0,$zero,8	; set for reading integer from keyboard
	sd $v0,0($t9)		; Wait for an integer...
	ld $s1,0($t8)		;
	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,mes2
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	daddi $v0,$zero,1	; set for unsigned integer output
	ld $s3,X($zero)
	sd $s3,0($t8)           ; write x to DATA register
	sd $v0,0($t9)           ; write to CONTROL register and make it happen
	
	ld $s4,Y($zero)
	sd $s4,0($t8)           ; write y to DATA register
	sd $v0,0($t9)           ; write to CONTROL register and make it happen
	
	ld $s5,Z($zero)		; load Z into Reg t5
	ld $s6,count($zero)	; load count into Reg t6
	
Loop:	dadd $s5,$s3,$s4	;z = x+y
	sd $s5,0($t8)           ; write z to DATA register
	sd $v0,0($t9)           ; write to CONTROL register and make it happen
	ld $t0,Y($zero)		;x = y
	sd $t0,0($s3)
	ld $t0,Z($zero)		;y = z
	sd $t0,0($s4)
	daddi $s6,$s6,1 	;increment count
	slt $t2,$s6,$s1		;while loop setup: count < entered integer ($t2 set to 1)
	bnez $t2,Loop		; loop until $t2 = 0

        halt
 
