import Foundation
// boj 5972 택배 배송, 골드 5, 다익스트라

class PriorityQueue<T> {
    private var heap: [T] = []
    private let comparing: (_ o1: T,_ o2: T) -> Bool
    
    init(_ comparing: @escaping (_ o1: T,_ o2: T) -> Bool) {
        self.comparing = comparing
    }
    
    func size() -> Int { heap.count }
    
    func isEmpty() -> Bool { heap.isEmpty }
    
    func clear() { heap.removeAll() }
    
    func peek() -> T? { heap.first }
    
    func push(_ value: T) {
        heap.append(value)
        if heap.count == 1 { return }
        var valueIndex = heap.count - 1
        var parentIndex = (valueIndex-1) / 2
        while !comparing(heap[parentIndex], heap[valueIndex]) {
            heap.swapAt(valueIndex, parentIndex)
            valueIndex = parentIndex
            parentIndex = (valueIndex-1) / 2
            if valueIndex == 0 { break }
        }
    }
    
    func pop() -> T? {
        if heap.count == 0 { return nil }
        if heap.count == 1 { return heap.removeFirst() }
        
        func isChildEmpty(_ value: Int,_ left: Int,_ right: Int) -> Bool {
            if heap.count <= left { return true }
            if heap.count > right { return false }
            if comparing(heap[value], heap[left]) { return true }
            heap.swapAt(value, left)
            return true
        }
        
        heap.swapAt(0, heap.count-1)
        let answer = heap.removeLast()
        
        var valueIndex = 0
        var leftIndex = valueIndex * 2 + 1
        var rightIndex = valueIndex * 2 + 2
        
        if isChildEmpty(valueIndex, leftIndex, rightIndex) { return answer }
        
        while !comparing(heap[valueIndex], heap[leftIndex]) || !comparing(heap[valueIndex], heap[rightIndex]) {
            let index = comparing(heap[leftIndex], heap[rightIndex]) ? leftIndex : rightIndex
            heap.swapAt(valueIndex, index)
            valueIndex = index
            leftIndex = valueIndex * 2 + 1
            rightIndex = valueIndex * 2 + 2
            
            if isChildEmpty(valueIndex, leftIndex, rightIndex) { break }
        }
        return answer
    }
}

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

struct Node {
    var num: Int = 0
    var dist: Int = 0
}

var edge = [[Node]](repeating: [], count: N+1)
for _ in 0..<M {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    edge[str2[0]].append(Node(num: str2[1], dist: str2[2]))
    edge[str2[1]].append(Node(num: str2[0], dist: str2[2]))
}

for i in 1...N {
    edge[i].sort(by: { $0.dist < $1.dist })
}

let INF = 50000*1000
var pq: PriorityQueue<Node> = PriorityQueue<Node>() { $0.dist < $1.dist }
var cost = [Int](repeating: INF, count: N+1)
var visited = [Bool](repeating: false, count: N+1)

cost[1] = 0
pq.push(Node(num: 1, dist: 0))

while !pq.isEmpty() {
    guard let mid = pq.pop() else { continue }
    
    if mid.dist > cost[mid.num] { continue }
    
    visited[mid.num] = true
    
    for i in 0..<edge[mid.num].count {
        let next = edge[mid.num][i]
    
        if visited[next.num] { continue }
        if next.dist == INF { continue }
        
        if cost[next.num] > mid.dist + next.dist {
            cost[next.num] = mid.dist + next.dist
            pq.push(Node(num: next.num, dist: cost[next.num]))
        }
    }
}

print(cost[N])



