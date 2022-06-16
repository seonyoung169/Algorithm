import Foundation

// 프로그래머스 최솟값 만들기, level 2

func solution(_ A:[Int], _ B:[Int]) -> Int {
    var ans = 0
    
    let arr1 = A.sorted()
    let arr2 = B.sorted(by: >)
    
    for i in 0..<A.count {
        ans += arr1[i] * arr2[i]
    }

    return ans
}
