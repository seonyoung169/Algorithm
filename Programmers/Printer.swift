import Foundation

// 프로그래머스 프린터, level 2

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

struct FileInfo {
    var index: Int = -1
    var priority: Int = -1
}


func solution(_ priorities:[Int], _ location:Int) -> Int {
    var q = Queue<FileInfo>()
    var rank = [Int]()
    
    var i = 0
    priorities.forEach {
        q.enqueue(FileInfo(index: i, priority: $0))
        rank.append($0)
        i += 1
    }
    
    rank = rank.sorted(by: >)
    
    var count = 0
    while (!q.isEmpty){
        if q.front.priority < rank[0] {
            if let file = q.dequeue() {
                q.enqueue(file)
            }
            continue
        }
        
        if let file = q.dequeue() {
            count += 1
            if file.index == location {
                break
            }
            
            rank.removeFirst()
        }
    }
    
    return count
}
