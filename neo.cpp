#include <iostream>
#include "bank.hpp"
#include "account.hpp"
#include <fstream>


using namespace account;


void setup(){
    std::cout<<"-----------WELCOME------------\n\n";
    std::cout<<"What would you like to with this system\n 1. Create an account\n 2. Login your account\n 3. Deposit money\n 4. Withdraw money\n 5. Get a loan\n";

    int answer;
    std::cin>>answer;

    switch(answer){
        case 1:
            infos::create_account();
            break;
        case 2:
            infos::login_account();
            break;
        case 3:
            {
                Bank l;
                l.loan();
                break;
            }
        case 4:
            {
                Bank a;
                a.withdraw();
                break;
            }
        case 5:
            {
                Bank o;
                o.loan();
                break;
            }
        default:
            std::cerr<<"Exiting this program due to wrong input\n";

    }

    std::cout<<"----------------------------\n\n";

}

int main(int argc, char* argv[]){

    setup();
    return 0;
}
