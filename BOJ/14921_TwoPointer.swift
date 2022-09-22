
import Foundation
// boj 14921 용액 합성하기, 골드 5, 투포인터

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int($0)!}

var result = 2*100000000
var answer = -1
var left = 0
var right = N-1

while left<right {
    let sum = arr[left] + arr[right]
    
    if result > Int(sum.magnitude) {
        result = Int(sum.magnitude)
        answer = sum
    }
    
    if sum<0 {
        left += 1
    } else if sum>0 {
        right -= 1
    } else {
        break
    }
}

print(answer)

