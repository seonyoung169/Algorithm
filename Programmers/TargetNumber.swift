import Foundation

// 프로그래머스 타켓 넘버, level 2, dfs

var count: Int = 0

func DFS(_ numbers:[Int], _ target:Int, _ sum:Int, _ index:Int) {
    if index == numbers.count-1 &&  sum == target {
        count += 1
        return
    }
    
    if index+1 < numbers.count {
        DFS(numbers, target, sum+numbers[index+1], index+1)
        DFS(numbers, target, sum-numbers[index+1], index+1)
    }
}

func solution(_ numbers:[Int], _ target:Int) -> Int {
    
    DFS(numbers, target, 0, -1)
    
    return count
}
