#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

#define MX 1'000'000
int arr[MX + 1], arr2[MX + 1], result[MX + MX + 2];
int n, m;

void merge(int* arr, int* arr2) {
	// 해결 방안 : 2개의 배열에서 각각의 시작 주소를 이용해 작은 값부터 채워나간다
	int idx1 = 0, idx2 = 0;
	int len = n + m;
	// 총 수행 시간 : N+M
	for (int i = 0; i < len; i++) {
		if (arr[idx1] < arr2[idx2]) result[i] = arr[idx1++];
		else result[i] = arr2[idx2++];
	}
}//merge

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	//logic
	merge(arr, arr2);
	//output
	for (int i = 0; i < n + m; i++) {
		cout << result[i] << " ";
	}

	return 0;
}//main

// 에러1. 마지막 1개가 안들어감.