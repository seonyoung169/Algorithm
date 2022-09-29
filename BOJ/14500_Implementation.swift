import Foundation
// boj 14500 테트로미노, 구현, 골드 4

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let M = str[1]

var answer = 0
var board = [[Int]]()
for _ in 0..<N {
    let row = readLine()!.split(separator: " ").map{Int($0)!}
    board.append(row)
}


let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

func isInRange(at point: (Int, Int)) -> Bool {
    return 0..<board.count ~= point.0 && 0..<board[0].count ~= point.1
}

func makeTetromino(_ count: Int, _ list: [(Int, Int)], _ sum: Int) {
    if count == 4 {
        answer = max(answer, sum)
        return
    }
     
    let cur = list[count-1]
    for i in 0..<4 {
        let ny = cur.0 + dy[i]
        let nx = cur.1 + dx[i]
        
        if !isInRange(at: (ny, nx)) { continue }
        if visited[ny][nx] { continue }
        
        visited[ny][nx] = true
        makeTetromino(count+1, list + [(ny,nx)], sum + board[ny][nx])
        visited[ny][nx] = false
    }
    
}

func shape1(_ r: Int, _ c: Int) -> Int {
    return board[r][c] + board[r][c+1] + board[r][c+2] + board[r-1][c+1]
}

func shape2(_ r: Int, _ c: Int) -> Int {
    return board[r][c] + board[r][c+1] + board[r][c+2] + board[r+1][c+1]
}

func shape3(_ r: Int, _ c: Int) -> Int {
    return board[r][c] + board[r-1][c+1] + board[r][c+1] + board[r+1][c+1]
}

func shape4(_ r: Int, _ c: Int) -> Int {
    return board[r][c] + board[r+1][c] + board[r+1][c+1] + board[r+2][c]
}

var visited = [[Bool]](repeating: [Bool](repeating: false, count: M), count: N)

for i in 0..<N {
    for j in 0..<M {
        let list = [(i, j)]
        
        visited[i][j] = true
        makeTetromino(1, list, board[i][j])
        visited[i][j] = false
        
        if i-1>=0 && j+2<M {
            let sum1 = shape1(i, j)
            answer = max(answer, sum1)
        }
        
        if i+1<N && j+2<M {
            let sum2 = shape2(i,j)
            answer = max(answer, sum2)
        }
        
        if i-1>=0 && i+1<N && j+1<M {
            let sum3 = shape3(i, j)
            answer = max(answer, sum3)
        }
        
        if i+2<N && j+1<M {
            let sum4 = shape4(i, j)
            answer = max(answer, sum4)
        }
    }
}

print(answer)
