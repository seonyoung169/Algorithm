import Foundation
// boj 2178 미로 탐색, 실버 1

struct Point {
    var y = -1
    var x = -1
    var dist = 0
}

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


var N: Int = 0
var M: Int = 0

var map: [[Character]] = []

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

func solution() -> Int {
    var answer = Int.max
    var q = Queue<Point>()
    var visited = Array(repeating: Array(repeating: false, count: M), count: N)
    
    q.enqueue(Point(y: 0, x: 0, dist: 1))
    visited[0][0] = true
    
    while !q.isEmpty {
        if let cur = q.dequeue() {
            if cur.y == N-1 && cur.x == M-1 {
                if cur.dist < answer {
                    answer = cur.dist
                }
                continue
            }
            
            for i in 0..<4 {
                let ny = cur.y + dy[i]
                let nx = cur.x + dx[i]
                
                if ny<0 || ny>=N || nx<0 || nx>=M {
                    continue
                }
                
                if map[ny][nx] == "1" && !visited[ny][nx] {
                    visited[ny][nx] = true
                    q.enqueue(Point(y: ny, x: nx, dist: cur.dist + 1))
                }
            }
        }
    }
    
    return answer
}

if let input = readLine() {
    let array = input.components(separatedBy: " ")
    N = Int(array[0])!
    M = Int(array[1])!
    
    for _ in 0..<N {
        if let row = readLine() {
            var arry = [Character]()
            for ch in row {
                arry.append(ch)
            }
            map.append(arry)
        }
    }
    
    print(solution())
}

