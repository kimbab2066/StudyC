#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int s[201], e[201], room[201];

int main() {
	//input
	int n;
	scanf_s("%d", &n);
	int i, j, dab = 0;
	//logic
	for (i = 0; i < n; i++) {
		scanf_s("%d%d", &s[i], &e[i]);
		if (s[i] > e[i]) { int t = s[i]; s[i] = e[i]; e[i] = t; }
		if (s[i] % 2 == 1)s[i]++;
		if (e[i] % 2 == 1)e[i]++;
		for (j = s[i] / 2; j <= e[i] / 2; j++) {
			room[j] += 10;
			if (dab < room[j])dab = room[j];
		}
	}
	//output
	printf("%d", dab);

	return 0;
}//main