import Foundation

// 프로그래머스 영어 끝말잇기, level 2
extension String {
    subscript(idx: Int) -> String? {
        guard (0..<count).contains(idx) else {
            return nil
        }
        
        let target = index(startIndex, offsetBy: idx)
        return String(self[target])
    }
}

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var answer = [0,0]
    var voca : Set = [words[0]]
    
    for i in 1..<words.count {
        guard let last = words[i-1][words[i-1].count-1], let start = words[i][0] else {
            break
        }
        
        if(voca.contains(words[i]) || last != start){
            var num = (i+1) % n
            if (num==0) {
                num = n
            }
            answer[0] = num
            answer[1] = (i/n) + 1
            break
        }
        voca.insert(words[i])
    }
    
    return answer
}
