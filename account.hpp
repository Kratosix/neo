#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <random>
#include <vector>
#include <fstream>

namespace account{
    class Account{
        private:
            std::string m_account_name;
            int m_account_number;
            std::string m_bitcoin_address;
            std::string m_ethereum_address;
            double m_amount;

        public:
            double getAmount(){
                return m_amount;
            }

            std::string getName(){
                return m_account_name;
            }
            int getAccountNumber(){
                return m_account_number;
            }
            
        public:
            Account(std::string account_name="None", int account_number=00000, std::string bitcoin_address="0000-0000-000", std::string ethereum_address="000-000-0000" ,double amount=0.000):
                m_account_name(account_name), m_account_number(account_number), m_bitcoin_address(bitcoin_address), m_ethereum_address(ethereum_address), m_amount(amount)
        {
        }

        friend std::ostream& operator<<(std::ostream& out,const Account& g);
        friend std::istream& operator>>(std::istream& in, Account& g);
    };

    std::ostream& operator<<(std::ostream& out,const Account& g){
        out<<"--This is the current info of your account\n";
        out<<"--Account name--> "<<g.m_account_name<<"\n";
        out<<"--Account number--> "<<g.m_account_number<<"\n";
        out<<"--Bitcoin address--> "<<g.m_bitcoin_address<<"\n";
        out<<"--Ethereuem address-->"<<g.m_ethereum_address<<"\n";
        out<<"--Amount you have --> "<<g.m_amount<<"\n";

        return out;
    }

    std::istream& operator>>(std::istream& in, Account& g){
        std::cout<<"Enter account name\n";
        in>>g.m_account_name;
        std::cout<<"Enter account number\n";
        in>>g.m_account_number;
        std::cout<<"Enter custom bitcoin address\n";
        in>>g.m_bitcoin_address;
        std::cout<<"Enter custom ethereum address\n";
        in>>g.m_ethereum_address;

        return in;
    }

    void prices(){
        std::cout<<"-------These are the prices of bitcoin and ethereum-----\n";
        double bitcoin = 30136.00;
        double eth = 1883.65;

        std::cout<<"---Bitcoin:[USD] --> "<<bitcoin<<"\n";
        std::cout<<"--Ethereum:[USD] --> "<<eth<<"\n";
    }

    namespace infos{
        void get_info(Account& acc){
            std::cout<<acc;
        }

        void create_account(){
            Account acc;
            std::cin>>acc;

            std::ofstream file("accounts.txt");

            if(!file){
                std::cerr<<"Failed to load and use file\n";
            }
            
            file<<"------------Account Information-----------------------\n";
            file<<acc;
            file<<"---------------------------------------\n";
        }

        int login_account(){
            Account ac;
            int acc_no = ac.getAccountNumber();
            
            std::cout<<"Enter account number\n";
            std::cin>>acc_no;

            std::cout<<"Enter account name\n";

            std::string acc_name = ac.getName();
            std::cin>>acc_name;
            
            std::ifstream my_file("accounts.txt");
            if(!my_file){
                std::cerr<<"Failed to load\n";
                return 1;
            }

            std::string line;
            int offset;
            //These lines had me crazy, Had to search for 3 days for a proper answer so I end up with this one

            while(my_file){
                std::getline(my_file, line);
                if((offset=line.find(acc_name, 0)) != std::string::npos){
                    std::cout<<"LOGGED IN\n";

                }
            }
        
            return 0;

        }

    }
}
#endif
