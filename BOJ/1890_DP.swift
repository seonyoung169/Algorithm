import Foundation
// boj 1890 점프, 실버 1, DP

var map = [[Int]]()
var dp : [[Int64]] = Array(repeating: Array(repeating: 0, count: 101), count: 101)
var size = -1

if let N = readLine() {
    
    size = Int(N)!
    
    for _ in 0..<size {
        if let row = readLine() {
            map.append(row.components(separatedBy: " ").map{Int($0)!})
        }
    }
}

func solution() -> Int64 {
    dp[0][0] = 1
    
    for i in 0..<size {
        for j in 0..<size {
            if i==size-1 && j==size-1 {
                break
            }
            
            let value = map[i][j]
            let right_x = j + value
            let down_y = i + value
            
            if(right_x < size) {
                dp[i][right_x] += dp[i][j]
            }
            
            if(down_y < size) {
                dp[down_y][j] += dp[i][j]
            }
        }
    }
    
    
    return dp[size-1][size-1]
}

print(solution())
