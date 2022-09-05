import Foundation
// boj 13397 구간 나누기2, 골드 4, 이분탐색

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let M = str1[1]

let str2 = readLine()!.split(separator: " ").map{Int(String($0))!}
var arr = [Int]()
var left = 0
var right = 0
var answer = Int.max

for num in str2 {
    arr.append(num)
    right = max(right, num)
}

func countSection(_ score: Int) -> Int {
    var count = 1
    
    var section_min = arr[0]
    var section_max = arr[0]
    
    for i in 1..<arr.count {
        section_min = min(section_min, arr[i])
        section_max = max(section_max, arr[i])
        
        if section_max-section_min > score {
            count += 1
            section_min = arr[i]
            section_max = arr[i]
        }
    }
    
    return count
}

while left<=right {
    let mid = (left+right)/2
    
    let sections = countSection(mid)
    
    if sections<=M {
        right = mid-1
        answer = min(answer, mid)
    } else{
        left = mid+1
    }
}

print(answer)
