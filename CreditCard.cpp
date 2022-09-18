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

CreditCard::CreditCard(){}

CreditCard::CreditCard(string isr, string rt, string ccn){
    setIssuer(isr);
    setRewardsType(rt);
    setCreditCardName(ccn);
    vector<double> transactionAmounts;
    vector<int> transactionTypes;
}

CreditCard::~CreditCard(){}

void CreditCard::setIssuer(string newIssuer){
    issuer = newIssuer;
}

void CreditCard::setRewardsType(string newRewardsType){
    rewardsType = newRewardsType;
}

void CreditCard::setCreditCardName(string newCreditCardName){
    creditCardName = newCreditCardName;
}

void CreditCard::setTransactionAmounts(vector<double> newTransactionAmounts){
    transactionAmounts = newTransactionAmounts;
}

void CreditCard::addTransactionAmount(double newTransactionAmounts){
    transactionAmounts.push_back(newTransactionAmounts);
}

void CreditCard::addTransactionType(int newTransactionType){
    transactionTypes.push_back(newTransactionType);
}

void CreditCard::addTransaction(double newTransactionAmounts, int newTransactionType){
    addTransactionAmount(newTransactionAmounts);
    addTransactionType(newTransactionType);
}

double CreditCard::getTotalAmountSpent() const{
    double totalTransanctionAmount=0;
    for (double transanctionAmount: transactionAmounts){
        totalTransanctionAmount += transanctionAmount;
    }
    return totalTransanctionAmount;
}
