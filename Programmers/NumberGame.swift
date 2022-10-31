import Foundation

func solution(_ a:[Int], _ b:[Int]) -> Int {
    var answer = 0
    var arr1 = a.sorted()
    var arr2 = b.sorted()

    var i = 0
    for j in 0..<b.count {
        if(arr2[j] <= arr1[i]) {
            continue
        }
        
        answer += 1
        i += 1
    }
    
    return answer
}
