.data
strA: .asciiz “Please enter your choice to skip numbers (1-4)\n”
strB: .asciiz "Sum: "
newline: .asciiz "\n"
Numbers: .byte 100, -7, 11, 25, -66, 99, -1, 34, 12, 22, -2, -7, 100,
11, 4, 67, 2, -90, 22, 2, 56, 3, -89, 12, -10, 21, 10, -25, -6, 9, 111,
34, 12, 22, -2, -17, 100, 111, -4, 7, 14, -19, -2, 29, 36, 31, -79, 2
.globl main
.text
main: # Your fully commented program starts here.
	
	 la $a0, strA
       jal printSum
      
       addi $v0, $zero, 5	#load input
       syscall
							#Intializations
       move $t0, $v0       # $t0 has skip value
       addi $t1, $zero, 0   # $t1 has the next number to add ($t2)
       addi $t2, $zero, 0   # $t2 has index to "Numbers" sequence
       addi $t3, $zero, 48   # $t3 has size of "Numbers"
       addi $t4, $zero, 0   # $t4 has sum of "Numbers"
      
       while:   ble $t2, $t3, end  #go to end while $t2 <= $t3
           lb $t1, Numbers($t2)		#load the next integer to add
           add $t4, $t4, $t1		#sum += next integer to add
           add $t2, $t2, $t0		#index += skip value(points to the next integer to add after skipping one or more integers)
           b while
          
       end:   				# Load in the resulting sum of integers
           la $a0, strB
           jal printSum
          
           move $a0, $t4
           addi $v0, $zero, 1
           syscall
          
           la $a0, newline	#loading a new line character
           jal printSum	# Go to printSum function
     
   printSum:   					#Function to print the sum of the integers
           addi $v0, $zero, 4
           syscall
          
           jr $ra


# Exit the program by means of a syscall.
# There are many syscalls - pick the desired one
# by placing its code in $v0. The code for exit is "10"
li $v0, 10 # Sets $v0 to "10" to select exit syscall
syscall # Exit