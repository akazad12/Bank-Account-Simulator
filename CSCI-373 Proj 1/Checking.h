//
//  Checking.h
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#ifndef Checking_h
#define Checking_h
#include "Bank.h"

class CheckingAccount : public Bank{
public:
    void checking(string);  //Main checking function
    void weeklyFee();       //weekly Fee adder function
};


#endif /* Checking_h */
