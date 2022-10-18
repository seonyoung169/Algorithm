import Foundation

// boj 15683 감시, 구현, 골드 4, dfs

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let M = str[1]

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

struct CCTV {
    var y: Int = 0
    var x: Int = 0
    var type: Int = 0
}

var board = [[Int]]()
var camera = [CCTV]()
var rotation = [4,2,4,4,1]

for i in 0..<N {
    let row = readLine()!.split(separator: " ").map{Int($0)!}
    for (j, num) in row.enumerated() {
        if num>=1 && num<=5 {
            camera.append(CCTV(y: i, x: j, type: num-1))
        }
    }
    board.append(row)
}

let K = camera.count
var answer = 100

func updateBoard(_ cam: CCTV, _ dir: Int) {
    var ny = cam.y
    var nx = cam.x
    
    switch dir {
    case 0 :
        ny -= 1
        while ny>=0 {
            if board[ny][nx]==6 {
                break
            }
            
            board[ny][nx] = -1
            ny -= 1
        }
        
    case 1:
        nx += 1
        while nx<M {
            if board[ny][nx]==6 {
                break
            }
            
            board[ny][nx] = -1
            nx += 1
        }
    
    case 2:
        ny += 1
        while ny<N {
            if board[ny][nx]==6 {
                break
            }
            
            board[ny][nx] = -1
            ny += 1
        }
        
    case 3:
        nx -= 1
        while nx>=0 {
            if board[ny][nx]==6 {
                break
            }
            
            board[ny][nx] = -1
            nx -= 1
        }
        
    default:
        break
    }
}

func dfs(_ cctvIndex: Int) {
    if cctvIndex == K {  // K 개의 cctv 방향이 다 정해진 상황, 커버되는 곳 확인
        var count = 0
        for i in 0..<N {
            for j in 0..<M {
                if board[i][j] == 0 {
                    count += 1
                }
            }
        }
        
        answer = min(answer, count)
        return
    }
    
    let curType = camera[cctvIndex].type
    let cam = camera[cctvIndex]
    
    for i in 0..<rotation[curType] {
        let copy = board
        
        switch curType {
        case 0:
            updateBoard(cam, i)
        case 1:
            updateBoard(cam, i)
            updateBoard(cam, (i+2)%4)
        case 2:
            updateBoard(cam, i)
            updateBoard(cam, (i+1)%4)
        case 3:
            updateBoard(cam, i)
            updateBoard(cam, (i+1)%4)
            updateBoard(cam, (i+2)%4)
        case 4:
            updateBoard(cam, i)
            updateBoard(cam, (i+1)%4)
            updateBoard(cam, (i+2)%4)
            updateBoard(cam, (i+3)%4)
        default:
            continue
        }
        
        dfs(cctvIndex+1)
        board = copy
    }
}


dfs(0)

print(answer)
