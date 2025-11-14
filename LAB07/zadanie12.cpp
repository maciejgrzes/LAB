#include <iostream> 
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() { //kod 07_03
   double czas;
   clock_t start, koniec;

   start = clock(); //rozpoczecie odliczania czasu

   for (int i = 0; i < 10000; i++)
      cout << i << " ";

   koniec = clock();  //zakonczenie odliczania czasu
   czas = (double)(koniec - start) / CLOCKS_PER_SEC; //zwrocenie czasu dzialania
   cout << endl << endl << "Czas dzialania = " << czas << endl;

   return 0;
}
