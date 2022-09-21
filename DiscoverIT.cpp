/**
 * @file DiscoverIT.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

/**
 * Default constructor
*/
DiscoverIT::DiscoverIT(){}


/**
 * DiscoverIT Class constructor specifying issuer, rewardsType, and creditCardName.
 * 
*/
DiscoverIT::DiscoverIT(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}


/**
 * Default destructor
*/
DiscoverIT::~DiscoverIT(){}


/**
 * A function to calculate total rewards earned from Discover IT
 * @return totalRewards double, the total rewards amount earned in dollor.
*/
double DiscoverIT::calculateRewards(){

    // Instantiate a double to allocate rewards
    double totalRewards = 0;

    for (int i=0;i < transactionAmounts.size(); i++){

        // use the index to get each transaction amount and its corresponding
        // transaction type
        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];

        switch (transactionType){

        // Restaurants and Paypal earns 5% back.
        case (1 || 7):
            totalRewards += (transactionAmount * 0.05);
            break;
        
        // All other purchases earn 1% back.
        default:
            totalRewards += (transactionAmount * 0.01);
            break;
        }
    }

    return totalRewards;
}