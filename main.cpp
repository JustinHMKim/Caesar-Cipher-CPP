#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <limits.h>

using std::cout; using std::endl; using std::string; using std::vector; using std::cin; using std::getline;

//uses ASCII values to convert from characters to integers and back

int returnVal(char x)
{
    return (int)x - 87;
}

char returnChar(int y){
    return (char)y + 87;
}

//allows user to use a Caesar Cipher of their own designated shift

int inputMessage(string user_input, int shifting)
{
    vector<int> alpha_nums;

    vector<char> message;

    vector<char> input(user_input.begin(), user_input.end());

    for (int i = 0; i < input.size(); ++i){

        alpha_nums.push_back(returnVal(input[i]));

        //Don't need to apply shift to nonalphabetical characters, just insert any nonalphabetical characters into the output

        if(alpha_nums[i] >= 10 && alpha_nums[i] <= 35){

            alpha_nums[i] = alpha_nums[i] + shifting;

            //Wraps around from 'z' to 'a' to only have alphabetical characters

            if (alpha_nums[i] + shifting > 35){

                alpha_nums[i] = alpha_nums[i]%35+9;

            }

            message.push_back(returnChar(alpha_nums[i]));

        }

        else{

            message.push_back(input[i]);

        }

    }

    cout<<endl<<"Your message with a shift of " << shifting<< " is: ";

    for (vector<char>::const_iterator i = message.begin(); i != message.end(); ++i){

        cout << *i;

    }

    cout<<endl;

    return 0;

}

int Cae_encrypt(string encrypted_phrase){

    vector<int> enc_alpha_nums;

    vector<char> unenc_input;

    vector<char> enc_input(encrypted_phrase.begin(), encrypted_phrase.end());

    //Do for each possible shift. Should get every letter in each position at least once

    for(int j = 0; j <=25 ; ++j){

        for (int i = 0; i < enc_input.size(); ++i){

            enc_alpha_nums.push_back(returnVal(enc_input[i]));

            //Don't need to apply shift to nonalphabetical characters, just insert any nonalphabetical characters into the output

            if(enc_alpha_nums[i] >= 10 && enc_alpha_nums[i] <= 35){

                enc_alpha_nums[i] = enc_alpha_nums[i] + j;

                //Wraps around from 'z' to 'a' to only have alphabetical characters

                if (enc_alpha_nums[i] > 35){

                    enc_alpha_nums[i] = enc_alpha_nums[i]%35+9;

                }

                unenc_input.push_back(returnChar(enc_alpha_nums[i]));

            }

            else{

                unenc_input.push_back(enc_input[i]);

            }

        }

        cout<<"Shift of "<<j<<": ";

        for (vector<char>::const_iterator l = unenc_input.begin(); l != unenc_input.end(); ++l){

            cout << *l;

        }

        cout<<endl;

        //Clear out vectors for next shift

        enc_alpha_nums.clear();

        unenc_input.clear();
    }
    return 0;
}

int main(){

    char cont = 'n';

    int choice;

    string user_in;

    int shift;

    do{

        cout<<"What would you like to do?"<<endl<<"1. Encrypt a message with a Caesar Cipher." <<endl
            <<"2. Decrypt a message with a Caesar Cipher." <<endl<<"3. Find out what the Caesar Cipher is."<<endl;

        cin>>choice;

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1){

            cout<<"Enter the message you'd like to be encrypted: ";

            getline(cin,user_in);

            cout<<"Enter the shift you'd like to apply: ";

            cin>>shift;

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            inputMessage(user_in, shift);

        }

        else if(choice ==2){

            cout<<"Please enter the message you'd like to decrypt: ";

            getline(cin,user_in);

            Cae_encrypt(user_in);

        }

        else if(choice == 3){

            cout<<"The Caesar Cipher, also known as a shift cipher, is one of the oldest and simplest forms of encrypting a message."<<endl<<
                  "It is a type of substitution cipher where each letter in the original message (which in cryptography is called the plaintext) is replaced with a letter corresponding to a certain number of letters shifted up or down in the alphabet. "<<endl<<
                  "For each letter of the alphabet, you would take its position in the alphabet, say 3 for the letter 'C', and shift it by the key number."<<endl<< "If we had a key of +3, that 'C' would be shifted down to an 'F' - and that same process would be applied to every letter in the plaintext. "<<endl<<
                  "In this way, a message that initially was quite readable, ends up in a form that cannot be understood at a simple glance. "<<endl<<
                  "-From https://learncryptography.com/classical-encryption/caesar-cipher"<<endl;

        }

        else{

            cout<<"Please enter a valid input"<<endl;

        }

        cout<<"Would you like to continue? (Y/N): ";

        cin>>cont;

        cout<<endl;

    }while (cont == 'Y' || cont =='y');

    cout<<"Thank you for your time"<<endl;

    return 0;

}
