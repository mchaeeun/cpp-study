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

// 상속과 접근 한정자 실습
// Base class (부모 클래스)
class Base {
private:
	int privateVar; // private: Base 클래스 내부에서만 접근 가능
protected:
	int protectedVar; // protected: Base 클래스와 자식 클래스에서 접근 가능
public:
	int publicVar; // public: 어디서든 접근 가능

	// 생성자
	// 부모 클래스의 메서드에서만 privateVar 접근 가능
	Base() : privateVar(10), protectedVar(20), publicVar(30) {}
	// 부모 클래스에서 virtual 키워드를 사용하여 자식 클래스에서 오버라이딩 가능한 메서드
	virtual void showVar() {
		cout << "privateVar: " << privateVar << ", protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}

	// 오버로딩	: 같은 이름의 메서드를 여러 개 정의
	// 매개변수의 개수나 유형이 다르면 같은 이름의 메서드를 여러 개 정의할 수 있음
	void print(int x) {
		cout << "int: " << x << endl;
	}
	void print(double x) {
		cout << "double: " << x << endl;
	}
	void print(int x, double y) {
		cout << "int: " << x << ", double: " << y << endl;
	}
};

// Derived class (자식 클래스)
class Derived : public Base {
public:
	// 부모의 showVar() 메서드를 오버라이딩
	// 오버라이딩: 부모 클래스의 메서드를 자식 클래스에서 재정의
	void showVar() override {
		// privateVar은 Base 클래스의 private 변수이므로 접근 불가
		// cout << "privateVar: " << privateVar << ", "; // 오류 발생
		// protectedVar은 Base 클래스의 protected 변수이므로 접근 가능
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

// 자식 클래스 - protected 상속
class DerivedProtected : protected Base {
public:
	// protected로 상속받으면 public 멤버도 protected처럼 동작
	void showVar() {
		// privateVar은 접근 불가
		// cout << "privateVar: " << privateVar << ", "; // 오류 발생
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

// 자식 클래스 - private 상속
// class DerivedPrivate : Base {}; // 명시되지 않으면 기본적으로 private 상속
class DerivedPrivate : private Base {
public:
	// private로 상속받으면 public, protected 멤버 private처럼 동작
	void showVar() {
		// privateVar은 접근 불가
		// cout << "privateVar: " << privateVar << ", "; // 오류 발생
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

void inheritanceExample() {
	cout << "-- 상속과 접근 한정자 --" << endl;
	// 기본	클래스 객체 생성
	Base b;
	cout << "Base 클래스의 멤버 변수 출력" << endl;
	b.showVar();
	cout << b.publicVar << endl; // public 멤버는 어디서든 접근 가능
	// b.protectedVar = 20; // protected 멤버는 Base 클래스 외부에서 접근 불가
	// b.privateVar = 10; // private 멤버는 Base 클래스 외부에서 접근 불가

	// 자식 클래스 객체 생성
	Derived d;
	cout << "Derived 클래스의 멤버 변수 출력" << endl;
	d.showVar();
	cout << d.publicVar << endl; // public 멤버는 어디서든 접근 가능

	// protected 상속
	DerivedProtected dp;
	cout << "DerivedProtected 클래스의 멤버 변수 출력" << endl;
	dp.showVar();
	// dp.publicVar; // protected 상속으로 접근 불가

	// private 상속
	DerivedPrivate dpr;
	cout << "DerivedPrivate 클래스의 멤버 변수 출력" << endl;
	dpr.showVar();
	// dpr.publicVar; // private 상속으로 접근 불가
}

// 오버로딩과 오버라이딩 실습
void overloadOverrideExample() {
	cout << "-- 오버로딩과 오버라이딩 --" << endl;
	Base b;
	cout << "오버로딩" << endl;
	b.print(10); // int: 10
	b.print(3.14); // double: 3.14
	b.print(10, 3.14); // int: 10, double: 3.14

	cout << "오버라이딩" << endl;
	Derived d;
	d.showVar(); // protectedVar: 20, publicVar: 30
}

// virtual과 override 키워드 실습
class VBase {
public:
	// virtual는 런타임에 동적 바인딩을 사용하여 오버라이딩된 함수를 호출
	virtual void show() {
		cout << "VBase show()" << endl;
	}
};

class VDerived : public VBase {
public:
	void show() override {
		cout << "VDerived show()" << endl;
	}
};

class VDerived2 : public VBase {
public:
	void show() {
		cout << "VDerived2 show()" << endl;
	}
};

class NoVBase {
public:
	// virtual 키워드가 없으면 정적 바인딩을 사용하여 함수 호출
	void show() {
		cout << "NoVBase show()" << endl;
	}
};

class NoVDerived : public NoVBase {
public:
	// override 키워드는 virtual 함수에만 사용 가능
	// void show() override {}; // 오류 발생
	void show() { // virtual 키워드가 없으면 오버라이딩이 아닌 새로운 함수로 인식
		cout << "NoVDerived show()" << endl;
	}
};

void virtualOverrideExample() {
	cout << "-- virtual과 override 키워드 --" << endl;
	VBase b;
	VDerived d;
	VDerived2 d2;

	b.show(); // VBase show()
	d.show(); // VDerived show()
	d2.show(); // VDerived2 show()

	VBase* ptr = &b;
	ptr->show(); // VBase show()

	ptr = &d;
	ptr->show(); // VDerived show()

	ptr = &d2;
	ptr->show(); // VDerived2 show()
}

int main() {
	// 객체 생성 및 소멸
	// objectExample();
	// 상속과 접근 한정자
	// inheritanceExample();

	// 오버로딩과 오버라이딩
	// overloadOverrideExample();

	// virtual과 override 키워드
	virtualOverrideExample();

	cout << "main() 함수 종료" << endl;
	return 0;
}