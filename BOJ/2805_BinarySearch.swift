import Foundation
// boj 2805 나무 자르기, 이분 탐색, 실버 2

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

let trees = readLine()!.split(separator: " ").map{Int(String($0))!}

var low = 0
var high = 1000000000


func check(_ h: Int) -> Bool {
    var sum: Int64 = 0
    
    for t in trees {
        if t<=h {continue}
        sum += Int64(t-h)
    }
    
    if sum>=M {
        return true
    }
    return false
}

while low<=high {
    let mid = (low+high)/2
    
    if check(mid) {
        low = mid+1
    } else {
        high = mid-1
    }
}

print(low-1)
