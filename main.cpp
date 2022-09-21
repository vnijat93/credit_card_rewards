/**
 * @file main.cpp
 * @author: Varis Nijat
 * CIS 554-M401 Object Oriented Programming in C++
 * Syracuse University
 * Final Project -  Credit Card Rewards Calculator
**/

#include "CreditCard.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::tolower;
using std::setw;
using std::setprecision;
using std::fixed;


// Helper function prototypes
void printBannerMessage();
void recordTransactions(CreditCard *);
void recordOwnership(CreditCard &, vector<CreditCard*> &);
void displaySummary(vector<CreditCard*> &);


int main(){

    // Print banner message and display useful information.
    printBannerMessage();

    // instantiate a vector for storing pointers from base class to derived class
    vector<CreditCard*> creditcardPrts;

    // instantiate a WellsFargoAutograph object
    WellsFargoAutograph wfa("Wells Fargo", "Miles", "Wells Fargo Autograph");
    // instantiate a WellsFargoActiveCash object
    WellsFargoActiveCash wfac("Wells Fargo", "Cash", "Wells Fargo Active Cash");
    // instantiate a DiscoverIT object
    DiscoverIT dit("Discover", "Cash", "Discover it");
    // instantiate a CapitalOneSavorOne object
    CapitalOneSavorOne coso ("Capital One", "Cash", "Capital One Savor One");

    // ask users if they own the listed credit cards.
    // if they to record their transaction amount and types
    recordOwnership(wfa, creditcardPrts);
    recordOwnership(wfac, creditcardPrts);
    recordOwnership(dit, creditcardPrts);
    recordOwnership(coso, creditcardPrts);

    // display rewords summary
    displaySummary(creditcardPrts);

    return 0;
}


/**
 * A function to display rewords summary.
 * Note that only credit cards owned by a user will be displayed
 * @param ccPtrs vector<CreditCard*>, reference to the credit card pointers vector
*/
void displaySummary(vector<CreditCard*> &ccPtrs){

    // cout some headers and set precisions
    cout << "\n\nRewards Summary: \n\n";
    cout << fixed;
    cout << setprecision(2);

    cout << left << setw(32) << "Credit Card Name"
         << left << setw(16) << "Amount Spent"
         << left << setw(16) << "Cash Earnd" 
         << left << setw(16)<< "Miles Earned"<< endl;

    // instantiate doubles to record totalAmountSpent, totalCashEarned, and 
    // totalMilesEarned. These will also be displayed
    double totalAmountSpent = 0;
    double totalCashEarned = 0;
    double totalMilesEarned = 0;

    // loop through the for loop and calculate the rewards earned and money spent
    for(auto ccptr: ccPtrs){

        // accumulate totalAmountSpent
        totalAmountSpent += ccptr->getTotalAmountSpent();

        // if the credit card rewards type is "Cash", skip Miles column
        if (ccptr->getRewardsType() == "Cash"){
            cout << left << setw(32) << ccptr->getCreditCardName()
                 << left << setw(16) << ccptr->getTotalAmountSpent()
                 << left << setw(16) << ccptr->calculateRewards()
                 << left << setw(16) << " "
                 << endl;
            // accumulate total cash earned
            totalCashEarned += ccptr->calculateRewards();
        }

        // if the credit card rewards type is "Miles", skip Cash column
        if (ccptr->getRewardsType() == "Miles"){
            cout << left << setw(32) << ccptr->getCreditCardName()
                 << left << setw(16) << ccptr->getTotalAmountSpent()
                 << left << setw(16) << " "
                 << left << setw(16) << ccptr->calculateRewards()
                 << endl;

            // accumulate total miles earned
            totalMilesEarned += ccptr->calculateRewards();
        }
    }

    // display totals of each category
    cout << left << setw(32) << "Total" 
         << left << setw(16) << totalAmountSpent 
         << left << setw(16) << totalCashEarned
         << left << setw(16) << totalMilesEarned
         << "\n\n"
         << endl;
}


/**
 * A function to capture user input. Ask user if they own the provided credit cards.
 * If they do, ask them to enter transaction type and amount
 * Note that only credit cards owned by a user will be displayed
 * @param cc CreditCard, reference to any derived class of CreditCard
 * @param ccPtrs vector<CreditCard*>, reference to the credit card pointers vector
*/
void recordOwnership(CreditCard &cc, vector<CreditCard*> &ccPtrs){

    // capture user input
    cout << "Do you own a " << cc.getCreditCardName() << " ?(y/n)";
    char ifOwns = 'y';
    cin >> ifOwns;

    // if they do own the list credit card, ask them to enter transactions that
    // will be used to calculate rewards
    if (tolower(ifOwns) == 'y'){

        // instantiate a base class pointer
        CreditCard *tempPtr = nullptr;

        // pointe the base class pointer to derived class.
        tempPtr = &cc;

        // record user's transactions
        recordTransactions(tempPtr);

        // add the baseclass pointer to the ccPtrs.
        ccPtrs.push_back(tempPtr);
    }
    
}


/**
 * A function to capture transaction amount and type.
 * @param ccPtr CreditCard pointer, baseclass pointer
*/
void recordTransactions(CreditCard *ccPtr){

    // Assume a user has more transactions to report
    char hasMoreTransactions = 'y';
    while (hasMoreTransactions == 'y'){

        // Ask user to enter transaction type and store it in txnType
        cout << "Please enter transaction type: ";
        int txnType = 0;
        cin >>txnType;

        // Ask user to enter transaction amount and store it in txnAmount
        cout << "Please enter transaction Amount: ";
        double txnAmount = 0;
        cin >> txnAmount;

        // add the transaction
        ccPtr->addTransaction(txnAmount, txnType);

        // ask user if they have more transactions to report
        cout << "\nDo you have more transactions to report?(y/n)";
        cin >> hasMoreTransactions;
    }
}


// function to print banner message
void printBannerMessage(){
    // Print out banner message
    cout << endl;
    cout << left;
    cout << "********************************************************\n"
         << "Use this credit card rewards calculator to calculate rewards "
         << "across all your credit cards. Use the following prompt to enter "
         << "your transaction details.\n";
    cout << "********************************************************\n\n";
}
