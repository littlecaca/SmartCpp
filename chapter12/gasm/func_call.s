#------------------------------
#       Call Functions
#------------------------------


    .global _start

    .macro pushall
        push %rax
        push %rdi
        push %rsi
        push %rdx
    .endm

    .macro popall
        pop %rdx
        pop %rsi
        pop %rdi
        pop %rax
    .endm

    .data
message:
    .ascii  "Hello, World!\n"

    .text
_start:
    jmp out_put


out_put:
    mov $18, %rdi
    call print
    mov $60, %rax
    syscall

print:
    pushall
    mov $1, %rax
    mov $1, %rdi
    mov $message, %rsi
    mov $14, %rdx
    syscall
    popall
    ret
