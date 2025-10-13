
(*ВАРИАНТ №2*)
(*Сделать с шаблонами без опинсания типов*)

fun f6 lst =
    let
        fun helper [] min max = (min, max)
          | helper (x::xs) min max = 
                helper xs (Real.min(x, min)) (Real.max(x, max))
    in
        case lst of
            [] => NONE
          | x::xs => SOME (helper xs x x)
    end

(* ТЕСТЫ  для f6*)
val test02 = f6 []                                 
val test12 = f6 [12.0]                            
val test22 = f6 [1.0, 2.0, 2.0, 2.0, 3.0, 3.0, 4.0, 5.0, 7.9]  
val test32 = f6 [115.5, 111.7, 111.0, 0.5, 2.0, 2.0, 3.0, 3.0, 3.0, 2.0, 2.0, 1.0, 2.0, 3.0, 3.0, 43.0, 4.0, 5.0, 6.0, 6.0, 4.0, 7.0] 
val test42 = f6 [~100.5, 3.2, 0.0, ~2.1, 10.7]      
val test52 = f6 [~5.4, 500.0, 55.5, ~5.4]     
val test62 = f6[] 



(*ОСТАТКИ ЗАДАНИЯ 4*)

(*fun f4 (lst : real list) : (real * real) option =
    if null lst then NONE
    else
        let
            fun findMinMax [] (min, max) = (min, max)
              | findMinMax (x::xs) (min, max) = 
                    findMinMax xs (Real.min(x, min), Real.max(x, max))
        in
            SOME (findMinMax (tl lst) (hd lst, hd lst))
        end*)

(* ТЕСТЫ  для f4*)
(*val test0 = f4 []                                 (* Результат NONE *)
val test1 = f4 [12.0]                            (* Результат SOME (12.0, 12.0) *)
val test2 = f4 [1.0, 2.0, 2.0, 2.0, 3.0, 3.0, 4.0, 5.0, 7.9]  (* Результат SOME (1.0, 7.9) *)
val test3 = f4 [115.5, 111.7, 111.0, 0.5, 2.0, 2.0, 3.0, 3.0, 3.0, 2.0, 2.0, 1.0, 2.0, 3.0, 3.0, 43.0, 4.0, 5.0, 6.0, 6.0, 4.0, 7.0] (* Результат SOME (0.5, 115.5) *)
val test4 = f4 [~100.5, 3.2, 0.0, ~2.1, 10.7]      (* Результат SOME (~100.5, 10.7) *)
val test5 = f4 [~5.4, 500.0, 55.5, ~5.4]      (* Результат SOME (~5.4, 500.0) *)
val test6 = f4[] (* Результат NONE *)*)