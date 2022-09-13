import Foundation
// boj 2293 동전1, DP, 골드 5

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let K = str[1]

var coins = [Int]()
for _ in 0..<N {
    let c = Int(readLine()!)!
    coins.append(c)
}

var dp = [Int](repeating: 0, count: K+1)
dp[0] = 1

for i in 0..<N {
    let coin = coins[i]
    
    if coin > K { continue }
    for j in coin...K {
        dp[j] += dp[j-coin]
        if dp[j] > Int(pow(2.0, 31.0)){ dp[j] = 0 }
    }
}

print(dp[K])
