#pragma once

long long Recur (long long N) {

    if (N == 0) {
        return 0;
    }
    else {
        return (1LL << N) + Recur(N - 1); 
    }
}

// ����������: ��� ������ �������� LL, ��������� �� ��������, ����� ����� ��� ���� ������������ �����, ��� ������� �������� ������� long long...