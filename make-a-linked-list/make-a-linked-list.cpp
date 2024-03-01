/***************************************
Make a Linked List
Author: Lawjay Lee
Date Completed: 2024-03-01
Description: Implementing logic for
a linked list from scrath
***************************************/

#include <iostream>
using namespace std;

class SList {
    // Note: Do not modify any code in the private section!
  private:
    // Node definition
    struct Node {
        Node *next;
        string data;

        Node(string d, Node *n) : data(d), next(n) {
        }
    };

    // Node pointer to head (front) of list
    Node *head_;

  public:
    // Constructor
    // Initializes head to null
    SList() : head_(nullptr){};

    // Ruturn true if the list is empty, otherwise false
    bool empty() {
        // if the head doesn't point to anything,
        // the linked list is empty
        return (head_ == nullptr);
    }

    // Return the number of nodes in the list
    int size() {
        if (head_ == nullptr) {
            return 0;
        }

        int count(1); // head wasn't nullptr, means at least 1
        Node *tmpHead(head_);
        while (tmpHead->next != nullptr) {
            tmpHead = tmpHead->next;
            count++;
        }
        return count;
    }

    // Create a new node to contain value and insert
    // the node to the front of the list
    void pushFront(string value) {
        head_ = new Node(value, head_);
    }

    // Create a new node to conatin value and insert
    // the node to the back of the list
    void pushBack(string value) {

        if (head_ == nullptr) {
            head_ = new Node(value, head_);
            return;
        }

        Node *curNode(head_);

        while (curNode->next != nullptr) {
            curNode = curNode->next;
        }
        // curNode should now be at last node
        Node *newNode = new Node(value, nullptr);
        curNode->next = newNode;
    }

    // Retrieve the node value at the specified list index.
    // Note: Your implementation may assume that the value
    // passed into the index parameter is within the range
    // of the linked list size
    string at(int index) {
        if (index == 0) {
            return head_->data;
        }

        Node *tmpNode(head_);
        for (int i(0); i < index; i++) {
            tmpNode = tmpNode->next;
        }

        return tmpNode->data;
    };

    // Remove the head node in the list such that
    // the second node in the list should become
    // the new head node. Then return the previous
    // head node's value.
    // Note: Your implementation may assume that the
    // size of the linked list is greater than zero
    string popFront() {
        Node *oldHead = head_;
        string oldHeadValue = oldHead->data;
        head_ = head_->next;
        delete oldHead;
        return oldHeadValue;
    }

    // Remove the node at the specified list index.
    // Return true if the node at the specified index
    // could be removed, otherwise false
    bool removeAt(int index) {
        if (empty()) {
            return false;
        }

        if (index == 0) {
            // could just do popFront(), but I don't
            // want to allocate new string space
            Node *oldHead = head_;
            head_ = head_->next;
            delete oldHead;
            return true;
        }

        Node *prevNode;
        Node *curNode = head_;

        for (int i(0); i < index; i++) {
            if (curNode->next == nullptr) {
                // if the next one is a nullptr
                // the index is out of bounds
                return false;
            }

            prevNode = curNode;
            curNode = curNode->next;
        }

        // update prevNode->next to be the new next one
        prevNode->next = curNode->next;
        delete curNode;

        return true;
    }

    // Remove all nodes in the list
    void clear() {
        if (empty()) {
            return;
        }

        Node *curNode = head_;
        while (curNode->next != nullptr) {
            Node *tmpNext = curNode->next;
            delete curNode;
            curNode = tmpNext;
        }
        // last node->next does equal nullptr
        // so this cleans last one
        delete curNode;
        head_ = nullptr;
    }

    // Destructor
    // Remove any remaining nodes in the list
    ~SList() {
        clear();
    }
};

int main() {
    cout << "Starting program...\n\n";

    {
        SList list;

        cout << "The size of the list is: " << list.size();

        cout << "\n\nPushing strings into the list...\n\n";
        list.pushFront("This should end up as index 2 in the list");
        list.pushFront("This should end up as index 1 in the list");
        list.pushBack("This should end up as index 3 in the list");
        list.pushBack("This should end up as index 4 in the list");
        list.pushFront("This should end up as index 0 in the list");

        cout << "The size of the list is: " << list.size();

        cout << "\n\nThe string at index 1 is \"" << list.at(1) << "\"\n";
        cout << "The string at index 3 is \"" << list.at(3) << "\"\n";

        cout << "\nClearing the list...\n\n";
        list.clear();

        cout << "Pushing four strings into the list...\n\n";
        list.pushBack("item 1");
        list.pushBack("item 2");
        list.pushBack("item 3");
        list.pushBack("item 4");

        if (list.removeAt(2)) {
            cout << "Successfully removed string at index 2 from list\n";
        }

        if (list.removeAt(3)) {
            cout << "Successfully removed string at index 3 from list\n";
        }

        cout << "\nThe size of the list is: " << list.size();

        cout << "\n\nItems in the list:\n";
        while (!list.empty()) {
            cout << list.popFront() << endl;
        }
    }

    cout << "\nExiting program...\n";

    return 0;
}
