//
//  Account.h
//  CSCI-373 Proj 1
//
//  Created by Abul Azad on 10/22/17.
//  Copyright © 2017 Azad. All rights reserved.
//

#ifndef Account_h
#define Account_h
#include <iostream>
using namespace std;

class Account {
public:
    string rGenerator();
    void setName(string); //Sets the name of the object
    virtual void setAnum(); //Sets the accout number of the object
    void setBalance(float);  //Sets the balance of the object
    string getName();   //Gets the name of the object
    string getAnum(); //Gets the account number of the object
    float getBalance();  //Gets the balance of the object
    bool getInitial();  //outputs the value of iState
    void setInitial();  //sets the value of iState to true
private:
    float AccountBalance;   //Variable for the Account Balance
    string name;//Variable for the user name
    bool iState=false;  //boolean variable to determine if program has been run once
protected:
    string Anum;   //Variable for Account number in protected for virtual members to access
    
};


#endif /* Account_h */
