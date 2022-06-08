import Foundation
// 프로그래머스 방문 길이, level 2

var y = 0, x = 0

func move(_ to : Character) {
    if to == "U" {
        y += 1
    } else if  to == "D" {
        y -= 1
    } else if to == "R" {
        x += 1
    } else {
        x -= 1
    }
}

func solution(_ dirs:String) -> Int {
    var answer = 0
    var path : Set<String> = []
    
    for dir in dirs {
        let from_y = y, from_x = x
        move(dir)
        let to_y = y, to_x = x
        
        if to_y < -5 || to_y > 5 || to_x < -5 || to_x > 5 {
            y = from_y
            x = from_x
            continue
        }
        
        let way1 = String(from_y) + String(from_x) + String(to_y) + String(to_x)
        let way2 = String(to_y) + String(to_x) + String(from_y) + String(from_x)
        
        if !path.contains(way1) && !path.contains(way2) {
            path.insert(way1)
            path.insert(way2)
            answer += 1
        }
    }
    
    return answer
}

print(solution("LULLLLLLU"))
