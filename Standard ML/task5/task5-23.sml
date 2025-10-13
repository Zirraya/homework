fun f5 (x : real, n : int) : real =
    let
        (* Вспомогательная функция, реализующая цикл *)
        fun f5Iter (i : int,          (* счетчик слагаемых *)
                    accum : real,      (* аккумулятор суммы *)
                    term : real)       (* текущее слагаемое *)
                    : real =
            if i > n then accum
            else f5Iter (i + 1, accum + term, term * (~x) * real(i + 1) / real(i + 2))
    in
        f5Iter (0, 0.0, 1.0)
    end

(* Функция с задания 23 *)
fun f5_alt (x : real, n : int) : real =
    let
        fun f5Iter (k : int, accum : real, term : real) : real =
            if k > n then accum
            else
                let
                    val new_term = term * (~x) * real(k) / real(k + 1)
                in
                    f5Iter (k + 1, accum + new_term, new_term)
                end
    in
        f5Iter (1, 0.0, 1.0)
    end

(* Функция для проверки - предел ряда *)
fun f5Test (x : real) : real = 
    if Real.abs(x) < 1.0 then 1.0 / Math.pow(1.0 + x, 2.0)
    else 0.0  

(* Тесты *)
val test11 = f5 (0.3, 100)  
val test12 = f5Test 0.3 
val test21 = f5 (0.9, 100) 
val test22 = f5Test 0.9 
val test31 = f5 (0.5, 100) 
val test32 = f5Test 0.5 




