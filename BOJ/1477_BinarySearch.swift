import Foundation
// boj 1477 휴게소 세우기, 이분 탐색, 골드 4

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]
let L = str1[2]

var station = readLine()!.split(separator: " ").map { Int(String($0))! }.sorted(by: <)
station.append(L)
station.insert(0, at: 0)

var left = 1
var right = L-1
var answer = 0

while left<=right {
    let mid = (left+right)/2
    var count = 0
    
    for i in 1..<station.count {
        let section = station[i]-station[i-1]
        if section<mid { continue }
        
        count += (section)/mid
        if section%mid == 0 {
            count -= 1
        }
    }
    
    if count>M {
        left = mid+1
    } else {
        right = mid-1
        answer = mid
    }
}

print(answer)
