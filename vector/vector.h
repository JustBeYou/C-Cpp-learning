#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include <cstddef>
#include <cmath>
#include <new>

namespace selfmade {

// I am not responsable for your integer overflows :P

template<typename T>
inline T max(const T& a, const T& b) {
    return a > b ? a : b;
}

__attribute__((unused)) size_t helper_fastPow(size_t base, size_t exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;

    if (exp % 2 == 0) return helper_fastPow(base * base, exp / 2);
    return base * helper_fastPow(base * base, (exp - 1) / 2);
}

size_t helper_nearestTwoPow(size_t n) {
    n--;
    for (size_t i = 1; i < sizeof(size_t); i *= 2) {
        n |= n >> i;
    }
    n++;

    return n;
}

const std::size_t gMinVectorCapacity = 16;

template<typename type>
class Vector {
    private:
        type *mVector;
        std::size_t mSize;
        std::size_t mCapacity;

        void init(std::size_t aSize) {
            size_t n = helper_nearestTwoPow(aSize);
            mCapacity = max(n, gMinVectorCapacity);
            mSize = aSize;
            mVector = new type[mCapacity];
        }
    public:
        Vector() {
           mVector = new type[gMinVectorCapacity];
           mSize = 0;
           mCapacity = gMinVectorCapacity;
        }

        Vector(const Vector<type>& aInstance) {
            mVector = nullptr;
            *this = aInstance;
        }

        Vector<type>& operator=(const Vector<type>& aInstance) {
            release();
            mCapacity = aInstance.capacity();
            mSize = aInstance.size();
            
            mVector = new type[mCapacity];
            for (int i = 0; i < mSize; i++) {
                mVector[i] = aInstance[i];
            }

            return *this;
        }

        Vector(std::size_t aSize) {
            init(aSize); 
        }

        Vector(std::size_t aSize, const type* aArray) { 
            init(aSize);
            for (int i = 0; i < aSize; i++) {
                mVector[i] = aArray[i];
            }
        }

        Vector(std::size_t aSize, type aValue) {
            init(aSize);
            for (int i = 0; i < aSize; i++) {
                mVector[i] = aValue;
            }
        }

        void release() {
            if (mVector != nullptr) {
                delete[] mVector;
                mVector = nullptr;
                mSize = 0;
                mCapacity = 0;
            }
        }

        ~Vector() {
            release();
        }


        std::size_t size() const {
            return mSize;
        }

        std::size_t capacity() const {
            return mCapacity;
        }

        bool isEmpty() const {
            return mSize == 0;
        }

        // I don't think we need non-const :P
        /*type& operator[] (std::size_t aIndex) {

        }*/

        const type& operator[](std::size_t aIndex) const {
            if (aIndex >= mSize) {
                throw "Vector size exceeded";
            }
            return mVector[aIndex];
        }


        void pushFront(const type& aObject) {

        }

        void pushBack(const type& aObject) {

        }

        void insert(std::size_t aIndex, const type& aObject) {

        }

        
        type popFront() {

        }

        type popBack() {

        }

        void remove(std::size_t aIndex) {

        }


        std::size_t find(const type& aObject) const {
            for (size_t i = 0; i < mSize; i++) {
                if (aObject == mVector[i]) return i;
            }

            throw "Object not found in vector";
        }

        void resize(std::size_t aCapacity) {

        }

};

}

#endif
