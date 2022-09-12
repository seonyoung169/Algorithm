import Foundation
// boj 2293 동전 1, DP, 골드 5

var input = readLine()!.split(separator: " ").map{ Int($0)! }
var N = input[0]
var K = input[1]
var coins = [Int]()

for _ in 0..<N{
    let coin = Int(readLine()!)!
    coins.append(coin)
}

var dp = [Int](repeating: 0, count: K+1)

dp[0] = 1

for coin in coins{
    for j in 1...K{
        if coin <= j {
            dp[j] += dp[j-coin]
            if dp[j] > Int(pow(2.0, 31.0)){ dp[j] = 0 }
        }
    }
}

print(dp[K])
