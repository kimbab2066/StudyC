#include <stdio.h>
// 정수 < 실수

void star1() {
	printf("  *   \n");
	printf(" * *  \n");
	printf("*   * \n");
	printf(" * *  \n");
	printf("  *   \n");
}

void star2() {
	printf("  ** **       ** **   \n");
	printf(" *  *  *     *  *  *  \n");
	printf("*       *   *       * \n");
	printf(" *     *     *     *  \n");
	printf("  *   *       *   *   \n");
	printf("   * *         * *    \n");
	printf("    *           *     \n");
}
void tmp1() {
	//long long a;
	//a = 3000000000;
	//int b = 10;

	//printf("%d %lld", b,a);

	//char a = 'A';
	//double b = 10 / 3.0;

	//printf("%d     %c  %lf", a, a);
	//printf("%.10lf", b);

	//char a[20] = "abc";

	// char* b = "123";


	//printf("%s", a);
}
void tmp2() {
	int a, b;
	scanf_s("%d%d", &a, &b);
	printf("%.2lf ", (double)a / b);
}

void tmp3() {
	int a = 5, b = 3;

	// && || ! 조건식과 착각하면 안됨.
	printf("%d", a && b);
}

void tmp4() {
	int a = 5, b = 3;
	// & | ^
	printf("%d", 20 >> 1);
}

int main() {
	//
	return 0;
} //main