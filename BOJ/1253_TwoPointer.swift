import Foundation
// boj 1253 좋다, 투포인터, 골드 4 

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int64($0)!}.sorted()

var answer = 0

func isGood(_ idx: Int, _ num: Int64) -> Bool {
    var left = 0, right = N-1
    
    if left==idx {
        left += 1
    } else  if right==idx {
        right -= 1
    }
    
    while left<right {
        let sum : Int64 = arr[left] + arr[right]
        
        if num < sum {
            right -= 1
            if right==idx { right -= 1 }
        }
        else if num > sum {
            left += 1
            if left==idx { left += 1}
        }
        else {
            return true
        }
    }
    
    return false
}

if N < 3 {
    answer = 0
} else {
    for i in 0..<N {
        if isGood(i, arr[i]) {
            answer += 1
        }
    }
}

print(answer)
