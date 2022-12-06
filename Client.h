#ifndef KURSACH2_CLIENT_H
#define KURSACH2_CLIENT_H
#include "Tarif.h"
#include "Drive20Tarif.h"
#include "Drive5Tarif.h"
#include "PlusTarif.h"
#include "StudentTarif.h"
#include "PensionerTarif.h"
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;


class Client {

private:
    string FirstName;
    string LastName;
    int Age;
    string Pasport;
    string Residence;
    string NameTarif;
    string Number;
    double BalanceAccount;

public:
    Tarif *tarif;


    Client() {
        FirstName = "empty";
        LastName = "empty";
        Age = 0;
        Pasport = "empty";
        Residence = "empty";
        NameTarif = "empty";
        Number = "empty";
        BalanceAccount = 0;
    }

    ~Client() {}


    void CreateClient(Client &person1) {

        string tarif;

        cout << "Creating new client:" << endl;

        person1.SetClient();

        cout << endl << endl;
        cout << "Choice tarif:" << endl;

        AllTarif();

        while (true) {
            person1.setTarif();
            break;
        }

    }

    void AllTarif(){

        cout << "Все тарифы нашей компании:" << endl;
        Tarif* info;
        cout << endl << endl;
        info = new Drive5Tarif;
        cout << "Тариф " << info->NameOfTarif() << endl;
        cout <<"Количество минут: " <<info->MinBalance()  <<"\tКоличество интернета: " << info->MbBalance() << endl << endl << endl;
        info = new PlusTarif;
        cout << "Тариф " <<info->NameOfTarif()<< endl;
        cout <<"Количество минут: "  << info->MinBalance()  <<"\tКоличество интернета: " << info->MbBalance() << endl << endl << endl;
        info = new Drive20Tarif;
        cout << "Тариф " <<info->NameOfTarif() << endl;
        cout <<"Количество минут: "  <<info->MinBalance()  <<"\tКоличество интернета: " << info->MbBalance() << endl << endl << endl;

        info = new StudentTarif;
        cout << "Тариф "<< info->NameOfTarif() << endl;
        cout <<"Количество минут: "  <<info->MinBalance()  <<"\tКоличество интернета: " << info->MbBalance() << endl << endl << endl;

        info = new PensionerTarif;
        cout << "Тариф "<<info->NameOfTarif() << endl;
        cout <<"Количество минут: "  <<info->MinBalance()  <<"\tКоличество интернета: " << info->MbBalance() << endl << endl << endl;
    }

    void SetClient() {
        cout << "Enter name:";
        cin >> FirstName;
        cout << "Enter lastname:";
        cin >> LastName;
        cout << "Enter age:";
        cin >> Age;
        cout << "Enter ID паспорта:";
        cin >> Pasport;
        cout << "Enter place of residence:";
        cin.ignore();
        getline(cin, Residence);
        cout << "Enter number with code:" << endl;
        cin >> Number;

    }

    void setTarif() {
        string tarifName;
        int choice = 100;


        while (choice != 0) {

            cout << "Choice tarif:";
            cin >> tarifName;

            if (!tarifName.compare("Plus")) {
                tarif = new PlusTarif();
                NameTarif = "Plus";
                SetBalance();
                choice = 0;

            } else if (!tarifName.compare("Drive20")) {
                tarif = new Drive20Tarif();
                NameTarif = "Drive20";
                SetBalance();
                choice = 0;

            } else if (!tarifName.compare("Drive5")) {
                tarif = new Drive5Tarif();
                NameTarif = "Drive5";
                SetBalance();
                choice = 0;

            } else if (!tarifName.compare("Student")) {
                tarif = new StudentTarif();
                NameTarif = "Student";
                SetBalance();
                choice = 0;

            } else if (!tarifName.compare("Pensioner")) {
                  tarif = new PensionerTarif();
                  NameTarif = "Pensioner";
                  SetBalance();
                  choice = 0;

            } else {
                tarif = nullptr;
                cout << endl << "You entered incorrect tarif. Repeat choice tarif again!" << endl << endl;
                NameTarif = "empty";

            }

        }
    }

    string GetPasport() {
        return Pasport;
    }

    void SetBalance() {
        BalanceAccount -= tarif->Balance();
    }

    string GetLastName(){
        return LastName;
    }


    void DepositBalance() {
        double summa;
        cout << "Enter sum for deposit:";
        cin >> summa;

        BalanceAccount += summa;
    }

    double GetBalance() {

        return BalanceAccount;

    }

    void SetNumber() {
        cout << "Enter number with code:" << endl;
        cin >> Number;
    }

    void GetClient() {

        cout
                << "| " << setw(26) << left << this->FirstName + " " + this->LastName
                << "| " << setw(4) << left << this->Age
                << "| " << setw(10) << left << this->Pasport
                << "| " << setw(20) << left << this->Residence
                << "| " << setw(14) << left << this->Number
                << "| " << setw(10) << left << this->NameTarif
                << "| " << setw(9) << left << this->BalanceAccount << "|" <<
                endl;
        cout
                << "------------------------------------------------------------------------------------------------------------"
                << endl;

    }

    string GetTarif() {
        return NameTarif;
    }

    string GetNumber() {
        return Number;
    }


    void WriteFile(Client person1) {

        string Path = "myFiles.txt";

        ofstream fout;

        fout.open(Path, ofstream::app);

        if (!fout.is_open()) {
            cout << "Error; File is not open";
        } else {

            fout << person1;

        }
        fout.close();
    }


    void ReadFile() {

        Client x;

        string Path = "myFiles.txt";

        fstream fin;

        fin.open(Path, ifstream::in);

        while(!(fin.eof())){
            fin >> x;
            x.GetClient();
        }

        fin.close();

    }

    Client ReadFilePasport(){

        Client x,y;
        string Indificator;

        cout << "Enter Pasport:";
        cin >> Indificator;

        string Path = "myFiles.txt";
        fstream fin;
        fin.open(Path);

        x.PrintViewClient();
        while(!(fin.eof())){
            fin >> x;
            if(!(x.GetPasport().compare(Indificator))){
                return x;
            }
            else{
                return y;
            }
        }
        fin.close();

    }


    void PrintViewClient(){
        cout
                << "------------------------------------------------------------------------------------------------------------"
                << endl;
        cout
                << "|           Client          | Age |  Pasport  |      Residence      |     Number    |   Tarif   |  Balance |"
                << endl;
        cout
                << "------------------------------------------------------------------------------------------------------------"
                << endl;

    }


//    bool numberValidation(string number, string phoneType) {
//           if (phoneType == "mobile") {
//            if (number.length() != MobileNumberLength) {
//                setRedTextColor();
//                cout << endl << WrongNumberLength << endl;
//                resetTextColor();
//
//                return false;
//            }
//
//            string countryCode = "0000";
//
//            for (int i = 0; i < 4; i++)
//                countryCode[i] = number[i];
//
//            if (countryCode != ValidCountryCode) {
//                setRedTextColor();
//                cout << endl << WrongCountryCode << endl;
//                resetTextColor();
//
//                return false;
//            }
//
//            string operatorCode = "00";
//            operatorCode[0] = number[4];
//            operatorCode[1] = number[5];
//
//            bool validOperatorCodeFlag = false;
//
//            for (int n = 0; n < sizeof(validCodes)/sizeof(string); n++) {
//                if (operatorCode == validCodes[n]) {
//                    validOperatorCodeFlag = true;
//                    break;
//                }
//            }
//
//            if (!validOperatorCodeFlag) {
//                setRedTextColor();
//                cout << endl << WrongOperatorCode << endl;
//                resetTextColor();
//
//                return false;
//            }
//
//            for (int n = 6; n < number.length(); n++) {
//                if (number[n] > '9' || number[n] < '0') {
//                    setRedTextColor();
//                    cout << endl << WrongSymbols << endl;
//                    resetTextColor();
//
//                    return false;
//                }
//            }
//
//            return true;
//        }
//        else {
//            if (number.length() != HomePhoneNumberLength) {
//                setRedTextColor();
//                cout << endl << WrongNumberLength << endl;
//                cout << "Valid number is " << HomePhoneNumberTemplate << endl;
//                resetTextColor();
//
//                return false;
//            }
//            if (
//                    !isSymbolDigit(number[0]) ||
//                    !isSymbolDigit(number[1]) ||
//                    !isSymbolDigit(number[3]) ||
//                    !isSymbolDigit(number[4]) ||
//                    !isSymbolDigit(number[6]) ||
//                    !isSymbolDigit(number[7])) {
//                setRedTextColor();
//                cout << NotValidNumber << endl;
//                cout << "Valid number is " << HomePhoneNumberTemplate << endl << endl;
//                resetTextColor();
//
//                return false;
//            }
//
//            if (number[2] != '-' || number[5] != '-') {
//                setRedTextColor();
//                cout << endl << NotValidNumber << endl;
//
//                cout << "Valid number is " << HomePhoneNumberTemplate << endl;
//                resetTextColor();
//
//                return false;
//            }
//        }
//    }


    friend ostream& operator << (std::ostream &os, Client &p);
    friend istream& operator >> (std::istream& in, Client& p);

};

std::ostream& operator << (std::ostream &os, Client &p)
{
    os <<"\n"<< p.FirstName << " " << p.LastName << " " << p.Age << " " << p.Pasport << " " << p.Residence << " " << p.NameTarif<< " " << p.Number << " " << p.BalanceAccount;

    return os ;
}

std::istream& operator >> (std::istream& in, Client& p)
{
    in >> p.FirstName >> p.LastName >>  p.Age >> p.Pasport >> p.Residence >> p.NameTarif >> p.Number >> p.BalanceAccount;

    return in;
}


#endif //KURSACH2_CLIENT_H
