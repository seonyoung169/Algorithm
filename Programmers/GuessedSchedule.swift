import Foundation

// 프로그래머스, 예상 대진표, level 2
func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var answer = 0
    var ap = a, bp = b
    
    while (ap != bp){
        answer += 1
        ap = (ap+1)/2
        bp = (bp+1)/2
    }
    return answer
}

