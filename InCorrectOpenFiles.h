#ifndef KURSACH2_INCORRECTOPENFILES_H
#define KURSACH2_INCORRECTOPENFILES_H
#include "MyException.h"

class InCorrectOpenFiles:public MyException {

    InCorrectOpenFiles(string message){

        this->message = message;

    }

};

#endif //KURSACH2_INCORRECTOPENFILES_H
