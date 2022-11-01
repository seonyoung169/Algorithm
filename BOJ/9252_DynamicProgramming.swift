import Foundation
// boj 9252 lcs 2

let str1 = Array(readLine()!)
let str2 = Array(readLine()!)

let N = str1.count
let M = str2.count

var dp = [[Int]](repeating: [Int](repeating: 0, count: M+1), count: N+1)

for i in 1...N {
    for j in 1...M {
        if str1[i-1] == str2[j-1] {
            dp[i][j]  = dp[i-1][j-1] + 1
        }else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        }
    }
}

var length = dp[N][M]
print(length)

if length != 0 {
    var lcs = ""
    var row = N, col = M
    while (dp[row][col] != 0) {
        
        if (dp[row][col] == dp[row - 1][col]) {
            row -= 1
        }
        else if (dp[row][col] == dp[row][col - 1]) {
            col -= 1
        }
        else {
            lcs = "\(str1[row-1])" + lcs
            row -= 1
            col -= 1
        }
        
    }
    
    print(lcs)
}


