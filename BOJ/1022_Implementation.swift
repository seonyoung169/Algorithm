import Foundation
// boj 1022 소용돌이 예쁘게 출력하기, 구현, 골드 4

var input = readLine()!.split(separator: " ").map{Int($0)!}
let R1 = input[0]
let C1 = input[1]
let R2 = input[2]
let C2 = input[3]

var layer = 0
for i in 0..<4 {
    if input[i]<0 {
        input[i] *= -1
    }
    layer = max(layer, input[i])
}

let N = 2 * layer + 1

let dy = [0,-1,0,1]
let dx = [1,0,-1,0]

func swirl(_ row: Int, _ col: Int) -> String {
    if row==N/2 && col==N/2 { return "1" }
    
    var r = row-layer
    if r<0 { r *= -1 }
    var c = col-layer
    if c<0 { c *= -1 }
    
    let cycle = max(r, c)
    var curY = N/2 + cycle - 1
    var curX = N/2 + cycle
    
    var curNumber = (2*cycle-1)*(2*cycle-1) + 1
    let maxNumber = (2*cycle+1)*(2*cycle+1)
    
    let from = N/2 - cycle
    let to = N/2 + cycle
    
    var dir = 0
    
    var result = 0
    
    while curNumber <= maxNumber {
        if curY==row && curX==col {
            result = curNumber
            break
        }
        
        var ny = curY + dy[dir]
        var nx = curX + dx[dir]
        
        if ny<from || ny>to || nx<from || nx>to {
            dir = (dir+1) % 4
            ny = curY + dy[dir]
            nx = curX + dx[dir]
        }
        
        curY = ny
        curX = nx
        
        curNumber += 1
    }
    
    return "\(result)"
}

var board = [[String]]()
var maxLen = 0

for i in R1+layer...R2+layer {
    var row = [String]()
    for j in C1+layer...C2+layer {
        let num = swirl(i,j)
        row.append(num)
        maxLen = max(maxLen, num.count)
    }
    board.append(row)
}


var answer = ""
for i in 0..<board.count {
    for j in 0..<board[0].count{
        if board[i][j].count < maxLen {
            for _ in 0..<maxLen-board[i][j].count {
                answer += " "
            }
        }
        answer += board[i][j]
        answer += " "
    }
    answer += "\n"
}

print(answer)

