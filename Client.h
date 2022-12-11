#ifndef KURSACH2_CLIENT_H
#define KURSACH2_CLIENT_H
#include "Tarif.h"
#include "Drive20Tarif.h"
#include "Drive5Tarif.h"
#include "PlusTarif.h"
#include "StudentTarif.h"
#include "PensionerTarif.h"
#include <fstream>
#include "ConstantsFile.h"
#include "OtherFunctionality.h"
#include "InCorrectStringInput.h"
#include "InCorrectIntInput.h"
#include "InCorrectOpenFiles.h"
#include "InCorrectLengthPassword.h"

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
    string Number;
    double BalanceAccount;
    string NameTarif;
    string PasswordAccount;

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

    ~Client() = default;

    void CreateClient(Client &person1) {

        cout<< endl << "Creating new client:" << endl;

        person1.SetClient();

        cout << endl << endl;
        cout << "Choice tarif:" << endl;

        AllTarif();

        while (true) {
            person1.setTarif();
            break;
        }
        SetBalance();

    }

    void SetName(){


    while(true) {

        rewind(stdin);
        cin.clear();
        cout << "Enter name:";
       // cin >> FirstName;
       //cin.ignore();
        getline(cin,FirstName);

        try {

            for (int i = 0; i < FirstName.length(); i++) {

                if (FirstName[i] >= 48 && FirstName[i] <= 57)
                    throw InCorrectStringInput("Entered number!");

                if (FirstName[i] == ' ') {
                    throw InCorrectStringInput("Enter without space!");
                }
            }
            break;
        }
        catch (InCorrectStringInput ex) {
            ex.show();
            continue;
        }

    }

    }

    void SetLastName(){


        while(true) {

            rewind(stdin);
            cin.clear();

            cout << "Enter Lastname:";
           // cin.ignore();
            getline(cin,LastName);
//            cin >> LastName;

            try {
                for (int i = 0; i < LastName.length(); i++) {
                    if (LastName[i] >= 48 && LastName[i] <= 57)
                        throw InCorrectStringInput("Entered number!");
                    if (LastName[i] == ' ') {
                        throw InCorrectStringInput("Enter without space!");
                    }
                }
                break;
            }
            catch (InCorrectStringInput ex) {
                ex.show();
                continue;
            }

        }

    }

    void SetAge(){


        while(true){


            while(true) {
                cout << "Enter age:";

                rewind(stdin);
                cin.clear();
                try{
                    if(!(  cin >> Age ))
                        throw InCorrectIntInput("Sorry, enter int!");
                    break;
                }
                catch(InCorrectIntInput &ex){
                    ex.show();
                    rewind(stdin);
                    cin.clear();
                    continue;
                }

            }

            if(Age <= 12){
                cout << "You are entered negative age. \nRepeat again!" << endl;
                continue;
            }else if(Age > 100){
                cout << "You are entered so big age. \nRepeat again!" << endl;
                continue;
            }else{
                break;
            }

        }

    }

    void SetPasport(){

        cout << endl << CorrectPasport << endl;
        while (true) {
            cout << "Enter ID pasport:";
            rewind(stdin);
            cin.clear();
            cin >> Pasport;

            if (pasportValidation(Pasport)) {
                if(CheckPasportInBase(Pasport))
                     break;
            }else{
                continue;
            }
        }
    }

    void SetResidence(){

        while(true) {
            rewind(stdin);
            cin.clear();
            cout << "Enter place of residence:";

            //cin.ignore();//не замечает пробелов но в файл записывать не оч
            getline(cin, Residence);

            try {
                for (int i = 0; i < Residence.length(); ++i) {
                    if(Residence[i] == ' ')
                        throw InCorrectStringInput("Enter without space!");
//                    if (Residence[i] >= 48 && Residence[i] <= 57)
//                        throw InCorrectStringInput("Entered number!");
                    if(Residence.length() > 25)
                        throw InCorrectStringInput("So long Residence. Max length is 25!");
                }
                break;
            }

            catch (InCorrectStringInput &ex){
                ex.show();
            }


        }


    }

    void SetNumber() {

        cout << endl <<"Correct number :" << endl << CorrectNumber << endl;

        while (true) {
            cout << "Enter number with code:" << endl;
            rewind(stdin);
            cin.clear();
            cin >> Number;
            if ( numberValidation(Number)) {
                if(CheckNumberInBase(Number))
                    break;
            }else{
                continue;
            }
        }
    }

    void SetPassword(){

        while (true) {
            cout << "Choice password:";
            rewind(stdin);
            cin.clear();
            cin >> PasswordAccount;


            try {
                for (int i = 0; i < PasswordAccount.length(); i++) {
                    if (PasswordAccount[i] == ' ') {
                        throw InCorrectStringInput("Enter password without space!");
                    }
                    if(PasswordAccount.length() < 8){
                        throw InCorrectLengthPassword("Password should have 8 characters long!");
                    }
                }
                break;
            }
            catch (InCorrectStringInput ex) {
                ex.show();
                continue;
            }
            catch (InCorrectLengthPassword ex) {
                ex.show();
                continue;
            }

        }
    }

    bool CheckPasportInBase(string CheckPasport){

        vector<Client> persons = LoadPeopleInVector();

        for (int i = 0; i < persons.size(); ++i) {

            if(persons[i].Pasport == CheckPasport){
                cout << "This ID pasport alredy in base! Check correct ID pasport!" << endl;
                return false;
            }

        }

        return true;

    }

    bool CheckNumberInBase(string CheckNumber){

        vector<Client> persons = LoadPeopleInVector();

        for (int i = 0; i < persons.size(); ++i) {

            if(persons[i].Number == CheckNumber){
                cout << "This ID number alredy in base! Choice other phone number!" << endl;
                return false;
            }
        }

        return true;
    }

     vector<Client> LoadPeopleInVector(){
        vector<Client> persons;
        Client x;
        string Path = "Clients.txt";

        fstream fin;

         fin.open(Path);


         while (true) {
             try {
                 if (!fin.is_open())
                     throw InCorrectOpenFiles("Files error!");
                 break;
             }
             catch (InCorrectOpenFiles& ex){
                 ex.show();
                 continue;
             }
         }


        while(!(fin.eof())){
            fin >> x;
            persons.push_back(x);
        }

        fin.close();

        return persons;

    }

    void SetClient() {

        SetName();
        SetLastName();
        SetAge();
        SetPasport();
        SetPassword();
        SetResidence();
        SetNumber();
    }

     void AllTarif(){


        cout << "Tarifs of own company:" << endl;
        Tarif* info;
        cout << endl << endl;
        info = new Drive5Tarif;
        cout << "Tarif " << info->NameOfTarif() << endl;
        cout <<"Minutes amount: " <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance()  << "\tPrice: " << info->Balance()  << " byn" << endl << endl << endl;
        info = new PlusTarif;
        cout << "Tarif " <<info->NameOfTarif()<< endl;
        cout <<"Minutes amount: "  << info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << "\tPrice: " << info->Balance()<< " byn"<<  endl << endl << endl;
        info = new Drive20Tarif;
        cout << "Tarif " <<info->NameOfTarif() << endl;
        cout <<"Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance()  << "\tPrice: " << info->Balance() << " byn" << endl << endl << endl;

        info = new StudentTarif;
        cout << "Tarif "<< info->NameOfTarif() << endl;
        cout <<"Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance()   << "\tPrice: " << info->Balance()<< " byn" << endl << endl << endl;

        info = new PensionerTarif;
        cout << "Tarif "<<info->NameOfTarif() << endl;
        cout <<" Minutes amount: "  <<info->MinBalance()  <<"\tInternet amount: " << info->MbBalance() << "\tPrice: " << info->Balance() << " byn" << endl << endl << endl;


    }

    void setTarif() {
        string tarifName;
        int choice = 100;

        while (choice != 0) {

            cout << "Choice tarif:";
            cin >> tarifName;

            if ( tarifName == "Plus") {
                tarif = new PlusTarif();
                NameTarif = "Plus";

                choice = 0;

            } else if (tarifName =="Drive20") {
                tarif = new Drive20Tarif();
                NameTarif = "Drive20";

                choice = 0;

            } else if (tarifName =="Drive5") {
                tarif = new Drive5Tarif();
                NameTarif = "Drive5";

                choice = 0;

            } else if (tarifName =="Student") {
                tarif = new StudentTarif();
                NameTarif = "Student";

                choice = 0;

            } else if (tarifName =="Pensioner") {
                  tarif = new PensionerTarif();
                  NameTarif = "Pensioner";

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

    string GetPassword(){
        return PasswordAccount;
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

        while(true){
            cout << "Enter sum for deposit:";
            cin >> summa;

            if(summa < 0){
                cout << "You are entered negative deposit!\nRepeat again!" ;
                continue;
            }else{
                break;
            }

        }


        BalanceAccount += summa;
    }

    double GetBalance() {

        return BalanceAccount;

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

        string Path = "Clients.txt";

        ofstream fout;

        fout.open(Path, ofstream::app);


        try {
            if (!fout.is_open())
                throw InCorrectOpenFiles("Files is not open!");

        }
        catch (InCorrectOpenFiles& ex){
            ex.show();
            exit(1);
        }


        fout << person1;

        fout.close();
    }

    friend ostream& operator << (std::ostream &os, Client &p);
    friend istream& operator >> (std::istream& in, Client& p);

};

std::ostream& operator << (std::ostream &os, Client &p)
{
    os <<"\n"<< p.FirstName << " " << p.LastName << " " << p.Age << " " << p.Pasport <<" " << p.PasswordAccount << " " << p.Residence << " " << p.NameTarif<< " " << p.Number << " " << p.BalanceAccount;

    return os ;
}

std::istream& operator >> (std::istream& in, Client& p)
{
    in >> p.FirstName >> p.LastName >>  p.Age >> p.Pasport >> p.PasswordAccount >> p.Residence >> p.NameTarif >> p.Number >> p.BalanceAccount;

    return in;
}


#endif //KURSACH2_CLIENT_H
