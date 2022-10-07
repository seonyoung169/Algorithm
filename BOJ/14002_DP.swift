import Foundation
// boj 14002 가장 긴 증가하는 부분 수열4, DP, 골드 4

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int($0)! }
var dp = [Int](repeating: 0, count: N)
dp[0] = 1

var answer = ""
var maxLen = 1
var lastIdx = 0

if N == 1 {
    answer = "\(arr[0])"
} else {
    for i in 1..<N {
        var len = 0
        for j in 0..<i {
            if arr[j] < arr[i] {
                len = max(dp[j], len)
            }
        }
        dp[i] = len + 1
        
        if maxLen < dp[i] {
            maxLen = dp[i]
            lastIdx = i
        }
    }

    answer = "\(arr[lastIdx])"
    
    var lastLen = dp[lastIdx]
    for i in (0..<lastIdx).reversed(){
        if dp[i] == lastLen-1 {
            answer = "\(arr[i]) " + answer
            lastLen = dp[i]
        }
    }
}

print(maxLen)
print(answer)
