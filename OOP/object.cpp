#include <iostream>
using namespace std;
class Test {
private:
	char* data;
	int size;
public:
	// 1. 기본 생성자
	Test() : data(nullptr), size(0) {
		cout << "Default Constructor called. Resource initialized with size " << size << "." << endl;
	}
	// 2. 매개변수가 있는 생성자
	Test(int size) : size(size) {
		data = new char[size];
		memset(data, 0, size); // data 배열을 0으로 초기화
		cout << "Parameterized Constructor called. Test initialized with size " << size << "." << endl;
	}
	// 3. 복사 생성자
	Test(const Test& other) : size(other.size) {
		data = new char[size];
		memcpy(data, other.data, size); // data 배열을 other.data 배열로 복사
		cout << "Copy Constructor called. Test copied with size " << size << "." << endl;
	}
	// 4. 이동 생성자
	Test(Test&& other) noexcept : data(other.data), size(other.size) {
		other.data = nullptr;
		other.size = 0;
		cout << "Move Constructor called. Test moved with size " << size << "." << endl;
	}
	// 5. 소멸자
	~Test() {
		if (data != nullptr) {
			delete[] data;
			cout << "Destructor called. Resource deleted." << endl;
		}
	}
	// 데이터 설정 함수
	void setData(char data) {
		if (data) {
			memset(this->data, data, size);
			cout << "Data set with " << data << "." << endl;
		}
	}
	// 데이터 표시 함수
	void showData() {
		if (data) {
			cout << "Data: ";
			for (int i = 0; i < size; i++) {
				cout << data[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "No data." << endl;
		}
	}
};

void objectExample() {
	cout << "-- 객체 생성 및 소멸 --" << endl;
	// 객체 생성
	Test t1; // 기본 생성자 호출]
	t1.showData();
	Test t2(5); // 매개변수가 있는 생성자 호출
	t2.setData('B');
	t2.showData();

	Test t3 = t2; // 복사 생성자 호출
	t3.showData();

	Test t4 = move(t2); // 이동 생성자 호출
	t4.showData();
	t2.showData(); // 이동된 객체는 빈 객체가 됨

	// 2. 객체 소멸
	// 객체가 소멸될 때 자동으로 소멸자가 호출되어 동적 메모리를 해제
}