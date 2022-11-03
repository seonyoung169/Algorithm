import Foundation
// boj 2096 내려가기, dp, 골드 5

let N = Int(readLine()!)!
var map = [[Int]]()

for _ in 0..<N {
    let row = readLine()!.split(separator: " ").map{Int($0)!}
    map.append(row)
}

func solve() -> String {
    var minDP = [[Int]](repeating: [Int](repeating: 0, count: 3), count: N)
    var maxDP = [[Int]](repeating: [Int](repeating: 0, count: 3), count: N)
    
    minDP[0][0] = map[0][0]
    minDP[0][1] = map[0][1]
    minDP[0][2] = map[0][2]
    
    maxDP[0][0] = map[0][0]
    maxDP[0][1] = map[0][1]
    maxDP[0][2] = map[0][2]
    
    for i in 1..<N {
        minDP[i][0] = min(minDP[i-1][0]+map[i][0], minDP[i-1][1]+map[i][0])
        minDP[i][1] = min(minDP[i-1][0]+map[i][1] ,minDP[i-1][1]+map[i][1], minDP[i-1][2]+map[i][1])
        minDP[i][2] = min(minDP[i-1][1]+map[i][2], minDP[i-1][2]+map[i][2])
        
        maxDP[i][0] = max(maxDP[i-1][0]+map[i][0], maxDP[i-1][1]+map[i][0])
        maxDP[i][1] = max(maxDP[i-1][0]+map[i][1] ,maxDP[i-1][1]+map[i][1], maxDP[i-1][2]+map[i][1])
        maxDP[i][2] = max(maxDP[i-1][1]+map[i][2], maxDP[i-1][2]+map[i][2])
    }
    
    let minSum = min(minDP[N-1][0], minDP[N-1][1], minDP[N-1][2])
    let maxSum = max(maxDP[N-1][0], maxDP[N-1][1], maxDP[N-1][2])
    
    return "\(maxSum) \(minSum)"
}

print(solve())

