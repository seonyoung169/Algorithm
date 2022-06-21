import Foundation
// 프로그래머스 JadenCase 문자열 만들기, 문자열, level 2

func solution(_ s:String) -> String {
    var answer = ""
    let array = Array(s)
    
    answer += String(array[0])
    
    if array[0] >= "a" && array[0] <= "z" {
        answer = answer.uppercased()
    }
    
    var firstflag = false
    
    for i in 1..<array.count {
        if array[i] == " " {
            answer += " "
            firstflag = true
            continue
        }
        
        if firstflag {
            if array[i] >= "a" && array[i] <= "z" {
                answer += String(array[i]).uppercased()
            } else {
                answer += String(array[i])
            }
            firstflag = false
        } else {
            answer += String(array[i]).lowercased()
        }
        
        
    }

    return answer
}
