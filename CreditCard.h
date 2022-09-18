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

        CreditCard();
        CreditCard(string issuer, string rewardsType, string creditCardName);
        ~CreditCard();

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

        double getTotalAmountSpent() const;
};

class WellsFargoAutograph: public CreditCard{

    public:
        WellsFargoAutograph();
        WellsFargoAutograph(string issuer, string rewardsType, string creditCardNam);
        ~WellsFargoAutograph();

        virtual double calculateRewards();
};

class WellsFargoActiveCash: public CreditCard{
    public:
        WellsFargoActiveCash();
        WellsFargoActiveCash(string issuer, string rewardsType, string creditCardNam);
        ~WellsFargoActiveCash();

        virtual double calculateRewards();
};

class DiscoverIT: public CreditCard{
    public:
        DiscoverIT();
        DiscoverIT(string issuer, string rewardsType, string creditCardNam);
        ~DiscoverIT();

        virtual double calculateRewards();
};

class CapitalOneSavorOne: public CreditCard{
    public:
        CapitalOneSavorOne();
        CapitalOneSavorOne(string issuer, string rewardsType, string creditCardNam);
        ~CapitalOneSavorOne();

        virtual double calculateRewards();
};

#endif
