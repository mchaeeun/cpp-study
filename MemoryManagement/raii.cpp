#include <iostream>
#include "raii.h"
using namespace std;

// RAII(Resource Acquisition Is Initialization)
// 자원 획득은 초기화에서 이루어진다.
// 자원 해제는 소멸자에서 이루어진다.

// RAII는 C++에서 자원 관리를 위한 디자인 패턴으로, 자원을 할당하는 코드와 자원을 해제하는 코드를 분리하지 않고
// 자원을 할당하는 코드를 생성자에서 처리하고 자원을 해제하는 코드를 소멸자에서 처리함으로써 자원 누수를 방지하는 방법

class MemoryManager {
private:
    int* data; // 동적으로 할당될 메모리
    size_t size; // 배열의 크기
public:
    // 생성자: 메모리 할당
    MemoryManager(size_t size) : size(size) {
        data = new int[size]; // 메모리 동적 할당
        cout << "Memory allocated for " << size << " integers." << endl;

        // 메모리가 제대로 할당되지 않은 경우 예외를 던질 수 있음
        if (!data) {
            throw std::runtime_error("Memory allocation failed!");
        }

        // 초기화
        for (size_t i = 0; i < size; i++) {
            data[i] = i * 10; // 임의의 값으로 초기화
        }
    }

    // 데이터를 출력하는 함수
    void printData() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // 소멸자: 메모리 해제
    ~MemoryManager() {
        delete[] data; // 동적 메모리 해제
        cout << "Memory deallocated." << endl;
    }
};

void raiiExample() {
    try {
        MemoryManager mem(5); // 5개의 정수를 위한 메모리 할당
        mem.printData(); // 할당된 메모리의 데이터 출력
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // 객체가 스코프를 벗어나면 소멸자가 호출되어 메모리가 자동으로 해제됨
    return;
}