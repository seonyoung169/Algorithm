import Foundation

// 프로그래머스 네트워크, level 3, dfs/bfs

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


var network: Int = 0
var visited: [Bool] = []

func BFS(_ start:Int, _ computers:[[Int]]) {
    var q = Queue<Int>()
    q.enqueue(start)
    
    while !q.isEmpty {
        if let cur = q.dequeue() {
            (0..<computers.count).forEach { i in 
                if computers[cur][i] == 1 && !visited[i] {
                    visited[i] = true
                    q.enqueue(i)
                }
            }
        }
    }
}

func solution(_ n:Int, _ computers:[[Int]]) -> Int {
    visited = Array(repeating: false, count: n)
    
    (0..<n).forEach { com in
        if !visited[com] {
            visited[com] = true
            network += 1
            BFS(com, computers)
        }
    }
    
    return network
}
