// khai báo thư viện cần thiết cho việc xử lý dữ liệu 
#include<fstream> // thư viện để đọc file
#include<string> // thư viện để xử lý chuỗi
#include<iostream> // thư viện để nhập xuất dữ liệu
using namespace std;
bool isSame(string c, string cutLine){ // kiểm tra xem ở dòng line có xuất hiẹn kí tự c hay không
    if(c == cutLine){
        return true;
    }
    return false;
};
string normalize(char c){ // chuẩn hoá kí tự c thành string c để tiến hành so sánh
    if(c == ' '){ // trường hợp " " thì thành Space
        return "Space";
    }
    string res = ""; // các trường hợp khác giữ nguyên nhưng đổi kiểu dữ liệu char to string
    res = res + c;
    return res;
}
string convertToBinary(char c){
    string res = ""; // khởi tạo chuỗi rỗng
    ifstream file ("asciiConverterData.txt"); // đọc file txt và gán nó tên là file 
    string line;
    while(true){
        getline(file, line); // lấy cả dòng trong file txt
        string cutLine = ""; // khởi tạo chuối rống để lưu cái string kiểm tra
        int j = 0;
        while(line[j] != ' '){ // tiến hành cut
            cutLine = cutLine + line[j];
            j++;
        }
        if(isSame(normalize(c), cutLine)){ // hàm kiểm tra
            break;
        }
    }
    // đế thời điểm này, thì mình có cái dòng chưa kí tự cần tìm 
    int i = line.length() - 1; // lấy độ dài của dòng
    while(line[i] != ' '){ // tiến hành cut binary
        res = line[i] + res;
        i--;
    }
    return res;
}
string normalizeString(string res){
    if(res == "Space"){
        return " ";
    }
    return res;
}
string convertToAscii(string binary){
    string res = "";
    ifstream file ("asciiConverterData.txt");
    string line;
    while(true){
        getline(file, line);
        string cutLine = "";
        int i = line.length() - 1; 
        while(line[i] != ' '){ // cut phần binary trong line
            cutLine = line[i] + cutLine;
            i--;
        }
        if(cutLine == binary){
            break;
        }
    }
    int j = 0;
    while(line[j] != ' '){ // cut phần kí tự trong line
        res = res + line[j];
        j++;
    }
    normalizeString(res);   
    return res;
}
string finalConvertToBinary(string s){
    string res = "";
    for(int i = 0; i < s.length(); i++){
        res = res + convertToBinary(s[i]);
    }
    return res;
}
string finalConvertToAscii(string s){
    s = s + '*';
    string res = "";
    string cut = "";
    cut = cut + s[0];
    for (int i = 1; i < s.length(); i++){
        if(i % 8 == 0){
            res = res + convertToAscii(cut);
            cut = "";
        }
        cut = cut + s[i];
    }
    return res;
}