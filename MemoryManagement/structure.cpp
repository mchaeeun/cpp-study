#include "structure.h"

void heapAllocationExample(int count) {
	int* heapVar = new int[count];  // 힙에 동적 메모리 할당
	for (int i = 0; i < count; i++) {
		heapVar[i] = i;
		cout << "heapVar[" << i << "]: " << heapVar[i]
			<< " at address " << &heapVar[i] << endl;
	}

	// 동적 메모리 해제
	delete[] heapVar;
}

void recursiveFunction(int count) {
	if (count == 0) return;
	int stackVar = count;  // 스택에 할당되는 변수
	cout << "stackVar at count " << count << ": " << stackVar
		<< " at address " << &stackVar << endl;

	// 재귀 호출로 스택 메모리를 계속 사용
	recursiveFunction(count - 1);
}

void basicStructure() {
	// 메모리 구조
	cout << "-- 메모리 구조 --" << endl;
	// 1. 코드 영역: 실행할 프로그램의 코드
	// 2. 데이터 영역: 전역 변수, 정적 변수, 상수
	// 3. 힙 영역: 동적 할당된 메모리
	// 4. 스택 영역: 지역 변수, 매개변수, 리턴 주소

	// 1. 코드 영역
	// 실행할 프로그램의 코드가 저장되는 영역
	// 프로그램이 실행될 때 텍스트 영역에 저장되어 CPU가 이를 실행
	// 읽기 전용 영역으로 수정 불가능

	// 2. 데이터 영역
	// 전역 변수, 정적 변수, 상수 등이 저장되는 영역
	// 프로그램 시작 시 할당되어 프로그램 종료 시 소멸
	// 데이터 영역은 초기화된 데이터 세그먼트와 초기화되지 않은 데이터 세그먼트로 나뉨
	// 초기화된 데이터 세그먼트: 초기화된 전역 변수, 정적 변수, 상수
	// 초기화되지 않은 데이터 세그먼트: 초기화되지 않은 전역 변수, 정적 변수

	// 3. 힙 영역
	// 동적 할당된 메모리가 저장되는 영역
	// 프로그래머가 원하는 만큼 메모리를 할당하고 해제할 수 있음
	// 힙 영역은 메모리 주소가 낮은 곳에서 높은 곳으로 할당됨
	// 힙 영역은 메모리 누수(Memory Leak)와 프로그램 성능 저하의 원인이 될 수 있음
	cout << "힙 예제" << endl;
	heapAllocationExample(5);

	// 4. 스택 영역
	// 지역 변수, 매개변수, 리턴 주소 등이 저장되는 영역
	// 함수 호출 시 할당되고 함수 종료 시 소멸
	// 스택 영역은 메모리 주소가 높은 곳에서 낮은 곳으로 할당됨
	// 스택 영역은 함수 호출 시 스택 프레임(Stack Frame)이라는 공간이 할당되어 함수의 지역 변수, 매개변수, 리턴 주소 등이 저장
	// 스택 프레임은 함수 호출 시 생성되고 함수 종료 시 소멸
	// 스택 프레임은 함수 호출 시 스택에 쌓이고 함수 종료 시 스택에서 제거
	// 스택 프레임은 후입선출(LIFO, Last In First Out) 구조로 동작
	// 스택 오버플로(Stack Overflow): 스택 영역이 가득 차서 더 이상 데이터를 저장할 수 없는 상태
	// 스택 언더플로(Stack Underflow): 스택 영역에 데이터가 없는 상태에서 데이터를 꺼내려고 할 때 
	cout << "스택 예제" << endl;
	recursiveFunction(3);
	// cout << "스택 오버플로우(Overflow) 예제" << endl;
	// recursiveFunction(100000); // 스택 오버플로우(Overflow) 발생
}