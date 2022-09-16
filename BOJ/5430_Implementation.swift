import Foundation
// boj 5430 AC, 구현, 골드 5

var testcase = Int(readLine()!)!
for _ in 1...testcase{
    var input = readLine()!
    var len = Int(readLine()!)!
    var nums = readLine()!.components(separatedBy: [",","[","]"])
    
    nums.removeFirst()
    nums.removeLast()
    
    var start = 0
    var end = len-1
    var reversed = false
    var error = false
    
    for i in input {
        if i == "D"{
            if start > end {
                error = true
                break
            }
            if reversed {
                end -= 1
            }
            else {
                start += 1
            }
        }
        else {
            reversed.toggle()
        }
    }
    
    if error {
        print("error")
    }
    else if start > end {
        print("[]")
    }
    else {
        if reversed {
            
            print("[",terminator: "")
            for i in 0...end-start {
                print(nums[end-i],terminator: "")
                if i != end-start {
                    print(",",terminator: "")
                }
            }
            print("]")
        }
        else {
            print("[",terminator: "")
            for i in start...end {
                print(nums[i],terminator: "")
                if i != end {
                    print(",",terminator: "")
                }
            }
            print("]")
        }
    }
}
