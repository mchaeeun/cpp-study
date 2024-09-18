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