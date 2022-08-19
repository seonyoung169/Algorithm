import Foundation
// boj 17609 회문, 문자열, 골드 5

let T = Int(readLine()!)!

var answer = ""

for _ in 0..<T {
    let word = readLine()!.map{String($0)}
    var result = 0
    var left = 0, right = word.count-1
    
    while left < right {
        if word[left] == word[right] {
            left += 1
            right -= 1
        } else {
            var nLeft = left + 1
            var nRight = right
            
            while nLeft < nRight {
                if word[nLeft] ==  word[nRight] {
                    nLeft += 1
                    nRight -= 1
                } else {
                    result += 1
                    break
                }
            }
            
            nLeft = left
            nRight = right-1
            
            while nLeft < nRight {
                if word[nLeft] ==  word[nRight] {
                    nLeft += 1
                    nRight -= 1
                } else {
                    result += 1
                    break
                }
            }
            
            if result == 0 { result += 1}
            break
        }
    }
    answer += "\(result)\n"
}

print(answer)

