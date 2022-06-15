import Foundation
// 프로그래머스 행렬의 곱셈, level 2

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    
    var result = Array(repeating: Array(repeating: 0, count: arr2[0].count), count: arr1.count)
    
    for i in 0..<arr1.count {
        for j in 0..<arr2[0].count {
            for k in 0..<arr1[0].count {
                result[i][j] += arr1[i][k] * arr2[k][j]
            }
        }
    }
    
    
    
    return result
}
