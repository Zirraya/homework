.model small
.stack 100h
.186
.data 

colour_cnt db 09h 
char_cnt db 04Dh ; Начинаем с M

.code
start:
mov ax,@data
mov ds,ax
;Код главной программы
 
          mov ax,0b900h ;Используя сегментный регистр ES, 
            mov es,ax ;организовать запись данных в видеопамять
                      ;по адресу В900h:0000h (страница 1)
					 
					 
					 
         mov ah, 0Fh ; Функция 0Fh - получить текущий видеорежим
             int 10h ; Вызов прерывания


; Установить видеорежим 03h (80x25 текстовый режим)
       mov ax, 0003h ; Функция 00h - установить видеорежим
             int 10h ; Вызов прерывания

; Установить текущую страницу 01h
         mov ah, 05h ; Функция 05h - установить активную страницу
         mov al, 01h ; Страница 1
             int 10h ; Вызов прерывания


call B10DISPLAY



         mov ah, 00h ; Функция 00h - ожидание нажатия клавиши
   int 16h 

         mov ax,4C00h ;Завершение программы
int 21h

;Определение подпрограммы

B10DISPLAY proc 
pusha
mov al, char_cnt
mov ah, colour_cnt
mov di, 820 ; Код 820 соответсвует 5:10
mov cx, 0

cycle:
push cx
mov cx, 7

lp:
mov es:word ptr[di], ax
add di, 2
loop lp

add di, 146 ; Переход к следующей к строке
inc al
inc ah


pop cx
inc cx
cmp cx, 6 ; Количетство строк
jl cycle

popa
ret

B10DISPLAY endp

            end start ;Конец программы