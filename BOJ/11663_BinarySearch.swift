import Foundation
// boj 11663 선분 위의 점, 이분 탐색, 실버 3

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

var points = readLine()!.split(separator: " ").map{Int(String($0))!}
points.sort()

var answer = [Int]()

func searchStart(_ dest: Int) -> Int {
    var left = 0
    var right = N-1
    
    while left<=right {
        let mid = (left+right)/2
        
        if points[mid] < dest {
            left = mid+1
        } else {
            right = mid-1
        }
    }
    
    return right+1
}
func searchEnd(_ dest: Int) -> Int {
    var left = 0
    var right = N-1
    
    while left<=right {
        let mid = (left+right)/2
        
        if points[mid] <= dest {
            left = mid+1
        } else {
            right = mid-1
        }
    }
    
    return right
}

for _ in 0..<M {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    let start  = str3[0]
    let end = str3[1]
    
    let start_index = searchStart(start)
    let end_index = searchEnd(end)
    
    answer.append(end_index-start_index+1)
}

for ans in answer {
    print(ans)
}
