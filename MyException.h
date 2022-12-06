#ifndef KURSACH2_MYEXCEPTION_H
#define KURSACH2_MYEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;

class MyException:public exception{

public:


    static void TypeErrorInt(){
        cout << endl << "Введен тип не Int.." << endl;
        exit(1);
    }


};

#endif //KURSACH2_MYEXCEPTION_H
