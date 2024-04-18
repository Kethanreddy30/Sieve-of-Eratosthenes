#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

void SieveOfEratosthenes(int n, ofstream &outputFile) {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Write prime numbers to output file
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            outputFile << p;
            if (p < n) outputFile << ",";
        }
    }
}

int main() {
    // Check if "input.txt" exists
    ifstream inputFileCheck("input.txt");
    bool fileExists = inputFileCheck.good();
    inputFileCheck.close();

    // Open input file for appending
    ofstream inputFile("input.txt", ios_base::app);
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // If file doesn't exist, write test cases
    if (!fileExists) {
        vector<int> testCases = {10, 20, 30}; // Example test cases
        for (int n : testCases)
            inputFile << n << endl;
    }

    inputFile.close(); // Close input file

    // Open output file
    ofstream outputFile("output.txt");
    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        return 1;
    }

    // Read from input file and write output to output file
    ifstream inputFileRead("input.txt");
    if (!inputFileRead) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int n;
    while (inputFileRead >> n) {
        SieveOfEratosthenes(n, outputFile);
        outputFile << endl; // Separate test cases by newline
    }

    inputFileRead.close(); // Close input file
    outputFile.close();    // Close output file

    cout << "Output has been written to 'output.txt'" << endl;

    return 0;
}
