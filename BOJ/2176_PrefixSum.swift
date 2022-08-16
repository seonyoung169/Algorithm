import Foundation

// boj 2167 2차원 배열의 누적 합, 브론즈 1, 누적 합 

var N = 0
var M = 0
var map: [[Int]] = []
var sum: [[Int]] = []


func solution(_ from : (Int,Int), _ to : (Int, Int)) -> Int {
    
    if from == to {
        return map[from.0][from.1]
    }
    
    var answer = 0
    for i in from.0...to.0 {
        answer += sum[i][to.1] - sum[i][from.1-1]
    }
    
    return answer
}

if let input = readLine() {
    N = input.components(separatedBy: " ").map{Int($0)!}[0]
    M = input.components(separatedBy: " ").map{Int($0)!}[1]

    map = Array(repeating: Array(repeating: 0, count: M+1), count: N+1)
    sum = Array(repeating: Array(repeating: 0, count: M+1), count: N+1)
    
    for i in 1...N {
        let row = readLine()!.components(separatedBy: " ").map{Int($0)!}
        for j in 1...M {
            map[i][j] = row[j-1]
            sum[i][j] = sum[i][j-1] + map[i][j]
        }
    }
    
    let T = Int(readLine()!)!
    
    for _ in 0..<T {
        let points = readLine()!.components(separatedBy: " ").map{Int($0)!}
        print(solution((points[0], points[1]), (points[2], points[3])))
    }
}
