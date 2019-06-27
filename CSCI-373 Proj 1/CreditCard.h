//
//  CreditCard.h
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#ifndef CreditCard_h
#define CreditCard_h
#include "Account.h"


class CreditAccount : public Account {
public:
    void CreditCard(string);    //Main Credit card program
    void setAnum(); //redefines virtual function to set Account number to credit card number
    void Finterest();   //Calculates the weekly interest charged based on Fico score and adds it to the balance
    void mPayment();    //Calculates the minimum payment due at the beginning of the a new week
private:
    int limit=1000; //Preset credit card limitd
    float Interest; //Stores interest rate on credit card
    float doubleCashBack(float);    //calculates the cashback
    void setInterest(int);  //Sets the interest based on user input for fico score

};


#endif /* CreditCard_h */
