import Foundation
// boj 16120 PPAP, 문자열, 골드 4

let N = 1000000
let str = readLine()!
var array = str.map{String($0)}

var st = [String](repeating: "", count: N)
var index = 0
let cmp = ["P", "P", "A", "P"]

var i = 0
while i<array.count {
    let ch = array[i]
    st[index] = ch
    
    if ch == "A" {
        index += 1
        i += 1
        continue
    }
    
    if index<3 {
        index += 1
        i += 1
        continue
    }
    
    var valid = true
    for j in 0...3 {
        if cmp[j] != st[index-3+j] {
            valid = false
            break
        }
    }
    
    if valid {
        index -= 2
    } else {
        index += 1
    }
    i += 1
}

var answer = "PPAP"
if index != 1 || st[index-1] != "P" {
    answer = "NP"
}

print(answer)
