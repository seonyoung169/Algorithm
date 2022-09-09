import Foundation
// boj 3020 개똥벌레, 누적 합, 골드 5

let str1 = readLine()!.split(separator: " ").map{Int($0)!}
let N = str1[0]
let H = str1[1]

var top = [Int](repeating: 0, count: H+1)
var bottom = [Int](repeating: 0, count: H+1)
var sum = [Int](repeating: 0, count: H+1)

for i in 0..<N {
    let n = Int(readLine()!)!
    
    if i%2 == 0 {
        bottom[n] += 1
    } else {
        top[H+1-n] += 1
    }
}

for i in (1...H-1).reversed() {
    bottom[i] += bottom[i+1]
}

var min = Int.max
var count = 0

for i in (1...H) {
    top[i] += top[i-1]
    sum[i] = top[i] + bottom[i]
    
    if sum[i] == min {
        count += 1
        continue
    }
    
    if sum[i] < min {
        min = sum[i]
        count = 1
    }
}

print("\(min) \(count)")


