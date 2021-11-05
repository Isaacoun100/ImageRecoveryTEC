//
// Created by michael on 28/10/21.
//

#include <iostream>
using namespace std;


#ifndef IMAGERECOVERYTEC_CIRCULARLINKEDLIST_H
#define IMAGERECOVERYTEC_CIRCULARLINKEDLIST_H
template<typename T>class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class CircularLinkedList;
public:
    Node(){
        this->next = NULL;
    }
};

template<typename T>class CircularLinkedList {
private:
    Node<T> *head;
public:
    CircularLinkedList() {
        this->head = NULL;
    }

    void add(T item) {
        Node<T> *node = new Node<T>[1];
        node->data = item;
        if (head == NULL) {
            head == node;
            head->next = node;
            cout << "New node added (firstnode)" << endl;
            return;
        }
        Node<T> *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = head;
        cout << "New node added to the back " << endl;
    }

    void addFront(T item) {
        Node<T> *node = new Node<T>[1];
        node->data = item;
        if (head == NULL) {
            head = node;
            node->next = head;
            cout << "New node added(Firstnode) " << endl;
            return;
        }
        node->next = head;
        Node<T> *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = node;
        head = node;
        cout << "New node added at front" << endl;
    }

    void add(int index, T item) {
        if (index > length() || index < 0) {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node<T> *node = new Node<T>[1];
        node->data = item;
        int count = 0;
        Node<T> *temp = head;
        while (count < index) {
            if (count == index - 1) {
                node->next = temp->next != head ? temp->next : head;
                temp->next = node;
                cout << "New node added at index " << index << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    int length() {
        if (head == NULL) return 0;
        int len = 1;
        Node<int> *temp = head;
        while (temp->next != head) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void displayALl() {
        if (head == NULL) {
            cout << "Circular linked list is empty" << endl;
            return;
        }

        cout << endl << "----Circular link list items -----" << endl;
        Node<T> *temp = head;
        while (true) {
            cout << temp->data << " | ";
            temp = temp->next;
            if (temp == head) break;
        }
        cout << endl << "-------------------------------" << endl;
    }

    void remove() {
        if (head == NULL) {
            cout << "Circular linked list is empty" << endl;
            return;
        }
        if (length() == 1) {
            removeFront();
            return;
        }
        Node<T> *temp = head;
        while (temp->next != head) {
            if (temp->next->next == head) {
                temp->next = head;
                cout << "Last item removed" << endl;
                break;
            }
            temp = temp->next;
        }
    }

    void remove(int index) {
        if (head == NULL) {
            cout << "Circular linked list is empty" << endl;
            return;
        }

        if (index >= length() || index < 0) {
            cout << "Index out of bounds " << endl;
            return;
        }

        if (index == 0) {
            removeFront();
            return;
        }

        int count = 0;
        Node<T> *temp = head;
        while (temp->next != head) {
            if (count == index - 1) {
                temp->next = temp->next->next;
                cout << "Item removed at index " << index << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }

    void removeFront(){
        if(head == NULL){
            cout << "Circular linked list is empty " << endl;
            return;
        }
        if(length() == 1){
            head == NULL;
            cout << "First item removed "<< endl;
            return;
        }
        Node<T>* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
        cout << "front item removed " << endl;
    }

    T get(int index){
        if(head == NULL){
            cout << "Linked list is empty " << endl;
            return -9999;
        }
        if(index >= length() || index < 0){
            cout << "Index out of bound" << endl;
            return -9999;
        }
        if(index == 0){
            return head->data;
        }
        int count = 0;
        T res;
        Node<T>* temp = head;
        while(true){
            if(count++ == index){
                res = temp->data;
                break;
            }
            temp = temp->next;
            if(temp == head) break;
        }
        return res;
    }
};


#endif //IMAGERECOVERYTEC_CIRCULARLINKEDLIST_H
