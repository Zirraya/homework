.model small
.stack 100h
.386 ;Разрешение трансляции команд процессора 386
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

mov AX, 65535 ;Занtсения числа в регситр AX
mov BX, 10 ;Занесение основания системы счисления
mov CX, 0 ;значение CX обнулятется
label1: mov DX, 0 ;устанавливается метка label1, значение DX обнуляется
div BX ;деление AX на BX, div для числа без знака
push DX ;сохранение значения регистра DX в стеке
add CX, 1 ;добавление к CX единицы
cmp AX, 0 ;сравнение AX с нулём
jnz label1 ; Условный переход в метку label1
label2: pop DX ;метка label2, сохранение DX в стеке
call print ;вывод DL на экран
loop label2 ;повторение с метки label2, пока значение CX не станет равно нулю
mov AX,4C00h ;завершение программы
int 21h

print proc ;процедура для вывода значения DL на экран

push AX
mov AH, 02h
add DL, 30h
int 21h
pop AX
ret

print endp

end start