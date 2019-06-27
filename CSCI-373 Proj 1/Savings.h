//
//  Savings.h
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#ifndef Savings_h
#define Savings_h
#include "Bank.h"

class SavingsAccount : public Bank{
public:
    void savings(string);   //Used to run the main Savings program
    void interest();    //Used to calculate the interest amount earned based on bank balance
};

#endif /* Savings_h */
