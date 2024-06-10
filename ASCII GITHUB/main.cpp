#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"asciitobin.h" // link file.h vào trong hàm main 
#include"binto4node.h"
#include"indexCal.h"

using namespace std;
int main(){
    string textToEncode;
    getline(cin, textToEncode);
    string fouthFinal = charToFourth(textToEncode);
    cout << fouthFinal << endl;
    string textDecode = fourthToChar(fouthFinal);
    cout << textDecode << endl;
    map<char, double> staticChar;
    staticString(textToEncode, staticChar);
    for(auto &it : staticChar){
        cout << it.first << " " << it.second << endl;
    }
    cout << entropyCal(staticChar) << endl;
}