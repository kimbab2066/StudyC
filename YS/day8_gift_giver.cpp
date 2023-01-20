#include <stdio.h>
#include <string.h>

int n, i, j, k, l, v, m;
char a[21][15];
//tmp
char b[25], ss[25];
int res[21];
int res2[21];

int main() {
	//input
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%s", a[i], 14);//이름 저장
	}
	for (i = 0; i < n; i++) {
		scanf_s("%s", b, 14);
		for (j = 0; j < n; j++) {
			scanf_s("%d%d", &v, &m);
			if (v == 0) continue;
			if (strcmp(b, a[j]) == 0) {//a랑 같은 이름 찾기
				res[j] += v;
				res2[j] += v % m;
				for (k = 0; k < m; k++) {//다음 m줄
					scanf_s("%s", ss, 14);
					for (l = 0; l < n; l++) {//같은 이름 찾기
						if (strcmp(ss, a[l]) == 0) {
							res2[l] += v / m;
						}//if
					}//l
				}//k
			}//if
		}//j
	}//i

	//logic

	//output
	for (i = 0; i < n; i++) {
		printf("%s %d\n", a[i], res2[i]-res[i]);
	}

	return 0;
}//main