#include <iostream>
using namespace std;
class Test {
private:
	char* data;
	int size;
public:
	// 1. �⺻ ������
	Test() : data(nullptr), size(0) {
		cout << "Default Constructor called. Resource initialized with size " << size << "." << endl;
	}
	// 2. �Ű������� �ִ� ������
	Test(int size) : size(size) {
		data = new char[size];
		memset(data, 0, size); // data �迭�� 0���� �ʱ�ȭ
		cout << "Parameterized Constructor called. Test initialized with size " << size << "." << endl;
	}
	// 3. ���� ������
	Test(const Test& other) : size(other.size) {
		data = new char[size];
		memcpy(data, other.data, size); // data �迭�� other.data �迭�� ����
		cout << "Copy Constructor called. Test copied with size " << size << "." << endl;
	}
	// 4. �̵� ������
	Test(Test&& other) noexcept : data(other.data), size(other.size) {
		other.data = nullptr;
		other.size = 0;
		cout << "Move Constructor called. Test moved with size " << size << "." << endl;
	}
	// 5. �Ҹ���
	~Test() {
		if (data != nullptr) {
			delete[] data;
			cout << "Destructor called. Resource deleted." << endl;
		}
	}
	// ������ ���� �Լ�
	void setData(char data) {
		if (data) {
			memset(this->data, data, size);
			cout << "Data set with " << data << "." << endl;
		}
	}
	// ������ ǥ�� �Լ�
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
	cout << "-- ��ü ���� �� �Ҹ� --" << endl;
	// ��ü ����
	Test t1; // �⺻ ������ ȣ��]
	t1.showData();
	Test t2(5); // �Ű������� �ִ� ������ ȣ��
	t2.setData('B');
	t2.showData();

	Test t3 = t2; // ���� ������ ȣ��
	t3.showData();

	Test t4 = move(t2); // �̵� ������ ȣ��
	t4.showData();
	t2.showData(); // �̵��� ��ü�� �� ��ü�� ��

	// 2. ��ü �Ҹ�
	// ��ü�� �Ҹ�� �� �ڵ����� �Ҹ��ڰ� ȣ��Ǿ� ���� �޸𸮸� ����
}

// ��Ӱ� ���� ������ �ǽ�
// Base class (�θ� Ŭ����)
class Base {
private:
	int privateVar; // private: Base Ŭ���� ���ο����� ���� ����
protected:
	int protectedVar; // protected: Base Ŭ������ �ڽ� Ŭ�������� ���� ����
public:
	int publicVar; // public: ��𼭵� ���� ����

	// ������
	// �θ� Ŭ������ �޼��忡���� privateVar ���� ����
	Base() : privateVar(10), protectedVar(20), publicVar(30) {}
	// �θ� Ŭ�������� virtual Ű���带 ����Ͽ� �ڽ� Ŭ�������� �������̵� ������ �޼���
	virtual void showVar() {
		cout << "privateVar: " << privateVar << ", protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}

	// �����ε�	: ���� �̸��� �޼��带 ���� �� ����
	// �Ű������� ������ ������ �ٸ��� ���� �̸��� �޼��带 ���� �� ������ �� ����
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

// Derived class (�ڽ� Ŭ����)
class Derived : public Base {
public:
	// �θ��� showVar() �޼��带 �������̵�
	// �������̵�: �θ� Ŭ������ �޼��带 �ڽ� Ŭ�������� ������
	void showVar() override {
		// privateVar�� Base Ŭ������ private �����̹Ƿ� ���� �Ұ�
		// cout << "privateVar: " << privateVar << ", "; // ���� �߻�
		// protectedVar�� Base Ŭ������ protected �����̹Ƿ� ���� ����
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

// �ڽ� Ŭ���� - protected ���
class DerivedProtected : protected Base {
public:
	// protected�� ��ӹ����� public ����� protectedó�� ����
	void showVar() {
		// privateVar�� ���� �Ұ�
		// cout << "privateVar: " << privateVar << ", "; // ���� �߻�
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

// �ڽ� Ŭ���� - private ���
// class DerivedPrivate : Base {}; // ��õ��� ������ �⺻������ private ���
class DerivedPrivate : private Base {
public:
	// private�� ��ӹ����� public, protected ��� privateó�� ����
	void showVar() {
		// privateVar�� ���� �Ұ�
		// cout << "privateVar: " << privateVar << ", "; // ���� �߻�
		cout << "protectedVar: " << protectedVar << ", publicVar: " << publicVar << endl;
	}
};

void inheritanceExample() {
	cout << "-- ��Ӱ� ���� ������ --" << endl;
	// �⺻	Ŭ���� ��ü ����
	Base b;
	cout << "Base Ŭ������ ��� ���� ���" << endl;
	b.showVar();
	cout << b.publicVar << endl; // public ����� ��𼭵� ���� ����
	// b.protectedVar = 20; // protected ����� Base Ŭ���� �ܺο��� ���� �Ұ�
	// b.privateVar = 10; // private ����� Base Ŭ���� �ܺο��� ���� �Ұ�

	// �ڽ� Ŭ���� ��ü ����
	Derived d;
	cout << "Derived Ŭ������ ��� ���� ���" << endl;
	d.showVar();
	cout << d.publicVar << endl; // public ����� ��𼭵� ���� ����

	// protected ���
	DerivedProtected dp;
	cout << "DerivedProtected Ŭ������ ��� ���� ���" << endl;
	dp.showVar();
	// dp.publicVar; // protected ������� ���� �Ұ�

	// private ���
	DerivedPrivate dpr;
	cout << "DerivedPrivate Ŭ������ ��� ���� ���" << endl;
	dpr.showVar();
	// dpr.publicVar; // private ������� ���� �Ұ�
}

// �����ε��� �������̵� �ǽ�
void overloadOverrideExample() {
	cout << "-- �����ε��� �������̵� --" << endl;
	Base b;
	cout << "�����ε�" << endl;
	b.print(10); // int: 10
	b.print(3.14); // double: 3.14
	b.print(10, 3.14); // int: 10, double: 3.14

	cout << "�������̵�" << endl;
	Derived d;
	d.showVar(); // protectedVar: 20, publicVar: 30
}

// virtual�� override Ű���� �ǽ�
class VBase {
public:
	// virtual�� ��Ÿ�ӿ� ���� ���ε��� ����Ͽ� �������̵��� �Լ��� ȣ��
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
	// virtual Ű���尡 ������ ���� ���ε��� ����Ͽ� �Լ� ȣ��
	void show() {
		cout << "NoVBase show()" << endl;
	}
};

class NoVDerived : public NoVBase {
public:
	// override Ű����� virtual �Լ����� ��� ����
	// void show() override {}; // ���� �߻�
	void show() { // virtual Ű���尡 ������ �������̵��� �ƴ� ���ο� �Լ��� �ν�
		cout << "NoVDerived show()" << endl;
	}
};

void virtualOverrideExample() {
	cout << "-- virtual�� override Ű���� --" << endl;
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
	// ��ü ���� �� �Ҹ�
	// objectExample();
	// ��Ӱ� ���� ������
	// inheritanceExample();

	// �����ε��� �������̵�
	// overloadOverrideExample();

	// virtual�� override Ű����
	virtualOverrideExample();

	cout << "main() �Լ� ����" << endl;
	return 0;
}