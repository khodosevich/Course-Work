#ifndef KURSACH2_PENSIONERTARIF_H
#define KURSACH2_PENSIONERTARIF_H
#include "Tarif.h"

class PensionerTarif : public Tarif{

private:
    string NameTarif = "Pensioner";
    double Price = 10;
    int minutes = 300;
    int internet = 2000;

public:

    string NameOfTarif() override{
        return NameTarif;
    }

    double Balance() override
    {
        return Price;
    }
    int MinBalance() override
    {
        return minutes;
    }

    int MbBalance() override
    {
        return internet;
    }


};



#endif //KURSACH2_PENSIONERTARIF_H
