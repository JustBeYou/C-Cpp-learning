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

        void destroy() {
            Node<type>* node = mTail;
            Node<type>* temp = nullptr;
            while (node != nullptr) {
                temp = node->next;
                delete node;
                node = temp;
            }

            mTail = nullptr;
            mSize = 0;
        }
    public:
        LinkedList() {
            mTail = nullptr;
            mSize = 0;
        }

        ~LinkedList() {
            destroy();
        }

        size_t getSize() const {
            return mSize;
        }

        bool isEmpty() const {
            return mSize == 0;
        }

        const type& operator[](size_t aIndex) const {
            
        }
};

} // namespace selfmade

#endif
