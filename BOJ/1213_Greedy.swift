import Foundation
// boj 1213 팰린드롬 만들기, 실버3, 구현, 그리디라는데.. 왜 그리디인가..? 
let str = readLine()!
var alphabet = [Int](repeating: 0, count: 26)

for ch in str {
    let idx = Int(ch.unicodeScalars.first!.value) - 65
    alphabet[idx] += 1
}

var oddCount = 0
for i in 0..<26 {
    if alphabet[i] % 2 == 1 {
        oddCount += 1
    }
    
    if oddCount>=2 {
        break
    }
}

var answer = ""

if oddCount>=2 {
    answer = "I'm Sorry Hansoo"
} else {
    var token = ""
    var center = ""
    
    for i in 0..<26 {
        if alphabet[i] == 0 { continue }
        
        if alphabet[i] % 2 == 1 {
            center = String(UnicodeScalar(65 + i)!)
            alphabet[i] -= 1
        }
        
        for _ in 0..<alphabet[i]/2 {
            token += String(UnicodeScalar(65 + i)!)
        }
    }
    
    answer += token
    if center != "" {
        answer += center
    }
    
    answer += token.reversed()
}

print(answer)
