#ifndef KURSACH2_INCORRECTOPENFILES_H
#define KURSACH2_INCORRECTOPENFILES_H
#include "MyException.h"

class InCorrectOpenFiles : public MyException {

public:

    InCorrectOpenFiles(string message){

        this->message = message;

    }

};

#endif
