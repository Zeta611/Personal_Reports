import time


def sieve_eratosthenes(n):
    sieve = [1] * n
    sieve[0] = 0
    for p in xrange(2, n + 1):
        if sieve[p - 1]:
            # print p
            for i in xrange(p ** 2, n + 1, p):
                sieve[i - 1] = 0


n = 100000000
average = 0
for _ in xrange(2):
    start = time.time()
    sieve_eratosthenes(n)
    end = time.time()
    average += end - start
print average / 2.
