/*
    Định hướng của mình thì mình sẽ chuyển đổi từng cái nhỏ một rồi sau đó thực hiện 
    n lần để nó trở thành một đoạn mã hoàn chỉnh.
    Với cái condition ban đầu là không data input/ prcessed data hay là mình cứ nhập 
    vào cái gì thì nó tự động chạy với convert thôi.
    Với quy chuẩn mã hóa chính là chuẩn được quy định trong C/C++ - tìm hiểu thêm ở 
    định nghĩa của kiểu dữ liệu char nhé.
*/
#include<iostream>
#include<string>

using namespace std;

string reverseAsciiToBin(char x){
    int numChar = (int)x; // step1: convert char x to (int)x 
    string res = ""; // define an empty string Var to store result
    while(numChar != 0){
        res += (char)(numChar % 2 + (int)'0'); 
        /*
        Explain: type casting everywhere!
            1:numChar % 2 - just a way to get 0/1 form int
            2:(int)'0' - get the number of '0' in ascii 
            3:(numchar % 2) + (int)'0' - find number of '0' / '1' in ascii 
            4:char(...) - to convert number of ascii into ascii_char 
        */
        numChar /= 2; // to descend numChar into 0 - end of process 
    }
    res.reserve(); // make the binary true
    while(res.length() < 8){ // the default of binary_ascii's length is 8-character num 
        res = "0" + res;
    }
    return res;
}
char convertBinToAscii(string x){
    int preChar = 0; // define a num to store a ordinal num of ascii
    int powOf2 = 1;  
    for (int i = x.length() - 1; i >= 0; i--){
        if(x[i] == '1'){
            preChar += powOf2;
        }
        powOf2 *= 2; 
    }
    /*
        to understand this, please read the way to convert binary to int 
        or 2-digit num to 10-digit num 
    */
    return (char)(preChar);
}
int main(){
    string x = "01100011";
    cout << convertBinToAscii(x);
}