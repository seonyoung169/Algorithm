#include <string>
#include <vector>
#include <list>
#include <algorithm>

// 프로그래머스 캐시, level 2, 구현, LRU 캐시 알고리즘
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int hit = 0, miss = 0;
    if (cacheSize == 0) return 5*cities.size();

    list<string> cache;

    for (int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

        list<string>::iterator iter;
        bool exist = false;

        for (iter = cache.begin(); iter!=cache.end(); iter++) {
            if (*iter == cities[i]){
                exist = true;
                break;
            }
        }

        if (exist){
            cache.erase(iter);
            hit++;
        }else{
            if (cache.size() >= cacheSize){
                cache.pop_back();
            }
            miss++;
        }
        cache.push_front(cities[i]);
    }

    return hit + 5*miss;
}
