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
using std::setfill;

void printBannerMessage();
void recordTransactions(CreditCard *);
void recordOwnership(CreditCard &, vector<CreditCard*> &);
void displaySummary(vector<CreditCard*> &);


int main(){

    printBannerMessage();

    vector<CreditCard*> creditcardPrts;

    WellsFargoAutograph wfa("Wells Fargo", "Miles", "Wells Fargo Autograph");
    WellsFargoActiveCash wfac("Wells Fargo", "Cash", "Wells Fargo Active Cash");
    DiscoverIT dit("Discover", "Cash", "Discover it");
    CapitalOneSavorOne coso ("Capital One", "Cash", "Capital One Savor One");

    recordOwnership(wfa, creditcardPrts);
    recordOwnership(wfac, creditcardPrts);
    recordOwnership(dit, creditcardPrts);
    recordOwnership(coso, creditcardPrts);

    displaySummary(creditcardPrts);

    return 0;
}

void displaySummary(vector<CreditCard*> &ccPtrs){
    cout << "Rewards Summary: \n";
    cout << fixed;
    cout << setprecision(2);

    cout << left << setw(32) << "Credit Card Name"
         << left << setw(16) << "Amount Spent"
         << left << setw(16) << "Cash Earnd" 
         << left << setw(16)<< "Miles Earned"<< endl;

    double totalAmountSpent = 0;
    double totalCashEarned = 0;
    double totalMilesEarned = 0;

    for(auto ccptr: ccPtrs){
        totalAmountSpent += ccptr->getTotalAmountSpent();
        if (ccptr->getRewardsType() == "Cash"){
            cout << left << setw(32) << ccptr->getCreditCardName()
                 << left << setw(16) << ccptr->getTotalAmountSpent()
                 << left << setw(16) << ccptr->calculateRewards()
                 << left << setw(16) << " "
                 << endl;
            totalCashEarned += ccptr->calculateRewards();
        }
        if (ccptr->getRewardsType() == "Miles"){
            cout << left << setw(32) << ccptr->getCreditCardName()
                 << left << setw(16) << ccptr->getTotalAmountSpent()
                 << left << setw(16) << " "
                 << left << setw(16) << ccptr->calculateRewards()
                 << endl;
            totalMilesEarned += ccptr->calculateRewards();
        }
    }
    cout << left << setw(32) << "Total" 
         << left << setw(16) << totalAmountSpent 
         << left << setw(16) << totalCashEarned
         << left << setw(16) << totalMilesEarned
         << endl;
}

void recordOwnership(CreditCard &cc, vector<CreditCard*> &ccPtrs){
    cout << "Do you own a " << cc.getCreditCardName() << " ?(y/n)";
    char ifOwns = 'y';
    cin >> ifOwns;

    if (tolower(ifOwns) == 'y'){

        CreditCard *tempPtr = nullptr;
        tempPtr = &cc;
        recordTransactions(tempPtr);
        ccPtrs.push_back(tempPtr);
    }
    
}

void recordTransactions(CreditCard *ccPtr){
    char hasMoreTransactions = 'y';
    while (hasMoreTransactions == 'y'){
        cout << "Please enter transaction type: ";
        int txnType = 0;
        cin >>txnType;

        cout << "Please enter transaction Amount: ";
        double txnAmount = 0;
        cin >> txnAmount;

        ccPtr->addTransaction(txnAmount, txnType);

        cout << "Do you have more transactions to report?(y/n)";
        cin >> hasMoreTransactions;
    }
}

void printBannerMessage(){
    // Print out banner message
    cout << endl;
    cout << left;
    cout << "********************************************************\n"
         << "Use this credit card rewards calculator to calculate rewards "
         << "across all your credit cards. Use the following prompt to enter "
         << "your transaction details.";
    cout << "********************************************************\n\n";
}
