//
//  Bank.h
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#ifndef Bank_h
#define Bank_h
#include "Account.h"


class Bank : public Account{
public:
    void setRnum(int); //Sets the Routing number of the bank
    void setCredit(float);   //Adds the deposit to the total
    void setDebit(float);    //Subtracts the withdrawl from the total
    int getRnum();   //Retrieves the routing number of the bank
    float getCredit(); //Retrieves the credited amount to the account
    float getDebit();  //Retrieves the debited amount to the account
private:
    int Rnum;   //Variable for Routing number
    float Credit;   //Variable for Credited amount
    float Debit;    //Variable for debited amount
};



#endif /* Bank_h */
