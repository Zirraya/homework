;;;Вариант 21 Исходный список ((A) (()) (B (C D)(()) () ((((X E) F)) G)) H)
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

