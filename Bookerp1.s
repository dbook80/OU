	.data
	   
V1: .asciiz "Enter total number of digits:\n"

V2: .asciiz "Enter the digit:\n"

V3: .asciiz "Entered Number:\n"

V4: .asciiz "Sum of product:\n"

V5: .asciiz "Armstrong number"

V6: .asciiz "Not an armstrong number"

CONTROL:	.word32 0x10000
DATA:		.word32 0x10008	  	
sum:		.double 0.0
capture:	.double 0.0
i:		.word 0
		
        .text

	lwu $t8,DATA($zero)	; $t8 = address of DATA register
	lwu $t9,CONTROL($zero)	; $t9 = address of CONTROL register
main:
	ld $s2,sum($zero)
	ld $s3,capture($zero)
	ld $s5,i($zero)
	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V1
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	daddi $v0,$zero,8	; set for reading integer from keyboard
	sd $v0,0($t9)		; Wait for an integer/double...(num)
	ld $s0,0($t8)		;
	
	ld $s6,0($s0)		;make copy of num
	daddi $s4,$s4,10	;multiplier for "capture"
	
Pow:
	dmul $t7,$t6,$t6	;power function, keep multiplying until power factor(num) is zero
	daddi $s6,$s6,-1	;decrement num
	bnez $s6, Pow
	
Loop:
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V2
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	daddi $v0,$zero,8	; set for reading integer from keyboard
	sd $v0,0($t9)		; Wait for an integer/double...(digit)
	ld $t6,0($t8)		;
	jal Pow
	dadd $s2,$s2,$t7	;update sum
	dmul $s3,$s3,$s4	;update capture
	dadd $s3,$s3,$t6
	daddi $s5,$s5,1		;increment i
	slt $t2,$s5,$s0		;loop as long as i < num
	bnez $t2, Loop
	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V3
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	daddi $v0,$zero,3	; set for double output
	l.d f1,capture($zero)
	s.d f1,0($t8)		; write double to DATA register
	sd $v0,0($t9)		; write to CONTROL register and make it happen
	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V4
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen

	daddi $v0,$zero,3	; set for double output
	l.d f1,sum($zero)
	s.d f1,0($t8)		; write double to DATA register
	sd $v0,0($t9)		; write to CONTROL register and make it happen
	
	beq $s3,$s2, L1		;if armstrong number = true
	bne $s3,$s2, L2		;else
	
L1:	
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V5
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen

L2:
	daddi $v0,$zero,4       ; set for ascii output
	daddi $t1,$zero,V6
	sd $t1,0($t8)           ; write address of message to DATA register
	sd $v0,0($t9)           ; make it happen
	
	halt