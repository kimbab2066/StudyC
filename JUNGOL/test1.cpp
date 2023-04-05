#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

char a[45];
int d[45];

int main() {
	//input
	scanf("%s", a);
	d[0] = 1;
	int i;
	//logic 
	for (i = 0; a[i]; i++) {
		a[i] -= '0';
		if (a[i]) {
			d[i + 1] += d[i];
			if (a[i] * 10 + a[i + 1] - '0' <= 34) d[i + 2] += d[i];
		}
	}
	//output
	printf("%d", d[i]);
	return 0;
}//main