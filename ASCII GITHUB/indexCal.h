#include<iostream>
#include<string>
#include<map>
#include<math.h>

using namespace std;
void staticString(string s, map<char, double> &check){
    for(int i = 0; i < s.length(); i++){
        check[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++){
        check[s[i]] = check[s[i]] / s.length();
    }
}
double loga_2(double n){
    return log(n) / log(2);
}
double entropyCal(map<char, double> &check){
    double res = 0;
    for(auto &it : check){
        res = res + it.second * loga_2(it.second);
    }
    return (-res);
}
double entropyMax(int n){
    return loga_2(n);
}