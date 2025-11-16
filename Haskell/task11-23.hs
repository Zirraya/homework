
f11 x eps n = take (n + 1) ys
  where
    y0 = 1.0
    y1 = x^2
    y2 = x^3 / 2

    ys = y0 : y1 : y2 : zipWith3 nextValue [3..] (drop 2 ys) (tail ys)

    nextValue i yn yn1 = (x * yn + (ys !! (i-3))^2) / (fromIntegral i * yn1)


-- Тестовые запуски
main = do -- тело функции - последовательное выполнение
  let y1 = f11 0.3 0.001 500 -- связываем вызов с именем 
  putStrLn "f11 0.3 0.001 500"
  print $ y1 !! 10 
  print $ y1 !! 35 
  print $ y1 !! 500 

  let y2 = f11 0.5 0.001 500
  putStrLn "f11 0.5 0.001 500"
  print $ y2 !! 10 
  print $ y1 !! 35 
  print $ y2 !! 500 

  let y3 = f11 1.7 0.001 500
  putStrLn "f11 1.7 0.001 500"
  print $ y3 !! 10 
  print $ y3 !! 100 
  print $ y3 !! 500 