//프로그래머스 해시#2 전화번호 목룍

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b){
    return a.size() < b.size() || a.size() == b.size() && a < b;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), compare);
    
    for(int i=0; i<phone_book.size(); i++){
        string key = phone_book[i];
        int keysize = key.size();
        
        for(int j=i+1; j<phone_book.size(); j++){
            if(phone_book[j].substr(0,keysize) == key){
                return false;
            }
        }
    }
    return true;
}



//*********************좀 더 간단한 풀이*********************
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b){
    return a.size() < b.size() || a.size() == b.size() && a < b;
}

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++){
        string key = phone_book[i];
        int keysize = key.size();
        
        if(phone_book[i+1].substr(0, keysize) == key){
            return false;
        }
    }
    return true;
}
