#ifndef KURSACH2_INCORRECTLENGTHPASSWORD_H
#define KURSACH2_INCORRECTLENGTHPASSWORD_H
#include "MyException.h"

class InCorrectLengthPassword:public MyException{

public:
    InCorrectLengthPassword(string message){

        this->message = message;

    }

};

#endif //KURSACH2_INCORRECTLENGTHPASSWORD_H
