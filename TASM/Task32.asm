.model small
.stack 100h
.386

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

mov EAX, 65536 ;Занtсения числа в регситр EAX
mov BX, 10 ;Занесение основания системы счисления
mov CX, 0 ;значение CX обнулятется
label1: mov EDX, 0 ;устанавливается метка label1, значение EDX обнуляется
div EBX ;деление EAX на EBX
push EDX ;сохранение значения регистра EDX в стеке
add CX, 1 ;добавление к CX единицы
cmp EAX, 0 ;сравнение EAX с нулём
jnz label1 ;Условный переход в метку label1
label2: pop EDX ;метка label2, сохранение EDX в стеке
call print ;вывод DL на экран

loop label2 ;повторение с метки label2, пока значение CX не станет равно 0
mov EAX, 4C00h
int 21h

print proc

push EAX
mov AH, 02h
add DL, 30h
int 21h
pop EAX
ret

print endp

end start