import Foundation

// 프로그래머스 오픈 채팅방, level 2

func solution(_ record:[String]) -> [String] {
    
    var nameInfo = [String : String]()
    var comeAndGoInfo = [[String]]()
    
    for data in record {
        let tokens = data.split(separator: " ")
        
        if(tokens[0] == "Change") {
            nameInfo[String(tokens[1])] = String(tokens[2])
            continue
        }
        
        comeAndGoInfo.append([String(tokens[0]), String(tokens[1])])
        
        if(tokens[0] == "Enter") {
            nameInfo[String(tokens[1])] = String(tokens[2])
        }
    }
    
    var answer = [String]()
    for i in 0..<comeAndGoInfo.count {
        let id = comeAndGoInfo[i][1]
        let name = nameInfo[id]!
        
        if comeAndGoInfo[i][0] == "Enter" {
            answer.append("\(name)님이 들어왔습니다.")
        } else {
            answer.append("\(name)님이 나갔습니다.")
        }
    }
    
    return answer
}
