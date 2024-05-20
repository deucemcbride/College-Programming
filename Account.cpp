#include <iostream>
#include <cctype>
#include <string>

using namespace std;

char usernameIn[30];
char passwordIn[30];
char ID[15];
string firstName;
string lastName;
string middleName;
string usernameUp;
char passwordUp [25];
char confirmPassword [25];
char mobileNumber [11];

void signIn ()
{
    cout << "Username: ";
    cin >> usernameIn;
    
    cout << "Password: ";
    cin >> passwordIn;
}

void signUp ()
{
    cout << "SIGN UP" << endl;
    cout << "ID: ";
    cin >> ID;
    cout << "First Name: ";
    cin >> firstName;
    cout <<"Middle Name: ";
    cin >> middleName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Username: " << firstName.at(0) << middleName.at(0) << lastName << endl;
    cout <<"Password: ";
    cin >> passwordUp;
    cout << "Confirm Password:  ";
    cin >> confirmPassword;
    cout << "Mobile Number: ";
    cin >> mobileNumber;
}

void signinMenu ()
{
    int option2;
    
    cout << "MENU" << endl;
    cout << "[1] Show Profile" << endl;
    cout << "[2] Back" << endl;
    cout << "Option: " << endl;
}


int main ()
{
    int option;
    
    cout << "ACCOUNT MENU" << endl;
    cout << "[1] Sign-in" << endl;
    cout << "[2] Sign-up" << endl;
    cout << "[3] Exit" << endl;
    cout << "Option: " << endl;
    cin >> option;
    
    switch (option)
    {
        case 1:
            signIn();
            break;
        case 2:
            signUp();
            break;
        case 3:
            exit (0);
            break;
        default:
            cout << "Invalid Option" << endl;
        
    }
}