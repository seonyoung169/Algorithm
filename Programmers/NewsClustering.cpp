#include <iostream>
#include <string>
#include <map>

// 프로그래머스 뉴스 클러스터링, 구현, string, level 2
using namespace std;

int isSmall(char ch){
    if(ch>='a' && ch<='z') return 1;
    if(ch>='A' && ch<='Z') return 0;
    return 2;
}

map<string, int> makeSet(string str){
    map<string, int> set;
    for(int i=0; i<str.size()-1; i++){
        string key = str.substr(i,2);
        if(isSmall(key[0])==2 || isSmall(key[1])==2) continue;  // 예외 문자 제외
        
        if(isSmall(key[0])){
            key[0] = toupper(key[0]);
            str[i] = key[0];
        } 
        if(isSmall(key[1])){
            key[1] = toupper(key[1]);
            str[i+1] = key[1];
        }
        
        if(set.find(key) == set.end()) set.insert({key, 1});
        else set[key] += 1;
    }
    return set;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    map<string, int> set_A, set_B, inter, uni;
    set_A = makeSet(str1);
    set_B = makeSet(str2);
    
    int inter_size = 0, uni_size = 0;
    
    for(auto iter : set_A){
        uni.insert(iter);
    }
    
    for(auto iter : set_B){
        if(uni.find(iter.first) == uni.end()) uni.insert(iter);
        else{
            int small = min(uni[iter.first], iter.second);
            int big = max(uni[iter.first], iter.second);
            
            uni[iter.first] = big;
            inter.insert({iter.first, small});
            inter_size += small;
        }
    }
    
    for(auto iter : uni) uni_size += iter.second;
    
    cout<<inter_size<<' '<<uni_size<<'\n';
    
    if(inter_size==0 && uni_size==0) return 65536;
    if(inter_size==0 || uni_size==0) return 0;
    
    double result = (double)inter_size / (double)uni_size;
    result *= 65536;
    answer = result/1;
    
    return answer;
}
