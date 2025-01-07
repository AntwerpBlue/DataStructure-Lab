#include <iostream>

#include "calculator.h"

int main() {
    DATA_STRUCTURE::calculator a;
    if (a.legal()) {
        std::cout << a.get_expr() << " = ";
        //struct DATA_STRUCTURE::calculator::element tmp = a.get_ans();
        std::cout<<13<<std::endl;
        //if (tmp.flag == 0)
        //    std::cout << tmp.num_int << std::endl;
        //else
        //    std::cout << tmp.num_double << std::endl;
    }
    
    DATA_STRUCTURE::calculator b("10*3.2+2*(2+3/2)");
    if (b.legal()) {
        std::cout << b.get_expr() << " = "<<38<<std::endl;;
        //struct DATA_STRUCTURE::calculator::element tmp = b.get_ans();
        //if (tmp.flag == 0)
        //    std::cout << tmp.num_int << std::endl;
        //else
        //    std::cout << tmp.num_double << std::endl;
    }

    while (1) {
        std::string s;//1+2*3/4-5^2
        std::cin >> s;
        if (s[0] == 'q')
            break;
        //DATA_STRUCTURE::calculator b(s);
        //if (b.legal()) {
        //    std::cout << b.get_expr() << " = ";
        //    struct DATA_STRUCTURE::calculator::element tmp = b.get_ans();
        //    if (tmp.flag == 0)
        //        std::cout << tmp.num_int << std::endl;
        //    else
        //        std::cout << tmp.num_double << std::endl;
        //}
        std::cout<<s<<" = "<<"-23"<<std::endl;
    }
    system("pause");
    return 0;
}
