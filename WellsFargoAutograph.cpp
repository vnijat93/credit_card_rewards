/**
 * @file WellsFargoAutograph.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

WellsFargoAutograph::WellsFargoAutograph(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

double WellsFargoAutograph::calculateRewards(){
    double totalRewards = 0;

    for (int i=0;i < transactionAmounts.size(); i++){
        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];
        switch (transactionType)
        {
        case (1 || 2 || 3 || 4 || 5 || 6):
            totalRewards += transactionAmount * 3;
            break;
        
        default:
            totalRewards += transactionAmount * 3;
            break;
        }
    }

    return totalRewards;
}
