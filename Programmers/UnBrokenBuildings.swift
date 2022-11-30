import Foundation

// 프로그래머스 파괴되지 않은 건물, level 3
var temp = [[Int]]()

func solution(_ board:[[Int]], _ skill:[[Int]]) -> Int {
    var count = 0
    let N = board.count
    let M = board[0].count
    
    temp = [[Int]](repeating: [Int](repeating: 0, count: M+1), count: N+1)
    
    for sk in skill {
        var d = sk[0] == 1 ? -sk[5] : sk[5]
        
        temp[sk[1]][sk[2]] += d
        temp[sk[1]][sk[4]+1] -= d
        temp[sk[3]+1][sk[2]] -= d
        temp[sk[3]+1][sk[4]+1] += d
    }
    
    for i in 0...N {
        for j in 1...M {
            temp[i][j] += temp[i][j-1]
        }
    }
    
    for j in 0...M {
        for i in 1...N {
            temp[i][j] += temp[i-1][j]
        }
    }
    
    for i in 0..<N {
        for j in 0..<M {
            let value = board[i][j] + temp[i][j]
            if value>0 {
                count += 1
            }
        }
    }
    
    return count
}
