import Foundation

// 프로그래머스 n^2 배열 자르기, level 2

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    var answer : [Int] = []
    
    for index in left...right {
        let row = Int(index) / n
        let col = Int(index) % n
        
        answer.append(max(row, col) + 1)
    }
    
    return answer
}
