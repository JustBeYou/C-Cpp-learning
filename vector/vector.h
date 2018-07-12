#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <new>

namespace selfmade {

const std::size_t gMinVectorCapacity = 16;

template<typename type>
class Vector {
    private:
        type *mVector;
        std::size_t mSize;
        std::size_t mCapacity;
    public:
        Vector() {
            
        }

        Vector(const Vector<type>& aInstance) {

        }

        Vector<type>& operator=(const Vector<type>& aObject) {

        }

        Vector(std::size_t aSize) {

        }

        Vector(std::size_t aSize, const type* aArray) {

        }

        Vector(std::size_t aSize, type aValue) {

        }

        ~Vector() {

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
