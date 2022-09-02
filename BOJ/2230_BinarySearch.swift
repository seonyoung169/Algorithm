import Foundation
// boj 2230 수 고르기, 이분탐색, 골드 5

let str = readLine()!.split(separator: " ").map{Int($0)!}
let N = str[0]
let M = str[1]

var arr = [Int]()
var answer = Int.max

for _ in 0..<N {
    let num = Int(readLine()!)!
    arr.append(num)
}

arr = arr.sorted(by: <)

var left = 0
var right = 0

while left < N {
    while right<N && arr[right]-arr[left]<M {
        right += 1
    }

    if right >= N {
        break
    }

    if arr[right]-arr[left] >= M {
        answer = min(answer, arr[right]-arr[left])
    }
    left+=1
}

print(answer)
