import Foundation
// boj 21278 호석이 두마리 치킨, floyd warshall , 골드 5

let str1 = readLine()!.split(separator: " ")
let N = Int(str1[0])!
let M = Int(str1[1])!
let INF = 100000

var graph = [[Int]](repeating: Array(repeating: INF, count: N+1), count: N+1)

for _ in 0..<M {
    let str2 = readLine()!.split(separator: " ")
    let a = Int(str2[0])!
    let b = Int(str2[1])!
    graph[a][b] = 1
    graph[b][a] = 1
}


func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result = [[T]]()
    if array.count < n { return result }

    func cycle(_ index: Int, _ now: [T]) {
        if now.count == n {
            result.append(now)
            return
        }
        
        for i in index..<array.count {
            cycle(i + 1, now + [array[i]])
        }
    }
    
    cycle(0, [])
    
    return result
}

func floydWarshall() -> Void {
    for mid in 1...N {
        for i in 1...N {
            for j in 1...N {
                if graph[i][j] > graph[i][mid] + graph[mid][j] {
                    graph[i][j] = graph[i][mid] + graph[mid][j]
                }
            }
        }
    }
}

let locations = combination([Int](1...N), 2)
floydWarshall()

var result: [(Int,Int,Int)] = []

for i in 0..<locations.count {
    let loc = locations[i].sorted(by: <)
    var sum = 0
    
    for start in 1...N {
        if start == loc[0] || start == loc[1] { continue }
        
        let dist1 = graph[start][loc[0]]
        let dist2 = graph[start][loc[1]]
        sum += min(dist1, dist2)
    }
    
    result.append((loc[0],loc[1],sum*2))
}

let sorted = result.sorted{ (first, second) -> Bool in
    if first.2 != second.2 {
        return first.2 < second.2
    }
    
    if first.0 != second.0 {
        return first.0 < second.0
    }
    
    return first.1 < second.1
}

print("\(sorted[0].0) \(sorted[0].1) \(sorted[0].2)")


