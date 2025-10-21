#include <iostream>
#include <limits>
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

#endif
