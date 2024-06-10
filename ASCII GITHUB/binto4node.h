#include"asciitobin.h"
#include<string>
#include<vector>
using namespace std;
string charToFourth(string s){
    string res = "";
    string check = finalConvertToBinary(s); // kết quả sẽ là chuỗi nhị phân dịch theo quy ước ascii
    // chuyển đổi sang mã hệ số 4
    for (int i = 0; i < check.length(); i+=2){
        if(check[i] == '0' && check[i + 1] == '0'){
            res = res + "0";
        }
        else if(check[i] == '0' && check[i + 1] == '1'){
            res = res + "1";
        }
        else if(check[i] == '1' && check[i + 1] == '0'){
            res = res + "2";
        }
        else if(check[i] == '1' && check[i + 1] == '1'){
            res = res + "3";
        }
    }
    return res;
}
string fourthToChar(string s){
    string res = "";
    // chuyển đổi từ mã hệ số 4 sang mã nhị phân 
    for (int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            res = res + "00";
        }
        else if(s[i] == '1'){
            res = res + "01";
        }
        else if(s[i] == '2'){
            res = res + "10";
        }
        else if(s[i] == '3'){
            res = res + "11";
        }
    }
    res = finalConvertToAscii(res); // chuyển đổi ngược từ mã nhị phân sang kí tự ascii
    return res;
}