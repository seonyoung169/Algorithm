import Foundation
// 프로그래머스 스티커 모으기(2) level3, DP 

func solution(_ sticker:[Int]) -> Int{
    let N = sticker.count
    
    if N==1 { return sticker[0] }
    if N==2 { return max(sticker[0], sticker[1]) }
    
    var dp1 = [Int](repeating: 0, count: N)
    var dp2 = [Int](repeating: 0, count: N)
    
    dp1[0] = sticker[0]
    dp1[1] = sticker[0]
    
    var i = 2
    while i<N-1{
        dp1[i] = max(dp1[i-1], dp1[i-2]+sticker[i])
        i+=1
    }
    
    dp2[1] = sticker[1]
    i = 2
    while i<N {
        dp2[i] = max(dp2[i-1], dp2[i-2]+sticker[i])
        i+=1
    }
    
    return max(dp1[N-2], dp2[N-1])
}
