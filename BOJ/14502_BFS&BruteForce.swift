import Foundation
// boj 14502 연구소, 골드 4, bfs, bruteforce

struct Point {
    var y = -1
    var x = -1
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

var map: [[Int]] = []
var copyMap: [[Int]] = []
var candidates: [Point] = []

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

func makeCases(_ pickCount: Int, _ index: Int = 0, _ tempArray: [Point], _ combsResult: inout [[Point]]) -> [[Point]] {
    if tempArray.count == pickCount {
        combsResult.append(tempArray)
        return []
    }

    for i in index..<candidates.count {
        makeCases(pickCount, i + 1, tempArray + [candidates[i]], &combsResult)
    }

    return combsResult
}


func bfs(_ startY: Int, _ startX: Int) -> Void {
    var q = Queue<Point>()
    q.enqueue(Point(y : startY, x: startX))
    
    while !q.isEmpty {
        if let cur = q.dequeue() {
            for i in 0..<4 {
                let ny = cur.y + dy[i]
                let nx = cur.x + dx[i]
                
                if ny<0 || ny>=N || nx<0 || nx>=M { continue }
                if copyMap[ny][nx] == 0 {
                    copyMap[ny][nx] = 2
                    q.enqueue(Point(y: ny, x: nx))
                }
            }
        }
    }
}

func countSafeArea() -> Int {
    var count = 0
    
    for i in 0..<N {
        for j in 0..<M {
            if copyMap[i][j] == 0 {
                count += 1
            }
        }
    }
    
    return count
}

func solution() -> Int {
    var answer = 0
    var combinations =  [[Point]]()
    makeCases(3, 0, [], &combinations)
    
    for points in combinations {
        copyMap = map
        
        for p in points {
            copyMap[p.y][p.x] = 1
        }
        
        for i in 0..<N {
            for j in 0..<M {
                if copyMap[i][j] == 2 {
                    bfs(i,j)
                }
            }
        }
        
        let count = countSafeArea()
        answer = max(answer, count)
    }
    
    return answer
}

if let input = readLine() {
    let array = input.components(separatedBy: " ")
    N = Int(array[0])!
    M = Int(array[1])!
    
    map = Array(repeating: Array(repeating: 0, count: M), count: N)
    
    for i in 0..<N {
        if let row = readLine() {
            let arry = row.components(separatedBy: " ")
            for j in 0..<M {
                if arry[j] == "0" {
                    candidates.append(Point(y: i, x: j))
                }
                map[i][j] = Int(arry[j])!
            }
        }
    }
    
    print(solution())
}

