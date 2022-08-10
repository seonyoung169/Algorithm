import Foundation

// boj 20055 컨베이어 벨트 위의 로봇, 골드 5, 시뮬 
var N: Int = 0
var K: Int = 0

var belt: [Int] = []
var robot: [Bool] = []

func rotate() -> Void {
    let SIZE = 2 * N
    var newBelt = Array(repeating: 0, count: SIZE)
    var newRobot = Array(repeating: false, count: SIZE)
    
    for i in 0..<2*N {
        newBelt[(i+1) % SIZE] = belt[i]
        newRobot[(i+1) % SIZE] = robot[i]
    }
    
    belt = newBelt
    robot = newRobot
}

func moveRobot() -> Void {
    for i in (0..<N-1).reversed() {
        if robot[i] && !robot[i+1] && belt[i+1] > 0 {
            robot[i+1] = true
            robot[i] = false
            belt[i+1] -= 1
        }
    }
}

func checkDurability() -> Int {
    var count = 0
    
    for i in 0..<2*N {
        if belt[i] == 0 {
            count += 1
        }
    }
    
    return count
}

func solution() -> Int {
    var stage = 0
    robot = Array(repeating: false, count: 2*N)
    
    while true {
        stage += 1
        
        rotate()
        
        if robot[N-1] {
            robot[N-1] = false
        }
        
        moveRobot()
        
        if robot[N-1] {
            robot[N-1] = false
        }
        
        if belt[0]>0 {
            robot[0] = true
            belt[0] -= 1
        }
        
        if checkDurability() >= K {
            break
        }
    }
    
    return stage
}

if let input = readLine() {
    let array = input.components(separatedBy: " ")
    N = Int(array[0])!
    K = Int(array[1])!
    
    if let row = readLine() {
        let a = row.components(separatedBy: " ")
        for i in  0..<(2*N) {
            belt.append(Int(a[i])!)
        }
    }
    
    print(solution())
}

