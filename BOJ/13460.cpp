#include <algorithm>
#include <iostream>

using namespace std;

char map[11][11];
int q[101][2];
int n, m;
int st, ed, res, sw;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}


int main(void) {
	//input
	cin >> n >> m;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	//logic
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			
		}
	}
	//output


	return 0;
}//main