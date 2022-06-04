import Foundation

// 프로그래머스 쿼드 압축 후 개수 세기, level 2, 재귀 이용

var answer = [0,0]
var matrix : [[Int]] = []

func split(_ y:Int, _ x:Int, _ size:Int) {
    if size == 1 {
        answer[matrix[y][x]] += 1
        return
    }
    
    var same = true
    let standard = matrix[y][x]
    
    for i in y..<y+size {
        for j in x..<x+size {
            if matrix[i][j] != standard {
                same = false
                break
            }
        }
        if !same {
            break
        }
    }
    
    if same {
        answer[standard] += 1
        return
    }
    
    let half = size/2
    
    split(y, x, half)
    split(y, x+half, half)
    split(y+half, x, half)
    split(y+half, x+half, half)
}

func solution(_ arr:[[Int]]) -> [Int] {
    matrix = arr
    split(0, 0, arr[0].count)
    
    return answer
}
