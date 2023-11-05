#include <bits/stdc++.h> 
using namespace std;  

unordered_map<char,char> newMap;  

void setup(string a, string b) 
{   
  newMap.clear();   
  for(int i=0; i<a.size(); i++)   
  {    
     newMap.insert(make_pair(a[i],b[i]));   
  } 
}  

string decrypt(string msg) 
{   
    string plaintext;   
    for(int i=0; i<msg.size(); i++) 
    {    
        plaintext.push_back(newMap[msg[i]]);  
    }     
    return plaintext;
}  
        
string encrypt(string msg) 
{
    string ciphertext;   
    for(int i=0; i<msg.size(); i++)  
    {    
        ciphertext.push_back(newMap[msg[i]]);  
    }      
    return ciphertext; 
}  
              
int main()  
{         
    string alphabet = "abcdefghijklmnopqrstuvwxyz";    
    string substitution = "zaybxcwdveuftgshriqj";  

    cout << "Enter the message to encrypt: ";
    string msg;
    cin >> msg;

    setup(alphabet, substitution);         
    string cipher = encrypt(msg);     
    cout<<"Encrypted Cipher Text: "<<cipher<<endl;

    // setup(substitution, alphabet);    
    // string plain = decrypt(cipher);   
    // cout<<"Decrypted Original Text: "<<plain<<endl; 

    cout << "Enter the ciphertext to decrypt: ";
    string ciphertext;
    cin >> ciphertext;

    setup(substitution, alphabet); 
    string decryptedText = decrypt(ciphertext);
    cout << "Decrypted Text: " << decryptedText << endl;
}