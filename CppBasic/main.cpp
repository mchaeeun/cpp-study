#include <iostream>
#include "macros.h"
using namespace std;
// 매크로 정의
#define PI 3.14159 // 매크로: 전처리기에 의해 치환됨

// 상수 정의
const double piConst = 3.14159; // 상수: 타입이 있으며, 메모리에 저장됨

// 매크로와 상수의 장단점
/*
매크로 장점:
1. 간단한 치환으로 코드의 가독성을 높일 수 있음.
2. 컴파일 타임에 값이 정해져 있음.

매크로 단점:
1. 타입이 없으므로 타입 안전성이 없고, 디버깅 시 문제가 발생할 수 있음.
2. 사용 범위가 전역적이어서 이름 충돌의 위험이 있음.

상수 장점:
1. 타입이 있으며, 컴파일 타임에 값이 결정되어 타입 안전성이 있음.
2. 스코프가 제한되어 이름 충돌의 위험이 적음.
3. 디버깅 시 더 명확하게 오류를 파악할 수 있음.

상수 단점:
1. 매크로에 비해 메모리 사용량이 있을 수 있음.
*/

// constexpr 함수: 컴파일 타임에 실행되는 함수
constexpr int sumTwoIntegers(int a, int b) {
	return a + b;
}

// 컴파일 상수와 런타임 상수
void constantExample() {
	// 컴파일 상수
	// const: 런타임에 값이 결정될 수도 있는 상수
	const int a = 10; // 컴파일 타임에 결정
	int num1, num2;
	cout << "두 개의 정수를 입력하세요: ";
	cin >> num1 >> num2;
	// 런타임 상수
	const int sum = num1 + num2; // 런타임에 결정
	cout << num1 << " + " << num2 << " = " << sum << endl;
	// 컴파일 타임에만 값이 결정되는 상수
	constexpr int b = 20;
	int num3 = 1;
	int num4 = 2;
	constexpr int c = sumTwoIntegers(1, 2);
	// constexpr int d = sumTwoIntegers(num3, num4); // 컴파일 에러
}

int main() {
	// constantExample();
	macroBasic();
	return 0;
}