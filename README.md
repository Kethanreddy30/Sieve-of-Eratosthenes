# Sieve of Eratosthenes

The Sieve of Eratosthenes is an ancient algorithm used for finding all prime numbers up to a given limit. It is named after the Greek mathematician Eratosthenes of Cyrene, who lived in the 3rd century BC. Eratosthenes was not only a mathematician, but also an astronomer, geographer, and poet. He is best known for his work on prime numbers and his algorithm for finding them, known as the Sieve of Eratosthenes.

As the word ‘Sieve’ means filtering out dirt elements. The algorithm starts by creating a list of all integers from 2 to the given limit. The first step is to mark the number 2 as a prime number. Then, starting with 2, all multiples of that number are crossed off the list as they cannot be prime numbers. The next unmarked number, which is guaranteed to be a prime number, is 3, similarly all the multiple of 3 are crossed off. This process is continued for each subsequent unmarked number until all prime numbers up to the given limit have been identified.

This repository contains implementations of the Sieve of Eratosthenes algorithm in various programming languages.

## Visualization

For a visual demonstration of the Sieve of Eratosthenes algorithm, you can visit
(https://algorithms-visual.com/eratosthenes/). 
It provides an interactive visualization that helps to understand how the algorithm works.

## Implementations

Each implementation in this repository includes the code files with instructions on how to use it.

- **Python**: [soe.py]
- **C++**: [soe.cpp]
- **C**: [soe.c]

## Usage

Instructions for using each implementation are provided in the Implementation files.

## Contributions

Contributions to improve existing implementations or add new languages are welcome! Please open a pull request with your changes.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
