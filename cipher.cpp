#include<iostream>
#include<string.h>
#include "Encrypt.h"
#include "Decrypt.h"
using namespace std;

int main()
{
    Decrypt d;
    Encrypt e;
    int choice;
    string key;        // the key word input
    string message;    // the message the user input 

    cout << "Welcome!\n";

    // Menu
    cout << "\nPlease select the following: " << endl;
    cout << "1. Encryption" << endl;
    cout << "2. Decryption" << endl << endl;
    cin >> choice;
    cout << endl;

    while (choice < 1 || choice > 3)   // validate the input
    {
        cout << "Invalid choice. \n";
        cout << "Please select 1-3 : ";
        cin >> choice;
        cout << endl;
    }

    // Get all the inputs
    cout << "Please enter a message (NO SPACE OR SYMBOLS): ";
    //cin >> message;
    cin.ignore();
    getline(cin, message);
    cout << endl;

    cout << "Please enter the key word: ";
    cin >> key;
    cout << endl;

    if (choice == 1)
    {
        e.ExtendKey(key, message.size());
        e.Encryp(message, key, message.size());
        cout << endl;
    }

    else if (choice == 2)
    {
        e.ExtendKey(key, message.size());
        d.Decryp(message, key, message.size());
        cout << endl;
    }

    cout << "Restart the program to input a different message" << endl;

    return 0;
}