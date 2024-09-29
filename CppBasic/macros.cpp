#include <iostream>
#include "macros.h"
// ������ ���忡�� assert �ڵ� ����
#define NDEBUG
#include <cassert>

using namespace std;

// ��ũ��(macro): ��ó���� ���ù��� ����Ͽ� �ڵ忡�� �ؽ�Ʈ ġȯ�� �����ϴ� ���
// 1. ��� ��ũ��: �ܼ��� ���� �̸����� �����ϴ� ��ũ��
#define PI 3.141592

// 2. �Լ��� ��ũ��: ���ڸ� �޴� �Լ�ó�� �����ϴ� ��ũ��
#define SQUARE(x) ((x) * (x))

// inline �Լ�: �����Ϸ��� �Լ� ȣ���� �����ϰ� �ش� �Լ��� �ڵ带 ȣ���ϴ� ��ġ�� ���� �����ϴ� ������� ����
// inline �Լ��� ��ũ�ο� �޸� Ÿ�� �������� �����ϰ� ������� �����ϴٴ� ����
inline float circleArea(int x) {
	return x * x * PI;
}

// ��ũ�� ����
#undef PI

void macroBasic() {
	int a;
	cout << "����� �Է��Ͻÿ�:";
	cin >> a;
	// �Է°��� ����� �ƴϸ� ���α׷� ����
	assert(a > 0);
	cout << "SQUARE VALUE: " << SQUARE(a) << endl;
	cout << "���� ����: " << circleArea(a) << endl;
	// PI ��ũ�� ����
	// cout << PI << endl; // ����
	return;
}