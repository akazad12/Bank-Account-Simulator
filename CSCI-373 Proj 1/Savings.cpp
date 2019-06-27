//
//  Savings.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Savings.h"
using namespace std;

//Calculates the interest, adds it to the total, notifies the user of the interest
void SavingsAccount::interest(){
    float interest,nint;
    interest =Account::getBalance()*.01;    //interest for savings account is 1%
    nint = Account::getBalance()+interest;   //adds the weekly interest to the total balance
    //to the value of the account multiplied
    //by the interest amount
    setBalance(nint);   //sets the account balance to orginial amount plus interest
    cout<< "Weekly interest of $"<<interest<<" added to your savings account: " <<getAnum()<<endl;
}

//MAIN SAVINGS FUNCTION
//Asks user the depsit amount and if it is greater than 0, it is added to the total balance
//If input is less than 0, try and catch block is executed
void SavingsAccount::savings(string name){
    string nName,nAnum;float nBal,deposit; //Initialized variables used for output
    cout <<"How much are you depositing: ";
    cin >> deposit;
    try {
        if (deposit<0){
            throw deposit;
        }
        setInitial();
        Account::setName(name); //Sets the name of the account by accessing private data member in Account
        Bank::setCredit(deposit);   //Sets the deposit amount by accessing private data member in bank
        nBal = Account::getBalance()+Bank::getCredit(); //Adds the deposit value to the totoal bank balance
        Account::setBalance(nBal);  //Replaces the orginal value with the value that includes new deposit
        nName = Account::getName(); //Assigns the Name on the account to this variable
        nBal = Account::getBalance();   //Assigns the balance on the account to this variable
        nAnum = Account::getAnum(); //Assings the account number to this variable
        cout<< nName <<" you have a balance of $" <<nBal<< " in the account "<<nAnum<<"\n"; //ouput
    }
    catch(float error){
        cout<<"Please enter a number greater than 0\n";
    }
    
}

