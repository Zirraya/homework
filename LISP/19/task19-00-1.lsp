(load "streams.lsp")
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; здесь должна быть реализация функций take и drop

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; пример, соответствующий содержимому файла task12-00-1.hs

;; функция - аналог divides
;; так как в task12-00-1.hs функция была каррированная и это свойство
;; использовалось в решении (функция вызывается от первого аргумента),
;; то определяем её как каррированную - функцию первого аргумента, 
;; возвращающую функцию от второго аргумента
(defun divides (x)
  (lambda (y)
    (= (mod y x) 0)))

;; функция - аналог iterate
(defun iterate (f x)
  (cons-stream x (iterate f (funcall f x))))

;; функция - аналог filter 
;; поток stream фильтруется в соответствии с предикатом p
(defun filter-stream (p stream)
  (cond ((empty-stream-p stream) TES)
        ((funcall p (head stream)) 
         (cons-stream (head stream) 
                      (filter-stream p (tail stream))))
        (T (filter-stream p (tail stream)))))

;; функция - аналог map
;; получает поток (бесконечный список)
;; формирует поток
(defun map-stream (f stream)
  (if (empty-stream-p stream) TES
      (cons-stream (funcall f (head stream))
                   (map-stream f (tail stream)))))

;; функция, аналог композиции (в Haskell - . )
;; предполагается, что второй аргумент - функция одного параметра
(defun o (f1 f2)
  (lambda (x) (funcall f1 (funcall f2 x))))

;; функция - аналог crossout
(defun crossout (stream 
                 &aux 
                 (x (head stream))
                 (xs (tail stream)))
  (filter-stream (o 'not (divides x)) xs))

;; так как последовательность не зависит от параметров, определим её как 
;; значение переменной f19
(defvar f19)
(setq f19 
      (map-stream 'head
                  (iterate 'crossout
                           (integers-starting-from 2))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; 4. тестовые примеры
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(print (head (tail (tail (tail (tail (tail f19))))))) ; 6-е простое число
(print 
  (head (tail (tail (tail (tail (tail (tail (tail f19))))))))) ; 8-е число

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; следующие примеры должны заработать после реализации функций drop и take
;; результат вывода должен совпадать с результатом запуска функции main,
;; определнной в task12-00-1.hs

; (print (take 15 f19))
; (print (take 15 (drop 100 f19)))
; (print (take 5 (drop 1000 f19)))
