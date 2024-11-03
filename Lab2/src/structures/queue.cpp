#include "queue.h"

using namespace DATA_STRUCTURE;

template<class T>
bool queue<T>::empty(){
    return head==tail;
}

template<class T>
void queue<T>::push(T item){
    auto cur = new node<T>(item);
    tail->next->next=cur;
    cur->next=tail;
    tail->next=cur;
}

template<class T>
T queue<T>::top(){
    return head->data;
}

template<class T>
void queue<T>::pop(){
    auto cur = head->next;
    delete head;
    head=cur;   
}

template<class T>
void queue<T>::clear(){
    while(!empty()){
        pop();
    }
}