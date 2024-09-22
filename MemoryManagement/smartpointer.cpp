#include <iostream>
#include <memory> // ����Ʈ �����͸� ����ϱ� ���� ���
#include "smartpointer.h"

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired." << std::endl;
    }
    ~Resource() {
        std::cout << "Resource released." << std::endl;
    }
    void display() {
        std::cout << "Resource in use." << std::endl;
    }
};

void uniquePointerExample() {
    std::cout << "-- Unique Pointer Example --" << std::endl;

    // std::unique_ptr ���
    std::unique_ptr<Resource> uniqueRes(new Resource());
    uniqueRes->display();

    // unique_ptr�� ������ �� ����
    // std::unique_ptr<Resource> anotherUniqueRes = uniqueRes; // ���� �߻�
    std::unique_ptr<Resource> anotherUniqueRes = std::move(uniqueRes); // ������ ����
    if (!uniqueRes) {
        std::cout << "uniqueRes is now null." << std::endl;
    }
    anotherUniqueRes->display();
}

void sharedPointerExample() {
    std::cout << "-- Shared Pointer Example --" << std::endl;

    // std::shared_ptr ���
    std::shared_ptr<Resource> sharedRes1(new Resource());
    {
        std::shared_ptr<Resource> sharedRes2 = sharedRes1; // ���� ������
        sharedRes2->display();
        std::cout << "Shared resource count: " << sharedRes2.use_count() << std::endl; // 2
    }
    // sharedRes2�� ������ �������Ƿ� sharedRes1�� ī��Ʈ�� 1�� �پ��ϴ�.
    std::cout << "Shared resource count after sharedRes2 goes out of scope: " << sharedRes1.use_count() << std::endl; // 1
    sharedRes1->display();
}