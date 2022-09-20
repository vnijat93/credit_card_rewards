/**
 * @file WellsFargoActiveCash.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

/**
 * Default constructor
*/
WellsFargoActiveCash::WellsFargoActiveCash(){}

/**
 * WellsFargoActiveCash Class constructor specifying issuer, rewardsType, and creditCardName.
 * 
*/
WellsFargoActiveCash::WellsFargoActiveCash(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

/**
 * Default destructor
*/
WellsFargoActiveCash::~WellsFargoActiveCash(){}

/**
 * A function to calculate total rewards earned from Wells Fargo Active Cash
 * @return totalRewards double, the total rewards amount earned in dollor.
*/
double WellsFargoActiveCash::calculateRewards(){

    // Instantiate a double to allocate rewards
    double totalRewards = 0;

    // All purchases earn 2% back
    for (double transactionAmount: transactionAmounts){
        totalRewards += (transactionAmount * 0.02);
    }

    return totalRewards;
}