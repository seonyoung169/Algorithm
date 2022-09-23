import Foundation
// boj 2531 회전초밥, 투포인터, 실버1

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let d = str[1]
let k = str[2]
let c = str[3]

var arr = [Int]()
for _ in 0..<N {
    arr.append(Int(readLine()!)!)
}

var answer = 0
var check = [Int](repeating: 0, count: d+1)
var count = 0
var coupon = true

for i in 0..<k {
    if check[arr[i]] == 0 {
        count += 1
    }
    check[arr[i]] += 1
}

if check[c] == 0 {
    coupon = false
}

if coupon {
    answer = max(answer, count)
} else {
    answer = max(answer, count+1)
}

for i in 1..<N {
    let removed = arr[i-1]
    let added = arr[(i+k-1)%N]
    
    check[removed] -= 1
    if check[removed] == 0 {
        count -= 1
    }
    
    if check[added] == 0 {
        count += 1
    }
    check[added] += 1
    
    if check[c] == 0 {
        coupon = false
    } else {
        coupon = true
    }
    
    
    if coupon {
        answer = max(answer, count)
    } else {
        answer = max(answer, count+1)
    }
}

print(answer)
