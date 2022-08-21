import Foundation
// boj 2470 두 용액, 투포인터, 골드 5

let N = Int(readLine()!)!
var liquid = [Int]()

let str = readLine()!.split(separator: " ").map{Int($0)!}
for num in str {
    liquid.append(num)
}

liquid = liquid.sorted(by: <)

var left = 0
var right = N-1
var minSum = Int.max
var answerLeft = -1
var answerRight = -1

while left < right {
    let sum = liquid[left] + liquid[right]
    
    if minSum > Int(sum.magnitude) {
        minSum = Int(sum.magnitude)
        answerLeft = liquid[left]
        answerRight = liquid[right]
    }
    
    if sum<0 {
        left += 1
    } else {
        right -= 1
    }
}


print("\(answerLeft) \(answerRight)")
