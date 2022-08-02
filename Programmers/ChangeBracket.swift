import Foundation

// 프로그래머스 괄호 변환, level 2, Stack 사용
extension String {
    func substring(from : Int, to : Int) -> String {
        guard from < count, to >= 0, to-from >= 0 else { return "" }
        
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to+1)
        
        return String(self[startIndex..<endIndex])
    }
}

struct Stack<T> {
    private var stack: [T] = []
    
    public var count: Int {
        return stack.count
    }
    
    public var isEmpty: Bool {
        return stack.isEmpty
    }
    
    public mutating func push(_ element: T) {
        stack.append(element)
    }
    
    public mutating func pop() -> T? {
        return isEmpty ? nil : stack.popLast()
    }
}


func isRight(_ s : String ) -> Bool {
    if s.substring(from: 0, to: 0) == ")" {
        return false
    }
    
    var st = Stack<String>()
    
    for ch in s {
        if ch == "(" {
            st.push(String(ch))
            continue
        }
        
        if !st.isEmpty {
            _ = st.pop()
        } else {
            return false
        }
    }
    
    if !st.isEmpty {
        return false
    }
    
    return true
}

func split(_ s : String) -> [String] {
    
    var head = 0, tail = 0
    var mid = 0
    
    for i in 0..<s.count {
        if s.substring(from: i, to: i) == "(" {
            head += 1
        } else {
            tail += 1
        }
        
        if head == tail {
            mid = i
            break
        }
    }
    
    return [s.substring(from: 0, to: mid), s.substring(from: mid+1, to: s.count-1)]
}

func convert(_ s : String) -> String {
    var result = ""
    let deleted = s.substring(from: 1, to: s.count-2)
    
    for ch in deleted {
        if ch == "(" {
            result += ")"
        } else {
            result += "("
        }
    }
    
    return result
}

func solution(_ p:String) -> String {
    
    if p == "" {
        return ""
    }
    
    if isRight(p) {
        return p
    }
    
    var answer = ""
    let tokens = split(p)
    
    if isRight(tokens[0]) {
        answer = tokens[0] + solution(tokens[1])
    } else {
        answer = "(" + solution(tokens[1]) + ")" + convert(tokens[0])
    }
    
    return answer
}
