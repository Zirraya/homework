;;; Вариант 21. Исходный список ((A) (()) (B (C D)(()) () ((((X E) F)) G)) H)
(print
  (cons 
    (cons 'A ()) 
          (cons 
            (cons () ())  
            (cons
    (cons 'B
          (cons 
            (cons 'C 
            (cons 'D ()))  
              (cons 
              (cons () ())  
              (cons 
                ()  
                    (cons 
                      (cons 
                      (cons 
                      (cons 
      (cons 'X 
            (cons 'E ()))  
              (cons 'F ()))  
                      ())  
              (cons 'G ()))  
                        ())))))
                        (cons 'H ())))))  


;; Образец 0. (A (B) () () (C D (E)) (F () (X ())) G H)
;(print 
;  (cons 'A
;        (cons 
;          (cons 'B ())
;          (cons ()
;               (cons ()
;                     (cons 
;                       (cons 'C
;                             (cons 'D
;                                   (cons (cons 'E ()) 
;                                         ())))
;                       (cons 
;                         (cons 'F
;                               (cons ()
;                                     (cons 
;                                       (cons 'X 
;                                             (cons () ())) 
;                                       ())))
;                         (cons 'G (cons 'H ())))))))))