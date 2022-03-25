/*
 * File: DictionaryOrderComp.cpp
 * -----------------
 * Implement dictionary order comparison.
 */
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Sort strings in dictionary order.
 * 
 * @param str1 
 * @param str2 
 * @return int 0:str1==str2, 1:str1>str2, -1:str1<str2
 */
int dictOrderComp(string str1, string str2) {
    int len_str1 = str1.size();
    int len_str2 = str2.size();
    int i = 0;
    while (i<len_str1 && i<len_str2) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        } else {
            i++;
        }
    }

    if (i==len_str1 && i==len_str2) {
        return 0;        
    } else if (i == len_str1) {
        return -1;
    } else if (i == len_str2) {
        return 1;
    }
}

// test
int main() {
    string str1 = "107";
    string str2 = "1079";

    int res = dictOrderComp(str1, str2);
    if (res == 0) cout << "str1 = str2\n";
    else if (res == 1) cout << "str1 > str2\n";
    else if (res == -1) cout << "str1 < str2\n";
}


