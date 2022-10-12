import Foundation
// 프로그래머스 K번째 수 

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    // 내 풀이 
//     var answer = [Int]()
    
//     for cmd in commands {
//         let from = cmd[0]
//         let to = cmd[1]
//         let k = cmd[2]
        
//         var sub = [Int]()
//         for i in from-1...to-1 {
//             sub.append(array[i])
//         }
//         sub.sort()
        
//         answer.append(sub[k-1])
//     }
    
//     return answer
    
    // 개선 풀이 
    return commands.map({ (cmd) in
                         let from = cmd[0]-1
                         let to = cmd[1]-1
                         let k = cmd[2]-1
                         return array[from...to].sorted()[k]
                        })
}
