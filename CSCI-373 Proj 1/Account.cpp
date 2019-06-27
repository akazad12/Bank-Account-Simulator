//
//  Account.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <stdio.h>
#include "Account.h"
#include <iostream>
using namespace std;

//Sets the value of iState to true
void Account::setInitial(){
    iState=true;
}

//Sets the value of iState to true
bool Account::getInitial(){
    return iState;
}

//Sets the value of the name variable
void Account::setName(string n){
    name = n;
}

//Sets the value of the account number using a random number generator
//generates two numbers using the random number generator and appends them for 8 digit number
void Account::setAnum(){
    string a,b;
    a = rGenerator();
    b= rGenerator();
    a+=b;
    Anum = a;
}

//Sets the value of the AccountBalance variable
void Account::setBalance(float b){
    AccountBalance = b;
}

//Returns the value of the name variable
string Account::getName(){
    return name;
}

//Returns the value of the account number variable
string Account::getAnum(){
    return Anum;
}

//Returns the value of the AccountBalance variable
float Account::getBalance(){
    return AccountBalance;
}
//RANDOM NUMBER GENERATOR
//returns a random number between 1000 & 9999
string Account::rGenerator(){  
    string num;
    num = to_string(rand()%9999 + 1000);
    return (num);
}
