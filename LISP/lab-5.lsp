;;; Шаблон для выполнения заданий Лабораторной работы №5 
;;; ВСЕ КОММЕНТАРИИ ПРИВЕДЕННЫЕ В ДАННОМ ФАЙЛЕ ДОЛЖНЫ ОСТАТЬСЯ НА СВОИХ МЕСТАХ
;;; НЕЛЬЗЯ ПЕРЕСТАВЛЯТЬ МЕСТАМИ КАКИЕ-ЛИБО БЛОКИ ДАННОГО ФАЙЛА
;;; решения заданий должны быть вписаны в отведенные для этого позиции 

;;; ВСПОМОГАТЕЛЬНЫЕ ОПРЕДЕЛЕНИЯ 
;;; Нельзя вносить изменения в следующий блок
;; отключение предупреждений (т.к. предполагается использование
;; взаимной рекурсии и будут предупреждения об использовании 
;; неописанных функций)
(declaim (sb-ext:muffle-conditions style-warning))

;; определяется исключение on-unknown-expression
;; которое предполагается поднимать при получении 
;; неизвестного выражения
(define-condition on-unknown-expression (error)
   ((message :initarg :message :reader message))
)

;;; РЕШЕНИЕ ЗАДАНИЙ 

;; Задание 1. Предикаты для выражений
;; 0? 
(defun 0? (expr)
  (and (numberp expr) (= expr 0)))

;; 1?
(defun 1? (expr)
  (and (numberp expr) (= expr 1)))

;; +?
(defun +? (expr)
  (and (listp expr) (eq (car expr) '+) (>= (length expr) 1)))

;; -?
(defun -? (expr)
  (and (listp expr) (eq (car expr) '-) (>= (length expr) 1)))

;; *?
(defun *? (expr)
  (and (listp expr) (eq (car expr) '*) (>= (length expr) 1)))

;; /?
(defun /? (expr)
  (and (listp expr) (eq (car expr) '/) (>= (length expr) 1)))

;; expt?
(defun expt? (expr)
  (and (listp expr) (eq (car expr) 'expt) (= (length expr) 3)))

;; sqrt?
(defun sqrt? (expr)
  (and (listp expr) (eq (car expr) 'sqrt) (= (length expr) 2)))

;; sin?
(defun sin? (expr)
  (and (listp expr) (eq (car expr) 'sin) (= (length expr) 2)))

;; cos?
(defun cos? (expr)
  (and (listp expr) (eq (car expr) 'cos) (= (length expr) 2)))

;; tan?
(defun tan? (expr)
  (and (listp expr) (eq (car expr) 'tan) (= (length expr) 2)))

;; asin?
(defun asin? (expr)
  (and (listp expr) (eq (car expr) 'asin) (= (length expr) 2)))

;; acos?
(defun acos? (expr)
  (and (listp expr) (eq (car expr) 'acos) (= (length expr) 2)))

;; atan?
(defun atan? (expr)
  (and (listp expr) (eq (car expr) 'atan) (= (length expr) 2)))

;; exp?
(defun exp? (expr)
  (and (listp expr) (eq (car expr) 'exp) (= (length expr) 2)))

;; log?
(defun log? (expr)
  (and (listp expr) (eq (car expr) 'log) 
       (or (= (length expr) 2) (= (length expr) 3))))

;; Задание 2. Конструкторы для выражений
;; make+
(defun make+ (&rest args)
  (cons '+ args))

;; make-
(defun make- (&rest args)
  (if (null args) (error "Too few arguments for -") (cons '- args)))

;; make*
(defun make* (&rest args)
  (cons '* args))

;; make/
(defun make/ (&rest args)
  (cons '/ args))

;; makeexpt
(defun makeexpt (base exponent)
  (list 'expt base exponent))

;; makesqrt
(defun makesqrt (arg)
  (list 'sqrt arg))

;; makesin
(defun makesin (arg)
  (list 'sin arg))

;; makecos
(defun makecos (arg)
  (list 'cos arg))

;; maketan
(defun maketan (arg)
  (list 'tan arg))

;; makeasin
(defun makeasin (arg)
  (list 'asin arg))

;; makeacos
(defun makeacos (arg)
  (list 'acos arg))

;; makeatan
(defun makeatan (arg)
  (list 'atan arg))

;; makeexp
(defun makeexp (arg)
  (list 'exp arg))

;; makelog
(defun makelog (&rest args)
  (if (or (null args) (> (length args) 2)) 
      (error "Invalid number of arguments for log")
      (cons 'log args)))

;; Задание 3. НОРМАЛИЗАЦИЯ ВЫРАЖЕНИЙ
;; Следующая функция должна остаться без изменений
(defun normalize (expr)
  (cond 
    ((atom expr) expr)  
    ((+? expr) (+-normalize expr))
    ((-? expr) (--normalize expr))
    ((*? expr) (*-normalize expr))
    ((/? expr) (/-normalize expr))
    ((expt? expr) (expt-normalize expr))
    ((sqrt? expr) (sqrt-normalize expr))
    ((sin? expr) (sin-normalize expr))
    ((cos? expr) (cos-normalize expr))
    ((tan? expr) (tan-normalize expr))
    ((asin? expr) (asin-normalize expr))
    ((acos? expr) (acos-normalize expr))
    ((atan? expr) (atan-normalize expr))
    ((exp? expr) (exp-normalize expr))
    ((log? expr) (log-normalize expr))
    (T (error 'on-unknown-expression))))

;; +-normalize
(defun +-normalize (expr)
  (let ((args (mapcar #'normalize (cdr expr))))
    (cond
      ((null args) 0)
      ((null (cdr args)) (car args))
      (T (make+ (car args) (apply #'make+ (cdr args)))))))

;; --normalize
(defun --normalize (expr)
  (let ((args (mapcar #'normalize (cdr expr))))
    (cond
      ((= (length args) 1) (make* -1 (car args)))
      (T (make+ (car args) (make* -1 (apply #'make+ (cdr args))))))))

;; *-normalize
(defun *-normalize (expr)
  (let ((args (mapcar #'normalize (cdr expr))))
    (cond
      ((null args) 1)
      ((null (cdr args)) (car args))
      (T (make* (car args) (apply #'make* (cdr args)))))))

;; /-normalize
(defun /-normalize (expr)
  (let ((args (mapcar #'normalize (cdr expr))))
    (cond
      ((= (length args) 1) (make/ (car args)))
      (T (make* (car args) (make/ (apply #'make* (cdr args))))))))

;; expt-normalize
(defun expt-normalize (expr)
  (makeexpt (normalize (cadr expr)) (normalize (caddr expr))))

;; sqrt-normalize
(defun sqrt-normalize (expr)
  (makeexpt (normalize (cadr expr)) 1/2))

;; sin-normalize
(defun sin-normalize (expr)
  (makesin (normalize (cadr expr))))

;; cos-normalize
(defun cos-normalize (expr)
  (makecos (normalize (cadr expr))))

;; tan-normalize
(defun tan-normalize (expr)
  (make* (makesin (normalize (cadr expr))) 
         (make/ (makecos (normalize (cadr expr))))))

;; asin-normalize
(defun asin-normalize (expr)
  (makeasin (normalize (cadr expr))))

;; acos-normalize
(defun acos-normalize (expr)
  (makeacos (normalize (cadr expr))))

;; atan-normalize
(defun atan-normalize (expr)
  (makeatan (normalize (cadr expr))))

;; exp-normalize
(defun exp-normalize (expr)
  (makeexp (normalize (cadr expr))))

;; log-normalize
(defun log-normalize (expr)
  (if (= (length expr) 2)
      (makelog (normalize (cadr expr)))
      (make* (makelog (normalize (cadr expr))) 
             (make/ (makelog (normalize (caddr expr)))))))

;; УПРОЩЕНИЕ ВЫРАЖЕНИЙ
;; Следующая функция должна остаться без изменений
(defun simplify (expr)
  (let ((expr (normalize expr)))
    (cond 
      ((atom expr) expr)
      ((+? expr) (simplify+ expr))
      ((*? expr) (simplify* expr))
      ((/? expr) (simplify/ expr))
      ((expt? expr) (simplifyexpt expr))
      ((sin? expr) (simplify-fun-1 expr))
      ((cos? expr) (simplify-fun-1 expr))
      ((asin? expr) (simplify-fun-1 expr))
      ((acos? expr) (simplify-fun-1 expr))
      ((atan? expr) (simplify-fun-1 expr))
      ((exp? expr) (simplifyexp expr))
      ((log? expr) (simplifylog expr))
      (T (error 'on-unknown-expression)))))

;; Задание 4. Упрощение сложения
;; simplify+
(defun simplify+ (expr)
  (let ((arg1 (simplify (cadr expr)))
        (arg2 (simplify (caddr expr))))
    (cond
      ((0? arg1) arg2)
      ((0? arg2) arg1)
      ((and (numberp arg1) (numberp arg2)) (+ arg1 arg2))
      ((numberp arg1) (simplify+-aux1 arg2 arg1))
      ((numberp arg2) (simplify+-aux1 arg1 arg2))
      ((+? arg1) (simplify+-aux2 arg2 arg1))
      ((+? arg2) (simplify+-aux2 arg1 arg2))
      (T (make+ arg1 arg2)))))

;; simplify+-aux1
(defun simplify+-aux1 (expr n)
  (cond
    ((numberp expr) (+ expr n))
    ((+? expr) 
     (let ((first (cadr expr))
           (rest (caddr expr)))
       (if (numberp first)
           (let ((sum (+ first n)))
             (if (0? sum)
                 rest
                 (make+ sum rest)))
           (make+ n expr))))
    (T (make+ n expr))))

;; simplify+-aux2
(defun simplify+-aux2 (expr +expr)
  (cond
    ((numberp expr) (simplify+-aux1 +expr expr))
    ((+? expr)
     (if (numberp (cadr expr))
         (simplify+-aux1 (make+ (cadr +expr) (caddr +expr)) (cadr expr))
         (make+ (cadr expr) (make+ (cadr +expr) (caddr +expr)))))
    (T (make+ (cadr +expr) (make+ (caddr +expr) expr)))))

;; Задание 5. Упрощение умножения
;; simplify*
(defun simplify* (expr)
  (let ((arg1 (simplify (cadr expr)))
        (arg2 (simplify (caddr expr))))
    (cond
      ((0? arg1) 0)
      ((0? arg2) 0)
      ((1? arg1) arg2)
      ((1? arg2) arg1)
      ((and (numberp arg1) (numberp arg2)) (* arg1 arg2))
      ((numberp arg1) (simplify*-aux1 arg2 arg1))
      ((numberp arg2) (simplify*-aux1 arg1 arg2))
      ((*? arg1) (simplify*-aux2 arg2 arg1))
      ((*? arg2) (simplify*-aux2 arg1 arg2))
      ((and (/? arg1) (equal (cadr arg1) arg2)) 1)
      ((and (/? arg2) (equal (cadr arg2) arg1)) 1)
      ((+? arg1) (simplify (apply #'make+ (simplify*-through+ (cdr arg1) arg2))))
      ((+? arg2) (simplify (apply #'make+ (simplify*-through+ (cdr arg2) arg1))))
      (T (make* arg1 arg2)))))

;; simplify*-through+
(defun simplify*-through+ (exprs n)
  (if (null exprs)
      nil
      (cons (make* (car exprs) n) 
            (simplify*-through+ (cdr exprs) n))))


;; simplify*-aux1
(defun simplify*-aux1 (expr n)
  (cond
    ((numberp expr) (* expr n))
    ((*? expr)
     (let ((first (cadr expr))
           (rest (caddr expr)))
       (if (numberp first)
           (let ((prod (* first n)))
             (if (1? prod)
                 rest
                 (make* prod rest)))
           (make* n expr))))
    ((+? expr) (simplify (apply #'make+ (simplify*-through+ (cdr expr) n))))
    (T (make* n expr))))

;; simplify*-aux2
(defun simplify*-aux2 (expr *expr)
  (cond
    ((numberp expr) (simplify*-aux1 *expr expr))
    ((*? expr)
     (if (numberp (cadr expr))
         (simplify*-aux1 (make* (cadr *expr) (caddr *expr)) (cadr expr))
         (make* (cadr expr) (make* (cadr *expr) (caddr *expr)))))
    ((+? expr) (simplify (apply #'make+ (simplify*-through+ (cdr expr) *expr))))
    (T (make* (cadr *expr) (make* (caddr *expr) expr)))))

;; Задание 6. Упрощение обратного элемента (унарного деления)
;; simplify/
(defun simplify/ (expr)
  (let ((arg (simplify (cadr expr))))
    (cond
      ((numberp arg) (/ 1 arg))
      ((/? arg) (cadr arg))
      ((*? arg) (simplify (apply #'make* (simplify/-through* (cdr arg)))))
      (T (make/ arg)))))

;; simplify/-through*
(defun simplify/-through* (exprs)
  (mapcar #'make/ exprs))

;; Задание 7. Упрощение возведения в степень
;; simplifyexpt
(defun simplifyexpt (expr)
  (let ((base (simplify (cadr expr)))
        (exponent (simplify (caddr expr))))
    (cond
      ((0? exponent) 1)
      ((0? base) 0)
      ((1? base) 1)
      ((1? exponent) base)
      ((and (numberp base) (numberp exponent)) (expt base exponent))
      ((expt? base)
       (simplify (makeexpt (cadr base) (make* (caddr base) exponent))))
      ((exp? base)
       (simplify (makeexp (make* (cadr base) exponent))))
      (T (makeexpt base exponent)))))

;; Задание 8. Упрощение остальных функций
;; simplify-fun-1
(defun simplify-fun-1 (expr)
  (let ((arg (simplify (cadr expr))))
    (if (numberp arg)
        (eval (list (car expr) arg))
        (list (car expr) arg))))

;; simplifyexp
(defun simplifyexp (expr)
  (let ((arg (simplify (cadr expr))))
    (cond
      ((numberp arg) (exp arg))
      ((log? arg) (cadr arg))
      (T (makeexp arg)))))

;; simplifylog
(defun simplifylog (expr)
  (let ((arg (simplify (cadr expr))))
    (cond
      ((numberp arg) (log arg))
      ((exp? arg) (cadr arg))
      ((expt? arg)
       (simplify (make* (caddr arg) (makelog (cadr arg)))))
      (T (makelog arg)))))

;; ПРОИЗВОДНАЯ ВЫРАЖЕНИЯ
;; Следующая функция должна остаться без изменений
(defun deriv (expr var) 
  (cond 
    ((atom expr) (if (eq expr var) 1 0))  
    ((+? expr) (+-deriv expr var))
    ((*? expr) (*-deriv expr var))
    ((/? expr) (/-deriv expr var))
    ((expt? expr) (expt-deriv expr var))
    ((sin? expr) (sin-deriv expr var))
    ((cos? expr) (cos-deriv expr var))
    ((asin? expr) (asin-deriv expr var))
    ((acos? expr) (acos-deriv expr var))
    ((atan? expr) (atan-deriv expr var))
    ((exp? expr) (exp-deriv expr var))
    ((log? expr) (log-deriv expr var))
    (T (error 'on-unknown-expression))))

;; Задание 9. Производная суммы 
;; +-deriv
(defun +-deriv (expr var)
  (make+ (deriv (cadr expr) var) (deriv (caddr expr) var)))

;; Задание 10. Производная произведения
;; *-deriv
(defun *-deriv (expr var)
  (let ((u (cadr expr))
        (v (caddr expr)))
    (make+ (make* (deriv u var) v)
           (make* u (deriv v var)))))

;; Задание 11. Производная обратного элемента
;; /-deriv
(defun /-deriv (expr var)
  (let ((u (cadr expr)))
    (make* -1 
           (make/ (makeexpt u 2))
           (deriv u var))))

;; Задание 12. Производная степенной функции
;; expt-deriv
(defun expt-deriv (expr var)
  (let ((u (cadr expr))
        (v (caddr expr)))
    (make+ (make* v 
                  (makeexpt u (make- v 1))
                  (deriv u var))
           (make* (makeexpt u v)
                  (makelog u)
                  (deriv v var)))))

;; Задание 13. Производные тригонометрических функций
;; sin-deriv
(defun sin-deriv (expr var)
  (let ((u (cadr expr)))
    (make* (deriv u var) (makecos u))))

;; cos-deriv
(defun cos-deriv (expr var)
  (let ((u (cadr expr)))
    (make* -1 (deriv u var) (makesin u))))

;; Задание 14. Производные обратных тригонометрических функций
;; asin-deriv
(defun asin-deriv (expr var)
  (let ((u (cadr expr)))
    (make* (deriv u var)
           (make/ (makeexpt (make- 1 (makeexpt u 2)) 1/2)))))

;; acos-deriv
(defun acos-deriv (expr var)
  (let ((u (cadr expr)))
    (make* -1
           (deriv u var)
           (make/ (makeexpt (make- 1 (makeexpt u 2)) 1/2)))))

;; atan-deriv
(defun atan-deriv (expr var)
  (let ((u (cadr expr)))
    (make* (deriv u var)
           (make/ (make+ 1 (makeexpt u 2))))))

;; Задание 15. Производные экспоненты и натурального логарифма
;; exp-deriv
(defun exp-deriv (expr var)
  (let ((u (cadr expr)))
    (make* (deriv u var) (makeexp u))))

;; log-deriv
(defun log-deriv (expr var)
  (let ((u (cadr expr)))
    (make* (deriv u var) (make/ u))))