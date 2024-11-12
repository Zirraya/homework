#pragma once

long long Recur (long long N) {

    if (N == 0) {
        return 0;
    }
    else {
        return (1LL << N) + Recur(N - 1); 
    }
}

// Примичание: Без явного указания LL, нормально не работает, пишут везде что идет переполнение стека, что странно учитывая размеры long long...