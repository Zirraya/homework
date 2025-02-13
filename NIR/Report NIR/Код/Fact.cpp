#pragma once
long long fact(long long N) {
	 if (N < 0) //отрицательное число
		 return -1;
	 else if (N == 0 || N == 1) // 0! = 1
		 return 1;
	 else
		 return N * fact(N - 1); //n! = n * (n - 1)!	
}
