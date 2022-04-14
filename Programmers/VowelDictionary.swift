import Foundation

// 프로그래머스 모음 사전, level 2
extension String {
    subscript(idx: Int) -> String? {
        guard (0..<count).contains(idx) else {
            return nil
        }
        
        let target = index(startIndex, offsetBy: idx)
        return String(self[target])
    }
}


func solution(_ word:String) -> Int {
    var answer = word.count
    
    let seq = ["A" : 0, "E" : 1,  "I" : 2, "O" : 3, "U" : 4]
    let diff = [781, 156, 31, 6, 1]
    
    for i in 0..<word.count {
        guard let str = word[i] else {
            continue
        }
        guard let time = seq[str] else {
            continue
        }
        answer += diff[i] * time
    }
    return answer
}
