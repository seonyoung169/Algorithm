
import Foundation

// 프로그래머스 가장 큰 수, 정렬, level 2

func cmp(_ str1: String, _ str2: String) -> Bool {
    if str1+str2 > str2+str1 {
        return true
    }
    return false
}

func solution(_ numbers:[Int]) -> String {
    var array = numbers.map{String($0)}
    array.sort(by: cmp)
    
    if array[0] == "0" {
        return "0"
    }
    
    let answer = array.reduce(""){$0+$1}
    
    return answer
}
