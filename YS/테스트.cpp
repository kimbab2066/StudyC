#include <stdio.h>

int main() {
	//input
	double s, w, p;
	int cnt = 0;
	scanf_s("%lf%lf%lf", &s, &w, &p);
	if (s <= 4.5 && w >= 150 && p >= 200) printf("Wide Receiver "), cnt = 1;
	if (s <= 6.0 && w >= 300 && p >= 500) printf("Lineman "), cnt = 1;
	if (s <= 5.0 && w >= 200 && p >= 300) printf("Quarterback "), cnt = 1;
	if (cnt == 0) printf("No positions");

	//logic

	//output

	return 0;
}//main