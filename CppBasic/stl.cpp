#include "main.h"
#include <iostream>
#include <cstddef>
using namespace std;

void cstddefExample() {
	// size_t: ��ȣ ���� ���� Ÿ��
	size_t s = -1; // overflow, �ִ밪 �Ҵ�

	// ptrdiff_t: ������ ���� ���̸� ���
	int arr[5] = {1, 2, 3, 4, 5};
	int* p1 = &arr[0];
	int* p2 = &arr[4];
	ptrdiff_t ptrd = p2 - p1;
	ptrdiff_t ptrd2 = p1 - p2;
	cout << "p2 - p1: " << ptrd << ", p1 - p2: " << ptrd2 << endl;
	int a = 1; int b = 2;
	p1 = &a; p2 = &b;
	ptrd = p2 - p1;
	ptrd2 = p1 - p2;
	cout << "p2 - p1: " << ptrd << ", p1 - p2: " << ptrd2 << endl;

	// nullptr_t: nullptr�� Ÿ���� ��Ÿ���� �ڷ���

	// byte: ����Ʈ Ÿ��

	// NULL, sizeof
	return;
}