#pragma once

#include "list.h"

namespace DATA_STRUCTURE {

template<class data_base>
class stack : public list<data_base> {
    public:
        stack() = default;
        ~stack() = default;

        bool empty() override{
            return top_index == 0;
        }
        void pop() override{
            top_index--;
        }
        data_base top() override{
            return list_data[top_index - 1];
        }
        void push(data_base push_data) override{
            list_data[top_index] = push_data;
            top_index++;
        }
        void clear() override{
            top_index = 0;
        }
    private:
        int top_index = 0;
        data_base list_data[MAX_LINK_LIST_NUM];
};

}
