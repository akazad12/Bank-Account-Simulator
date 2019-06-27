//
//  main.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/17/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <iostream>
#include <time.h>   //Used for Random number generator
#include <unistd.h> //Used for sleep function
#include "Account.h"    //Header files of all the classes
#include "Bank.h"
#include "CreditCard.h"
#include "Savings.h"
#include "Checking.h"
using namespace std;



int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));   //Used to generate random number
    string name,account_type;
    int tCount=0;   //initializes tCount to keep track of the day
    cout << "What is your name: ";
    cin >> name;
    SavingsAccount savings_account;        //Creates Saving account object
    savings_account.setAnum();             //Assigns a account number to this object
    CheckingAccount obj2;       //Creates a Checking account object
    obj2.setAnum();             //Assigns account number to this object
    CreditAccount obj3;         //Creates a Credit Card object
    obj3.setAnum();             //Assigns a credit card number to this account
    
    while (account_type!= "q"){ //Program ends when user enters q
    //Displays messages at the beginning of the week after user creates the account
    //Week is denoted as user accessing the accounts a total of 3 times
        if (tCount%3==0 && tCount>1){
            usleep(1111111);    //Program pauses to demonstrate change in week
            cout<<"******************Its a new week!******************"<<endl;
            if(savings_account.getInitial()==true){     //Calculates interest in savings account
                savings_account.interest();             //only if object is accessed 1 or more times
            }
            if(obj2.getInitial()==true){                //Calculates weekly fee in checking account
                obj2.weeklyFee();                       //only if object is accessed 1 or more times
            }
            if (obj3.getInitial()==true){               //Tells users minimum balance due and interest
                obj3.mPayment();                        //based on user input for fico score
                obj3.Finterest();
            }
        }
        //******************************************************************//
        //Main program is run here
        cout << "******************TO EXIT ENTER q ******************\n";
        cout << "What type of account are you accessing ";
        cout << "(x = credit, c = checking, s = saving): ";
        cin >>account_type;
        if (account_type== "s"){            //Runs if user input is s
            cout<< "*********YOU CAN ONLY DEPOSIT IN SAVINGS*********\n";
            savings_account.savings(name);  //Runs the main Savings function for savings object
            tCount++;                       //incrementor used to keep track of days of the week
        }
        else if (account_type== "c"){       //Runs if user input is c
            obj2.checking(name);            //Runs the main Checking function for the checking object
            tCount++;                       //incrementor used to keep track of days of the week
        }
        else if (account_type== "x"){       //Runs if user input is x
            obj3.CreditCard(name);          //Runs the main CreditCard function for the CreditCredit object
            tCount++;                       //incrementor used to keep track of days of the week
        }
    }
    
    return 0;
}
