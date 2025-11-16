f12 a1 = a1 : f12 (sumDigits (a1 * a1))

sumDigits n
  | n == 0    = 0
  | otherwise = (n `mod` 10) + sumDigits (n `div` 10)

main = do
  print $ take 6 $ f12 136
  print $ take 15 $ f12 5
