.model small                 ;Модель памяти SMALL использует сегменты 
                             ;размером не более 64Кб
.stack 100h                  ;Сегмент стека размером 100h (256 байт)
.data                        ;Начало сегмента данных
Niki db 'Nikitenko Yana 211$'
.code                        ;Начало сегмента кода
start:                       ;Точка входа в программу start 
                             ;Предопределенная метка @data обозначает
                             ;адрес сегмента данных в момент запуска программы,
mov AX, @data                ;который сначала загрузим в AX,
mov DS,AX                    ;а затем перенесем из AX в DS
mov AH,09h
mov DX,offset Niki
int 21h
mov AX,4C00h
int 21h
end start