/**
 * @file CreditCard.h
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project - Credit Card Rewards Calculator
**/

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class CreditCard{

    protected:
        string issuer;
        string rewardsType;
        string creditCardName;
        vector<double> transactionAmounts;
        vector<int> transactionTypes;

    public:
        CreditCard(string issuer, string rewardsType, string creditCardName);

        void setIssuer(string newIssuer);
        string getIssuer(){ return issuer;}

        void setRewardsType(string newRewardsType);
        string getRewardsType(){return rewardsType;}

        void setCreditCardName(string newCreditrCardName);
        string getCreditCardName(){ return creditCardName; }

        void setTransactionAmounts(vector<double> newTransactionAmounts);
        vector<double> getTransactionAmounts(){return transactionAmounts;}
        void addTransactionAmount(double newTransactionAmount);

        void setTransactionTypes(vector<int> newTransactionTypes);
        vector<int> getTransactionTypes(){return transactionTypes;}
        void addTransactionType(int newTransactionType);

        void addTransaction(double newTransactionAmounts, int newTransactionType);
        virtual double calculateRewards() = 0;
};


class WellsFargoAutograph: public CreditCard{

    public:
        WellsFargoAutograph(string issuer="Wells Fargo", string rewardsType="miles", string creditCardName="Wells Fargo Autograph");

        double calculateRewards();
};

#endif
