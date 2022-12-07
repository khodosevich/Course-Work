#ifndef KURSACH2_TARIF_H
#define KURSACH2_TARIF_H
#include <iomanip>
using namespace std;

class Tarif
{

protected:
    string NameTarif;
    double Price;
    int minutes;
    int internet;

public:

    string virtual NameOfTarif() = 0;
    double virtual Balance() = 0;
    int virtual MinBalance() = 0;
    int virtual MbBalance() = 0;


};


#endif //KURSACH2_TARIF_H
