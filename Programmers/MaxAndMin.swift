import Foundation
// 프로그래머스 최댓값과 최솟값, level 2 

func solution(_ s:String) -> String {
    
    var numbers : [Int] = []
    let tokens = s.components(separatedBy: " ")
    
    for tok in tokens {
        numbers.append(Int(tok)!)
    }
    
    var min = numbers[0], max = numbers[0]
    for i in 1..<numbers.count {
        if min > numbers[i] {
            min = numbers[i]
        }
        
        if max < numbers[i] {
            max = numbers[i]
        }
    }
    
    return String(min) + " " + String(max)
}
