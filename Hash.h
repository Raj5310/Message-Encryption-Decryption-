
#ifndef Hash_h
#define Hash_h
#include<iostream>
#include<string>
using namespace std;

class Hash{

public:
    Hash(); // Constructor
    int hash(string key); // Generate a index in the hashtable
    void encrypt_message(string); // Encrpt the message with the user input
    void AddIteam(string, string, string); // Add the userinput, encrypted message and key in th hashtable
    void decrypt_message(string, string); // Decrypt the message
    
private:
    static const int tableSize = 100; //Initialize the hashtable size
    //Stored the encryped, decrypted, and the key inside the Hashtable
    struct item{
        string encrypt_message;
        string User_input;
        string key;
        item * next;
    };
    
    item* HashTable[tableSize];  
};


#endif /* Header_h */
