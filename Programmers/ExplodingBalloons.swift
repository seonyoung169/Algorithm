import Foundation

// programmers 풍선 터뜨리기, level 3 
func solution(_ a:[Int]) -> Int {
    let N = a.count
    
    var leftMin = [Int](repeating: 0, count: N)
    var rightMin = [Int](repeating: 0, count: N)
    
    leftMin[0] = a[0]
    rightMin[N-1] = a[N-1]
    
    for i in 1..<N {
        leftMin[i] = min(leftMin[i-1], a[i])
        rightMin[N-i-1] = min(rightMin[N-i], a[N-i-1])
    }
    
    var count = 0
    for i in 0..<N {
        if a[i]>leftMin[i] && a[i]>rightMin[i] {
            count += 1
        }
    }
    
    return N-count
}

print(solution([-16,27,65,-2,58,-92,-71,-68,-61,-33]))
