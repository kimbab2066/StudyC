#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;
int A,B,C;
int freq[10];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B >> C;
	int result= A * B * C;
	while (result > 0) {
		freq[result % 10]++;
		result /= 10;
	}
	for (auto val : freq)
		cout << val << " ";
}