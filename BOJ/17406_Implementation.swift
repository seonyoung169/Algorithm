import Foundation
// boj 17406 배열 돌리기4, 골드 4, 구현 

let str1 = readLine()!.split(separator: " ").map{Int($0)!}

let N = str1[0]
let M = str1[1]
let K = str1[2]

struct Command {
    var r = -1
    var c = -1
    var s = -1
}

var map = [[Int]]()
map.append([Int](repeating: 0, count: M+1))

var commands = [Command]()
var permutations = [[Command]]()  // K 개의 회전 연산 순열 K! 개
var answer = Int.max

let dy = [0,1,0,-1]
let dx = [1,0,-1,0]

for _ in 0..<N {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    map.append([0]+str2)
}

for _ in 0..<K {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    commands.append(Command(r: str3[0], c: str3[1], s: str3[2]))
}

func permutaionWithRecursion(array: [Command], pickCount: Int, permutations: inout [[Command]], index: Int = 0) {
    if index == pickCount {
        permutations.append(Array(array[0..<index]))
        return
    }
    
    var arr = array
    
    for i in index..<arr.count {
        arr.swapAt(index, i)
        permutaionWithRecursion(array: arr, pickCount: pickCount, permutations: &permutations, index: index + 1)
        arr.swapAt(index, i)
    }
}

func move(_ rotation: Command, _ matrix: inout [[Int]]) {
    var s = rotation.s
    var moved = matrix
    
    while s>=0 {
        let from_r = rotation.r-s, from_c = rotation.c-s
        let to_r = rotation.r+s, to_c = rotation.c+s
        
        if from_r==to_r && from_c==to_c {
            break
        }
        
        var cur = (from_r, from_c)
        var dir = 0
        
        while true {
            var next = (cur.0+dy[dir], cur.1+dx[dir])
            
            if next.0<from_r || next.0>to_r || next.1<from_c || next.1>to_c {
                dir+=1
                if dir == 4 {
                    break
                }
                next = (cur.0+dy[dir], cur.1+dx[dir])
            }
            
            moved[next.0][next.1] = matrix[cur.0][cur.1]
            cur = next
        }
        
        s -= 1
        matrix = moved
    }
}

func value(_ matrix: [[Int]]) -> Int {
    var val = Int.max
    
    for i in 1...N {
        var rowSum = 0
        for j in 1...M {
            rowSum += matrix[i][j]
        }
        val = min(val, rowSum)
    }
    
    return val
}

permutaionWithRecursion(array: commands, pickCount: K, permutations: &permutations)

for permutation in permutations {
    var matrix = map
    
    for rotation in permutation {
        move(rotation, &matrix)
    }
    
    answer = min(answer, value(matrix))
}

print(answer)
