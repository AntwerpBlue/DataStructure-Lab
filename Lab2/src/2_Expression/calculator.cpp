#include "calculator.h"

namespace DATA_STRUCTURE {

std::string calculator::get_expr() {
    return expr;
}

bool is_oprt(char c){
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

bool is_digit(char c){
    return c>='0'&&c<='9'||c=='.';
} 

bool calculator::legal() {
    //DONE
    stack<char> s;
    int flag=0;
    int oprt=0;
    for(auto it:expr){
        if(is_oprt(it)){
            if(oprt==1) return false;
            oprt=1;
        }
        else if(it!='(') oprt=0;
        if(it=='('){
            s.push(it);
            flag=1;
        }
        else if(it==')'){
            if(s.empty()||flag==1){
                return false;
            }
            if(s.top()=='('){
                s.pop();
            }
        }
        else{
            flag=0;
        }
    }
    if(s.empty()&&oprt==0){
        return true;
    }
}

struct calculator::element calculator::read_num(std::string number) {
    int num = 0, expo = 0, flag = 0;
    // DONE 
    for(auto it:number){
        if(it=='.'){
            flag=1;
        }
        else if(flag==0){
            num=num*10+it-'0';
        }
        else{
            expo++;
            num=num*10+it-'0';
        }
    }
    if(flag==1){
        double num_d=num/pow(10,expo);
        return {1,0, num_d};
    }
    else{
        return {0, num, 0};
    }
}

struct calculator::element calculator::operate(struct calculator::element element1, char c, struct calculator::element element2) {
    // DONE
    if(element1.flag==0){
        if(element2.flag==1){
            int num1=element1.num_int;
            double num2=element2.num_double;
            switch(c){
                case '+':
                    return {1,0,num1+num2};
                case '-':
                    return {1,0,num1-num2};
                case '*':
                    return {1,0,num1*num2};
                case '/':
                    return {1,0,num1/num2};
            }
        }
        else{
            int num1=element1.num_int;
            int num2=element2.num_int;
            switch(c){
                case '+':
                    return {0, num1+num2, 0};
                case '-':
                    return {0, num1-num2, 0};
                case '*':
                    return {0, num1*num2, 0};
                case '/':
                    return {0, num1/num2, 0};
            }
        }
    }
    else{
        if(element2.flag==1){
            double num1=element1.num_double;
            double num2=element2.num_double;
            switch(c){
                case '+':
                    return {1,0,num1+num2};
                case '-':
                    return {1,0,num1-num2};
                case '*':
                    return {1,0,num1*num2};
                case '/':
                    return {1,0,num1/num2};
            }
        }
        else{
            double num1=element1.num_double;
            double num2=element2.num_double;
            switch(c){
                case '+':
                    return {1, 0, num1+num2};
                case '-':
                    return {1, 0, num1-num2};
                case '*':
                    return {1, 0, num1*num2};
                case '/':
                    return {1, 0, num1/num2};
            }
        }
    }
}

int priority_regular(char c){
    if(c=='^')return 3;
    if(c=='*'||c=='/')return 2;
    if(c=='+'||c=='-')return 1;
}

int priority(char c1, char c2) {
    return priority_regular(c1)-priority_regular(c2);
}

struct calculator::element calculator::get_ans() {
    // TODO
    stack<element> values;
    stack<char> opts;
    for(auto it:expr){
        if(is_digit(it)){
            auto begin=it;
            while(is_digit(it)){
                it++;
            }
            auto dig=expr.substr(begin,it);
            it--;
            auto cur=read_num(dig);
            values.push(cur);
        }
        else if(it=='('){
            opts.push(it);
        }
        else if(it==')'){
            while(!opts.empty()&&opts.top()!='('){
                auto val2=values.top();values.pop();
                auto val1=values.top();values.pop();
                char opt=opts.top();opts.pop();
                values.push(operate(val1,opt,val2));
            }
            if(!opts.empty())opts.pop();
        }
        else if(is_oprt(it)){
            while(!opts.empty()&&priority(opts.top(),it)>=0){
                auto val2=values.top();values.pop();
                auto val1=values.top();values.pop();
                char opt=opts.top();opts.pop();
                values.push(operate(val1,opt,val2));
            }
            opts.push(it);
        }
    }
    return {0, 0, 0};
}

}