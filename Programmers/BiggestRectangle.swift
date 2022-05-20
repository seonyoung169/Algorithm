import Foundation

// 프로그래머스 가장 큰 정사각형 찾기, level2, dp
func solution(_ board:[[Int]]) -> Int {
    var answer = 0
    let R = board.count, C = board[0].count
    var memo = Array(repeating: Array(repeating: 0, count: C+1), count: R+1)

    
    for i in 0..<R {
        for j in 0..<C {
            memo[i+1][j+1] = board[i][j]
        }
    }
    
    for i in 1...R {
        for j in 1...C {
            if memo[i][j] == 0 {
                continue
            }
            
            memo[i][j] = min(memo[i-1][j], memo[i][j-1], memo[i-1][j-1]) + 1
            answer = max(answer, memo[i][j])
        }
    }
    
    return answer*answer
}

print(solution([[1,1,1],[1,0,1],[1,1,1]]))

