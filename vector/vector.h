#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <cmath>
#include <new>

namespace selfmade {

// I am not responsable for your integer overflows :P

size_t helper_fastPow(size_t base, size_t exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;

    if (exp % 2 == 0) return helper_fastPow(base * base, exp / 2);
    return base * helper_fastPow(base * base, (exp - 1) / 2);
}

size_t helper_nearestTwoPow(size_t n) {
    n--;
    for (int i = 1; i < sizeof(size_t); i *= 2) {
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
    public:
        Vector() {
           mVector = new type[gMinVectorCapacity];
           mSize = 0;
           mCapacity = gMinVectorCapacity;
        }

        Vector(const Vector<type>& aInstance) {
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
    
        }

        Vector(std::size_t aSize) {
            
        }

        Vector(std::size_t aSize, const type* aArray) {

        }

        Vector(std::size_t aSize, type aValue) {

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

        }

        std::size_t capacity() const {

        }

        bool isEmpty() const {

        }

        // I don't think we need non-const :P
        /*type& operator[] (std::size_t aIndex) {

        }*/

        const type& operator[] (std::size_t aIndex) const {

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

        }

        void resize(std::size_t aCapacity) {

        }

};

}

#endif
