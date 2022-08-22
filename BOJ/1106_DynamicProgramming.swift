import Foundation
// boj 1106 호텔, 골드 5 dp

let st1 = readLine()!.split(separator: " ").map{Int($0)!}
let C = st1[0]
let N = st1[1]

var promInfo = [(Int, Int)]()
var dp = [Int](repeating: Int.max-100, count: C+101)

dp[0] = 0

for _ in 0..<N {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    promInfo.append((str2[0], str2[1]))
}

promInfo = promInfo.sorted{ $0.1 < $1.1 }

for (m, p) in promInfo {
    for i in p...(C+100) {
        dp[i] = min(dp[i], dp[i-p] + m)
    }
}

print(dp[C...C+100].min()!)
