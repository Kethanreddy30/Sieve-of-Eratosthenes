def sieve_of_eratosthenes(n):
    # Create a boolean list "prime[0..n]" and initialize
    # all entries it as True. A value in prime[i] will
    # finally be False if i is Not a prime, else True.
    primes = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if primes[p]:
            # Update all multiples of p
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1

    # Collect prime numbers
    prime_numbers = [p for p in range(2, n + 1) if primes[p]]
    return prime_numbers

def main():
    # Check if "input.txt" exists
    try:
        with open("input.txt", "r") as f:
            input_exists = True
    except FileNotFoundError:
        input_exists = False

    # Create input file with default test cases if it doesn't exist
    if not input_exists:
        test_cases = [10, 20, 30]  # Example test cases
        with open("input.txt", "w") as f:
            for case in test_cases:
                f.write(str(case) + "\n")
        print("Input file 'input.txt' has been created with default test cases")

    # Compute prime numbers for each test case
    with open("input.txt", "r") as f:
        test_cases = [int(line.strip()) for line in f]
    
    prime_results = [sieve_of_eratosthenes(n) for n in test_cases]

    # Write output to file
    with open("output.txt", "w") as f:
        for primes in prime_results:
            f.write(','.join(map(str, primes)) + '\n')

    print("Output has been written to 'output.txt'")

if __name__ == "__main__":
    main()
