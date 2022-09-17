import Foundation
// boj 14891 톱니바퀴, 구현, 골드 5

extension String {
    func substring(from : Int, to : Int) -> String {
        guard from < count, to >= 0, to-from >= 0 else { return "" }
        
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to+1)
        
        return String(self[startIndex..<endIndex])
    }
}

var wheel = [String](repeating: "", count: 5)
for i in 1...4 {
    let row = readLine()!
    wheel[i] = row
}

let K = Int(readLine()!)!
var visited = [Bool]()

func move(_ cur: Int, _ dir: Int) {
    let opposite = dir * (-1)
    let circle = wheel[cur]
    let left = wheel[cur].substring(from: 6, to: 6)
    let right = wheel[cur].substring(from: 2, to: 2)
    
    if dir == 1 {
        wheel[cur] = circle.substring(from: 7, to: 7) + circle.substring(from: 0, to: 6)
    } else {
        wheel[cur] = circle.substring(from: 1, to: 7) + circle.substring(from: 0, to: 0)
    }
    
    visited[cur] = true
    
    if cur+1<=4 {
        if wheel[cur+1].substring(from: 6, to: 6) != right && !visited[cur+1]{
            move(cur+1, opposite)
        }
    }
    
    if cur-1>=1 {
        if wheel[cur-1].substring(from: 2, to: 2) != left && !visited[cur-1] {
            move(cur-1, opposite)
        }
    }
}

for _ in 0..<K {
    let str = readLine()!.split(separator: " ").map{Int($0)!}
    visited = [Bool](repeating: false, count: 5)
    move(str[0], str[1])
}

var answer = 0
var score = 1
for i in 1...4 {
    if wheel[i].substring(from: 0, to: 0) == "1" {
        answer += score
    }
    score *= 2
}

print(answer)
