#include <iostream>
#include "main.h"
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

// 람다 표현식: 코드 내에서 함수 객체를 즉석에서 만들고 전달할 수 있는 기능
void lambdaExample() {
	// 람다 함수는 자체적인 타입(익명 타입: 컴파일 전 알 수 없음)을 갖고 있으므로
	// auto 또는 함수 포인터로 정의하는 것이 일반적
	// auto 또한 컴파일 타임에서 자동으로 타입이 할당됨
	auto add = [](int a, int b) -> int {
		return a + b;
		};
	cout << "3 + 4 = " << add(3, 4) << endl;

	// 반환형이 return 타입과 달라도 오류 안 뜸. 
	// return 타입을 명시적 반환형으로 변환
	auto add2 = [](int a, int b) -> bool {
		return a + b;
		};

	// 캡처: 외부 변수 사용 가능
	int x = 1; int y = 2;
	// [x, y] 값 캡처
	// -> [반환형] 생략 가능
	auto mul = [x, y]() {
		// x += 1; // 오류: 캡처한 변수 수정 불가능
		return x * y;
		};
	cout << "1 * 2 = " << mul() << endl;

	// mutable 람다: 캡처한 변수 수정 가능
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