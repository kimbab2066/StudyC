#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int coin[6] = { 500,100,50,10,5,1 };
int arr[6], w;

int main() {
	//in
	scanf("%d", &w);
	int i, sum = 0;
	for (i = 0; i < 6; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i] * coin[i];
	}
	//pro
	//°Å½º¸§µ·
	w = sum - w;
	int t, cnt = 0;
	for (i = 0; i < 6; i++) {
		t = min(w / coin[i], arr[i]);
		arr[i] -= t;
		w -= t * coin[i];
		cnt += arr[i];
	}
	//out
	printf("%d\n", cnt);
	for (i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}//main