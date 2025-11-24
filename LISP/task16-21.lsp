;;;Вариант 21. Исходный список ((A) (()) (B (C D)(()) () ((((X E) F)) G)) H)
(print 
  (let ((L '((A) (()) (B (C D) (()) () ((((X E) F)) G)) H)))
    (car
      (caaaar
        (cddddr
          (caddr L))))))



