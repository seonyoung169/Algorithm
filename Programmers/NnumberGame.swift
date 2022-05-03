import Foundation

// 프로그래머스 N진수 게임, level 2 

let list = ["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E", "F"]

extension String {
    subscript(idx: Int) -> String? {
        guard (0..<count).contains(idx) else {
            return nil
        }
        
        let target = index(startIndex, offsetBy: idx)
        return String(self[target])
    }
}

func n_convert(_ num : Int, _ n : Int) -> String {
    var result = ""
    var number = num
    
    while(number >= n){
        let left = number%n
        result = list[left] + result
        number = number/n
    }
    result = list[number] + result
    
    return result
}

func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    var answer = ""
    var converted = "0"
    
    for i in 1..<t*m {
        converted += n_convert(i, n)
    }
    
    var count = t, i = p-1
    while(count>0){
        guard let frag = converted[i] else {
            continue
        }
        
        answer += frag
        i += m
        count -= 1
    }
    
    return answer
}

print(solution(16,16,2,1))
