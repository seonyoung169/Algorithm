import Foundation

// 프로그래머스 삼각 달팽이, level 2, 구현

let dy = [1,0,-1]
let dx = [0,1,-1]

func solution(_ n:Int) -> [Int] {
    
    var matrix = Array(repeating: Array(repeating: 0, count: n), count: n)
    var count = 0, dir = 0, cycle_max = n
    var cur_num = 1
    var y = 0, x = 0
    
    while(cycle_max > 0) {
        matrix[y][x] = cur_num
        count += 1
        cur_num += 1
        
        if count == cycle_max {
            dir = (dir+1) % 3
            cycle_max -= 1
            count = 0
        }
        
        y += dy[dir]
        x += dx[dir]
    }
    
    var answer  : [Int] = []
    
    for i in 0..<n {
        for j in 0..<i+1 {
            answer.append(matrix[i][j])
        }
    }
    
    return answer
}
