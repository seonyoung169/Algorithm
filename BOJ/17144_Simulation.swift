import Foundation
// boj 17144 미세먼지 안녕! 시뮬, 골드 4

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let R = str1[0]
let C = str1[1]
var T = str1[2]

var map = [[Int]](repeating: [Int](repeating: 0, count: C), count: R)
var machine = [(Int, Int)]()

let dy = [[0,-1,0,1], [0,1,0,-1]]
let dx = [[1,0,-1,0], [1,0,-1,0]]

for i in 0..<R {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    for j in 0..<C {
        map[i][j] = str2[j]
        if map[i][j] == -1 {
            machine.append((i,j))
        }
    }
}

func diffuse() {
    var diffused = [[Int]](repeating: [Int](repeating: 0, count: C), count: R)
    diffused[machine[0].0][machine[0].1] = -1
    diffused[machine[1].0][machine[1].1] = -1
    
    for i in 0..<R {
        for j in 0..<C {
            if map[i][j] < 5 { continue }
            
            var count = 0
            let dust = Int(map[i][j]/5)
            
            for k in 0..<4 {
                let ny = i + dy[0][k]
                let nx = j + dx[0][k]
                
                if ny<0 || ny>=R || nx<0 || nx>=C || map[ny][nx] == -1 { continue }
                
                diffused[ny][nx] += dust
                count += 1
            }
            
            map[i][j] -= dust*count
        }
    }
    
    for i in 0..<R {
        for j in 0..<C {
            map[i][j] += diffused[i][j]
        }
    }
    
    map[machine[0].0][machine[0].1] = -1
    map[machine[1].0][machine[1].1] = -1
    
}

// area 0 = top, 1 = bottom
func clean(_ area : Int, _ moved: inout [[Int]]) {
    let end = machine[area]
    var cur = (machine[area].0 + dy[area][0], machine[area].1 + dx[area][0])
    var dir = 0
    
    moved[cur.0][cur.1] = 0
    
    while dir < 4 && cur != end {
        var ny = cur.0 + dy[area][dir]
        var nx = cur.1 + dx[area][dir]
        
        if ny<0 || ny>=R || nx<0 || nx>=C {
            dir += 1
            ny = cur.0 + dy[area][dir]
            nx = cur.1 + dx[area][dir]
        }
        
        moved[ny][nx] = map[cur.0][cur.1]
        cur = (ny, nx)
    }
}

while T > 0 {
    T -= 1
    diffuse()
    
    var moved = map
    
    clean(0, &moved)
    clean(1, &moved)
    
    map = moved
    
    map[machine[0].0][machine[0].1] = -1
    map[machine[1].0][machine[1].1] = -1
}

var answer = 0

for i in 0..<R {
    for j in 0..<C {
        if map[i][j] == 0 { continue }
        answer += map[i][j]
    }
}
answer += 2

print(answer)
