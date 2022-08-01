import Foundation

// 프로그래머스 기능 개발, level 2
func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    if progresses.count == 1 {
        return [1]
    }
    
    var left_days = Array(repeating: 0, count: progresses.count)
    
    for i in 0..<progresses.count {
        let work = 100 - progresses[i]
        
        var days = work / speeds[i]
        if work%speeds[i] > 0 {
            days += 1
        }
        
        left_days[i] = days
    }
    
    var answer = [Int]()
    var count = 1
    var standard = left_days[0]
    
    for i in 1..<progresses.count {
        if left_days[i] <= standard {
            count += 1
            continue
        }
        
        answer.append(count)
        count = 1
        standard = left_days[i]
    }
    
    answer.append(count)
    return answer
}

print(solution([95, 90, 99, 99, 80, 99],[1, 1, 1, 1, 1, 1]))
