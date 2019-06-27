//
//  CreditCard.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "CreditCard.h"

//INTEREST BASED ON FICO SCORE CALCULATOR
//Lower fico score = higher interest rate
void CreditAccount::setInterest(int s){
    float interest;
    if (s>=720){
        interest = .01;
    }
    else if(s>=690){
        interest = .03;
    }
    else if(s>=620){
        interest = .05;
    }
    else if(s>=300){
        interest = .07;
    }
    else interest= .10;
    Interest = interest;
}

//APPLIES INTEREST TO THE TOTAL
//Takes the balance user owes, applies interest, adds that value back into the total user owes
//If interest makes the balance negative, interest is not taken from account
//Notifies that Interest rate has been added to the total value owed
void CreditAccount::Finterest(){
    float nBal;
    nBal = Account::getBalance()*Interest;
    if (getBalance()+nBal>limit){
        nBal=0;
    }
    cout<<"Weekly interest of $"<<nBal<<" charged based on Fico score to Creditcard: " <<getAnum()<<endl;
    setBalance(getBalance()+nBal);
}

//CASHBACK CALCULATOR
//Takes the user input and adds the percentage of the user input the user gets back
//Notifies the user of Cashback amount
float CreditAccount::doubleCashBack(float input){
    float cBack;    //Keeps track of amount received during cashback;
    cBack = input*.01;
    cout<< "you have recieved $"<< cBack<<" in cashback\n";
    return cBack;
}

//CALCULATES THE MINIMUM PAYMENT
//User owes 5 percent of minimum balance towards minimum payment
//If 5 percent is less than $25, user owes $25
//Noties the user of minimum payment due
void CreditAccount::mPayment(){
    int payment;
    if (Account::getBalance()*.05>25){
        payment =Account::getBalance()*.05;
    }
    else if (Account::getBalance()>0){
        payment= 25;
    }
    cout<<"You need to pay a minimum payment of $"<<payment<<" on your credit card\n";
}
//SETS CREDIT CARD NUMBER
//Modifies the setAnum() function from account
//generates 4 four digit number greater than 1000,appends - to the end of first 3,appends the all the strings
void CreditAccount::setAnum(){
    string a,b,c,d;
    a= rGenerator()+"-";
    b= rGenerator()+"-";
    c= rGenerator()+"-";
    d= rGenerator();
    a+=b;
    a+=c;
    a+=d;
    Anum = a;
}

//MAIN CREDIT CARD FUNCTION
void CreditAccount::CreditCard(string name){
    string nName,action,nAnum;float nBal,pay,spent,owe;int score; //Initialized variables used for output
    cout<<"*********YOUR CREDIT LIMIT IS $1000*********\n";
    //Asks user for the Fico score, sets the interest
    //Changes state of iState using setInitial() to show that the function has been run once
    if (getInitial()==false) {
        cout<<"What is your credit score: ";
        cin>>score;
        setInterest(score);
        setInitial();
    }
    cout << "What do you want to do (s = spend, p = pay)";
    cin >> action;
    
    //If action value is s, spend part of the function is run
    if (action=="s"){
        cout<<"How much will you spend: ";
        cin >> spent;
        
        //sets the amount user owes as the users balance
        owe = Account::getBalance();
        
        //throws function user is spending more than their limit
        try {
            if (owe+spent>limit){
                throw spent;
            }
            Account::setName(name);
            nName = Account::getName(); //Assigns the Name on the account to this variable
            spent-= doubleCashBack(spent);
            owe+=spent; //Adds the spent value to the amount owed
            nBal = limit-owe;  //Assigns the balance on the account to this variable
            Account::setBalance(owe);  //Replaces the orginal value with the value that includes new withdrawl
            nAnum = Account::getAnum(); //Assigns the account number to this variable
            cout<< nName <<",you can still spend $" <<nBal<< " on the card " << nAnum<<"\n"; //ouput
            
        } catch (float num) {   //catch outputs how much the user can spend
            cout<< nName<<" you have only $"<< limit-owe << " to spend, please pay your balance to spend more\n";
        }
    }
    //if action value is p, pay part of the function is run
    else if (action=="p"){
        cout<<"How much will you pay: ";
        cin >> pay;
        //throws function is user is paying more than their limit or paying a negative value
        try {
            if (Account::getBalance()-pay<0){
                throw pay;
            }
            if (pay<0){
                throw pay;
            }
            Account::setName(name);
            owe = Account::getBalance();
            pay+= doubleCashBack(pay);
            owe-=pay; //Subtracts paid value from the value owed
            Account::setBalance(owe);  //Replaces the orginal value with the value that includes new deposit
            nName = Account::getName(); //Assigns the Name on the account to this variable
            nBal = limit-owe;   //Assigns the balance on the account to this variable
            nAnum = Account::getAnum(); //Assigns the account number to this variable
            cout<< nName <<" you can spend $" <<nBal<< " on the card " << Anum <<"\n "; //ouput
        }
        catch (float num) { //catches ouputs how much the user owes
            cout<<"Sorry you are paying less than 0 or over your limit\n";
            cout<<"You owe "<<Account::getBalance()<<"\n";
        }
        
    }
    else {
        cout<<"Sorry invalid input\n";
    }
    
}

