#6

import Foundation

// boj 12904 A와 B, 문자열, 골드 5

let S = readLine()!
let T = readLine()!

var answer = "0"


func check(_ str: [String]) {
    if str.count == 0 { return }
    
    if str.reduce(""){$0+$1} == S {
        answer = "1"
        return
    }
    
    var array = str
    guard let last = array.popLast() else {
        return
    }
    
    if last == "A" {
        check(array)
    } else  {
        check(array.reversed())
    }
}

check(T.map{String($0)})

print(answer)
