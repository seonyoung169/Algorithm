import Foundation
// boj 2230 수 고르기, 투포인터, 골드 5

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let M = str[1]

var arr = [Int]()
var answer = Int.max

for _ in 0..<N {
    let num = Int(readLine()!)!
    arr.append(num)
}

arr = arr.sorted(by: <)

var left = 0
var right = 0

while left<N && right<N {
    let diff = arr[right]-arr[left]
    
    if diff<M {
        right+=1
    } else {
        answer = min(answer, diff)
        left+=1
    }
}

print(answer)
