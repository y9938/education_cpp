#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");

	int x, y, r1, r2;
	cout << "������� ���������� ����� � r1, r2: ";
	cin >> x >> y >> r1 >> r2;

	if (x < 0 || y < 0 || r1 <= 0 || r2 <= 0) {
		cout << "�������� ������ ���� ��������������.\n";
		return 1;
	}

	// r1 ������ ������ r2
	if (r2 < r1) {
		int temp = r1;
		r1 = r2;
		r2 = temp;
	}

	// ������� ��������
	int R = sqrt(pow(x, 2) + pow(y, 2));

	if (R > r1 && R < r2) cout << "����� ����� � ������.\n";
	else cout << "����� �� ����� � ������.\n";

	return 0;
}
