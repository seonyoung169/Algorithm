import Foundation

// 프로그래머스 피로도, level2, 완탐 

func permute(_ array : [Int], _ targetNum : Int) -> [[Int]] {
    var result : [[Int]] = []
    var visited = [Bool](repeating: false, count: array.count)
    
    func premutation(_ nowPermute : [Int]){
        if nowPermute.count == targetNum {
            result.append(nowPermute)
            return
        }
        
        for i in 0..<array.count {
            if visited[i] {
                continue
            }
            
            visited[i] = true
            premutation(nowPermute + [array[i]])
            visited[i] = false
            
        }
    }
    
    premutation([])
    
    return result
}

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    var answer = -1
    
    let N = dungeons.count
    let indexes = Array<Int>(0...N-1)
    let permutations = permute(indexes, N)
    
    for index in permutations {
        var energy = k, count = 0
        
        for i in index {
            if energy < dungeons[i][0] {
                break
            }
            
            energy -= dungeons[i][1]
            count += 1
        }
        
        if count > answer {
            answer = count
        }
    }
    return answer
}
