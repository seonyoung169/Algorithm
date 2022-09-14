import Foundation
// boj 9935 문자열 폭발, 문자열, 골드 4

var origin = Array(readLine()!)
let bomb = Array(readLine()!)

var st = [String](repeating: "", count: 1000001)

var idx = 0
for i in 0..<origin.count {
    st[idx] = String(origin[i])
    idx += 1
    
    // C4 중 4를 찾으면
    if origin[i] == bomb[bomb.count-1] {
        var found = true
        
        for j in 0..<bomb.count {
            if idx-1-j < 0 {
                found = false
                break
            }
            if st[idx-1-j] != String(bomb[bomb.count-1-j]) {
                found = false
                break
            }
        }
        
        if found {
            idx -= bomb.count
        }
    }
}

var answer = ""

if idx == 0 {
    answer = "FRULA"
} else {
    for i in 0..<idx {
        answer += st[i]
    }
}

print(answer)
