#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double factorial(int n) 
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
double binomialDistribution(int n, int x, double p)
{

    return (factorial(n) / (factorial(x) * factorial(n - x))) * pow(p, x) * pow(1 - p, n - x);
}
double poissonDistribution(int x, double lambda) 
{

    return (exp(-lambda) * pow(lambda, x)) / factorial(x);
}

double normalDistribution(double x, double mean, double stddev) 
{
    return (1 / (stddev * sqrt(2 * 3.14))) * exp(-pow((x - mean), 2) / (2 * pow(stddev, 2)));
}

int main() 
{
    int choice;
    bool exitProgram = false;
    
    while (!exitProgram) {
        printf("Probability Distribution Calculator\n");
        printf("1. Binomial Distribution\n");
        printf("2. Poisson Distribution\n");
        printf("3. Normal Distribution\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1: 
            {
                int n, x;
                double p, result;
                
                printf("Enter the number of trials (n): ");
                scanf("%d", &n);
                
                printf("Enter the number of successful outcomes (x): ");
                scanf("%d", &x);
                
                printf("Enter the probability of success (p): ");
                scanf("%lf", &p);
                
                result = binomialDistribution(n, x, p);
                
                printf("Binomial Distribution: %.6f\n", result);
                break;
            }
            case 2: 
            {
                int x;
                double lambda, result;
                
                printf("Enter the average number of events per interval (lambda): ");
                scanf("%lf", &lambda);
                
                printf("Enter the number of events (x): ");
                scanf("%d", &x);
                
                result = poissonDistribution(x, lambda);
                
                printf("Poisson Distribution: %.6f\n", result);
                break;
            }
            case 3: 
            {
                double x, mean, stddev, result;
                
                printf("Enter the value (x): ");
                scanf("%lf", &x);
                
                printf("Enter the mean (μ): ");
                scanf("%lf", &mean);
                
                printf("Enter the standard deviation (σ): ");
                scanf("%lf", &stddev);
                
                result = normalDistribution(x, mean, stddev);
                
                printf("Normal Distribution: %.6f\n", result);
                break;
            }
            case 4: 
            {
                exitProgram = true;
                break;
            }
            default:
                printf("Invalid choice!\n");
        }
        
        printf("\n");
    }
    
    return 0;
}