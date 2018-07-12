#include <iostream>

#include "vector.h"
#include "gtest/gtest.h"

TEST(Vector, SizeAndCapacity) {
    selfmade::Vector<int> v1;

    ASSERT_EQ(selfmade::gMinVectorCapacity, v1.capacity());
    ASSERT_EQ(0, v1.size());

    selfmade::Vector<int> v2(10);
    ASSERT_EQ(selfmade::gMinVectorCapacity, v2.capacity());
    ASSERT_EQ(10, v2.size());

    int a[22];
    for (int i = 0; i < 22; i++) a[i] = i;
    selfmade::Vector<int> v3(22, a);
    ASSERT_EQ(selfmade::gMinVectorCapacity * 2, v3.capacity());
    ASSERT_EQ(22, v3.size());

    selfmade::Vector<int> v4(64, 10);
    ASSERT_EQ(64, v4.capacity());
    ASSERT_EQ(64, v4.size());

    selfmade::Vector<int> v5(v4);
    ASSERT_EQ(64, v5.capacity());
    ASSERT_EQ(64, v5.size());
}

TEST(Vector, CopyAndAccess) {
    int a[512];
    for (int i = 0; i < 512; i++) a[i] = i;

    selfmade::Vector<int> v(512, a);
    ASSERT_EQ(10, v.find(10));
    ASSERT_EQ(120, v[120]);
    ASSERT_EQ(512, v.size());
}

TEST(Vector, PushAndPop) {
    selfmade::Vector<int> v;
    int check[] = {
        -8, -7, -6, -4, -3, -2, -1, 0,
        1, 2, 3, 4, 5, 6, 7
    };

    for (int i = 1; i < 10; i++) {
        v.pushBack(i);
        v.pushFront(-i);
    }

    for (int i = 0; i < 3; i++) {
        v.insert(i, 0);
    }

    for (int i = 0; i < 3; i++) {
        v.remove(i * 3);
    }

    for (int i = 0; i < 3; i++) {
        v.popBack();
        v.popFront();
    }

    for (int i = 0; i < 15; i++) {
        ASSERT_EQ(check[i], v[i]);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
