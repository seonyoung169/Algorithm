import Foundation
// boj 1451 직사각형으로 나누기

extension String {
    func substring(from : Int, to : Int) -> String {
        guard from < count, to >= 0, to-from >= 0 else { return "" }
        
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to+1)
        
        return String(self[startIndex..<endIndex])
    }
}

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let M = str[1]

var board = [[Int]](repeating: [Int](repeating: 0, count: M), count: N)
var answer: Int64 = 0

for i in 0..<N {
    let row = readLine()!
    for j in 0..<M {
        board[i][j] = Int(row.substring(from: j, to: j))!
    }
}

func sum(_ sr: Int, _ sc: Int, _ er: Int, _ ec: Int) -> Int64 {
    var result: Int64 = 0
    
    for i in sr...er {
        for j in sc...ec {
            result += Int64(board[i][j])
        }
    }
    
    return result
}

func divideRow() {
    if N<=2 { return }
    
    for i in 0..<N-2 {
        for j in i+1..<N-1 {
            let a: Int64 = sum(0, 0, i, M-1)
            let b: Int64 = sum(i+1, 0, j, M-1)
            let c: Int64 = sum(j+1, 0, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

func divideCol() {
    if M<=2 { return }
    
    for i in 0..<M-2 {
        for j in i+1..<M-1 {
            let a: Int64 = sum(0, 0, N-1, i)
            let b: Int64 = sum(0, i+1, N-1, j)
            let c: Int64 = sum(0, j+1, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

func bottomRow() {
    if N<2 || M<2 { return }
    
    for i in 0..<N-1 {
        for j in 0..<M-1 {
            let a: Int64 = sum(0, 0, i, j)
            let b: Int64 = sum(0, j+1, i, M-1)
            let c: Int64 = sum(i+1, 0, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

func topRow() {
    if N<2 || M<2 { return }
    
    for i in 0..<N-1 {
        for j in 0..<M-1 {
            let a: Int64 = sum(0, 0, i, M-1)
            let b: Int64 = sum(i+1, 0, N-1, j)
            let c: Int64 = sum(i+1, j+1, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

func rightCol() {
    if N<2 || M<2 { return }
    
    for i in 0..<N-1 {
        for j in 0..<M-1 {
            let a: Int64 = sum(0, 0, i, j)
            let b: Int64 = sum(i+1, 0, N-1, j)
            let c: Int64 = sum(0, j+1, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

func leftCol() {
    if N<2 || M<2 { return }
    
    for i in 0..<M-1 {
        for j in 0..<N-1 {
            let a: Int64 = sum(0, 0, N-1, i)
            let b: Int64 = sum(0, i+1, j, M-1)
            let c: Int64 = sum(j+1, i+1, N-1, M-1)
            
            answer = max(answer, a*b*c)
        }
    }
}

divideRow()
divideCol()
topRow()
bottomRow()
rightCol()
leftCol()

print(answer)
