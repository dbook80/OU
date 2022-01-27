.data
strA: .asciiz "Original Array:\n "
strB: .asciiz "Second Array:\n "
newline: .asciiz "\n"
space:  .ascii " "

Original: 	.word 200, 270, 250, 100
		.word 205, 230, 105, 235
		.word 190, 95, 90, 205
		.word 80, 205, 110, 215
Second: .space 64

.align 2
.globl main
.text

main: # Your fully commented program starts here.

	li $v0, 4
	syscall
	la	$a1, strA   #load address of Original array into $a1
	li	$s0, 16		# load end of the array into $s0
	li	$s1, 0		# load beginning of the array into $s1

loop:
	li	$v0, 5		#load input
	syscall
	sll	$s2, $s1, 2	#shift left
	add	$s0, $a1, $a2	# $s0 = $a1 + (4 * $s1)
	sw	$v0, 0($s0)	# $v0 = $s0
	addi	$s0, $s0, -1	#$s0 = array[3]
	addi	$s1, $s1, 1		#$s1 = array[1]
	bgtz	$s0, loop
	
	li	$v0, 4
	la	$a0, strB	# load address of Second array into $a0
	syscall
	li	$s0, 16
	li	$s1, 0		# array index intialization
	
	addi $a2, $s1, 0	# i is stored in a2
	addi $a3, $s1, 0	# j is stored in a3

Transposition:
	addi $s0, $zero, 3	# Register $s0 = 3(serves as a for loop index)
	beq $a2, $s0, cond1

cond1:
	beq $a3, $s0, cond2

cond2:
	jr $ra
	beq $a2, $a3, swap #nested loop condition

swap:
	addi $a2, $a2, 1	#increment i
	addi $a3, $zero, 0
	jal Transposition	#go to Transpostion function
	sll $s1, $a3, 2
	add $s2, $s1, $a2
	sll $s3, $s2, 2
	add $s4, $a1, $s3	# array[i][j] = 1
	sll $s1, $a2, 2
	add $a2, $s1, $a2
	sll $s3, $s2, 2		#next statements proceed to execute element swapping
	add $s5, $a1, $s3	#array[j][i] = 1
	lw $s6, 0($s5)		#Register $s6(temp) = array[j][i]
	lw $s7, 0($s4)		#s7 = array[i][j]
	sw $s7, 0($s5)		#array[j][i] = array[i][j]
	sw $s6, 0($s5)		#array[i][j] = temp
	jr $ra
	li $s0, 16
	li $s1, 0			# Array index intialization
	b clprint

	clprint:			#Function to print original and transposed matrices
	sll $s2, $s1, 2
	add $s3, $a1, $s2
	lw $s4, 0($s3)
	li $v0, 1
	addi $a0, $s4, 0
	syscall
	li $v0, 4
	la $a0, space
	syscall
	addi $s0, $s0, -1
	addi $s1, $s1, 1
	sll $s2, $s1, 2
	add $s3, $a1, $a2
	lw $s4, 0($s3)
	li $v0, 1
	addi $a0, $s4, 0
	syscall
	li $v0, 4
	la $a0, space
	syscall
	addi $s0, $s0, -1
	addi $s1, $s1, 1
	sll $s2, $s1, 2
	add $s3, $a1, $a2
	lw $s4, 0($s3)
	li $v0, 1
	addi $a0, $s4, 0
	syscall
	li $v0, 4
	la $a0, space
	syscall
	addi $s0, $s0, -1
	addi $s1, $s1, 1
	sll $s2, $s1, 2
	add $s3, $a1, $a2
	lw $s4, 0($s3)
	li $v0, 1
	addi $a0, $s4, 0
	syscall
	li $v0, 4
	la $a0, space
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	addi $s0, $s0, -1
	addi $s1, $s1, 1
	bgtz $s0, clprint
	li $v0, 4
	la $a0, newline
	syscall

# Exit the program by means of a syscall.
# There are many syscalls - pick the desired one
# by placing its code in $v0. The code for exit is "10"
li $v0, 10 # Sets $v0 to "10" to select exit syscall
syscall # Exit
