#include "stack.h"

using namespace DATA_STRUCTURE;

template<class T>
bool stack<T>::empty(){
    return (length == 0);
}

template<class T>
void stack<T>::pop(){
    auto top=head;
    head = head->next;
    delete top;
    length--;
}

template<class T>
T stack<T>::top(){
    return head->data;
}

template<class T>
void stack<T>::push(T data){
    auto temp = new node<T>;
    temp->data = data;
    temp->next = head;
    head = temp;
    length++;
}

template<class T>
void stack<T>::clear(){
    while(length!=0){
        pop();
    }
}