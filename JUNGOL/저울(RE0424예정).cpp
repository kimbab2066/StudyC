#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
/*
IN
7
3 1 6 2 7 30 1
OUT
21
-----
*/
int main() {
	//in
	int n;
	scanf("%d", &n);
	int i, j, k, sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &k);
		v.push_back(k);
	}
	//pro
	sort(v.begin(), v.end());
	
	//out
	
	return 0;
}//main