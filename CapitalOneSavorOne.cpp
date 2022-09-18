/**
 * @file CapitalOneSavorOne.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

CapitalOneSavorOne::CapitalOneSavorOne(){}

CapitalOneSavorOne::CapitalOneSavorOne(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

CapitalOneSavorOne::~CapitalOneSavorOne(){}

double CapitalOneSavorOne::calculateRewards(){

    double totalRewards = 0;

    for (int i=0;i < transactionAmounts.size(); i++){

        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];

        switch (transactionType)
        {
        case (1 || 5 || 9):
            totalRewards += (transactionAmount * 0.03);
            break;
        
        case 8:
            totalRewards += (transactionAmount * 0.08);
            break;

        case 10:
            totalRewards += (transactionAmount * 0.05);
            break;

        case 11:
            totalRewards += (transactionAmount * 0.05);
            break;
        
        default:
            totalRewards += (transactionAmount * 0.01);
            break;
        }
    }

    return totalRewards;
}