import Foundation

// boj 16234 인구이동, bfs, 골드 5
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

var N = 0
var L = 0
var R = 0

var map: [[Int]] = []
var population: [Int] = []
var unions: [[(Int, Int)]] = []

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

func bfs(_ startY: Int, _ startX: Int, _ visited: inout [[Bool]]) {
    var sum = map[startY][startX]
    var temp: [(Int, Int)] = [(startY, startX)]
    var q = Queue<(Int, Int)>()
    
    visited[startY][startX] = true
    q.enqueue((startY, startX))
    
    while !q.isEmpty {
        if let cur = q.dequeue() {
            for i in 0..<4 {
                let ny = cur.0 + dy[i]
                let nx = cur.1 + dx[i]
                
                if ny<0 || ny>=N || nx<0 || nx>=N {continue}
                
                let diff = (map[cur.0][cur.1] - map[ny][nx]).magnitude
                
                if !visited[ny][nx] && (diff >= L && diff <= R) {
                    visited[ny][nx] = true
                    sum += map[ny][nx]
                    temp.append((ny,nx))
                    q.enqueue((ny,nx))
                }
            }
        }
    }
    
    
    if temp.count > 1 {
        unions.append(temp)
        population.append(sum)
    }
}

func move() {
    for i in 0..<unions.count {
        let avg = population[i] / unions[i].count
        for (r,c) in unions[i] {
            map[r][c] = avg
        }
    }
}

func solution() -> Int {
    var answer = 0
    
    while true {
        
        var visited = Array(repeating: Array(repeating: false, count: N), count: N)
        
        for i in 0..<N {
            for j in 0..<N {
                if !visited[i][j] {
                    bfs(i,j, &visited)
                }
            }
        }
        
        if unions.isEmpty {
            break
        }
        
        move()
        
        unions = []
        population = []
        answer += 1
    }
    
    return answer
}


if let line = readLine() {
    let arr = line.components(separatedBy: " ").map{Int($0)!}
    N = arr[0]
    L = arr[1]
    R = arr[2]
    
    for _ in 0..<N {
        if let input = readLine() {
            let row = input.components(separatedBy: " ").map{Int($0)!}
            map.append(row)
        }
    }
    
    print(solution())
}
