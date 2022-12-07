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
#include "ConstantsFile.h"
#include "OtherFunctionality.h"
using namespace std;


class Client {

private:
    string FirstName;
    string LastName;
    int Age;
    string Pasport;
    string Residence;

    string Number;
    double BalanceAccount;
    string NameTarif;

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

    void SetName(){
        cout << "Enter name:";
        cin >> FirstName;
    }

    void SetLastName(){
        cout << "Enter lastname:";
        cin >> LastName;
    }

    void SetAge(){
        cout << "Enter age:";
        cin >> Age;
    }

    void SetPasport(){
        while (1) {
            cout << "Enter ID паспорта:";
            cin >> Pasport;

            if (pasportValidation(Pasport)) {
                break;
            }else{
                continue;
            }
        }
    }

    void SetResidence(){
        cout << "Enter place of residence:";
        cin.ignore();
        getline(cin, Residence);
    }

    void SetClient() {

        SetName();
        SetLastName();
        SetAge();
        SetPasport();
        SetResidence();
        SetNumber();
    }

    void AllTarif(){

        cout << "Tarifs of own company:" << endl;
        Tarif* info;
        cout << endl << endl;
        info = new Drive5Tarif;
        cout << "Tarif " << info->NameOfTarif() << endl;
        cout <<"Minutes amount: " <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << endl << endl << endl;
        info = new PlusTarif;
        cout << "Tarif " <<info->NameOfTarif()<< endl;
        cout <<"Minutes amount: "  << info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << endl << endl << endl;
        info = new Drive20Tarif;
        cout << "Tarif " <<info->NameOfTarif() << endl;
        cout <<"Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << endl << endl << endl;

        info = new StudentTarif;
        cout << "Tarif "<< info->NameOfTarif() << endl;
        cout <<"Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << endl << endl << endl;

        info = new PensionerTarif;
        cout << "Tarif "<<info->NameOfTarif() << endl;
        cout <<"Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << endl << endl << endl;
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

    string GetName(){
        return FirstName;
    }

    string GetLastName(){
        return LastName;
    }

    string GetResidence(){
        return Residence;
    }

    int GetAge(){
        return Age;
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

        while (1) {
            cout << "Enter number with code:" << endl;
            cin >> Number;
            if ( numberValidation(Number)) {
                break;
            }else{
                continue;
            }
        }
    }

    void GetClient() {

        cout
                << "| " << setw(26) << left << this->FirstName + " " + this->LastName
                << "| " << setw(4) << left << this->Age
                << "| " << setw(10) << left << this->Pasport
                << "| " << setw(25) << left << this->Residence
                << "| " << setw(14) << left << this->Number
                << "| " << setw(10) << left << this->NameTarif
                << "| " << setw(9) << left << this->BalanceAccount << "|" <<
                endl;
        cout
                << "-----------------------------------------------------------------------------------------------------------------"
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
