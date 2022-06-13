import Foundation

// 프로그래머스 빛의 경로 사이클, level 2 인데 3인듯 ㅡㅡ

struct Location : Equatable {
    var y : Int, x : Int, dir : Int
}

func turn(_ to : String, _ d : Int) -> Int {
    if to == "S" {
        return d
    } else if to == "L" {
        return (d+3) % 4
    } else {
        return (d+1) % 4
    }
}


func solution(_ grid:[String]) -> [Int] {
    var answer : [Int] = []
    
    let R = grid.count
    let C = grid[0].count
    let map = grid.map{$0.map{String($0)}}
    let dy = [-1,0,1,0]
    let dx = [0,1,0,-1]
    var visited = Array(repeating: Array(repeating: Array(repeating: false, count: 4), count: C), count: R)
    
    for i in 0..<R {
        for j in 0..<C {
            for k in 0..<4 {
                if visited[i][j][k] { continue }
                
                let start = Location(y: i, x: j, dir: k)
                var cur = start
                var count = 0
                
                while (true){
                    if visited[cur.y][cur.x][cur.dir] { break }
                    
                    count += 1
                    visited[cur.y][cur.x][cur.dir] = true
                    
                    let nd = turn(map[cur.y][cur.x], cur.dir)
                    let ny = (cur.y + dy[nd] + R) % R
                    let nx = (cur.x + dx[nd] + C) % C
                    
                    cur.y = ny
                    cur.x = nx
                    cur.dir = nd
                    
                    if cur == start && count > 0 {
                        answer.append(count)
                        break
                    }
                }
                
            }
        }
    }
    
    return answer.sorted()
}

print(solution(["SL","LR"]))
