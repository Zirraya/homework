(defun f18 (l1 l2 &optional path (index 1) (result nil))
  (if (null l2) 
      result
      (let ((el (car l2)))
        ;; Проверяем текущий элемент списка l2
        (let ((sub-result (if (listp el)
                              (f18 l1 el (cons index path) 1 nil)
                              nil))
              (fragment-result (if (starts-with l2 l1)
                                   (list (reverse (cons index path)))
                                   nil))
              (tail-result (f18 l1 (cdr l2) path (+ index 1) result)))
          (append fragment-result sub-result tail-result)))))

(defun starts-with (lst sub)
  (cond
    ((null sub) t)
    ((null lst) nil)
    ((equal (car lst) (car sub))
     (starts-with (cdr lst) (cdr sub)))
    (t nil)))

;; Тестовый пример
(print (f18 '(a a (b) a) 
            '(c a a (b) a a (b) a (a d a a (b a a (b a a (b) a z) a h a a (b) a) a))))



