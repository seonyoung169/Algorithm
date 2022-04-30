#include <string>
#include <vector>
#include <map>
#include <algorithm>

// 프로그래머스 매칭 점수, level 3, 복잡한 구현, 문자연 
using namespace std;

struct PageInfo {
    int basePoint;
    vector<string> output;

    int input = 0;
    double linkPoint = 0.0;
    double matchPoint = 0.0;
    int index;

    PageInfo() {};
    PageInfo(int b, vector<string> urls, int i) : basePoint(b), output(urls), index(i) {};
};

// 소문자 변환
string makeLower(string str){
    string result = str;
    for(int i = 0;i <str.size(); i++) result[i] = tolower(str[i]);
    return result;
}

// 링크 추출
string getURL(string page){
    string target1 = "<meta property=\"og:url\" content=\"https://";
    string target2 = "\"";

    int start = page.find(target1) + target1.size();
    int end = page.find(target2, start);

    return page.substr(start, end-start);
}

bool cmp (pair<string, PageInfo>& a, pair<string, PageInfo>& b){
    if (a.second.matchPoint == b.second.matchPoint){
        return a.second.index < b.second.index;
    }
    return a.second.matchPoint > b.second.matchPoint;
};
// body 추출
string getBody(string page){
    string target1 = "<body>", target2 = "</body>";
    int start = page.find(target1) + target1.size();
    int end = page.find(target2);

    return page.substr(start, end-start);
}

// body 내 외부 링크 제외 순수 text 추출
string getText(string body){
    string text = "";

    bool inTag = false;
    for (int i = 0; i < body.size(); ++i) {
        if(body[i] == '<') {
            inTag = true;
            continue;
        }
        if(body[i] == '>'){
            inTag = false;
            continue;
        }

        if (!inTag) text += body[i];
    }
    return text;
}

// 기본점수 계산
int countWord(string text, string word){
    int cnt = 0;

    string token = "";
    for (int i = 0; i < text.size(); ++i) {
        if (isalpha(text[i]) != 0) token += text[i];
        else{
            if (token == word) cnt++;
            token = "";
        }
    }
    return cnt;
}

// a tag 내 링크 수집
vector<string> checkLink(string body){
    vector<string> links;
    string target1 = "<a href=\"https://";
    string target2 = "\">";

    int pos = 0;
    int start = 0, end = 0;

    while (1){
        start = body.find(target1, pos);
        if (start == string::npos) break;

        end = body.find(target2, start);
        int len = end - (start + target1.size());

        string url = body.substr(start+target1.size(), len);
        links.push_back(url);
        pos = end + target2.size();
    }

    return links;
}

int solution(string word, vector<string> pages) {
    double score = -1;
    int answer = pages.size();
    map<string, PageInfo> network;

    word = makeLower(word);

    // map 완성
    for (int i = 0; i < pages.size(); ++i) {
        pages[i] = makeLower(pages[i]);

        string url = getURL(pages[i]);
        string body = getBody(pages[i]);

        string text = getText(body);
        int basePoint = countWord(text,word);
        vector<string> links = checkLink(body);

        network.insert({url, PageInfo(basePoint, links, i)});
    }

    // 외부 링크 계산
    for (auto iter = network.begin(); iter != network.end(); iter++) {
        vector<string> links = iter->second.output;
        for (int i = 0; i < links.size(); ++i) {
            if (network.find(links[i]) != network.end()){
                network[links[i]].input += 1;
            }
        }
    }

    // 링크 점수 계산
    for (auto iter = network.begin(); iter != network.end(); iter++) {
        vector<string> links = iter->second.output;
        for (int i = 0; i < links.size(); ++i) {
            if (network.find(links[i]) != network.end()) {
                double point = double(iter->second.basePoint) / double(iter->second.output.size());
                network[links[i]].linkPoint += point;
            }
        }
    }

    // 매칭 점수 계산
    for (auto iter = network.begin(); iter != network.end(); iter++) {
        iter->second.matchPoint = iter->second.basePoint + iter->second.linkPoint;
    }

    // 정답 추출
    vector<pair<string, PageInfo>> v(network.begin(), network.end());
    sort(v.begin(), v.end(), cmp);

    return v[0].second.index;
}
