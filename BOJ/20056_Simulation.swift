import Foundation
// boj 20056 마법사 상어와 파이어볼, 골드 4, 시뮬

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]
var K = str1[2]

let dy = [-1,-1,0,1,1,1,0,-1]
let dx = [0,1,1,1,0,-1,-1,-1]

struct Fireball {
    var m: Int = -1
    var s: Int = -1
    var d: Int = -1
}

var map = [[[Fireball]]](repeating: [[Fireball]](repeating: [Fireball](), count: N+1), count: N+1)

for _ in 0..<M {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    let r = str2[0], c = str2[1]
    let m = str2[2], s = str2[3], d = str2[4]
    map[r][c].append(Fireball(m: m, s: s, d: d))
}

func moveBall(_ moved: inout [[[Fireball]]]) {
    // 이동
    for r in 1...N {
        for c in 1...N {
            if map[r][c].isEmpty { continue }
            
            for i in 0..<map[r][c].count {
                // r,c 에 위치한 파이어볼 1개 혹은 4개의 새로운 위치 계산
                let ball = map[r][c][i]
                var nr = r + dy[ball.d] * (ball.s % N)
                var nc = c + dx[ball.d] * (ball.s % N)
                
                if nr<1 { nr += N }
                if nr>N { nr -= N }
                
                if nc<1 { nc += N }
                if nc>N { nc -= N}
                
                moved[nr][nc].append(ball)
            }
        }
    }
}

func arrangeBall(_ moved: inout [[[Fireball]]]) {
    // 2개 이상 있는 곳 정리 하기
    for r in 1...N {
        for c in 1...N {
            if moved[r][c].count < 2 { continue }
            
            var nm = 0
            var ns = 0
            var dirCount = [0,0]
            
            for i in 0..<moved[r][c].count {
                nm += moved[r][c][i].m
                ns += moved[r][c][i].s
                
                let idx = moved[r][c][i].d % 2
                dirCount[idx] += 1
            }
            
            nm /= 5
            ns /= moved[r][c].count
            
            if nm == 0 {  // 새로운 질량이 0 이면 소멸
                map[r][c] = []
                continue
            }
            
            var nd_start = 0
            if !(dirCount[0] == moved[r][c].count || dirCount[1] == moved[r][c].count) {
                nd_start += 1
            }
            
            // 새로운 4개의 ball 의 방향 nd_start 부터 2씩 올리면서 생성해서 map 에 새롭게 넣기
            var arranged = [Fireball]()
            for _ in 0..<4 {
                arranged.append(Fireball(m: nm, s: ns, d: nd_start))
                nd_start += 2
            }
            map[r][c] = arranged
        }
    }
}

while K > 0 {
    var moved = [[[Fireball]]](repeating: [[Fireball]](repeating: [Fireball](), count: N+1), count: N+1)
    
    moveBall(&moved)
    map = moved
    arrangeBall(&moved)
    
    K -= 1
}

var answer = 0
for i in 1...N {
    for j in 1...N {
        if map[i][j].isEmpty { continue }
        let count = map[i][j].count
        answer += map[i][j][0].m * count
    }
}

print( answer )
