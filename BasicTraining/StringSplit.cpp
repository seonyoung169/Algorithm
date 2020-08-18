#include <iostream>
#include <vector>
#include <string.h>

//문자열 이용 -  단어의 개수
//cin -> 공백, 엔터가 나오면 입력 끝, getline -> 공백 포함 입력, get -> 엔터도 입력받을 문자로 간주

using namespace std;

int main() {
    string str, word;
    char strArray[1000000];
    vector<string> wordVector;

    getline(cin, str);
    strcpy(strArray, str.c_str());

    char *tok = strtok(strArray, " ");

    while (tok != NULL){
        word = tok;
        wordVector.push_back(word);
        tok = strtok(NULL, " ");
    }

    cout<<wordVector.size()<<endl;
    return  0;
}
