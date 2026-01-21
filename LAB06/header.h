#include <iostream>
#include <optional>
#include <vector>
#include <string>
using namespace std;
#ifndef HEADER_INCLUDE

#define HEADER_INCLUDE

enum class Unit { Kelvin, Celsius, Fahrenheit };

struct Entry {
    double before;
    Unit unitBefore;
    double after;
    Unit unitAfter;
};


string unitToString(Unit u);

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

void printVector(const vector<Entry>& history, optional<Unit> filter = nullopt);

void showHistoryMenu();

void showHistoryEditMenu();

char inputScale();

char inputScaleToCalculate();

void calculateAndReplace(vector<Entry>& history);

void generateRandomHistory(vector<Entry>& history);

#endif
