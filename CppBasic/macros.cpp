#include <iostream>
#include "macros.h"
// 릴리즈 빌드에서 assert 자동 제거
#define NDEBUG
#include <cassert>

using namespace std;

// 매크로(macro): 전처리기 지시문을 사용하여 코드에서 텍스트 치환을 수행하는 기능
// 1. 상수 매크로: 단순한 값을 이름으로 정의하는 매크로
#define PI 3.141592

// 2. 함수형 매크로: 인자를 받는 함수처럼 동작하는 매크로
#define SQUARE(x) ((x) * (x))

// inline 함수: 컴파일러가 함수 호출을 생략하고 해당 함수의 코드를 호출하는 위치에 직접 삽입하는 방식으로 동작
// inline 함수는 매크로와 달리 타입 안전성을 보장하고 디버깅이 가능하다는 장점
inline float circleArea(int x) {
	return x * x * PI;
}

// 매크로 해제
#undef PI

void macroBasic() {
	int a;
	cout << "양수를 입력하시오:";
	cin >> a;
	// 입력값이 양수가 아니면 프로그램 종료
	assert(a > 0);
	cout << "SQUARE VALUE: " << SQUARE(a) << endl;
	cout << "원의 넓이: " << circleArea(a) << endl;
	// PI 매크로 해제
	// cout << PI << endl; // 오류
	return;
}