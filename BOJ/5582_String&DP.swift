import Foundation
// boj 5582 공통 부분 문자열, 골드 5, 문자열, dp

let str1 = readLine()!.map{ String($0)}
let str2 = readLine()!.map{ String($0)}

let N = str1.count
let M = str2.count

var dp = [[Int]](repeating: [Int](repeating: 0, count: N+1), count: M+1)
var answer = 0

for i in 1...M {
    for j in 1...N {
        if str2[i-1] == str1[j-1] {
            dp[i][j] = dp[i-1][j-1] + 1
            answer = max(answer, dp[i][j])
        }
        
    }
}

print(answer)
