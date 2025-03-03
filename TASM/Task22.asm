.model small

.stack 100h

.data

Niki db 'Nikitenko Yana 211 $'
    newLine db 13, 10, '$'  ; Символы для новой строки  13 возрващает в начало строки, 10 переводит строку вниз

.code

start:

mov AX, @data
mov DS, AX

	; Вывод сообщения
    mov DX, offset Niki
    mov AH, 09h
    int 21h

    ; Переход на новую строку
    mov DX, offset newLine
    mov AH, 09h
    int 21h
	
	
mov AX, 2
mov BX, 3
mov DL, AL

call print

mov DL, 0D0h

call print

mov DL, BL

call print

mov DL, 0DDh

call print

mov DL, 0DAh

call print

xchg AX, BX
mov DL, AL

call print

mov DL, 0D0h

call print

mov DL, BL

call print

mov AX, 4C00h
int 21h

print proc

push AX
push dx

mov AH, 02h
add DX, 30h
int 21h

pop DX
pop AX

ret

print endp

end start