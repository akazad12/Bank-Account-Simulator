//
//  Checking.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <stdio.h>
#include "Checking.h"

//Applies weekly fee to the total checking balance if account balance is greater than 15
//Tells the user the weekly fee charged
void CheckingAccount::weeklyFee(){
    if (Account::getBalance()>15){
        Account::setBalance(Account::getBalance()-15);
        cout<<"Weekly fee of $15 taken from your checking account: "<<getAnum()<<endl;
    }
}

//MAIN CHECKING FUNCION
void CheckingAccount::checking(string name){
    string nName,action,nAnum;float nBal,deposit,withdrawl; //Initialized variables used for output
    cout << "What do you want to do (d = deposit, w = withdrawl): ";
    cin >> action;  //Obtains whether user wants to deposit or withdrawl
    
//If user is depositing, the deposit amount is added to the users total balance
//Tells user the total balance after deposit has been made
    if (action == "d"){
        cout <<"How much are you depositing: ";
        cin >> deposit;
        if (deposit>=0){        //Program only runs if input is greater than zero
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
    }
    
//If user is withdrawing, the withdrawl amount is subtracted from the users balance
//Tells user the total balancce after withdrawl has been made
    else if(action == "w"){
        cout << "How much are you withdrawing? ";
        cin >> withdrawl;
//Try block used to catch if user input is greater than total balance in account
        try  {
            if(withdrawl>getBalance()){
                throw withdrawl;
            }
            if (withdrawl>=0){  //Program only runs if input is greater than zero, but less than the total balance
            setInitial();
            Account::setName(name); //Sets the name of the account by accessing private data member in Account
            Bank::setDebit(withdrawl);   //Sets the withdrawl amount by accessing private data member in bank
            nBal = Account::getBalance()-Bank::getDebit(); //Adds the withdrawl value to the total bank balance
            Account::setBalance(nBal);  //Replaces the orginal value with the value that includes new withdrawl
            nName = Account::getName(); //Assigns the Name on the account to this variable
            nBal = Account::getBalance();   //Assigns the balance on the account to this variable
            nAnum = Account::getAnum(); //Assings the account number to this variable
            cout<< nName <<" you have a balance of $" <<nBal<< " in the account "<<nAnum<<"\n"; //ouput
            }
        }
        catch(float w){
            cout<<"Sorry you cannot withdrawl more than your balance of $"<<getBalance()<<endl;
        }
    }
    
}

