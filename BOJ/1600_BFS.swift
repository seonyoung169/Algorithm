import Foundation
// boj 1600 말이 되고픈 원숭이, 골드 3, bfs

let K = Int(readLine()!)!
let str = readLine()!.split(separator: " ")
let W = Int(str[0])!
let H = Int(str[1])!


var map = [[Int]]()
for _ in 0..<H {
    let row = readLine()!.split(separator: " ").map{Int($0)!}
    map.append(row)
}

let INF = Int.max

let horse_dy = [-2, -1,1,2,2,1,-1,-2]
let horse_dx = [1,2,2,1,-1,-2,-2,-1]

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

var route = [[[Int]]](repeating: [[Int]](repeating: [Int](repeating: 0, count: K+1), count: W), count: H)
var q = [(0,0,0)]
var idx = 0

var answer = INF

if W==1 && H==1 {
    answer = 0
} else {
    
    while idx < q.count {
        let cur = q[idx]
        idx += 1
        
        if cur.0 == H-1 && cur.1 == W-1 { continue }
        
        for i in 0..<4 { // 일반 이동
            let ny = cur.0 + dy[i]
            let nx = cur.1 + dx[i]
            
            if !((0..<H) ~= ny && (0..<W) ~= nx) { continue }
            if map[ny][nx] == 1 { continue }
            if ny==0 && nx==0 { continue }
            
            if route[ny][nx][cur.2] == 0 || route[ny][nx][cur.2] > route[cur.0][cur.1][cur.2] + 1 {
                route[ny][nx][cur.2] = route[cur.0][cur.1][cur.2] + 1
                q.append((ny, nx, cur.2))
            }
        }
        
        if cur.2 == K { continue }
        
        for i in 0..<8 {
            let ny = cur.0 + horse_dy[i]
            let nx = cur.1 + horse_dx[i]
            
            if !((0..<H) ~= ny && (0..<W) ~= nx) { continue }
            if map[ny][nx] == 1 { continue }
            if ny==0 && nx==0 { continue }
            
            if route[ny][nx][cur.2+1] == 0 ||  route[ny][nx][cur.2+1] > route[cur.0][cur.1][cur.2] + 1 {
                route[ny][nx][cur.2+1] = route[cur.0][cur.1][cur.2] + 1
                q.append((ny, nx, cur.2+1))
            }
        }
    }
    
    for k in 0...K {
        if route[H-1][W-1][k]>0 {
            answer = min(answer, route[H-1][W-1][k])
        }
    }
    
    if answer == INF {
        answer = -1
    }
}

print(answer)
