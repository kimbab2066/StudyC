#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int a[100000], n, idx;

void nq(int n) {
	if (n % 2 != 0 && n % 3 != 0) {
		//È¦¼ö
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2 - 1;
		//È¦¼ö°³ÀÎ °æ¿ì ¸¶Áö¸· ¼ýÀÚ Ãß°¡
		if (n % 2 == 1) a[idx++] = n;
		//Â¦¼ö
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2;
	}
	else if (n % 2 == 0) {
		//Â¦¼ö
		for (int i = 1; i <= n / 2; i++) a[idx++] = i * 2;
		a[idx++] = 3;
		a[idx++] = 1;
		//È¦¼ö
		//for (int i = 3; i <= n / 2; i++) a[idx++] = (i * 2) - 1;
		for (int i = ((n / 2) + 2); i < (n - 1); i++) a[idx++] = 1 + (2 * (i - (n / 2) + 1));
		a[idx++] = 5;
	}
	else if (n % 6 == 3) {
		//Â¦¼ö(2´Â ¸¶Áö¸·)
		for (int i = 2; i <= n / 2; i++) a[idx++] = i * 2;
		a[idx++] = 2;
		//È¦¼ö(1,3À¸·Î ³¡³ª±â)
		//for (int i = 3; i <= n / 2; i++) a[idx++] = (i * 2) - 1;
		for (int i = (n / 2); i < (n - 2); i++) a[idx++] = 1 + (((i - (n / 2)) + 2) * 2);
		a[idx++] = 1;
		a[idx++] = 3;
	}
}

int main() {
	//input
	scanf_s("%d", &n);
	//logic
	nq(n);
	//output
	for (int i = 0; i < idx; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}//main