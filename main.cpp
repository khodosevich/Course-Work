#include <iostream>
#include <string>
#include "Client.h"
#include "Tarif.h"
#include "User.h"
#include "Admin.h"
#include "MyException.h"
using namespace std;


int main() {


    int choice = 100  , x ;

    User user;
    Admin admin;

    while(choice != 0){

        cout << endl  << "Menu for:" << endl;
        cout << "1 - admin" << endl;
        cout << "2 - user" << endl;
        cout << "0 - end of program" << endl;


        cin >> choice;


        switch (choice) {
            case 1:{
                admin.CheckAdmin();
                break;
            }
            case 2:
            {
                x = 100;
                while(x != 0){

                    cout << endl << endl  << "Menu user:" << endl;
                    cout << "1 - older client" << endl;
                    cout << "2 - create new client" << endl;
                    cout << "0 - main menu" << endl;

                    cin >> x;

                    switch (x) {
                        case 1:{
                           user.ForBasicUser();
                            break;
                        }

                        case 2:{
                            user.ForNewUser();
                            break;
                        }

                        case 0:{
                            x = 0;
                            break;
                        }

                        default:{
                            continue;
                        }

                    }
                }

                break;
            }
            case 0:
                return 0;

            default:{
                continue;
            }
        }
    }

return 0;
}
