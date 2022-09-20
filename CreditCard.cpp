/**
 * @file CreditCard.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"
#include <iostream>

using std::cout;;
using std::cin;
using std::endl;
using std::string;

/**
 * Default constructor
*/
CreditCard::CreditCard(){}


/**
 * Clacc constructor specifying issuer, rewardsType, and creditCardName
*/
CreditCard::CreditCard(string isr, string rt, string ccn){
    setIssuer(isr);
    setRewardsType(rt);
    setCreditCardName(ccn);
    vector<double> transactionAmounts;
    vector<int> transactionTypes;
}


/**
 * Default destructor
*/
CreditCard::~CreditCard(){}


/**
 * @return issuer string, the issuer.
*/
void CreditCard::setIssuer(string newIssuer){
    issuer = newIssuer;
}


/**
 * @param newRewardsType string, set the rewardsType to the given option.
*/
void CreditCard::setRewardsType(string newRewardsType){
    rewardsType = newRewardsType;
}


/**
 * @param newCreditrCardName string, set the creditCardName to the given option.
*/
void CreditCard::setCreditCardName(string newCreditCardName){
    creditCardName = newCreditCardName;
}


/**
 * @param newTransactionAmounts vector<double>, set the transactionAmounts
 *     to the given option.
*/
void CreditCard::setTransactionAmounts(vector<double> newTransactionAmounts){
    transactionAmounts = newTransactionAmounts;
}


/**
 * @param newTransactionAmount double, add a new transaction amount to the
 *     transactionAmounts vector.
*/
void CreditCard::addTransactionAmount(double newTransactionAmounts){
    // use push_back to increase the size dynamically
    transactionAmounts.push_back(newTransactionAmounts);
}


/**
 * @param newTransactionTypes vector<int>, set the transactionTypes
 *     to the given option.
*/
void CreditCard::setTransactionTypes(vector<int> newTransactionTypes){
    transactionTypes = newTransactionTypes;
}


/**
 * @param newTransactionType int, add a new transaction type to the
 *     transactionTypes vector.
*/
void CreditCard::addTransactionType(int newTransactionType){
    transactionTypes.push_back(newTransactionType);
}


/**
 * Add a new transaction. Add the newTransactionAmount to the transactionAmounts
 *     vector and newTransactionType to the transactionTypes vector
 * @param newTransactionAmount double, a new transaction amount
 * @param newTransactionType int, a transaction type correspodning to the
 *     newTransactionAmount
*/
void CreditCard::addTransaction(double newTransactionAmounts, int newTransactionType){
    addTransactionAmount(newTransactionAmounts);
    addTransactionType(newTransactionType);
}


/**
 * A function to calculate total money spent on a credit card.
 * @return totalAmountSpent double, the total amount spent with a credit card.
*/
double CreditCard::getTotalAmountSpent() const{
    double totalTransanctionAmount=0;
    for (double transanctionAmount: transactionAmounts){
        totalTransanctionAmount += transanctionAmount;
    }
    return totalTransanctionAmount;
}
