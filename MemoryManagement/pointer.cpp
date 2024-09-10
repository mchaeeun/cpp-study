#include <string>
#include "pointer.h"

void basicPointer() {
	cout << "-- 포인터 기본 개념 --" << endl;
	// 포인터: 메모리 주소를 저장하는 변수
	int* ptr; // int형 변수를 가르키는 포인터 ptr 선언

	float y = 3.14;
	// ptr = &y; // 오류: int형 포인터에 float형 변수 주소 저장 불가

	// 주소 연산자(&): 변수의 메모리 주소를 반환
	int x = 5;
	ptr = &x; // ptr에 x의 주소를 저장
	cout << "x: " << x << endl;
	cout << "ptr: " << ptr << endl;
	cout << "&x: " << &x << endl;
	cout << "&ptr: " << &ptr << endl;

	// 역참조 연산자(*): 포인터가 가르키는 주소에 저장된 값을 반환
	cout << "*ptr: " << *ptr << endl;
	cout << endl;
}

void pointerWarnings() {
	cout << "-- 포인터 사용 시 주의사항 --" << endl;
	// 1. 초기화하지 않은 포인터 사용
	// -- int* uninitializedPtr; vs. int* initializedPtr = nullptr; --
	// 초기화하지 않은 포인터
	int* uninitializedPtr; // 쓰레기 값이 들어갈 수 있음
	// cout << "*uninitializedPtr: " << *uninitializedPtr << endl; // 오류: 초기화하지 않은 포인터 사용

	// 초기화한 포인터
	int* initializedPtr = nullptr; // 초기화되어 쓰레기 값이 들어가지 않음
	cout << initializedPtr << endl; // 0

	// 2. Dangling Pointer: 해제된 메모리 접근
	int* deletedPtr = new int;
	delete deletedPtr;
	cout << "*deletedPtr: " << *deletedPtr << endl; // 강제종료: 해제된 메모리 접근

	// 3. 메모리 누수(Memory Leak): 동적 메모리 해제하지 않음
	int* memoryLeakPtr = new int; // 쓰레기 값이 들어갈 수 있음
	cout << "*memoryLeakPtr: " << *memoryLeakPtr << endl;
	// delete memoryLeakPtr; // 동적 메모리 해제하지 않음
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}
*/

int* returnPointer() {
	int* retPtr = new int;
	*retPtr = 10;
	return retPtr;
}

class PointerClass {
private:
	int x;
public:
	PointerClass() {
		x = 0;
	}
	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}
};

void typeofPointer() {
	cout << " --포인터 유형-- " << endl;
	// 1. void 포인터: 모든 데이터 유형을 가르킬 수 있는 포인터
	void* voidPtr;
	string s = "Hello";
	voidPtr = &s;
	cout << "s: " << s << endl;
	cout << "voidPtr: " << voidPtr << endl;

	// 2. nullptr: 포인터가 가르키는 주소가 없음을 나타내는 값
	int* nullPtr = nullptr;
	cout << "nullPtr: " << nullPtr << endl;

	// 3. 동적 메모리 할당: 프로그램 실행 중에 메모리를 할당
	int* dynamicPtr = new int; // int형 변수를 가르키는 포인터 dynamicPtr 선언
	*dynamicPtr = 15; // dynamicPtr이 가르키는 주소에 15 저장
	cout << "dynamicPtr: " << dynamicPtr << endl;
	cout << "*dynamicPtr: " << *dynamicPtr << endl;
	delete dynamicPtr; // 동적 메모리 해제

	// 4. 배열 동적 메모리 할당
	int* dynamicArr = new int[5]; // int형 배열을 가르키는 포인터 dynamicArr 선언
	for (int i = 0; i < 5; i++) {
		dynamicArr[i] = i;
	}
	for (int i = 0; i < 5; i++) {
		cout << "dynamicArr[" << i << "]: " << dynamicArr[i] << endl;
	}
	delete[] dynamicArr; // 배열 동적 메모리 해제

	// 5. 포인터 배열
	int a = 1, b = 2, c = 3;
	int* ptrArr[3] = { &a, &b, &c }; // int형 변수를 가르키는 포인터 배열 ptrArr 선언
	for (int i = 0; i < 3; i++) {
		cout << "*ptrArr[" << i << "]: " << *ptrArr[i] << endl;
		cout << "ptrArr[" << i << "]: " << ptrArr[i] << endl;
	}

	// 6. 이중 포인터
	int x = 10;
	int* singlePtr = &x; // int형 변수를 가르키는 포인터 singlePtr 선언
	int** doublePtr = &singlePtr; // int형 포인터를 가르키는 포인터 doublePtr 선언
	cout << "doublePtr: " << doublePtr << endl;
	cout << "*doublePtr: " << *doublePtr << endl;
	cout << "**doublePtr: " << **doublePtr << endl;

	// 7. 상수 포인터: 포인터가 가르키는 주소의 값을 변경할 수 없음
	const int* constPtr = &x; // x의 주소를 가르키는 상수 포인터 constPtr 선언
	// *constPtr = 20; // 오류: constPtr이 가르키는 주소의 값을 변경할 수 없음
	cout << "*constPtr: " << *constPtr << endl;
	const int z = 30;
	constPtr = &z; // constPtr이 z의 주소를 가르킴
	cout << "*constPtr: " << *constPtr << endl;

	// 8. 포인터 매개변수
	int d = 4, e = 5;
	swap(&d, &e); // d와 e의 주소를 전달
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;

	// 9. 포인터 반환값
	int* retPtr = returnPointer(); // int형 포인터를 반환하는 함수 호출
	cout << "*retPtr: " << *retPtr << endl;
	delete retPtr; // 반환된 포인터 메모리 해제

	// 10. Class 포인터
	PointerClass* classPtr = new PointerClass; // PointerClass 객체를 가르키는 포인터 classPtr 선언
	classPtr->setX(10); // classPtr이 가르키는 객체의 x값 설정
	cout << "classPtr->getX(): " << classPtr->getX() << endl;
	cout << "(*classPtr).getX(): " << (*classPtr).getX() << endl; // 역참조 연산자 사용
	delete classPtr; // classPtr이 가르키는 객체 메모리 해제
}