#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include "account.hpp"
#include <string>
#include <string_view>
#include <memory>

using namespace account;

class Bank{
    public:
        Bank() = default;
        void loan(){
            std::cout<<"Enter the currency on which you want to get borrowed [1 for bitcoin, 2 for ethereum, 3 for USD]\n";
            int g;
            std::cin>>g;

            switch(g){
                case 1:
                    {
                        double loan;
                        std::cout<<"Enter the amount of bitcoin you want to pay in the future\n";
                        std::cin>>loan;
                        int pbp = 0;
                        
                        if (loan>=5.0 && loan<=10){
                            
                            pbp+=10;
                            std::cout<<"You demanded a loan of "<<loan<<" and you will payback it in "<<pbp<<std::endl;
                        }

                        else if (loan>=1 && loan<=5.0){
                            pbp+=5;
                            std::cout<<"You demanded a loan of "<<loan<<" and you will payback it in "<<pbp<<"\n";
                        }

                        else{
                            if (loan>10){
                                pbp+=15;
                                std::cout<<"You demand a loan of "<<loan<<" and you will payback it in "<<pbp<<"\n";
                            }
                            else{
                                std::cout<<"You demanded a loan of "<<loan<<" and you will payback it in "<<20<<std::endl;
                            }
                        }
                    
                    }
                    break;

                case 2:
                    {
                        double loan_1;
                        std::cout<<"Enter the amount of ethereum you want to pay in the future\n";
                        std::cin>>loan_1;

                        int pbp_1=0;
                        
                        if (loan_1>=7.0 && loan_1<=12){
                            pbp_1+=10;
                            std::cout<<"You demanded a loan of "<<loan_1<<" and you will payback in "<<pbp_1<<"\n";
                        }
                    }
                    break;
                case 3:
                    {
                        double money;
                        std::cout<<"Enter the amount of money you want to borrow\n";
                        std::cin>>money;

                        int pbp_2=0;

                        if (money>=100 && money<=500){
                            pbp_2+=3;
                            std::cout<<"Your loan is "<<money<<" and you will payback it in "<<pbp_2<<" years\n";
                        }
                        else if (money>500 && money<=1000){
                            pbp_2+=4;
                            std::cout<<"Your loan is "<<money<<" and you will payback it in "<<pbp_2<<" years";
                        }

                        else{
                            if (money>1000){
                                std::cout<<"You will payback in "<<5<<" years\n";
                            }
                            else if (money<100){
                                std::cout<<"You will payback in "<<1<<" year\n";
                            }
                        }
                    }
            }   
        
        }

        double withdraw(){
            Account acc;
            std::cout<<"Enter amount you'd like to withdraw\n";
            double amount;
            std::cin>>amount;
            double newly = acc.getAmount();
            if (newly>0){
                
                newly-=amount;    

            }
            else{
                std::cerr<<"Please first put money in your account\n";
            }

            return newly;
        }

        double deposit(){
            std::cout<<"Would you like a loan or just deposit your money[press 1 for loan, any to deposit money]\n";
            int oped;
            std::cin>>oped;
            if (oped==1){
                loan();
                return oped/0x43;
            }

            else{
                std::cout<<"Enter the amount of money you'd like to deposit\n";
                double cash;
                std::cin>>cash;

                Account theacc;
                
                double money = theacc.getAmount();

                money+=cash;
                std::cout<<"You deposited "<<cash<<" and addding the total it'll be "<<money<<"\n";
                return money;

            }       
        }
};
#endif
