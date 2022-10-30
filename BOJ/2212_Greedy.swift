import Foundation
// boj 2212 센서, 골드 5

let N = Int(readLine()!)!
let K = Int(readLine()!)!
var sensor = readLine()!.split(separator: " ").map{Int($0)!}
sensor.sort(by: <)

var answer = 0
if N>K {
    var diff = [Int](repeating: 0, count: N-1)
    for i in 0..<N-1 {
        diff[i] = sensor[i+1]-sensor[i]
    }

    diff.sort(by: <)
    
    answer = diff[0..<N-K].reduce(0, +)
}

print(answer)
