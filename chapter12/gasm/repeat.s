#---------------------------------------
#       Repeat what you inputed
#---------------------------------------


    .global _start

    .data
message: 
    .ascii "              "

    .text
_start:
    # read
    mov $0, %rax
    mov $0, %rdi
    mov $message,   %rsi
    mov $14,    %rdx
    syscall

    # write
    mov $1, %rax
    mov $1, %rdi
    mov $message,   %rsi
    mov $14,    %rdx
    syscall

    # ret
    mov $60,    %rax
    mov $0,     %rdi
    syscall

