import Foundation
// 프로그래머스 위장, Level 2, 해시

func solution(_ clothes:[[String]]) -> Int {
    var dic = [String : Int]()
    
    for arr in clothes {
        let key = arr[1]
        
        guard let value = dic[key] else {
            dic[key] = 1
            continue
        }
        
        dic.updateValue(value + 1, forKey: key)
    }
    
    var answer = 1
    for (key, value) in dic {
        answer *= (value + 1)
    }
    
    return answer-1
}

print(solution([["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]))
