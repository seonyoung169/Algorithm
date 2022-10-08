import Foundation

// boj 9205 맥주 마시면서 걸어가기, 실버 1, bfs

let T = Int(readLine()!)!
var answer = ""

func getDist(_ loc1: (Int, Int), _ loc2: (Int, Int)) -> Int {
    return Int((loc1.0-loc2.0).magnitude + (loc1.1-loc2.1).magnitude)
}

func bfs(_ cvs: [(Int, Int)], _ home: (Int, Int), _ festival: (Int, Int)) -> String {
    var result = "sad"
    var visited = [Bool](repeating: false, count: cvs.count)
    var q = [home]
    var index = 0
    
    while index<q.count {
        let cur = q[index]
        index += 1
        
        if getDist(cur, festival) <= 1000 {
            result = "happy"
            break
        }
        
        for i in 0..<cvs.count {
            if visited[i] { continue }
            
            if getDist(cur, cvs[i]) <= 1000 {
                visited[i] = true
                q.append(cvs[i])
            }
        }
    }

    return result
}

for _ in 0..<T {
    let N = Int(readLine()!)!
    let home = readLine()!.split(separator: " ").map{Int($0)!}
    
    var cvs = [(Int, Int)]()
    for _ in 0..<N {
        let str = readLine()!.split(separator: " ").map{Int($0)!}
        cvs.append((str[0], str[1]))
    }
    
    let festival = readLine()!.split(separator: " ").map{Int($0)!}
    
    let result = bfs(cvs, (home[0], home[1]), (festival[0], festival[1]))
    
    answer += result + "\n"
}

print(answer)


