#include <iostream>
#include "raii.h"
using namespace std;

// RAII(Resource Acquisition Is Initialization)
// �ڿ� ȹ���� �ʱ�ȭ���� �̷������.
// �ڿ� ������ �Ҹ��ڿ��� �̷������.

// RAII�� C++���� �ڿ� ������ ���� ������ ��������, �ڿ��� �Ҵ��ϴ� �ڵ�� �ڿ��� �����ϴ� �ڵ带 �и����� �ʰ�
// �ڿ��� �Ҵ��ϴ� �ڵ带 �����ڿ��� ó���ϰ� �ڿ��� �����ϴ� �ڵ带 �Ҹ��ڿ��� ó�������ν� �ڿ� ������ �����ϴ� ���

class MemoryManager {
private:
    int* data; // �������� �Ҵ�� �޸�
    size_t size; // �迭�� ũ��
public:
    // ������: �޸� �Ҵ�
    MemoryManager(size_t size) : size(size) {
        data = new int[size]; // �޸� ���� �Ҵ�
        cout << "Memory allocated for " << size << " integers." << endl;

        // �޸𸮰� ����� �Ҵ���� ���� ��� ���ܸ� ���� �� ����
        if (!data) {
            throw std::runtime_error("Memory allocation failed!");
        }

        // �ʱ�ȭ
        for (size_t i = 0; i < size; i++) {
            data[i] = i * 10; // ������ ������ �ʱ�ȭ
        }
    }

    // �����͸� ����ϴ� �Լ�
    void printData() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // �Ҹ���: �޸� ����
    ~MemoryManager() {
        delete[] data; // ���� �޸� ����
        cout << "Memory deallocated." << endl;
    }
};

void raiiExample() {
    try {
        MemoryManager mem(5); // 5���� ������ ���� �޸� �Ҵ�
        mem.printData(); // �Ҵ�� �޸��� ������ ���
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // ��ü�� �������� ����� �Ҹ��ڰ� ȣ��Ǿ� �޸𸮰� �ڵ����� ������
    return;
}