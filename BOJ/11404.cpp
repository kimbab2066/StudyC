#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MX 101
#define INF 987654321
int n, m, dist[MX][MX];

int main(void) {
	//input
	scanf("%d%d", &n, &m);
	int a, b, c;
	int i, j, k;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for (i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = min(dist[a][b], c);
	}
	//logic
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	//output
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (dist[i][j] == INF) printf("0 ");
			else printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

	return 0;
}//main