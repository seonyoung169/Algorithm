import Foundation
// boj 2110 공유기 설치, 이분 탐색, 골드 5 

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let C = str1[1]


var temp = [Int]()
for _ in 0..<N {
    let time = Int(readLine()!)!
    temp.append(time)
}

var house = temp.sorted(by: < )

var left = 1
var right = house[N-1] - house[0]

var answer = 0

while left <= right {
    let mid = (left + right) / 2
    
    var router = 1
    var from = house[0]
    
    for i in 1..<N {
        if house[i]-from >= mid {
            router += 1
            from = house[i]
        }
    }
    
    if router>=C {
        left = mid + 1
        answer = max(answer, mid)
    } else {
        right = mid - 1
    }
}

print(answer)
