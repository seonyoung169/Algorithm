import Foundation
// boj 2469 사다리 타기, 구현, 골드 5

let K = Int(readLine()!)!
let N = Int(readLine()!)!
var result = readLine()!.map{String($0)}

var board: [[String]] = []
var stopR = -1

var unknown = ""
for _ in 0..<K-1 {
    unknown += "?"
}

for i in 0..<N {
    let input = readLine()!
    if input == unknown {
        stopR = i
    }
    board.append(input.map{String($0)})
}

func runTop() -> [String] {
    var start: [String] = []
    for i in 0..<K {
        start.append(String(UnicodeScalar(i + 65)!))
    }
    
    var i = 0
    
    while i<stopR {
        for j in 0...K-2 {
            if board[i][j] == "-" {
                let tok = start[j]
                start[j] = start[j+1]
                start[j+1] = tok
            }
        }
        i += 1
    }
    
    return start
}

func runBottom() -> [String] {
    var i = N-1
    
    while i>stopR {
        for j in 0...K-2 {
            if board[i][j] == "-" {
                let tok = result[j]
                result[j] = result[j+1]
                result[j+1] = tok
            }
        }
        i -= 1
    }
    
    return result
}

var top = runTop()
let bottom = runBottom()

var answer = ""
var impossible = false

for i in 0..<K-1 {
    if top[i] == bottom[i] {
        answer += "*"
    } else if top[i] == bottom[i+1] && top[i+1] == bottom[i] {
        answer += "-"
        let tok = top[i]
        top[i] = top[i+1]
        top[i+1] = tok
    } else {
        impossible = true
        break
    }
}

if impossible {
    answer = ""
    for _ in 0..<K-1 { answer += "x"}
}

print(answer)
