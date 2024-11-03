#pragma once

#include "list.h"

namespace DATA_STRUCTURE {

template<class data_base>
class queue : public list<data_base> {
    public:
        queue() = default;
        ~queue() = default;

        bool empty() override; 
        data_base top() override; 
        void push(data_base push_data) override;
        void pop() override;
        void clear() override; 
    private:
        node<data_base> *tail = new node<data_base>;
        node<data_base> *head = tail;
};

}
