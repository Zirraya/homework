.model small
.stack 100h
.186
.data

simple db 20 dup(?)
   result db ' $'
nl db 0Ah, 0Dh, '$'

.code
start:

mov ax, @data
mov ds, ax

mov cx, 10
mov bl, 2
mov si, 0
mov al, 5

vvod:
mul bl
mov simple[si], bl
mov simple[si+10], al
inc si
add bl, 2
mov al, 5
loop vvod

mov si, 0
call vyvod_pr
call vyvod_pr

mov ax,4C00h
int 21h


vyvod_pr proc
push cx
mov cx, 10
vyvod:
mov al, simple[si]
mov bl, 10
call byte_asc

mov ah, 09h
mov dx, offset result
int 21h
inc si
loop vyvod

pop cx

mov ah, 09h
mov dx, offset nl
int 21h


vyvod_pr endp

byte_asc proc
pusha
mov si, 3
delim:
dec si
mov ah, 0
div bl
add ah, 30h
mov result[si], ah
cmp al, 0
jg delim

popa

ret
byte_asc endp

end start
