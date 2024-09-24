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
	// cout << *initializedPtr << endl; // nullptr 역참조 - ! 강제 종료

	// 2. Dangling Pointer: 해제된 메모리 접근
	int* deletedPtr = new int;
	delete deletedPtr;
	// cout << "*deletedPtr: " << *deletedPtr << endl; // 강제종료: 해제된 메모리 접근

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

// 두 숫자를 더하는 함수
int add(int a, int b) {
	return a + b;
}

// 콜백 함수 선언
void callBack(int x, int y, int (*callback)(int, int)) {
	cout << "process: " << callback(x, y) << endl;
}

void typeofPointer() {
	cout << " --포인터 유형-- " << endl;
	// 1. void 포인터: 모든 데이터 유형을 가르킬 수 있는 포인터
	void* voidPtr;
	string s = "Hello";
	voidPtr = &s;
	cout << "s: " << s << endl;
	// cout << "voidPtr: " << *voidPtr << endl; // 오류: void 포인터는 역참조 불가
	// voidPtr를 string*로 캐스팅 후 역참조
	cout << "*voidPtr: " << *(static_cast<string*>(voidPtr)) << endl;
	int ten = 10;
	voidPtr = &ten;
	cout << "ten: " << ten << endl;
	cout << "*voidPtr: " << *(static_cast<int*>(voidPtr)) << endl;

	// 2. nullptr: 포인터가 가르키는 주소가 없음을 나타내는 값
	int* nullPtr = nullptr;
	cout << "nullPtr: " << nullPtr << endl;

	// 3. 동적 메모리 할당: 프로그램 실행 중에 메모리를 할당
	int* dynamicPtr = new int; // int형 변수를 가르키는 포인터 dynamicPtr 선언
	cout << "*dynamicPtr: " << *dynamicPtr << endl; // 쓰레기 값이 들어갈 수 있음
	*dynamicPtr = 15; // dynamicPtr이 가르키는 주소에 15 저장
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

	// 11. 참조자(Reference): 포인터와 유사한 개념
	int f = 6;
	int g = 7;
	int& ref = f; // int형 변수 f를 참조하는 참조자 ref 선언
	// int& ref2; // 오류: 참조자는 선언과 동시에 초기화해야 함
	cout << "f: " << f << ", ref: " << ref << endl;
	cout << "&f: " << &f << ", &ref: " << &ref << endl;
	ref = 7; // ref가 가르키는 변수 f의 값 변경
	cout << "f: " << f << ", ref: " << ref << endl;
	f = 8; // f의 값 변경
	cout << "f: " << f << ", ref: " << ref << endl;
	// 참조자는 한 번 선언되면 다른 변수를 참조할 수 없음
	ref = g; // ref이 g를 참조하도록 변경하는 게 아니라 ref가 가르키는 변수 값을 g로 변경
	g = 9; // g의 값 변경
	cout << "f: " << f << ", ref: " << ref << endl;

	// 12. 함수 포인터: 함수의 주소를 저장하는 포인터
	int (*funcPtr)(int, int); // int형 매개변수 두 개를 받아 int형 값을 반환하는 함수 포인터 선언
	funcPtr = &add; // add 함수의 주소를 funcPtr에 저장
	// 함수 이름은 해당 함수의 주소를 나타냄
	// 따라서 add와 &add는 동일한 동작
	funcPtr = add;
	cout << "add(1, 2): " << funcPtr(1, 2) << endl; // funcPtr이 가르키는 함수 호출

	// 함수	포인터 배열 선언
	int (*funcPtrArr[2])(int, int) = { add, add }; // add 함수의 주소를 가지는 함수 포인터 배열 선언
	cout << "add(3, 4): " << funcPtrArr[0](3, 4) << endl;
	cout << "add(5, 6): " << funcPtrArr[1](5, 6) << endl;

	// 콜백 함수
	callBack(7, 8, add); // add 함수의 주소를 콜백 함수에 전달
}