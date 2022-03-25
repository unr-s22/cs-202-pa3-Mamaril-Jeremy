//Jeremy Mamaril
//Tanner Ashby

#include "Money.h"
#include "Account.h"


int main(){

    Money money(300, 23);
    Account account(money);

    std::cout << account << std::endl;

    money.setMoney(200, 0);
    account.makeDeposit(money);
    
    money.setMoney(300, 24);
    account.makeDeposit(money);

    money.setMoney(501, 22);
    account.makeDeposit(money);

    std::cout << account << std::endl;

    money.setMoney(300, 10);
    account.makeWithdrawals(money);

    money.setMoney(201, 34);
    account.makeWithdrawals(money);

    std::cout << account << std::endl;

    std::cout << std::endl;

    //verify overloads
    std::cout << "Verify Overloads: " << std::endl;
    Money m(100,10);
    Money n(100,10);

    std::cout << "m > n: " << ((m > n) ? "true" : "false") << std::endl;
    std::cout << "m == n: " << ((m == n) ? "true" : "false") << std::endl;

    return 0;
}
