#include <iostream>

#include "linked_list.hpp"
#include "gtest/gtest.h"

void show(selfmade::LinkedList<int>& list) {
    for (int i = 0; i < list.getSize(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl; 
}

TEST(LinkedList, FullTesting) {
    selfmade::LinkedList<int> mylist;

    ASSERT_EQ(true, mylist.isEmpty());
    ASSERT_EQ(0, mylist.getSize());

    try {
        mylist[5];
        ASSERT_STREQ("An exception should be raisen","No exception");
    } catch (...) {
        
    }

    int check[] = {
        -8, -7, -6, -4, -3, -2, -1,
        1, 2, 3, 4, 5, 6, 7
    };

    for (int i = 1; i <= 10; i++) {
        mylist.pushBack(i);
        show(mylist);
        mylist.pushFront(-i);
        show(mylist);
    }

    for (int i = 0; i < 3; i++) {
        mylist.insert(i, 0);
        show(mylist);
    }

    for (int i = 0; i < 3; i++) {
        mylist.erase(i * 3);
        show(mylist);
    }

    for (int i = 0; i < 3; i++) {
        mylist.popBack();
        mylist.popFront();
    }

    for (int i = 0; i < 14; i++) {
        ASSERT_EQ(check[i], mylist[i]);
    }


    int i = 0;
    for (selfmade::LinkedList<int>::iterator it = mylist.begin();
         it != mylist.end();
         ++it) {
        std::cout << "Index " << i << " -> " << *it << std::endl;
        i++;
    }

    for (auto& elem: mylist) {
        std::cout << elem << std::endl; 
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
