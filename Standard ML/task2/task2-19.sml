fun f2 (a : int, b : int, c : int) : int =
  let

    val min_val = Int.min(a, Int.min(b, c))
    val last_a = a mod 10
    val last_b = b mod 10
    val last_c = c mod 10
    val max_last = Int.max(last_a, Int.max(last_b, last_c))

  in

    min_val * max_last
  end

(* ТЕСТОВЫЕ ЗАПУСКИ *)
val test1 = f2 (70, 35, 78) (* Ожидаемое значение 280*)
val test2 = f2 (500, ~40, 50) (* Ожидаемое значение 0*)
val test3 = f2 (12, 43, 100)  (* Ожидаемое значение 36*)
val test4 = f2 (20, 30, 300)  (* Ожидаемое значение 0*)
val test5 = f2 (17, 5, ~150)  (* Ожидаемое значение -1050*)
