import Foundation
// boj 10036 적록색약, bfs, 골드 5

let N = Int(readLine()!)!

var normal = [[String]](repeating: [String](repeating: "", count: N), count: N)
var special = [[String]](repeating: [String](repeating: "", count: N), count: N)

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

for i in 0..<N {
    let input = readLine()!.map{String($0)}
    for j in 0..<N {
        normal[i][j] = input[j]
        
        if input[j] == "G" {
            special[i][j] = "R"
        } else {
            special[i][j] = input[j]
        }
    }
}

func bfs(_ startR: Int, _ startC: Int, _ board: [[String]], _ visited: inout [[Bool]]) {
    var queue = [(Int, Int)]()
    queue.append((startR, startC))
    
    var front = 0
    let ch = board[startR][startC]
    
    visited[startR][startC] = true
    
    while front < queue.count {
        let cur = queue[front]
        front += 1
        
        for i in 0..<4 {
            let ny = cur.0 + dy[i]
            let nx = cur.1 + dx[i]
            
            if ny<0 || ny>=N || nx<0 || nx>=N { continue }
            
            if !visited[ny][nx] && board[ny][nx] == ch {
                visited[ny][nx] = true
                queue.append((ny,nx))
            }
        }
    }
}

var normalCount = 0
var specialCount = 0

var normalVisited = [[Bool]](repeating: [Bool](repeating: false, count: N), count: N)
var specialVisited = [[Bool]](repeating: [Bool](repeating: false, count: N), count: N)

for i in 0..<N {
    for j in 0..<N {
        if !normalVisited[i][j] {
            normalCount += 1
            bfs(i, j, normal, &normalVisited)
        }
        
        if !specialVisited[i][j] {
            specialCount += 1
            bfs(i, j, special, &specialVisited)
        }
    }
}


print("\(normalCount) \(specialCount)")

