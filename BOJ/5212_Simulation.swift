import Foundation

// boj 5212 지구 온난화, 시뮬레이션, 실버 2

var R: Int = 0
var C: Int = 0
var map: [[String]] = []

let dy = [-1,0,1,0]
let dx = [0,1,0,-1]

extension String {
    func substring(from : Int, to : Int) -> String {
        guard from < count, to >= 0, to-from >= 0 else { return "" }
        
        let startIndex = index(self.startIndex, offsetBy: from)
        let endIndex = index(self.startIndex, offsetBy: to+1)
        
        return String(self[startIndex..<endIndex])
    }
}

func solution() -> Void {
    
    var futureMap = Array(repeating: Array(repeating: ".", count: C), count: R)
    var minY = R, minX = C
    var maxY = 0, maxX = 0
    
    for i in 0..<R {
        for j in 0..<C {
            if map[i][j] == "." {
                continue
            }
            
            var count = 0
            for k in 0..<4 {
                let ny = i + dy[k], nx = j + dx[k]
                
                if ny<0 || ny>=R || nx<0 || nx>=C {
                    count += 1
                    continue
                }
                
                if map[ny][nx] == "." {
                    count += 1
                }
            }
            
            if count < 3 {
                futureMap[i][j] = "X"
                if i<minY {
                    minY = i
                }
                
                if i>maxY {
                    maxY = i
                }
                
                if j<minX {
                    minX = j
                }
                
                if j>maxX {
                    maxX = j
                }
            }
        }
    }
    

    for i in minY...maxY {
        var substr = ""
        for j in minX...maxX {
            substr += futureMap[i][j]
        }
        print(substr)
    }
}

if let input = readLine() {
    let array = input.components(separatedBy: " ")
    R = Int(array[0])!
    C = Int(array[1])!
    
    for _ in 0..<R {
        if let row = readLine() {
            map.append(row.map{String($0)})
        }
    }
    
    solution()
}

