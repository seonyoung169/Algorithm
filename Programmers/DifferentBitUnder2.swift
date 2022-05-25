import Foundation

// 프로그래머스 2개 이하로 다른 비트, level 2
func decToBinary(_ decimal : Int64) -> String {
    return "0" + String(decimal, radix: 2)
}

func binaryToDec(_ binary : String) -> Int64 {
    return Int64(binary,radix: 2)!
}

func findMinNumber(n:Int64) -> Int64 {
    var nBinary = decToBinary(n).map{String($0)}
    for i in 0..<nBinary.count {
        if nBinary[nBinary.count - (i+1)] == "0" {
            nBinary[nBinary.count - (i+1)] = "1"
            if i != 0 {
                nBinary[nBinary.count - i] = "0"
            }
            break
        }
    }
    return binaryToDec(nBinary.joined())
}

func solution(_ numbers:[Int64]) -> [Int64] {
    return numbers.map{findMinNumber(n:$0)}
}
