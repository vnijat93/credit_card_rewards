/**
 * @file WellsFargoActiveCash.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

WellsFargoActiveCash::WellsFargoActiveCash(){}

WellsFargoActiveCash::WellsFargoActiveCash(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

WellsFargoActiveCash::~WellsFargoActiveCash(){}

double WellsFargoActiveCash::calculateRewards(){

    double totalRewards = 0;

    for (double transactionAmount: transactionAmounts){
        totalRewards += (transactionAmount * 0.02);
    }

    return totalRewards;
}