import QuartzCore

func sieveEratosthenes(_ n: Int) {
    var sieve = Array(repeating: 1, count: n)
    sieve[0] = 0
    for p in 2...n {
        if sieve[p - 1] == 1 {
            // print(p)
            for i in stride(from: p * p, through: n, by: p) {
                sieve[i - 1] = 0
            }
        }
    }
}

let n = 100000000
var average = 0.0
for _ in 1...100 {
    let start = CACurrentMediaTime()
    sieveEratosthenes(n)
    let end = CACurrentMediaTime()
    average += end - start
}
print(average / 100.0)
