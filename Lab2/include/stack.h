#pragma once

#include "list.h"

namespace DATA_STRUCTURE {

template<class data_base>
class stack : public list<data_base> {
    public:
        stack() = default;
        ~stack() = default;

        bool empty() override; 
        void pop() override;
        data_base top() override;
        void push(data_base push_data) override;
        void clear() override;
    private:
        int length = 0;
        node<data_base> *head=nullptr;
};

}
