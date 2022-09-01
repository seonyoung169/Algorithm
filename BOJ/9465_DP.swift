import Foundation
// boj 9465 스티커, DP, 실버 1

let T = Int(readLine()!)!

var answer = [Int]()

for _ in 0..<T {
    var sticker = [[Int]]()
    
    let N = Int(readLine()!)!
    for _ in 0..<2 {
        let row = readLine()!.split(separator: " ").map{Int($0)!}
        sticker.append(row)
    }
    
    var dp = [[Int]](repeating: [Int](repeating: 0, count: N), count: 2)
    
    
    if N==1 {
        answer.append(max(sticker[0][0], sticker[1][0]))
        continue
    }
    
    dp[0][0] = sticker[0][0]
    dp[1][0] = sticker[1][0]
    dp[0][1] = sticker[1][0] + sticker[0][1]
    dp[1][1] = sticker[0][0] + sticker[1][1]
    
    if N == 2 {
        answer.append(max(dp[0][1], dp[1][1]))
        continue
    }
    
    for j in 2..<N {
        dp[0][j] = max(dp[1][j-1], dp[0][j-2], dp[1][j-2]) + sticker[0][j]
        dp[1][j] = max(dp[0][j-1], dp[0][j-2], dp[1][j-2]) + sticker[1][j]
    }
    
    answer.append(max(dp[0][N-1], dp[1][N-1]))
}

for n in answer {
    print(n)
}
