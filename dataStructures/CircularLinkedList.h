//
// Created by michael on 28/10/21.
//

#include <iostream>
using namespace std;

/**
 * @file CircularLinkedList.h
 * @author Michael Valverde Navarro
 * @brief Clase que obtiene una lista circular
 * @version 1.0
 * @date 28/10/2021
 */


#ifndef IMAGERECOVERYTEC_CIRCULARLINKEDLIST_H
#define IMAGERECOVERYTEC_CIRCULARLINKEDLIST_H
template<typename T>class Node{
private:
    T data;
    Node<T>* next;
    template<typename U>friend class CircularLinkedList;
public:
    /**
     * @brief constructor de la clase Node, que sirve para crear una estructura que permite almacenar datos
     */
    Node(){
        this->next = NULL;
    }
};

template<typename T>class CircularLinkedList {
private:
    Node<T> *head;
public:
    /**
     * @brief Constructor de la lista Circular
     */
    CircularLinkedList() {
        this->head = NULL;
    }

    /**
     * @brief método para añadir, un elemento a la lista circular
     * @param item elemento de algun tipo de dato que se añade a la lista
     */
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

    /**
     * @brief método que permite añadir un elemento al inicio de la lista
     * @param item elemento de algun tipo de dato que se añade a la lista
     */
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

    /**
     * @brief método que permite añadir un elemento de tipo T a la lista, se puede añadir el elemento a cualquier indice de esta
     * @param index posición en la que ubicaría el elemento que se añade
     * @param item dato que entra a la lista
     */
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

    /**
     * @brief método que retorna la longitud de la lista circular
     * @return integer que indica la longitud de la lista
     */
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

    /**
     *  @brief método que permite mostrar todos los elementos que se encuentran en la lista
     */
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

    /**
     * @brief método que permite eliminar un elemento de la lista
     */
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

    /**
     * @brief método que permite eliminar un elemento de la lista en un indice en especifico
     * @param index posición en la que se elimina un elemento
     */
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

    /**
     * @brief método que permite eliminar el elemento que se encuentra al inicio de la lista circular
     */
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

    /**
     * @brief método que permite obtener un elemento que se encuentra en la lista
     * @param index posición del elemento que se desea obtener
     * @return dato de tipo T
     */
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
