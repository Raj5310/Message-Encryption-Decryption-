/*
    
    Name:    Raj Pokhrel
    Class:   CMPSC 360
    Project: 1 Encrpt and Decrypt messages
    
    Description: The main objective of this program is to encrypt and decrypt messages. First, We
    promp user what message they would like to encrypt.Then, take that message and encrype using random
    numbers,strings, and char. With the encrypted messages, the program also geneate a random key that
    goes with the encrypted messages. Next, the user can continueto encrypting more messages or decrypt any
    previous message. The program is able to store the user input, encrytped message, and the key in the hashtable
    in the specific index. The encryption message and key changes everytime the enter any messages. Therefore, you 
    should never have the same key and encrypted messages.
    
    Math Model: set the hashtable equal to 100 with index 1 to 100, Then used struct to store the information
*/


#include<iostream>
#include<string>
#include<iomanip>
#include<ctime>
#include "Hash.h"
using namespace std;


int main() {
    // Make the object called test to display the result
    Hash test;
    char repeat = 'y';
    char choice = 'a';
    string user_input;
    string key = "";
    
    cout<<"********** Welcome to the Encryption and Decryption Software  ****************"<<endl;
    
    do{
        //Ask the user if they would like to encrypt or decrpt the messages with the choice A or B
        cout<<"Encrypt or Decrypt Messages (A/B)"<<endl; // Ask the user if they would like to encrypt or decrypt message
        cin>>choice;
        cin.ignore();
        
        // If the user choice is A encrpt the message
        if(choice == 'A' || choice == 'a'){
            cout<<"Write a message that you would like to encrypt: "<<endl;
            getline(cin,user_input);
            test.encrypt_message(user_input);
        }
       // If the user choice is B decrypt the message
        else{
            cout<<"Enter an Encrypted Message: "<<endl;
            getline(cin,user_input);
            cout<<"Enter an Encrypted Key: "<<endl;
            getline(cin,key);
            test.decrypt_message(user_input, key);
        }
        // Promp the user if they would like continue the program
        cout<<"Do you wish to continue (Y/N)"<<endl;
        cin>>repeat;
        
    } while(repeat == 'y' || repeat == 'Y');
    
    return 0;

}
/*
            The Output Result
 
 ********** Welcome to the Encryption and Decryption Software  ****************
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 Raj Pokhrel
 Encrypted Messages:AJuTjeURwTRQA2gs
 Encrypted Key:69
 Index: 13
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 Raj Pokhrel
 Encrypted Messages:NBHwumxcscWdWQlxD
 Encrypted Key:25
 Index: 45
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 Prateek Chandra
 Encrypted Messages:DhmWigSGwlD7fp2aYhaF9
 Encrypted Key:14
 Index: 58
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 OB
 Encrypted Messages:2rvVUmQ
 Encrypted Key:56
 Index: 43
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 Kevin Obrian
 Encrypted Messages:EFJoQ0ibFyHXxi5bPg
 Encrypted Key:19
 Index: 66
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 AJuTjeURwTRQA2gs
 Enter an Encrypted Key:
 69
 Index: 13
 Decrypted Message is:Raj Pokhrel
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 NBHwumxcscWdWQlxD
 Enter an Encrypted Key:
 25
 Index: 45
 Decrypted Message is:Raj Pokhrel
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 DhmWigSGwlD7fp2aYhaF9
 Enter an Encrypted Key:
 14
 Index: 58
 Decrypted Message is:Prateek Chandra
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 2rvVUmQ
 Enter an Encrypted Key:
 56
 Index: 43
 Decrypted Message is:OB
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 Penn State
 Enter an Encrypted Key:
 2019
 Index: 78
 Message not found
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 a
 Write a message that you would like to encrypt:
 Penn State
 Encrypted Messages:bSRZXWBahBV8iDi6
 Encrypted Key:1
 Index: 35
 Do you wish to continue (Y/N)
 y
 Encrypt or Decrypt Messages (A/B)
 b
 Enter an Encrypted Message:
 bSRZXWBahBV8iDi6
 Enter an Encrypted Key: 
 1
 Index: 35
 Decrypted Message is:Penn State 
 Do you wish to continue (Y/N)
 
 */
