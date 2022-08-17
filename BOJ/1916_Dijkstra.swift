import Foundation
// boj 1916 최소 비용 구하기, 골드 5, 다익스트라

let N = Int(readLine()!)!
let M = Int(readLine()!)!
let INF = Int(1e9)

var fee = [[Int]](repeating: [Int](repeating: INF, count: N+1), count: N+1)
var cost = [Int](repeating: INF, count: N+1)

for _ in 0..<M {
    let line = readLine()!.split(separator: " ")
    let from = Int(line[0])!
    let to = Int(line[1])!
    let c = Int(line[2])!
    
    fee[from][to] = min(fee[from][to], c)
}

let dest = readLine()!.split(separator: " ")
let S = Int(dest[0])!
let E = Int(dest[1])!

var queue = [S]
cost[S] = 0

while !queue.isEmpty {
    let mid = queue.removeLast()
    
    for i in 1...N {
        let temp = fee[mid][i]
        
        if temp == INF {
            continue
        }
        
        if cost[i] > cost[mid] + temp {
            cost[i] = cost[mid] + temp
            queue.append(i)
        }
    }
}

print(cost[E])
