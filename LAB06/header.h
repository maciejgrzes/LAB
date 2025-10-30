#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef HEADER_INCLUDE

#define HEADER_INCLUDE

bool check(double temp, char unit);

double inputC();

double inputF();

double inputK();

double FtoC (double F);

double FtoK (double F);

double CtoF (double C);

double CtoK (double C);

double KtoC (double K);

double KtoF (double K);

void showMenu();

bool outOfRange(double temp);

void pressEnter();

void printVector(vector<string> data);

void showHistoryMenu();

void showHistoryEditMenu();

char inputScale();

char inputScaleToCalculate();

void calculateAndReplace(vector<string>& vec);

void generateRandomHistory(vector<string>& history, vector<string>& historyC, vector<string>& historyF, vector<string>& historyK);

#endif
