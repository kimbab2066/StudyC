#include <iostream>
using namespace std;

#define MX 1000
int n, arr[MX * 2 + 1];

int main() {
    cin >> n;
    int x, j = 0;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> x >> ch;
        if (ch == 'R') for (int k = j; k < x; k++) arr[k + MX]++;
        else for (int k = j; k > j - x; k--) arr[k + MX]++;
    }
    //output
    int cnt = 0;
    for (int i = 0; i < 2000; i++) {
        if (arr[i] >= 2) cnt++;
    }

    cout << cnt;

    return 0;
}