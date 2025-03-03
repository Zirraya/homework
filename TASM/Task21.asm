.model small                 ; Модель памяти SMALL.stack 100h                  ; Сегмент стека размером 256 байт
.data
Niki db 'Nikitenko Yana 211 $', 
    newLine db 13, 10, '$'  ; Символы для новой строки 13 возрващает в начало строки, 10 переводит строку вниз
.code
start:
mov AX, @data     ;Загружает адрес сегмента данных в регистр AX.
mov DS, AX     ;Устанавливает сегмент данных (DS) на значение, находящееся в AX.

	; Вывод сообщения
    mov DX, offset Niki
    mov AH, 09h
    int 21h

    ; Переход на новую строку
    mov DX, offset newLine
    mov AH, 09h
    int 21h
	
mov AX, 3     ;Загружает значение 3 в регистр AX.
mov BX, 2     ;Загружает значение 2 в регистр BX.
mov AH, 02h     
mov DL, AL     ;Переносит значение из AL (которое равно 23) в DL.
add DL, 30h     
int 21h      

mov DL, 0h     ;Обнуляет DL
int 21h      ;Вызывает прерывание 21h для вывода символа '11' на экран.
mov DL, BL
add DL, 30h
int 21h
mov AX, 4C00h
int 21h
end start