#-----------------------------------
#    Hello World using C library
#-----------------------------------

.section .data
hello_string:
    .ascii "hello world\n\0"  # Null-terminated string

.section .text
.globl main

main:
    # Call the puts function
    mov $hello_string, %rdi   # Load the address of the string into rdi (1st argument)
    call puts                 # Call the puts function

    # Exit the program
    mov $60, %rax             # syscall number for "exit"
    xor %rdi, %rdi            # Status code 0
    syscall                  # Make the syscall to exit the program
