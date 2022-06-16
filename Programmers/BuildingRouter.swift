import Foundation
// 프로그래머스 기지국 설치, level 3 

func solution(_ n:Int, _ stations:[Int], _ w:Int) -> Int{
    var answer = 0
    let range = 2*w + 1
    
    var from = 0, to = 0
    for num in stations {
        from = num - w
        
        if from - to > 1 {
            let section = from-to-1
            if section % range != 0 {
                answer += 1
            }
            answer += section / range
        }
        
        to = num + w
    }
    
    if to < n {
        let last = n-to
        if last % range != 0 {
            answer += 1
        }
        answer += last / range
    }
    return answer
}
