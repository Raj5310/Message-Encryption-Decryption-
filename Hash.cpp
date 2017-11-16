
#include "Hash.h"
#include<iostream>
#include<ctime>
#include<string>
using namespace std;

Hash::Hash(){
    
    //Store all the messages in the table Hashtable
    for( int i= 0; i <tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i] -> encrypt_message = "";
        HashTable[i] -> User_input = "";
        HashTable[i] -> key = "";
        HashTable[i] -> next = NULL;
   }
}


void Hash::AddIteam(string message, string User_input, string key){
    
    int index = hash(message); //Get the index of where the message will be stored
    // Check and see if the message is store in the specificy index, if the hashtable is empty store the all the messages
    if( HashTable[index] -> encrypt_message== ""){
        HashTable[index] -> encrypt_message = message;
        HashTable[index] -> User_input = User_input;
        HashTable[index] -> key = key;
    }
    // Store the messages in the new hashtable table index
    else{
        item* Ptr = HashTable[index];
        item* n = new item;
        n -> User_input = User_input;
        n -> encrypt_message = message;
        n -> key=key;
        n -> next = NULL;
       
        while(Ptr ->next != NULL){
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int Hash::hash(string key){
    
    int index =1;
    int hash=0;
    for( int i =0; i<key.length(); i++){
        hash += (int)key[i];
    }

    index = hash % tableSize;
    cout<<"Index: "<<index<<endl;
    return index;
}

void Hash::encrypt_message(string User_input){
    //Generate random encrption message for the user
    srand(time(0));
    static const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string newkey = "";
    string message = "";
    int key= rand() % 100 + 1 ;  //Give user a random key that goes withe the encrypted message
    newkey = to_string(key);
    
    for(int i=0; i<User_input.length() + 5; i++){
        message += alphabet [rand() % alphabet.size()];
        
    }
    cout<<"Encrypted Messages:"<<message<<endl;   //Display Encryped messages
    cout<<"Encrypted Key:"<< newkey<<endl;        //Display the key
    AddIteam(message, User_input, newkey);  //Add encrypted messages, user inuput, and key in the hashtable
    
}


void Hash::decrypt_message(string mess, string key){
   
    int index = hash(mess);
    bool foundkey = false;
    string found_mess;
    //set the Ptr to the first index in the hashtable
    item* Ptr = HashTable[index];
    //Lookup the encrpted message and key in the hashtable
    while(Ptr != NULL){
        
        if(Ptr ->encrypt_message == mess && Ptr ->key == key){
            foundkey = true;
            found_mess = Ptr -> User_input;
        }
        
        Ptr = Ptr->next ;
    
    } // If the key and message is found display the message
        if(foundkey == true){
            
            cout<<"Decrypted Message is:"<<found_mess<<endl;
        }
        else
            cout<<"Message not found"<<endl;
    
    }


