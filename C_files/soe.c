#include <stdio.h>
#include <stdbool.h>

void SieveOfEratosthenes(int n, FILE *outputFile)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    for (int i = 0; i <= n; i++)
        prime[i] = true;

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Write prime numbers to output file
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            fprintf(outputFile, "%d", p);
            if (p < n)
                fprintf(outputFile, ",");
        }
    }
}

int main()
{
    // Check if "input.txt" exists
    FILE *inputFileCheck = fopen("input.txt", "r");
    bool fileExists = (inputFileCheck != NULL);
    if (inputFileCheck != NULL)
        fclose(inputFileCheck);

    // Open input file for appending
    FILE *inputFile = fopen("input.txt", "a");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    // If file doesn't exist, write test cases
    if (!fileExists)
    {
        int testCases[] = {10, 20, 30};                                    // Example test cases
        for (int i = 0; i < (int)(sizeof(testCases) / sizeof(testCases[0])); i++) // Casting to int 
            fprintf(inputFile, "%d\n", testCases[i]);
    }

    fclose(inputFile); // Close input file

    // Open output file
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        fprintf(stderr, "Error: Unable to create output file.\n");
        return 1;
    }

    // Read from input file and write output to output file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Error: Unable to open input file.\n");
        return 1;
    }

    int n;
    while (fscanf(inputFile, "%d", &n) != EOF)
    {
        SieveOfEratosthenes(n, outputFile);
        fprintf(outputFile, "\n"); // Separate test cases by newline
    }

    fclose(inputFile);  // Close input file
    fclose(outputFile); // Close output file

    printf("Output has been written to 'output.txt'\n");

    return 0;
}
