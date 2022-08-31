import Foundation
// boj 15961 회전 초밥, 슬라이딩 윈도우, 골드 4

final class FileIO {
    private var buffer:[UInt8]
    private var index: Int

    init(fileHandle: FileHandle = FileHandle.standardInput) {
        buffer = Array(fileHandle.readDataToEndOfFile())+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
        index = 0
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer.withUnsafeBufferPointer { $0[index] }
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
            || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45{ isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var str = ""
        var now = read()

        while now == 10
            || now == 32 { now = read() } // 공백과 줄바꿈 무시

        while now != 10
            && now != 32 && now != 0 {
                str += String(bytes: [now], encoding: .ascii)!
                now = read()
        }

        return str
    }
}

let fileIO = FileIO()

let (n, d, k, c) = (fileIO.readInt(), fileIO.readInt(), fileIO.readInt(), fileIO.readInt())

var belt = [Int]()
for _ in 0..<n {
    belt.append(fileIO.readInt())
}

var answer = 0
var check = [Int](repeating: 0, count: d+1)
var set = Set<Int>()

for i in 0..<k {
    check[belt[i]] += 1
    set.insert(belt[i])
}

answer = set.contains(c) ? set.count : set.count+1

for i in 1..<n {
    let delete = belt[i-1]
    check[delete] -= 1
    if check[delete] == 0 {
        set.remove(delete)
    }


    let add = belt[(i+k-1)%n]
    check[add] += 1
    set.insert(add)

    let count = set.contains(c) ? set.count : set.count+1
    answer = max(answer, count)
}

print(answer)
