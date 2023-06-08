#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <string>
#include <iostream>
using namespace std;

class Encrypt
{
public:
    void ExtendKey(string& key, int wordSize)
    {
        //If Key size matches word size, no changes are made
        if (key.size() == wordSize)
        {
            return;
        }

        //Key size is above wordSize
        else if (key.size() > wordSize)
        {
            int temp = key.size() - wordSize;
            string t = "" + key.substr(0, key.size() - temp);
            key = t;
        }

        else
        {

            //Extends the key to the size of the of the word that will be encrypted
            int temp = key.size();
            for (int i = 0, j = 0; i < wordSize - temp; i++)
            {
                key += key[j];
                j++;

                if (j == key.size())
                {
                    j = 0;
                }
            }

        }

    }

    void Encryp(string word, string key, int size)
    {

        //Iterates through each element of the word
        for (int i = 0; i < size; i++)
        {

            //Use the equation to apply the number of shifts to the starting letter of A
            word[i] = ((word[i] + key[i] % 26) % 26) + 'A';

        }
        //Print encrypted word
        cout << "Encrypted Word: " << word << endl;
    }

};

#endif // !ENCRYPT.H
