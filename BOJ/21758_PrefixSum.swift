import Foundation
// boj 21758 꿀 따기, 골드 5, 누적 합

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{Int($0)!}

var answer = -1

var leftSum = arr
var rightSum = arr

for i in 1...N-1 {
    leftSum[i] += leftSum[i-1]
}
for i in (0...N-2).reversed() {
    rightSum[i] += rightSum[i+1]
}


for i in 1..<N-1 {
    answer = max(answer, leftSum[N-1] - leftSum[0] + leftSum[N-1] - leftSum[i] - arr[i])
}

for i in 1..<N-1 {
    answer = max(answer, rightSum[0] - rightSum[N-1] + rightSum[0] - rightSum[i] - arr[i])
}

for i in 1..<N-1 {
    answer = max(answer, leftSum[i] - leftSum[0] + rightSum[i] - rightSum[N-1])
}


print(answer)



