#include "Money.h"


int main(){

    Money money(300, 23);

    money.setMoney(200, 0);
    
    money.setMoney(300, 24);

    money.setMoney(501, 22);

    

    money.setMoney(300, 10);
    

    money.setMoney(201, 34);
    
    std::cout << std::endl;

    //verify overloads
    Money m(100,10);
    Money n(100,10);
    std::cout << ((m > n) ? "true" : "false") << std::endl;
    std::cout << ((m == n) ? "true" : "false") << std::endl;

    return 0;
}

