#ifndef KURSACH2_CONSTANTSFILE_H
#define KURSACH2_CONSTANTSFILE_H
#include <string>
using namespace std;

#define WrongNumberLength "You entered dont allow number! Please repeat enter!"

#define MobileNumberLength 13
#define PasportLength 9

#define ValidCountryCode "+375"
#define WrongCountryCode "You entered incorrect code. +375xxxxxxxxx"
const string validCodes[] = {"29", "33", "44", "25"};
#define WrongOperatorCode "You entered wrong operator code! ( 25 29 33 44 )"

#define WrongSymbols "You entered wrong symbols. Should be 0-9!"

#define WrongPasportLength "Length of passport dont correct! Please repeat enter"

const string ValidCountrySerial[] = {"MC" ,"AB", "BM", "HB" , "KH", "MP", "KB" };
#define WrongCountrySerial   "You entered wrong serial code! ( Good serial code: АВ ВМ НВ КН МР МС КВ )"


#endif //KURSACH2_CONSTANTSFILE_H
