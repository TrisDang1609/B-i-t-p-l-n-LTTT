#include<iostream>
#include<string>
#include<fstream>
#include"convert.h" // link file.h vào trong hàm main 
#include"preprocessing.h"
using namespace std;
int main(){
    string textToEncode;
    getline(cin, textToEncode);
    string fouthFinal = charToFourth(textToEncode);
    cout << fouthFinal << endl;
    string textDecode = fourthToChar(fouthFinal);
    cout << textDecode << endl;
}