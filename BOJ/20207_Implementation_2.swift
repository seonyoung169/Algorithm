import Foundation

// boj 20207 달력, 구현, 실버 1 - 누적합 이용!!

var schedule: [(Int,Int)] = []

func solution() -> Int {
    var answer = 0
    var count = Array(repeating: 0, count: 368)
    
    for (S,E) in schedule {
        count[S] += 1
        count[E+1] -= 1
    }
    
    
    var maxCount = 0
    var width = 0
    
    for i in 1...366{
        count[i] += count[i-1]
        
        if count[i] == 0 {
            answer += maxCount * width
            maxCount = 0
            width = 0
        } else {
            maxCount = max(maxCount, count[i])
            width += 1
        }
    }
    
    return answer
}


if let N = readLine() {
    for _ in 0..<Int(N)! {
        if let num = readLine() {
            let arr = num.components(separatedBy: " ").map{Int($0)!}
            schedule.append((arr[0], arr[1]))
            
        }
    }
    print(solution())
}
