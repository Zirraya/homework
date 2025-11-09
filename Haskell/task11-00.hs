f11 :: (Ord a, Fractional a) => a -> a -> Int -> [a]
f11 x eps n
    | n == 0    = [y0]
    | otherwise = take n' ys
  where
    y0 = 1.0
    y1 = x^2
    y2 = x^3 / 2
    n' = min n 1000  -- Ограничиваем максимальную длину
    
    -- Более безопасная реализация без циклических ссылок
    ys = y0 : y1 : y2 : [ nextValue i (ys !! (i-1)) (ys !! (i-2)) (ys !! (i-3)) | i <- [3..n'] ]
    
    nextValue i yn yn1 yn2 = (x * yn + yn2^2) / (fromIntegral i * yn1)

-- Упрощенная реализация zipWith4 (на всякий случай оставляем)
zipWith4 :: (a -> b -> c -> d -> e) -> [a] -> [b] -> [c] -> [d] -> [e]
zipWith4 f (a:as) (b:bs) (c:cs) (d:ds) = f a b c d : zipWith4 f as bs cs ds
zipWith4 _ _ _ _ _ = []

-- Упрощенные тестовые запуски
main = do
  putStrLn "Тестирование функции f11"
  putStrLn $ "=" ++ replicate 40 '='
  
  -- Тест с меньшими значениями
  let result1 = f11 0.3 0.001 50
  putStrLn "Тест 1: f11 0.3 0.001 50"
  putStrLn $ "Длина результата: " ++ show (length result1)
  putStrLn $ "10-й элемент: " ++ (if length result1 > 9 then show (result1 !! 9) else "не существует")
  putStrLn $ "50-й элемент: " ++ (if length result1 > 49 then show (result1 !! 49) else "не существует")
  putStrLn ""
  
  let result2 = f11 0.5 0.001 50
  putStrLn "Тест 2: f11 0.5 0.001 50"
  putStrLn $ "Длина результата: " ++ show (length result2)
  putStrLn $ "10-й элемент: " ++ (if length result2 > 9 then show (result2 !! 9) else "не существует")
  putStrLn $ "50-й элемент: " ++ (if length result2 > 49 then show (result2 !! 49) else "не существует")
  putStrLn ""
  
  let result3 = f11 1.7 0.001 50
  putStrLn "Тест 3: f11 1.7 0.001 50"
  putStrLn $ "Длина результата: " ++ show (length result3)
  putStrLn $ "10-й элемент: " ++ (if length result3 > 9 then show (result3 !! 9) else "не существует")
  putStrLn $ "50-й элемент: " ++ (if length result3 > 49 then show (result3 !! 49) else "не существует")