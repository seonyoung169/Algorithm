import Foundation
// boj 3190 뱀, 구현, 골드 5

let N = Int(readLine()!)!
let K = Int(readLine()!)!

var map = [[Int]](repeating: [Int](repeating: 0, count: N+1), count: N+1)

for _ in 0..<K {
    let str = readLine()!.split(separator: " ").map{Int($0)!}
    map[str[0]][str[1]] = 2
}

let L = Int(readLine()!)!
var rotation = [String](repeating: "-", count: 10000)
for _ in 0..<L {
    let str = readLine()!.split(separator: " ")
    let idx = Int(str[0])!
    rotation[idx] = String(str[1])
}

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

var sec = 0
var head = (1,1)
var tail = (1,1)
var dir = 1
var q = [(1,1)]
var front = 0

map[1][1] = 1

while true {
    sec += 1
    let ny = head.0 + dy[dir]
    let nx = head.1 + dx[dir]
    
    if ny<1 || ny>N || nx<1 || nx>N || map[ny][nx] == 1 {
        break
    }
    
    head = (ny, nx)
    q.append((ny, nx))
    
    if map[ny][nx] != 2 {
        map[tail.0][tail.1] = 0
        front += 1
        tail = q[front]
    }
    
    map[ny][nx] = 1
    
    if rotation[sec] == "L" {
        dir = (dir+3)%4
        continue
    }
    
    if rotation[sec] == "D" {
        dir = (dir+1)%4
        continue
    }
}

print(sec)
