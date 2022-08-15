import Foundation

// boj 20207 달력, 구현, 실버 1

var schedule: [(Int,Int)] = []
var minStart = 367
var maxEnd = 0

func solution() -> Int {
    var answer = 0
    var count = Array(repeating: 0, count: 368)
    
    for (S,E) in schedule {
        for i in S...E {
            count[i] += 1
        }
    }
    
    var day = minStart
    var from = minStart
    var to = -1
    var maxCount = 0
    
    while day <= maxEnd {
        if count[day] == 0 {
            day += 1
            continue
        }
        
        from = day
        while count[day] > 0 {
            maxCount = max(maxCount, count[day])
            day += 1
        }
        to = day
        answer += maxCount * (to-from)
        maxCount = 0
    }
    

    return answer
}


if let N = readLine() {
    for _ in 0..<Int(N)! {
        if let num = readLine() {
            let arr = num.components(separatedBy: " ").map{Int($0)!}
            schedule.append((arr[0], arr[1]))
            
            minStart = min(minStart, arr[0])
            maxEnd = max(maxEnd, arr[1])
        }
    }
    print(solution())
}
