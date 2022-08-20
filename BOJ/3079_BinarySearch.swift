import Foundation
// boj 3079 입국심사, 시뮬, 골드 5

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

var desk = [Int]()

for _ in 0..<N {
    let time = Int(readLine()!)!
    desk.append(time)
}

_ = desk.sorted(by: <)

var left = 0
var right = desk[N-1] * M

var answer = Int.max

while left <= right {
    let mid = (left + right) / 2
    var count = 0
    
    for d in desk {
        count += mid/d
    }
    
    if count>=M {
        answer = min(answer, mid)
        right = mid-1
    } else {
        left = mid+1
    }
}


print(answer)
