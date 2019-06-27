//
//  Bank.cpp
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#include <stdio.h>
#include "Bank.h"
#include <iostream>

//Sets the value of the routing number variable
void Bank::setRnum(int routing_num){
    Rnum = routing_num;
}

//Sets the value of the Credit variable
void Bank::setCredit(float deposit){
    Credit = deposit;
}

//Sets the value of the Debit variable
void Bank::setDebit(float withdrawl){
    Debit = withdrawl;
}

//outputs the value of the routing number
int Bank::getRnum(){
    return Rnum;
}

//ouputs the value of the Credit variable
float Bank::getCredit(){
    return Credit;
}

//ouputs the value of the Debit variable
float Bank::getDebit(){
    return Debit;
}
