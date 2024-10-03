#include <iostream>
#include "main.h"
using namespace std;
// ��ũ�� ����
#define PI 3.14159 // ��ũ��: ��ó���⿡ ���� ġȯ��

// ��� ����
const double piConst = 3.14159; // ���: Ÿ���� ������, �޸𸮿� �����

// ��ũ�ο� ����� �����
/*
��ũ�� ����:
1. ������ ġȯ���� �ڵ��� �������� ���� �� ����.
2. ������ Ÿ�ӿ� ���� ������ ����.

��ũ�� ����:
1. Ÿ���� �����Ƿ� Ÿ�� �������� ����, ����� �� ������ �߻��� �� ����.
2. ��� ������ �������̾ �̸� �浹�� ������ ����.

��� ����:
1. Ÿ���� ������, ������ Ÿ�ӿ� ���� �����Ǿ� Ÿ�� �������� ����.
2. �������� ���ѵǾ� �̸� �浹�� ������ ����.
3. ����� �� �� ��Ȯ�ϰ� ������ �ľ��� �� ����.

��� ����:
1. ��ũ�ο� ���� �޸� ��뷮�� ���� �� ����.
*/

// constexpr �Լ�: ������ Ÿ�ӿ� ����Ǵ� �Լ�
constexpr int sumTwoIntegers(int a, int b) {
	return a + b;
}

// ������ ����� ��Ÿ�� ���
void constantExample() {
	// ������ ���
	// const: ��Ÿ�ӿ� ���� ������ ���� �ִ� ���
	const int a = 10; // ������ Ÿ�ӿ� ����
	int num1, num2;
	cout << "�� ���� ������ �Է��ϼ���: ";
	cin >> num1 >> num2;
	// ��Ÿ�� ���
	const int sum = num1 + num2; // ��Ÿ�ӿ� ����
	cout << num1 << " + " << num2 << " = " << sum << endl;
	// ������ Ÿ�ӿ��� ���� �����Ǵ� ���
	constexpr int b = 20;
	int num3 = 1;
	int num4 = 2;
	constexpr int c = sumTwoIntegers(1, 2);
	// constexpr int d = sumTwoIntegers(num3, num4); // ������ ����
}

// ���� ǥ����: �ڵ� ������ �Լ� ��ü�� �Ｎ���� ����� ������ �� �ִ� ���
void lambdaExample() {
	// ���� �Լ��� ��ü���� Ÿ��(�͸� Ÿ��: ������ �� �� �� ����)�� ���� �����Ƿ�
	// auto �Ǵ� �Լ� �����ͷ� �����ϴ� ���� �Ϲ���
	// auto ���� ������ Ÿ�ӿ��� �ڵ����� Ÿ���� �Ҵ��
	auto add = [](int a, int b) -> int {
		return a + b;
		};
	cout << "3 + 4 = " << add(3, 4) << endl;

	// ��ȯ���� return Ÿ�԰� �޶� ���� �� ��. 
	// return Ÿ���� ����� ��ȯ������ ��ȯ
	auto add2 = [](int a, int b) -> bool {
		return a + b;
		};

	// ĸó: �ܺ� ���� ��� ����
	int x = 1; int y = 2;
	// [x, y] �� ĸó
	// -> [��ȯ��] ���� ����
	auto mul = [x, y]() {
		// x += 1; // ����: ĸó�� ���� ���� �Ұ���
		return x * y;
		};
	cout << "1 * 2 = " << mul() << endl;

	// mutable ����: ĸó�� ���� ���� ����
	auto lambda = [x]() mutable {
		return x++;
		};

}

int main() {
	// constantExample();
	// macroBasic();
	// cstddefExample();
	lambdaExample();
	return 0;
}