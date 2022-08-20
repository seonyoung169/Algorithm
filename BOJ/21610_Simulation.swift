import Foundation
// boj 21610 마법사 상어와 비바라기, 골그 5 시뮬

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

var map = [[Int]](repeating: [Int](repeating: 0, count: N+1), count: N+1)

var direction = [Int]()
var speed = [Int]()

let dy = [0,0,-1,-1,-1,0,1,1,1]
let dx = [0,-1,-1,0,1,1,1,0,-1]

for i in 1...N {
    let str2 = readLine()!.split(separator: " ").map{Int($0)!}
    for j in 1...N {
        map[i][j] = str2[j-1]
    }
}

for _ in 0..<M {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    
    direction.append(str3[0])
    speed.append(str3[1])
}

struct Point : Hashable {
    var y = -1
    var x = -1
}

var cloud: Set<Point> = [Point(y: N-1, x: 1),
                         Point(y: N-1, x: 2),
                         Point(y: N, x: 1),
                         Point(y: N, x: 2)]


// 구름 이동 후 이동한 위치의 바구니 물 양 1 증가
func moveCloud(_ idx: Int) {
    let d = direction[idx]
    let s = speed[idx]
    
    var moved = Set<Point>()
    for p in cloud {
        var ny = p.y + dy[d] * (s % N)
        var nx = p.x + dx[d] * (s % N)
        
        if ny<1 { ny += N }
        if ny>N { ny -= N }
        
        if nx<1 { nx += N }
        if nx>N { nx -= N }
        
        map[ny][nx] += 1
        moved.insert(Point(y: ny, x: nx))
    }
    
    cloud = moved
}

// 물복사 마법
func copyWater(_ location: Set<Point>) {
    
    for p in location {
        var idx = 2
        var count = 0
        
        while idx<=8 {
            let ny = p.y + dy[idx]
            let nx = p.x + dx[idx]
            
            idx += 2
            
            if ny<1 || ny>N || nx<1 || nx>N {
                continue
            }
            
            if map[ny][nx] > 0 { count += 1 }
            
        }
        
        map[p.y][p.x] += count
    }
}

// 새로운 구름 생성
func makeNewCloud(_ deleted: Set<Point>) {
    for i in 1...N {
        for j in 1...N {
            let newPoint = Point(y: i, x: j)
            if map[i][j] >= 2 && !deleted.contains(newPoint) {
                cloud.insert(newPoint)
                map[i][j] -= 2
            }
        }
    }
}

var order = 0
while order < M {
    
    moveCloud(order)
    let deleted = cloud
    
    copyWater(cloud)
    
    cloud = []
    makeNewCloud(deleted)
    
    
    order += 1
}

var water = 0
for i in 1...N {
    for j in 1...N {
        if map[i][j] > 0 {
            water += map[i][j]
        }
    }
}

print(water)


