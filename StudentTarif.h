#ifndef KURSACH2_STUDENTTARIF_H
#define KURSACH2_STUDENTTARIF_H
#include "Tarif.h"

class StudentTarif : public Tarif{

private:
    string NameTarif = "Student";
    double Price = 20;
    int minutes = 75;
    int internet = 25000;

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


#endif //KURSACH2_STUDENTTARIF_H
