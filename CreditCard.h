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

/**
 * Implementation of the Credit Card Calculator.
 * 
 * A Credit class has five protected data members
 * - issuer: a string that represents the issuer of the credit card  
 * - rewardsType: a string that represents the rewards type. There are only two types
 *     of reward types, cash and miles.
 * - creditCardName: a string thats the name of the credit card
 * - transactionAmounts: a vector to store transaction amounts in double.
 * - transactionTypes: a vector to store transaction type. This application supports
 *    the following transaction types.
 *     | Transaction Type  | Number |
 *     | ----------------- | ------ |
 *     | Restaurants       | 1      |
 *     | Travel            | 2      |
 *     | Gas               | 3      |
 *     | Transit           | 4      |
 *     | Streaming Service | 5      |
 *     | Phone Plans       | 6      |
 *     | Paypal            | 7      |
 *     | Entertainment     | 8      |
 *     | Groceries         | 9      |
 *     | Hotel             | 10     |
 *     | Rental Car        | 11     |
 *     | Other             | 12     |
**/


class CreditCard{

    protected:
        /**< represents the issuer of the credit card */
        string issuer;

        /**< represents the rewards type. */
        string rewardsType;

        /**< represents the name of the credit card */
        string creditCardName;

        /**< used to store transaction amounts in double. */
        vector<double> transactionAmounts;

        /**< used to store transaction amounts in type. */
        vector<int> transactionTypes;

    public:

        /**
         * Default constructor
        */
        CreditCard();

        /**
         * Class constructor specifying issuer, rewardsType, and creditCardName
        */
        CreditCard(string issuer, string rewardsType, string creditCardName);

        /**
         * Default destructor
        */
        ~CreditCard();

        /**
         * @param newIssuer string, set the issuer to the given option.
        */
        void setIssuer(string newIssuer);

        /**
         * @return issuer string, the issuer.
        */
        string getIssuer(){ return issuer;}

        /**
         * @param newRewardsType string, set the rewardsType to the given option.
        */
        void setRewardsType(string newRewardsType);

        /**
         * @return rewardsType string, the problem type.
        */
        string getRewardsType(){return rewardsType;}

        /**
         * @param newCreditrCardName string, set the creditCardName to the given option.
        */
        void setCreditCardName(string newCreditrCardName);

        /**
         * @return creditCardName string, the name of the credit card.
        */
        string getCreditCardName(){ return creditCardName; }

        /**
         * @param newTransactionAmounts vector<double>, set the transactionAmounts
         *     to the given option.
        */
        void setTransactionAmounts(vector<double> newTransactionAmounts);

        /**
         * @return transactionAmounts vector<double>, the vector that stores
         *     transaction amounts in double
        */
        vector<double> getTransactionAmounts(){return transactionAmounts;}

        /**
         * @param newTransactionAmount double, add a new transaction amount to the
         *     transactionAmounts vector.
        */
        void addTransactionAmount(double newTransactionAmount);

        /**
         * @param newTransactionTypes vector<int>, set the transactionTypes
         *     to the given option.
        */
        void setTransactionTypes(vector<int> newTransactionTypes);

        /**
         * @return transactionAmounts vector<int>, the vector that stores
         *     transaction types in int
        */
        vector<int> getTransactionTypes(){return transactionTypes;}

        /**
         * @param newTransactionType int, add a new transaction type to the
         *     transactionTypes vector.
        */
        void addTransactionType(int newTransactionType);

        /**
         * Add a new transaction. Add the newTransactionAmount to the transactionAmounts
         *     vector and newTransactionType to the transactionTypes vector
         * @param newTransactionAmount double, a new transaction amount
         * @param newTransactionType int, a transaction type correspodning to the
         *     newTransactionAmount
        */
        void addTransaction(double newTransactionAmount, int newTransactionType);

        /**
         * Each child class will implement its own calculateRewards function to
         *    calculate rewards
         * @return totalRewards double, the total rewards calculated. This number's
         *     unit will be determined by the rewardsType.
        */
        virtual double calculateRewards() = 0;

        /**
         * A function to calculate total money spent on a credit card.
         * @return totalAmountSpent double, the total amount spent with a credit card.
        */
        double getTotalAmountSpent() const;
};


/**
 * WellsFargoAutograph class represents the Autograph credit card from wells fargo
 * Card holders earn miles.
*/
class WellsFargoAutograph: public CreditCard{

    public:
        WellsFargoAutograph();
        WellsFargoAutograph(string issuer, string rewardsType, string creditCardNam);
        ~WellsFargoAutograph();

        virtual double calculateRewards();
};


/**
 * WellsFargoActiveCash class represents the Activa Cash credit card from wells fargo
 * Card holders earn 2% cash back on all purchases.
*/
class WellsFargoActiveCash: public CreditCard{
    public:
        WellsFargoActiveCash();
        WellsFargoActiveCash(string issuer, string rewardsType, string creditCardNam);
        ~WellsFargoActiveCash();

        virtual double calculateRewards();
};


/**
 * DiscoverIT class represents the Discover it credit card from Discover
 * Card holders earn 5% cash back on selected categories.
*/
class DiscoverIT: public CreditCard{
    public:
        DiscoverIT();
        DiscoverIT(string issuer, string rewardsType, string creditCardNam);
        ~DiscoverIT();

        virtual double calculateRewards();
};


/**
 * CapitalOneSavorOne class represents the Savor One credit card from Capital One
 * Card holders earn up to 8% cash back on selected categories.
*/
class CapitalOneSavorOne: public CreditCard{
    public:
        CapitalOneSavorOne();
        CapitalOneSavorOne(string issuer, string rewardsType, string creditCardNam);
        ~CapitalOneSavorOne();

        virtual double calculateRewards();
};

#endif
