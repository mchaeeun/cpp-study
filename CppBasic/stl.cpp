#include "main.h"
#include <iostream>
#include <cstddef>
using namespace std;

void cstddefExample() {
	// size_t: 부호 없는 정수 타입
	size_t s = -1; // overflow, 최대값 할당

	// ptrdiff_t: 포인터 간의 차이를 계산
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

	// nullptr_t: nullptr의 타입을 나타내는 자료형

	// byte: 바이트 타입

	// NULL, sizeof
	return;
}