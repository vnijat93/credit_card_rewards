/**
 * @file DiscoverIT.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

DiscoverIT::DiscoverIT(){}

DiscoverIT::DiscoverIT(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

DiscoverIT::~DiscoverIT(){}

double DiscoverIT::calculateRewards(){

    double totalRewards = 0;

    for (int i=0;i < transactionAmounts.size(); i++){

        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];

        switch (transactionType)
        {
        case (1 || 7):
            totalRewards += (transactionAmount * 0.05);
            break;
        
        default:
            totalRewards += (transactionAmount * 0.01);
            break;
        }
    }

    return totalRewards;
}