import Foundation
// boj 20438 출석체크, 누적 합, 실버 2

let str1 = readLine()!.split(separator: " ")
let N = Int(str1[0])!
let K = Int(str1[1])!
let Q = Int(str1[2])!
let M = Int(str1[3])!

var isSleep = [Bool](repeating: false, count: N+3)

let str2 = readLine()!.split(separator: " ")
for i in 0..<K {
    isSleep[Int(str2[i])!] = true
}

let called = readLine()!.split(separator: " ").map{Int($0)!}
var exist = [Int](repeating: 1, count: N+3)

func makePrefix() {

    for student in called {
        if isSleep[student] {
            continue
        }
        
        var i = student
        while i < exist.count {
            if !isSleep[i] {
                exist[i] = 0
            }
            i += student
        }
    }
    
    for i in 3...N+2 {
        exist[i] += exist[i-1]
    }
}

makePrefix()

var answer = ""
for _ in 0..<M {
    let str3 = readLine()!.split(separator: " ").map{Int($0)!}
    let count = exist[str3[1]] - exist[str3[0]-1]
    answer += "\(count)\n"
}

print(answer)
