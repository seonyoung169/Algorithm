import Foundation
// 프로그래머스 배달, level 2, 다익스트라 이용 

let INF = 1000000

func solution(_ N:Int, _ road:[[Int]], _ k:Int) -> Int {
    var answer = 1
    
    var cost = Array(repeating: INF, count: N+1)
    var visited = Array(repeating: false, count: N+1)
    var adjacent = Array(repeating: Array(repeating: INF, count: N+1), count: N+1)

    // 연결 리스트 생성
    for info in road {
        let from = info[0], to = info[1], dist = info[2]
        adjacent[from][to] = min(adjacent[from][to], dist)
        adjacent[to][from] = min(adjacent[to][from], dist)
    }
    
    
    cost[1] = 0
    visited[1] = true
    
    for i in 2...N {
        cost[i] = min(cost[i], adjacent[1][i])
    }
    
    var midCount = 0
    while midCount < N-1 {
        var mid = 0
        var minDist = INF
        
        for i in 2...N {  // 중간 지점 찾기
            if !visited[i] && cost[i] < minDist {
                minDist = cost[i]
                mid = i
            }
        }
        
        visited[mid] = true
        midCount += 1
        
        for i in 2...N {
            cost[i] = min(cost[i], minDist + adjacent[mid][i])
        }
    }
    
    // k 이하 거리 내 마을 count
    for i in 2...N {
        if cost[i] <= k {
            answer += 1
        }
    }
    
    return answer
}
