// boj 16928 뱀과 사다리 게임, 그래프탐색, 골드 5

import Foundation

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


let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

var port = [Int : Int]()

for _ in 0..<N {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    port[str2[0]] = str2[1]
}

for _ in 0..<M {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    port[str3[0]] = str3[1]
}

func solution() -> Int {
    var answer = Int.max
    var q = Queue<(Int, Int)>()
    var visited = [Bool](repeating: false, count: 101)
    
    q.enqueue((1,0))
    visited[1] = true
    
    
    while !q.isEmpty {
        guard let cur = q.dequeue() else { continue }
        
        if cur.1 >= answer { continue }
        
        if cur.0 == 100 {
            answer = min(answer, cur.1)
            continue
        }
        
        for i in 1...6 {
            let pos = cur.0 + i
            if pos>100 { break }
            
            if let next = port[pos] {
                if !visited[next] {
                    visited[next] = true
                    q.enqueue((next, cur.1+1))
                }
            } else {
                if !visited[pos] {
                    visited[pos] = true
                    q.enqueue((pos, cur.1+1))
                }
            }
        }
    }
    
    return answer
}

print(solution())

