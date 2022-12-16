import Foundation

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int($0)!}

var stack = [(Int, Int)](repeating: (0,0), count: N+2)
var idx = 0 // stack top 의 위치
var size = 1 // stack 사이즈

stack[0] = (arr[0], 1)

var answer = "0 "

for i in 1..<N {
    
    while size > 0 {
        if arr[i] < stack[idx].0 {
            answer += "\(stack[idx].1) "
            break
        }
        
        size -= 1
        idx -= 1
    }
    
    if size == 0 {
        answer += "0 "
    }
    
    stack[idx+1] = (arr[i], i+1)
    idx += 1
    size += 1
}

print(answer)
