#ifndef KURSACH2_OTHERFUNCTIONALITY_H
#define KURSACH2_OTHERFUNCTIONALITY_H

bool numberValidation(string number) {


    if (number.length() != MobileNumberLength) {

        cout << endl << WrongNumberLength << endl;

        return false;
    }

    string countryCode = "0000";

    for (int i = 0; i < 4; i++)
        countryCode[i] = number[i];

    if (countryCode != ValidCountryCode) {

        cout << endl << WrongCountryCode << endl;

        return false;
    }

    string operatorCode = "00";
    operatorCode[0] = number[4];
    operatorCode[1] = number[5];

    bool validOperatorCodeFlag = false;

    for (int n = 0; n < sizeof(validCodes)/sizeof(string); n++) {
        if (operatorCode == validCodes[n]) {
            validOperatorCodeFlag = true;
            break;
        }
    }


    if (!validOperatorCodeFlag) {

        cout << endl << WrongOperatorCode << endl;


        return false;
    }

    for (int n = 6; n < number.length(); n++) {
        if (number[n] > '9' || number[n] < '0') {

            cout << endl << WrongSymbols << endl;

            return false;
        }
    }

    return true;
}


bool pasportValidation(string pasportID) {


    string countrySerial = "00";

    for (int i = 0; i < 2; i++)
        countrySerial[i] = pasportID[i];

    bool validOperatorSerialFlag = false;

    for (int n = 0; n < sizeof(ValidCountrySerial)/sizeof(string); n++) {

        if (countrySerial == ValidCountrySerial[n]) {
            validOperatorSerialFlag = true;
            break;
        }
    }

    if (!validOperatorSerialFlag) {

        cout << endl << WrongCountrySerial << endl;

        return false;
    }


    if (pasportID.length() != PasportLength) {

        cout << endl << WrongPasportLength << endl;

        return false;
    }



    for (int n = 2; n < pasportID.length(); n++) {
        if (pasportID[n] > '9' || pasportID[n] < '0') {

            cout << endl << WrongSymbols << endl;

            return false;
        }
    }

    return true;
}

void PrintViewClient(){
    cout
            << "-----------------------------------------------------------------------------------------------------------------"
            << endl;
    cout
            << "|           Client          | Age |  Pasport  |        Residence         |     Number    |   Tarif   |  Balance |"
            << endl;
    cout
            << "-----------------------------------------------------------------------------------------------------------------"
            << endl;

}

#endif //KURSACH2_OTHERFUNCTIONALITY_H
