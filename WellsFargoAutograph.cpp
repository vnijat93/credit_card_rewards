/**
 * @file WellsFargoAutograph.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

/**
 * Default constructor
*/
WellsFargoAutograph::WellsFargoAutograph(){}

/**
 * WellsFargoAutograph Class constructor specifying issuer, rewardsType, and creditCardName.
 * 
*/
WellsFargoAutograph::WellsFargoAutograph(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}

/**
 * Default destructor
*/
WellsFargoAutograph::~WellsFargoAutograph(){}

/**
 * A function to calculate total rewards earned from Wells Fargo Autograph
 * @return totalRewards double, the total rewards amount earned in dollor.
*/
double WellsFargoAutograph::calculateRewards(){

    // Instantiate a double to allocate rewards
    double totalRewards = 0;

    for (int i=0;i < transactionAmounts.size(); i++){

        // use the index to get each transaction amount and its corresponding
        // transaction type 
        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];

        switch (transactionType){

        // Restaurants, Travel, Gas, Transit, Streaming Service, and Phone Plans
        // earn 3X miles
        case (1 || 2 || 3 || 4 || 5 || 6):
            totalRewards += (transactionAmount * 3);
            break;
        
        // All other purchases make 1X miles
        default:
            totalRewards += (transactionAmount * 1);
            break;
        }
    }

    return totalRewards;
}
