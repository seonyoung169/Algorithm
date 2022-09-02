import Foundation
// boj 16953 A->B, 그리디, 실버 2

let str = readLine()!.split(separator: " ").map{Int($0)!}
let A = str[0]
let B = str[1]

var answer = 0

func solution(_ num: Int, _ count: Int) {
    if num > B { return }
    
    if num == B {
        if answer == 0 {
            answer = count
        } else {
            answer = min(answer, count)
        }
        return
    }
    
    solution(2*num, count+1)
    
    let next = Int(String(num) + "1")!
    solution(next, count+1)
}

solution(A, 0)

if answer == 0 {
    print("-1")
} else {
    print("\(answer+1)")
}
