#pragma once
#include <iostream>

using namespace std;

template <typename T>
class ListNode {
public:
T data;
	ListNode<T>* next;
	ListNode(T value) : data(value), next(nullptr) {}

}; 

template <typename T>
class LinkedList {
private:
	ListNode<T>* head;
    ListNode<T>* tail;
public:
	LinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = head;
        }
    }

    void push_back(T value) {
        ListNode<T>* newNode = new ListNode<T>(value);
        if (!head) {
            head = newNode;
            tail = head;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head) {
            ListNode<T>* temp = head;
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            delete temp;
        }
        else {
            throw out_of_range("List is empty");
        }
    }

    void pop_back() {
        if (head) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                ListNode<T>* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
        }
        else {
            throw out_of_range("List is empty");
        }
    }

    int size() const {
        int count = 0;
        ListNode<T>* current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    ListNode<T>* getHead() const {
        return head;
    }

    ListNode<T>* getTail() const {
        return tail;
    }

    bool empty() const {
        return head == nullptr;
    }

    T& operator[](int index) {
        ListNode<T>* current = head;
        int count = 0;
        while (current) {
            if (count == index) {
                return current->data;
            }
            current = current->next;
            count++;

        }
        cerr << "Index out of range: " << index << endl;
        return head->data;
    }


    class Iterator {
    private:
        ListNode<T>* current;
    public:
        Iterator(ListNode<T>* node) : current(node) {}

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        T& operator*() const {
            return current->data;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    ~LinkedList() {
        while (head) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};