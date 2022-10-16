import Foundation
// 프로그래머스 베스트 앨범, 해시, level 3

struct Song {
    var index = -1
    var count = 0
}
func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    var record = [String : [Song]]()
    
    genres.enumerated().forEach { (i, gen) in
        let played = plays[i]
        
        if let list = record[gen]  {
            record.updateValue(list + [Song(index: i, count: played)], forKey: gen)
        } else {
            record[gen] = [Song(index: i, count: played)]
        }
    }
    
    var answer = [Int]()
    let playedSorted = Array(record.values).sorted {
            ($0.reduce(0){$0 + $1.count}) > ($1.reduce(0){$0 + $1.count})
        }
    
    for genList in playedSorted {
        let sortedList = genList.sorted { (first, second) in
            if first.count == second.count {
                return first.index < second.index
            }

            return first.count > second.count
        }

        let maxCount = sortedList.count > 1 ? 2 : 1

        for i in 0..<maxCount {
            answer.append(sortedList[i].index)
        }
    }
    
    return answer
}

print(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]))
