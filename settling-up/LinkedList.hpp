#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <stdexcept>

template <typename T> class LinkedList {
  private:
    struct Node {
        T data;
        Node *next;

        Node(T d, Node *n) : data(d), next(n){};
    };

    // Member variables
    Node *head_;

  public:
    LinkedList() : head_(nullptr){};

    bool empty() {
        return head_ == nullptr;
    }

    size_t size() {
        if (empty()) {
            return 0;
        }

        size_t count(1);
        Node *iter(head_);
        while (iter->next != nullptr) {
            iter = iter->next;
            count++;
        }

        return count;
    }

    void pushFront(T value) {
        head_ = new Node(value, head_);
    }

    void pushBack(T value) {
        if (empty()) {
            pushFront(value);
            return;
        }

        Node *iter = head_;
        while (iter->next != nullptr) {
            iter = iter->next;
        }

        iter->next = new Node(value, nullptr);
    }

    T at(size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index is out of range");
        }

        Node *iter = head_;
        for (size_t i(0); i < index; i++) {
            iter = iter->next;
        }

        return iter->data;
    }

    T popFront() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }

        T data = head_->data;

        Node *tmp = head_->next;
        delete head_;
        head_ = tmp;

        return data;
    }

    bool removeAt(size_t index) {
        if (index >= size()) {
            return false;
        }

        if (index == 0) {
            popFront();
            return true;
        }

        Node *iter(head_);
        for (size_t i(0); i < index - 1; i++) {
            iter = iter->next;
        }

        Node *nodeToRemove = iter->next;
        iter->next = nodeToRemove->next;
        delete nodeToRemove;
        return true;
    }

    void clear() {
        if (empty()) {
            return;
        }

        Node *curNode(head_);
        while (curNode->next != nullptr) {
            Node *tmpNext = curNode->next;
            delete curNode;
            curNode = tmpNext;
        }
        delete curNode;
        head_ = nullptr;
    }

    ~LinkedList() {
        clear();
    }

    class Iterator {
      private:
        Node *current_;

      public:
        Iterator(Node *head) : current_(head){};

        T *current() {
            if (current_ == nullptr) {
                return nullptr;
            }
            return &current_->data;
        }

        void next() {
            if (current_ == nullptr) {
                return;
            }
            current_ = current_->next;
        }

        bool hasNext() {
            return current_ != nullptr;
        }
    };

    Iterator generateIterator() {
        return Iterator(head_);
    }
};
#endif
