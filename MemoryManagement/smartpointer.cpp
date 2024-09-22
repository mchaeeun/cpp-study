#include <iostream>
#include <memory> // 스마트 포인터를 사용하기 위한 헤더
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

    // std::unique_ptr 사용
    std::unique_ptr<Resource> uniqueRes(new Resource());
    uniqueRes->display();

    // unique_ptr은 복사할 수 없음
    // std::unique_ptr<Resource> anotherUniqueRes = uniqueRes; // 오류 발생
    std::unique_ptr<Resource> anotherUniqueRes = std::move(uniqueRes); // 소유권 이전
    if (!uniqueRes) {
        std::cout << "uniqueRes is now null." << std::endl;
    }
    anotherUniqueRes->display();
}

void sharedPointerExample() {
    std::cout << "-- Shared Pointer Example --" << std::endl;

    // std::shared_ptr 사용
    std::shared_ptr<Resource> sharedRes1(new Resource());
    {
        std::shared_ptr<Resource> sharedRes2 = sharedRes1; // 공유 소유권
        sharedRes2->display();
        std::cout << "Shared resource count: " << sharedRes2.use_count() << std::endl; // 2
    }
    // sharedRes2의 범위가 끝났으므로 sharedRes1의 카운트는 1로 줄어듭니다.
    std::cout << "Shared resource count after sharedRes2 goes out of scope: " << sharedRes1.use_count() << std::endl; // 1
    sharedRes1->display();
}