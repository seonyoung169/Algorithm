import Foundation

// 프로그래머스 문자열 압축 level 2 
extension String {
    func substring(from : Int, to : Int) -> String {
        guard from < count, to >= 0, to-from >= 0 else { return "" }
        
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to+1)
        
        return String(self[startIndex..<endIndex])
    }
}

func split(_ s : String, _ len : Int) -> [String] {
    var splitted = [String]()
    
    var i = 0
    while(i < s.count){
        let to = i+len-1
        
        if(to >= s.count) {
            splitted.append(s.substring(from: i, to: s.count-1))
            break
        }
        
        splitted.append(s.substring(from: i, to: to))
        i += len
    }
    
    return splitted
}

func compress(_ tokens : [String]) -> Int {
    
    var compressed = ""
    var count = 1
    
    for i in 1..<tokens.count {
        
        if tokens[i] == tokens[i-1] {
            count += 1
            continue
        }
        
        if count > 1 {
            compressed += "\(count)"
        }
        compressed += tokens[i-1]
        count = 1
    }
    
    if count > 1 {
        compressed += "\(count)"
    }
    compressed += tokens[tokens.count-1]
    
    
    return compressed.count
}

func solution(_ s:String) -> Int {
    if s.count == 1 {
        return 1
    }
    
    var answer = s.count
    
    for len in 1...s.count/2 {
        let tokens = split(s,len)
        answer = min(answer, compress(tokens))
    }
    
    return answer
}


