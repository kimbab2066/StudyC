#include <iostream> 
#include <algorithm>
#include <string>

using namespace std;

int n;

void sbar(const char* str, int stk) {
	for (int i = 0; i < stk; i++) cout << "____";
	cout << str;
}

void func(int cnt) {
	sbar("\"����Լ��� ������?\"\n", cnt);
	if (n == cnt) sbar("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n", cnt);
	else {
		sbar("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n", cnt);
		sbar("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n", cnt);
		sbar("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n", cnt);
		func(cnt + 1);
	}
	sbar("��� �亯�Ͽ���.\n", cnt);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//input
	cin >> n;
	//output
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(0);
}//main