import Foundation
// boj 2636 치즈, 골드 4, bfs

struct Queue<T> {
    private var queue: [T] = []
    
    public var count: Int {
        return queue.count
    }
    
    public var front : T {
        return queue[0]
    }
    
    public var isEmpty: Bool {
        return queue.isEmpty
    }
    
    public mutating func enqueue(_ element: T) {
        queue.append(element)
    }
    
    public mutating func dequeue() -> T? {
        return isEmpty ? nil : queue.removeFirst()
    }
}

let st1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = st1[0]
let M = st1[1]

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

var map = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
var cheese = 0
var time = 0
var deleted = 0

for i in 0..<N {
    let st2 = readLine()!.split(separator: " ").map{Int($0)!}
    for j in 0..<M {
        map[i][j] = st2[j]
        if map[i][j] == 1 { cheese += 1 }
    }
}

func bfs(_ startR: Int, _ startC: Int, _ visited: inout [[Bool]], _ newMap: inout [[Int]]) {
    var q = Queue<(Int, Int)>()
    
    q.enqueue((startR, startC))
    visited[startR][startC] = true
    
    while !q.isEmpty {
        guard let cur = q.dequeue() else { continue }
        
        for i in 0..<4 {
            let ny = cur.0 + dy[i]
            let nx = cur.1 + dx[i]
            
            if ny<0 || ny>=N || nx<0 || nx>=M || visited[ny][nx] { continue }
            
            visited[ny][nx] = true
            
            if map[ny][nx] == 0 {
                q.enqueue((ny, nx))
            } else {
                newMap[ny][nx] = 0
                deleted += 1
            }
        }
    }
    
}

while cheese > 0 {
    
    time += 1
    
    var newMap = map
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: M), count: N)
    
    deleted = 0
    bfs(0, 0, &visited, &newMap)
    
    cheese -= deleted
    map = newMap
}

print("\(time)\n\(deleted)")
