(****************************************************************************** 
  Шаблон для выполнения заданий лабораторной работы №1

  НЕ СЛЕДУЕТ УДАЛЯТЬ ИЛИ ПЕРЕСТАВЛЯТЬ МЕСТАМИ ЭЛЕМЕНТЫ, 
  ПРЕДСТАВЛЕННЫЕ В ШАБЛОНЕ (ВКЛЮЧАЯ КОММЕНТАРИИ). 
  ЭЛЕМЕНТЫ РЕШЕНИЯ СЛЕДУЕТ ВПИСЫВАТЬ В ПРОМЕЖУТКИ,
  ОПРЕДЕЛЕННЫЕ КОММЕНТАРИЯМИ.
 ******************************************************************************)

(****************************************************************************** 
  Загрузка определений модулей MyDate и Fixed и вспомогательных списков данных 
 ******************************************************************************)
use "lab-1-use.sml";

(****************************************************************************** 
  Задание 1 isLeapYear
 ******************************************************************************)

fun isLeapYear (year, isJulian) =
    if isJulian then
        year mod 4 = 0
    else
        year mod 4 = 0 andalso (year mod 100 <> 0 orelse year mod 400 = 0)
(******************************************************************************)

(****************************************************************************** 
  Задание 2 isLongMonth
 ******************************************************************************)

fun isLongMonth numberOfMonth  = 
  numberOfMonth = 1 orelse numberOfMonth = 3 orelse numberOfMonth = 5 orelse 
    numberOfMonth = 7 orelse numberOfMonth = 8 orelse numberOfMonth = 10 orelse 
    numberOfMonth = 12

(******************************************************************************)

(****************************************************************************** 
  Задание 3 daysInMonth
 ******************************************************************************)

fun daysInMonth (date, isJulian) =
    let
        val (year, month, _) = date
        val isLeap = isLeapYear(year, isJulian)
    in
        if isLongMonth(month) then 31
        else if month = 2 then
            if isLeap then 29 else 28
        else 30
    end

(******************************************************************************)

(****************************************************************************** 
  Задание 4 isDayOK
 ******************************************************************************)

fun isDayOK ((year, month, day), isJulian) =
    let val numDays = daysInMonth((year, month, day), isJulian)
    in
        day >= 1 andalso day <= numDays
    end

(******************************************************************************)

(****************************************************************************** 
  Задание 5 isMonthOK
 ******************************************************************************)

fun isMonthOK (year, month, day) =
    month >= 1 andalso month <= 12
(******************************************************************************)

(****************************************************************************** 
  Задание 6 isCorrectDate
 ******************************************************************************)

fun isCorrectDate (date, isJulian) =
    isMonthOK date andalso isDayOK (date, isJulian)

(******************************************************************************)

(****************************************************************************** 
  Задание 7 incDateByNum
 ******************************************************************************)

fun incDateByNum (date, days, isJulian) =
    let
        fun addDays ((y, m, d), n) =
            if n = 0 then (y, m, d)
            else
                let
                    val maxDays = daysInMonth((y, m, d), isJulian)
                in
                    if d + n <= maxDays
                    then (y, m, d + n)
                    else 
                        let
                            val remaining = n - (maxDays - d + 1)
                        in
                            if m = 12
                            then addDays((y + 1, 1, 1), remaining)
                            else addDays((y, m + 1, 1), remaining)
                        end
                end
    in
        addDays(date, days)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 8 decDateByNum
 ******************************************************************************)


 fun decDateByNum (date, days, isJulian) =
    let
        fun subtractDays ((y, m, d), n) =
            if n = 0 then (y, m, d)
            else if d > n
            then (y, m, d - n)
            else
                let
                    val prevMonth = if m = 1 then 12 else m - 1
                    val prevYear = if m = 1 then y - 1 else y
                    val daysInPrev = daysInMonth((prevYear, prevMonth, 1), isJulian)
                    val remaining = n - d
                in
                    subtractDays((prevYear, prevMonth, daysInPrev), remaining)
                end
    in
        subtractDays(date, days)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 9 newStyleCorrection
 ******************************************************************************)


 fun newStyleCorrection (y, m, d) =
    let
        val effectiveYear = if m < 3 then y - 1 else y
        val centuries = effectiveYear div 100
        val fourHundreds = effectiveYear div 400
    in
        centuries - fourHundreds - 2
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 10 toJulianDay
 ******************************************************************************)

fun toJulianDay date =
    let
        val correction = newStyleCorrection date
    in
        decDateByNum(date, correction, false)
    end

(******************************************************************************)

(****************************************************************************** 
  Задание 11 toGrigorianDay
 ******************************************************************************)

 fun toGrigorianDay date =
    let
        val correction = newStyleCorrection date
    in
        incDateByNum(date, correction, true)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 12 younger
 ******************************************************************************)

 fun younger (date1, date2) =
    let
        val (y1, m1, d1) = date1
        val (y2, m2, d2) = date2
    in
        if y1 > y2 then true
        else if y1 < y2 then false
        else if m1 > m2 then true
        else if m1 < m2 then false
        else d1 > d2
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 13 youngest
 ******************************************************************************)

 fun youngest [] = NONE
  | youngest ((name, date)::rest) =
    let
        fun findYoungest (currentName, currentDate) [] = (currentName, currentDate)
          | findYoungest (currentName, currentDate) ((name, date)::rest) =
            if younger(date, currentDate) 
            then findYoungest (name, date) rest
            else findYoungest (currentName, currentDate) rest
    in
        SOME (findYoungest (name, date) rest)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 14 getNthFixed
 ******************************************************************************)

 fun getNthFixed (0, x::xs) = x
  | getNthFixed (n, x::xs) = getNthFixed (n - 1, xs)


(******************************************************************************)

(****************************************************************************** 
  Задание 15 numToDigits
 ******************************************************************************)

 fun numToDigits (num, numDigits) =
    let
        fun digits n 0 = []
          | digits n count = (n mod 10) :: digits (n div 10) (count - 1)
    in
        digits num numDigits
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 16 listElements
 ******************************************************************************)
 fun listElements (indices, lists) =
    let
        fun getElement (i, lst) = getNthFixed (i, lst)
    in
        ListPair.map getElement (indices, lists)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 17 listSum
 ******************************************************************************)

fun listSum lst =
    let
        fun helper [] acc = acc
          | helper (x::xs) acc = helper xs (Fixed.fromInt (Fixed.toInt x + Fixed.toInt acc))
    in
        helper lst (Fixed.fromInt 0)
    end

(******************************************************************************)

(****************************************************************************** 
  Задание 18 maxSmaller
 ******************************************************************************)

 fun maxSmaller (lst, amount) =
    let
        fun findMax ([] : fixed list, currentMax) = currentMax
          | findMax (x::xs, currentMax) =
            if Fixed.toInt x < Fixed.toInt amount then
                if Fixed.toInt currentMax = 0 orelse Fixed.toInt x > Fixed.toInt currentMax then
                    findMax (xs, x)
                else
                    findMax (xs, currentMax)
            else
                findMax (xs, currentMax)
    in
        findMax (lst, Fixed.fromInt 0)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 19 dateToCorrectionNums
 ******************************************************************************)

 fun dateToCorrectionNums (year, month, day) =
    let
        val monthIndex = month - 1
        val yearDigits = numToDigits(year, 4)
        val yearMod4 = year mod 4
    in
        monthIndex :: yearDigits @ [yearMod4]
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 20 firstNewMoon
 ******************************************************************************)

 fun firstNewMoon (year, month, day) =
    let
       
        val effectiveYear = if month < 3 then year - 1 else year
        val currentDate = (year, month, day)
        
        
        val styleCorrection = Fixed.fromInt (newStyleCorrection currentDate)
        
        
        val correctionPositions = dateToCorrectionNums (effectiveYear, month, day)
        
        
        val correctionValues = listElements (correctionPositions, corrections)
        
       
        val correctionsSum = listSum correctionValues
        
       
        val total = Fixed.fromInt (Fixed.toInt styleCorrection + Fixed.toInt correctionsSum)
        
        
        val totalMinusOne = Fixed.fromInt (Fixed.toInt total - 1)
        val maxReduction = maxSmaller (map Fixed.fromInt reductions, totalMinusOne)
        
        
        val fnum = Fixed.fromInt (Fixed.toInt total - Fixed.toInt maxReduction)
        
       
        val dayNum = Fixed.toInt fnum
        val newMoonDate = (year, month, dayNum)
    in
        if isCorrectDate (newMoonDate, false) then
            SOME (fnum, newMoonDate)
        else
            NONE
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 21 winterSolstice
 ******************************************************************************)

fun winterSolstice year =
    let
        val yearsFromZero = year - 1
        val leapYears = yearsFromZero div 4 - yearsFromZero div 100 + yearsFromZero div 400
        val commonYears = yearsFromZero - leapYears
        val delta = Fixed.fromInt (commonYears * 2422 + leapYears * ~7578)
        val total = Fixed.fromInt (Fixed.toInt (Fixed.fromInt 225000) + Fixed.toInt delta)
        val day = Fixed.toInt total div 10000
    in
        (year, 12, day)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 22 chineseNewYearDate
 ******************************************************************************)

 fun chineseNewYearDate year =
    let
        val prevYear = year - 1
        val decNewMoonOpt = firstNewMoon (prevYear, 12, 1)
        val winterSolsticeDate = winterSolstice prevYear
    in
        case decNewMoonOpt of
            NONE => (year, 1, 1)  
          | SOME (newMoonDay, newMoonDate) =>
            if younger(newMoonDate, winterSolsticeDate) then
               
                let
                    val nextNewMoon = Fixed.fromInt (Fixed.toInt newMoonDay + 2953059)
                    val day = Fixed.toInt nextNewMoon div 100000
                in
                    (year, 1, day)
                end
            else
                
                let
                    val nextNewMoon = Fixed.fromInt (Fixed.toInt newMoonDay + 5906118)
                    val day = Fixed.toInt nextNewMoon div 100000
                in
                    (year, 1, day)
                end
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 23 getNthString
 ******************************************************************************)

 fun getNthString (0, x::xs) = x
  | getNthString (n, x::xs) = getNthString (n - 1, xs)

(******************************************************************************)

(****************************************************************************** 
  Задание 24 dateToString
 ******************************************************************************)

 fun dateToString (year, month, day) =
    let
        val monthName = getNthString (month - 1, months)
        val dayStr = Int.toString day
        val yearStr = Int.toString year
    in
        monthName ^ " " ^ dayStr ^ ", " ^ yearStr
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 25 chineseYear
 ******************************************************************************)

 fun chineseYear gregorianYear =
    let
        val cycleNumber = (gregorianYear + 2396) mod 60
        val celestialIndex = cycleNumber mod 10
        val terrestrialIndex = cycleNumber mod 12
        val colorIndex = celestialIndex div 2
        
        val celestialChiName = getNthString (celestialIndex, celestialChi)
        val terrestrialChiName = getNthString (terrestrialIndex, terrestrialChi)
        val celestialEngName = getNthString (celestialIndex, celestialEng)
        val terrestrialEngName = getNthString (terrestrialIndex, terrestrialEng)
        val colorName = getNthString (colorIndex, celestialColor)
        
        val chineseName = celestialChiName ^ "-" ^ terrestrialChiName
    in
        (chineseName, colorName, terrestrialEngName, celestialEngName)
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 26 dateToChineseYear
 ******************************************************************************)

 fun dateToChineseYear (year, month, day) =
    let
        val chineseNewYearDate = chineseNewYearDate year
    in
        if younger((year, month, day), chineseNewYearDate) then
            (* Дата до китайского нового года *)
            chineseYear (year - 1)
        else
            (* Дата после китайского нового года *)
            chineseYear year
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 27 dateToAnimal
 ******************************************************************************)

 fun dateToAnimal date =
    let
        val (_, _, animal, _) = dateToChineseYear date
    in
        animal
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 28 animal
 ******************************************************************************)

 fun animal (name, date) =
    dateToAnimal date


(******************************************************************************)

(****************************************************************************** 
  Задание 29 extractAnimal
 ******************************************************************************)

 fun extractAnimal (students, targetAnimal) =
    let
        fun filterStudents [] = []
          | filterStudents ((name, date)::rest) =
            if dateToAnimal date = targetAnimal then
                (name, date) :: filterStudents rest
            else
                filterStudents rest
    in
        filterStudents students
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 30 extractAnimals
 ******************************************************************************)

 fun extractAnimals (students, animals) =
    let
        fun hasAnimal date = List.exists (fn a => dateToAnimal date = a) animals
    in
        List.filter (fn (name, date) => hasAnimal date) students
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 31 youngestFromAnimals
 ******************************************************************************)

 fun youngestFromAnimals (students, animals) =
    let
        val filteredStudents = extractAnimals (students, animals)
    in
        youngest filteredStudents
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 32 oldStyleStudents
 ******************************************************************************)

 fun oldStyleStudents students =
    let
        fun convertStudent (name, date) = (name, toGrigorianDay date)
    in
        map convertStudent students
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 33 youngestFromOldStyleAnimals
 ******************************************************************************)

 fun youngestFromOldStyleAnimals (students, animals) =
    let
        (* Преобразавание даты в григорианский календарь для определения животного *)
        val gregorianStudents = oldStyleStudents students
        
        (* Функция для получения животного по григорианской дате *)
        fun getAnimal (name, date) = (name, date, dateToAnimal (toGrigorianDay date))
        
        (* Добавление животное к каждому студенту *)
        val studentsWithAnimals = map getAnimal students
        
        (* Фильтрация студентов по животным *)
        fun filterByAnimals [] = []
          | filterByAnimals ((name, date, animal)::rest) =
            if List.exists (fn a => animal = a) animals then
                (name, date) :: filterByAnimals rest
            else
                filterByAnimals rest
        
        val filteredStudents = filterByAnimals studentsWithAnimals
    in
        youngest filteredStudents
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 34 listOfStringDates
 ******************************************************************************)

 fun listOfStringDates students =
    let
        fun convertStudent (name, date) = (name, dateToString date)
    in
        map convertStudent students
    end


(******************************************************************************)

(****************************************************************************** 
  Задание 35 oldStyleStudentStringDates
 ******************************************************************************)

 fun oldStyleStudentStringDates students =
    listOfStringDates (oldStyleStudents students)

(******************************************************************************)

