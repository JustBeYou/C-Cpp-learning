#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>
#include <exception>
#include <string>

namespace selfmade {

class LinkedListException final : public std::exception {
    private:
        std::string mMsg;
    public:
        explicit LinkedListException(const std::string& aMsg): mMsg(aMsg) {
        }

        const char* what() const noexcept override {
            return mMsg.c_str();
        }
};

template<typename type>
class Node {
    private:
        Node<type>* mNext;
        type mData;
    public:
        Node() {
            mNext = nullptr;
        }

        explicit Node(const Node<type>* aNext) {
            mNext = aNext;
        }

        Node(const Node<type>* aNext, const type& aData) {
            mNext = aNext;
            mData = aData;
        }

        Node<type>* getNext() const {
            return mNext;
        }

        const type& getData() const {
            return mData;
        }

        void setNext(Node<type>* aNext) {
            mNext = aNext;
        }

        void setData(const type& aData) {
            mData = aData;
        }

        void destroy() {
            if (mNext != nullptr) {
                delete mNext;
                mNext = nullptr;
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
                temp = node->getNext();
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
            if (aIndex >= mSize) { 
                throw LinkedListException("Index out of range");
            }
            Node<type>* node;
            size_t id = 0;

            for (node = mTail;
                 node->getNext() != nullptr;
                 node = node->getNext(), id++) {
                if (id == aIndex) {
                    break;
                }
            }

            return node->getData(); 
        }

        void insert(size_t aIndex, const type& aObject) {

        }

        void pushBack(const type& aObject) {
        }

        void pushFront(const type& aObject) {

        }

        void remove(const type& aObject) {

        }

        void erase(size_t aIndex) {

        }

        type popBack() {
        
        }

        type popFront() {

        }

        const type& front() const {

        }

        const type& back() const {

        }

        size_t find(const type& aObject) {

        }

        void reverse() {

        }
};

} // namespace selfmade

#endif
