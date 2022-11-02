import Foundation
// boj 2866 문자열 잘라내기, 문자열, 시간 초과 주의!

let str = readLine()!.split(separator: " ").map{Int($0)!}
let R = str[0]
let C = str[1]

var map = [[String]]()
var key = [String](repeating: "" , count: C)
for _ in 0..<R {
    let row = Array(readLine()!).map{String($0)}
    map.append(row)
}

var answer = 0

for r in (0..<R).reversed() {
    var dic = [String : Int]()
    
    var duplicate = false
    
    for c in 0..<C {
        key[c] += map[r][c]
        
        if let value = dic[key[c]] {
            dic[key[c]] = value + 1
            duplicate = true
        } else {
            dic[key[c]] = 1
        }
    }
    
    answer = r
    if !duplicate {
        break
    }
}

print(answer)
