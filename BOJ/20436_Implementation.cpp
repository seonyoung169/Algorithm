#include <iostream>
#include <map>
#include <cmath>

using namespace std;

map<char, pair<int, int>> left_keyboard;
map<char, pair<int, int>> right_keyboard;

int distance(pair<int, int> from, pair<int, int> to) {
    return abs(from.first-to.first) + abs(from.second-to.second);
}

int main() {

    left_keyboard.insert({'q',{0,0}});
    left_keyboard.insert({'w',{0,1}});
    left_keyboard.insert({'e',{0,2}});
    left_keyboard.insert({'r',{0,3}});
    left_keyboard.insert({'t',{0,4}});
    right_keyboard.insert({'y',{0,5}});
    right_keyboard.insert({'u',{0,6}});
    right_keyboard.insert({'i',{0,7}});
    right_keyboard.insert({'o',{0,8}});
    right_keyboard.insert({'p',{0,9}});

    left_keyboard.insert({'a',{1,0}});
    left_keyboard.insert({'s',{1,1}});
    left_keyboard.insert({'d',{1,2}});
    left_keyboard.insert({'f',{1,3}});
    left_keyboard.insert({'g',{1,4}});
    right_keyboard.insert({'h',{1,5}});
    right_keyboard.insert({'j',{1,6}});
    right_keyboard.insert({'k',{1,7}});
    right_keyboard.insert({'l',{1,8}});

    left_keyboard.insert({'z',{2,0}});
    left_keyboard.insert({'x',{2,1}});
    left_keyboard.insert({'c',{2,2}});
    left_keyboard.insert({'v',{2,3}});
    right_keyboard.insert({'b',{2,4}});
    right_keyboard.insert({'n',{2,5}});
    right_keyboard.insert({'m',{2,6}});

    char left, right;
    string word;
    cin>>left>>right>>word;

    pair<int, int> left_pos = left_keyboard[left];
    pair<int, int> right_pos = right_keyboard[right];

    int answer = 0;
    for (int i = 0; i < word.size(); ++i) {
        answer++;
        if (word[i]==left || word[i]==right) continue;

        if (right_keyboard.find(word[i]) != right_keyboard.end()){
            answer += distance(right_pos, right_keyboard[word[i]]);
            right_pos = right_keyboard[word[i]];
            right = word[i];
        } else {
            answer += distance(left_pos, left_keyboard[word[i]]);
            left_pos = left_keyboard[word[i]];
            left = word[i];
        }
    }

    cout<<answer;

    return 0;
}
