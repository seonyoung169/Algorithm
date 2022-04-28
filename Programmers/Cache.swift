import Foundation

// 프로그래머스 캐시, level 2, LRU 알고리즘 적용 
func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    if cacheSize==0 {
        return 5*cities.count
    }
    
    let cities = cities.map({ $0.lowercased()})
    var cache = [String]()
    var hit = 0, miss = 0
    
    for city in cities {
        
        var exist = false
        for i in 0..<cache.count {
            if cache[i] == city {
                exist = true
                cache.remove(at: i)
                break
            }
        }
        
        if exist {
            hit += 1
        }else{
            miss += 1
            if cache.count >= cacheSize {
                cache.removeFirst()
            }
        }
        cache.append(city)
    }
    
    return miss*5 + hit
}
