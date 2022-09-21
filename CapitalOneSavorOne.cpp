/**
 * @file CapitalOneSavorOne.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"

/**
 * Default constructor
*/
CapitalOneSavorOne::CapitalOneSavorOne(){}


/**
 * CapitalOneSavorOne Class constructor specifying issuer, rewardsType, and creditCardName.
 * 
*/
CapitalOneSavorOne::CapitalOneSavorOne(string isr, string rt, string ccn):CreditCard(isr, rt, ccn){}


/**
 * Default destructor
*/
CapitalOneSavorOne::~CapitalOneSavorOne(){}

/**
 * A function to calculate total rewards earned from Capital One Savor One
 * @return totalRewards double, the total rewards amount earned in dollor.
*/
double CapitalOneSavorOne::calculateRewards(){

    // Instantiate a double to allocate rewards
    double totalRewards = 0;

    // loop through the totalRewards list
    for (int i=0;i < transactionAmounts.size(); i++){

        // use the index to get each transaction amount and its corresponding
        // transaction type
        double transactionAmount = transactionAmounts[i];
        int transactionType = transactionTypes[i];

        // use transactionType to calcuate cash back on different categories
        switch (transactionType){

        // Restaurants, Streaming Service, and Groceries earn 3% back
        case (1 || 5 || 9):
            totalRewards += (transactionAmount * 0.03);
            break;
        
        // Entertainment earns 8% back
        case 8:
            totalRewards += (transactionAmount * 0.08);
            break;

        // Hotel earns 5%
        case 10:
            totalRewards += (transactionAmount * 0.05);
            break;

        // Rental earns 5%
        case 11:
            totalRewards += (transactionAmount * 0.05);
            break;
        
        // all other purchases earn 1%
        default:
            totalRewards += (transactionAmount * 0.01);
            break;
        }
    }

    return totalRewards;
}