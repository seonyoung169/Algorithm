import Foundation
// boj 3649 로봇프로젝트, 이분탐색, 골드 5

while let input = readLine() {
    let X = Int(input)! * 10000000
    let N = Int(readLine()!)!

    var frag = [Int]()
    for _ in 0..<N {
        frag.append(Int(readLine()!)!)
    }
    frag.sort()

    var left = 0
    var right = N-1
    var answer = [(Int, Int)]()
    var possible = false

    while left<right {
        let sum = frag[left] + frag[right]
        
        if sum > X {
            right -= 1
        } else if sum < X {
            left += 1
        } else {
            possible = true
            answer.append((frag[left], frag[right]))
            break
        }
    }

    print(possible ? "yes \(answer[0].0) \(answer[0].1)" : "danger")
}
