#include <string>
#include <vector>
#include <iostream>

// 프로그래머스 신규 아이디 추천 2021 카카오 블라인드 
using namespace std;

string solution(string new_id) {
    string answer = "";
    int len = new_id.size();
    int count = new_id.size();
    vector<bool> isAlive(count, true);

    // 1. 소문자 치환
    for (int i = 0; i < len; ++i) {
        if (new_id[i]>= 'A' && new_id[i] <= 'Z'){
            new_id[i] = new_id[i] + 32;
        }
    }

    // 2. 가능하지 않은 문자 제거
    for (int i = 0; i < len; ++i) {
        if (new_id[i] == 45 || new_id[i] == 46 || (new_id[i] >=48 && new_id[i] <=57) || new_id[i] == 95 ||
        (new_id[i] >= 97 && new_id[i] <= 122)){
            continue;
        }else{
            new_id.replace(i, 1, "");
            len--;
            i--;
        }
    }

    // 3. 연속 마침표 하나로
    for (int i = 0; i < len-1; ++i) {
        if (new_id[i] == '.'){
            int j = i+1;
            while (new_id[j]=='.'){
                new_id.replace(j,1,"");
                len--;
            }
        }
    }

    // 4. 처음과 끝에 마침표가 있으면 제거
    if(new_id[0] == '.'){
        new_id.replace(0,1,"");
        len--;
    }

    if (new_id[len-1] == '.'){
        new_id.replace(len-1,1,"");
        len--;
    }



    // 5. 비어있으면 "a" 대입
    if (len == 0) {
        new_id = "a";
        len = 1;
    }

    // 6. 길이가 16 이상이면 15까지만
    if (len >= 16){
        while (len > 15){
            new_id.replace(len-1,1,"");
            len--;
        }

        if (new_id[len-1] == '.'){
            new_id.replace(len-1,1,"");
            len--;
        }
    }


    // 7. 길이가 2 이하면 마지막 문자를 반복
    if (len<=2){
        char last = new_id[len-1];
        while (len <3){
            new_id += last;
            len++;
        }
    }

    return new_id;
}

