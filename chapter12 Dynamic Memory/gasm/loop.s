.section .data
message:
    .ascii "-\n"
.section .text
.globl _start

_start:
    movq $1, %rax       # Initialize the loop counter to 1
    movq $5, %rbx       # Set the loop limit to 5

loop_start:
    # Your loop body goes here

    # Print the loop counter
    movq %rax, %rdi
    call print_number
 
    incq %rax           # Increment the loop counter
    cmpq %rbx, %rax     # Compare the loop counter with the loop limit
    jle loop_start      # Jump to loop_start if less than or equal (i.e., continue the loop)
   

    # Exit the program
    movq $60, %rax      # syscall number for "exit"
    xorq %rdi, %rdi     # Status code 0
    syscall             # Make the syscall to exit the program

# Function to print a number
print_number:
    pushq %rax
    pushq %rbx
    pushq %rcx

    movq $10, %rbx      # Base 10
    xorq %rcx, %rcx     # Initialize digit count to 0

num_to_ascii_loop:
    xorq %rdx, %rdx     # Clear rdx before the division
    divq %rbx           # Divide rax by 10, remainder in rdx, quotient in rax
    addq $48, %rdx       # Convert remainder to ASCII digit
    pushq %rdx          # Push the digit onto the stack
    incq %rcx           # Increment digit count
    
    test %rax, %rax     # Check if quotient is zero
    jnz num_to_ascii_loop   # Jump if not zero (more digits to process)


print_loop:

    // pushq %rcx

    movq $1, %rax       # syscall number for "write"
    movq $1, %rdi       # File descriptor 1 (stdout)
    movq %rsp, %rsi     # Pointer to the ASCII digit
    movq $1, %rdx       # Number of bytes to write (1 digit)
    
    pushq %rcx
    syscall             # Make the syscall to print the digit
    popq %rcx

    popq %rdx
  
    // popq %rcx

    decq %rcx           # Decrement digit count
    jnz print_loop

    movq $message, %rsi
    movq $2, %rdx
    syscall
    
    popq %rcx
    popq %rbx
    popq %rax

    ret
