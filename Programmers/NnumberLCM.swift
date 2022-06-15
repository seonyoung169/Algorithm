import Foundation
// 프로그래머스 N개의 최소 공배수, level 2

var numbers = [Int]()

func LSM(_ num1 : Int, _ num2 : Int) -> Int {
    var small = num1, big = num2
    
    if num1 > num2 {
        small = num2
        big = num1
    }
    
    var mul = 1
    var result = big
    
    while (result % small != 0){
        mul += 1
        result = big*mul
    }
    
    return result
}

func solution(_ arr:[Int]) -> Int {
    numbers = arr
    numbers.sorted()
    
    if numbers.count == 1 { return numbers[0] }
    else if numbers.count == 2 { return LSM(numbers[0], numbers[1])}
    
    var left = numbers[0]
    for i in 1..<numbers.count {
        var temp = LSM(left, numbers[i])
        left = temp
    }
    
    return left 
}
