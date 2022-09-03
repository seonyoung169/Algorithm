import Foundation
// boj 20444 색종이와 가위, 이분 탐색, 골드 5

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let K = str[1]

var answer = "NO"
var left = 0
var right = N/2

while left<=right {
    let x = (left+right)/2
    let y = N-x
    let frags = (x+1)*(y+1)
    
    if frags<K {
        left = x+1
    } else if frags>K {
        right = x-1
    } else {
        answer = "YES"
        break
    }
}

print(answer)
