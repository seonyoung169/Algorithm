import Foundation
// boj 2473 세 용액, 투포인터, 골드 3

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{Int64($0)!}

arr = arr.sorted(by: < )

var flag = 0
var min = Int64.max
var answer = ""

while flag<N-2 {
    var left = flag+1
    var right = N-1
    
    while left<right {
        let sum = arr[flag] + arr[left] + arr[right]
        
        if min > sum.magnitude {
            min = Int64(sum.magnitude)
            answer = "\(arr[flag]) \(arr[left]) \(arr[right])"
        }
        
        if sum<0 {
            left += 1
        } else if sum > 0 {
            right -= 1
        } else {
            break
        }
    }
    flag += 1
}

print(answer)

