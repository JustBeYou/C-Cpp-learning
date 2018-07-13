#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

namespace selfmade {

template<typename type>
class Node {
    private:
        Node<type>* mNext;
        type* mData;
    public:
        Node() {
            mNext = nullptr;
            mData = nullptr;
        }

        explicit Node(Node<type>* aNext) {
            mNext = aNext;
            mData = nullptr;
        }

        Node(Node<type>* aNext, type* aData) {
            mNext = aNext;
            mData = aData;
        }

        Node<type>* getNext() const {
            return mNext;
        }

        type* getData() const {
            return mData;
        }

        void setNext(Node<type>* aNext) {
            mNext = aNext;
        }

        void setData(type* aData) {
            mData = aData;
        }

        void destroy() {
            if (mNext != nullptr) {
                delete mNext;
                mNext = nullptr;
            }

            if (mData != nullptr) {
                delete mData;
                mData = nullptr;
            }
        }

        ~Node() {
            destroy();
        }

};

template<typename type>
class LinkedList {
    private:
        Node<type>* mTail;
        size_t mSize;
    public:
        LinkedList() {
            mTail = nullptr;
            mSize = 0;
        }

        size_t getSize() const {
            return mSize;
        }
};

} // namespace selfmade

#endif
