#include <iostream>
#include <vector>
#include <map>

// boj 12933 오리, 구현 
using namespace std;

map<char, char> nextCh;

int countDuck(string sound){

    if (sound.size() % 5 != 0) return -1;
    if (sound[0] != 'q') return -1;

    vector<bool> isChecked(sound.size(), false);
    int alive = sound.size()-1;
    int count = 0;


    char before = sound[0];
    isChecked[0] = true;
    int i = 1;

    while (alive>0){
        for (; i < sound.size(); ++i) {
            if (isChecked[i]) continue;

            if (nextCh[before] == sound[i]){
                isChecked[i] = true;
                alive--;
                before = sound[i];
            } else continue;
        }

        if (before == 'k'){
            count ++;
            if (alive==0) break;
            for (int j = 0; j < sound.size(); ++j) {
                if (!isChecked[j]) {
                    before = sound[j];
                    isChecked[j] = true;
                    alive--;
                    i = j+1;
                    break;
                }
            }
        } else{
            count = -1;
            break;
        }
    }

    if(count==0) count = -1;

    return count;
}

int main(){
    string sound;
    cin>>sound;

    nextCh.insert({'q','u'});
    nextCh.insert({'u','a'});
    nextCh.insert({'a','c'});
    nextCh.insert({'c','k'});
    nextCh.insert({'k','q'});

    cout<<countDuck(sound);

    return 0;
}

