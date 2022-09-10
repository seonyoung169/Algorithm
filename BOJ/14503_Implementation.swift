import Foundation
// boj 14503 로봇 청소기, 구현, 골드 5

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

let str2 = readLine()!.split(separator: " ").map{Int($0)!}
var loc = (str2[0], str2[1])
var dir = str2[2]

var map = [[Int]]()
for _ in 0..<N {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    map.append(str3)
}

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

var count = 0
var visited = [[Bool]](repeating: [Bool](repeating: false, count: M), count: N)

func find(_ y: Int, _ x: Int, _ d: inout Int) -> (Int, Int) {
    var loc = (-1,-1)
    
    for _ in 0..<4 {
        d = (d+3) % 4
        let ny = y + dy[d]
        let nx = x + dx[d]
        
        if ny<0 || ny>=N || nx<0 || nx>=M {
            continue
        }
        
        if !visited[ny][nx] && map[ny][nx] == 0 {
            loc = (ny, nx)
            break
        }
    }
    
    return loc
}

visited[loc.0][loc.1] = true

while count<N*M {
    count += 1
    
    var newLoc = find(loc.0, loc.1, &dir)
    
    if newLoc == (-1, -1) {
        
        while newLoc == (-1,-1) {
            let opp = (dir+2) % 4
            let backy = loc.0 + dy[opp]
            let backx = loc.1 + dx[opp]
            
            if backy>=0 && backy<N && backx>=0 && backx<M {
                if map[backy][backx] == 1 {
                    break
                }
                
                loc = (backy, backx)
                newLoc = find(loc.0, loc.1, &dir)
            }
        }
    }
    
    if newLoc == (-1, -1) {
        break
    }
    
    loc = newLoc
    visited[loc.0][loc.1] = true
}

print(count)
