#pragma once

#include "list.h"

namespace DATA_STRUCTURE {

template<class data_base>
class queue : public list<data_base> {
    public:
        queue() = default;
        ~queue() = default;

        bool empty() override {
            return top_index==tail_index;
        }
        void pop() override {
            tail_index++;
        }
        data_base top() override {
            return list_data[tail_index];
        }
        void push(data_base push_data) override {
            if(tail_index>200){
                for(int i=tail_index;i<top_index;i++){
                    list_data[i-tail_index]=list_data[i];
                }
                tail_index=0;
                top_index-=tail_index;
            }
            list_data[top_index++]=push_data;
        }
        void clear() override {
            top_index=0;
            tail_index=0;
        }
    private:
        int top_index = 0;
        int tail_index = 0;
        data_base list_data[MAX_LINK_LIST_NUM];
};

}
