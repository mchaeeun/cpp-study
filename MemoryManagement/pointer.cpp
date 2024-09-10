#include <string>
#include "pointer.h"

void basicPointer() {
	cout << "-- ������ �⺻ ���� --" << endl;
	// ������: �޸� �ּҸ� �����ϴ� ����
	int* ptr; // int�� ������ ����Ű�� ������ ptr ����

	float y = 3.14;
	// ptr = &y; // ����: int�� �����Ϳ� float�� ���� �ּ� ���� �Ұ�

	// �ּ� ������(&): ������ �޸� �ּҸ� ��ȯ
	int x = 5;
	ptr = &x; // ptr�� x�� �ּҸ� ����
	cout << "x: " << x << endl;
	cout << "ptr: " << ptr << endl;
	cout << "&x: " << &x << endl;
	cout << "&ptr: " << &ptr << endl;

	// ������ ������(*): �����Ͱ� ����Ű�� �ּҿ� ����� ���� ��ȯ
	cout << "*ptr: " << *ptr << endl;
	cout << endl;
}

void pointerWarnings() {
	cout << "-- ������ ��� �� ���ǻ��� --" << endl;
	// 1. �ʱ�ȭ���� ���� ������ ���
	// -- int* uninitializedPtr; vs. int* initializedPtr = nullptr; --
	// �ʱ�ȭ���� ���� ������
	int* uninitializedPtr; // ������ ���� �� �� ����
	// cout << "*uninitializedPtr: " << *uninitializedPtr << endl; // ����: �ʱ�ȭ���� ���� ������ ���

	// �ʱ�ȭ�� ������
	int* initializedPtr = nullptr; // �ʱ�ȭ�Ǿ� ������ ���� ���� ����
	cout << initializedPtr << endl; // 0

	// 2. Dangling Pointer: ������ �޸� ����
	int* deletedPtr = new int;
	delete deletedPtr;
	cout << "*deletedPtr: " << *deletedPtr << endl; // ��������: ������ �޸� ����

	// 3. �޸� ����(Memory Leak): ���� �޸� �������� ����
	int* memoryLeakPtr = new int; // ������ ���� �� �� ����
	cout << "*memoryLeakPtr: " << *memoryLeakPtr << endl;
	// delete memoryLeakPtr; // ���� �޸� �������� ����
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
	cout << " --������ ����-- " << endl;
	// 1. void ������: ��� ������ ������ ����ų �� �ִ� ������
	void* voidPtr;
	string s = "Hello";
	voidPtr = &s;
	cout << "s: " << s << endl;
	cout << "voidPtr: " << voidPtr << endl;

	// 2. nullptr: �����Ͱ� ����Ű�� �ּҰ� ������ ��Ÿ���� ��
	int* nullPtr = nullptr;
	cout << "nullPtr: " << nullPtr << endl;

	// 3. ���� �޸� �Ҵ�: ���α׷� ���� �߿� �޸𸮸� �Ҵ�
	int* dynamicPtr = new int; // int�� ������ ����Ű�� ������ dynamicPtr ����
	*dynamicPtr = 15; // dynamicPtr�� ����Ű�� �ּҿ� 15 ����
	cout << "dynamicPtr: " << dynamicPtr << endl;
	cout << "*dynamicPtr: " << *dynamicPtr << endl;
	delete dynamicPtr; // ���� �޸� ����

	// 4. �迭 ���� �޸� �Ҵ�
	int* dynamicArr = new int[5]; // int�� �迭�� ����Ű�� ������ dynamicArr ����
	for (int i = 0; i < 5; i++) {
		dynamicArr[i] = i;
	}
	for (int i = 0; i < 5; i++) {
		cout << "dynamicArr[" << i << "]: " << dynamicArr[i] << endl;
	}
	delete[] dynamicArr; // �迭 ���� �޸� ����

	// 5. ������ �迭
	int a = 1, b = 2, c = 3;
	int* ptrArr[3] = { &a, &b, &c }; // int�� ������ ����Ű�� ������ �迭 ptrArr ����
	for (int i = 0; i < 3; i++) {
		cout << "*ptrArr[" << i << "]: " << *ptrArr[i] << endl;
		cout << "ptrArr[" << i << "]: " << ptrArr[i] << endl;
	}

	// 6. ���� ������
	int x = 10;
	int* singlePtr = &x; // int�� ������ ����Ű�� ������ singlePtr ����
	int** doublePtr = &singlePtr; // int�� �����͸� ����Ű�� ������ doublePtr ����
	cout << "doublePtr: " << doublePtr << endl;
	cout << "*doublePtr: " << *doublePtr << endl;
	cout << "**doublePtr: " << **doublePtr << endl;

	// 7. ��� ������: �����Ͱ� ����Ű�� �ּ��� ���� ������ �� ����
	const int* constPtr = &x; // x�� �ּҸ� ����Ű�� ��� ������ constPtr ����
	// *constPtr = 20; // ����: constPtr�� ����Ű�� �ּ��� ���� ������ �� ����
	cout << "*constPtr: " << *constPtr << endl;
	const int z = 30;
	constPtr = &z; // constPtr�� z�� �ּҸ� ����Ŵ
	cout << "*constPtr: " << *constPtr << endl;

	// 8. ������ �Ű�����
	int d = 4, e = 5;
	swap(&d, &e); // d�� e�� �ּҸ� ����
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;

	// 9. ������ ��ȯ��
	int* retPtr = returnPointer(); // int�� �����͸� ��ȯ�ϴ� �Լ� ȣ��
	cout << "*retPtr: " << *retPtr << endl;
	delete retPtr; // ��ȯ�� ������ �޸� ����

	// 10. Class ������
	PointerClass* classPtr = new PointerClass; // PointerClass ��ü�� ����Ű�� ������ classPtr ����
	classPtr->setX(10); // classPtr�� ����Ű�� ��ü�� x�� ����
	cout << "classPtr->getX(): " << classPtr->getX() << endl;
	cout << "(*classPtr).getX(): " << (*classPtr).getX() << endl; // ������ ������ ���
	delete classPtr; // classPtr�� ����Ű�� ��ü �޸� ����
}