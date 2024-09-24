#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str){

    int value = 0;

    int i = 0;
    int sign = 1;

    while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
        i++;
    if (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        value = (value * 10) + (str[i] - '0');
        i++;
    }
    
    return (value * sign);
}

void ft_putnbr(int value){
    //if value is more than / equal to 10
    //as ft_putnbr() gets evaluated after printing
    if (value >= 10)
        ft_putnbr(value);
    
    char digit = value % 10 + '0';
    write(1, &digit, 1);
}

int is_prime(int num){
    int i = 2;

    if (num <= 1)
        return 0; //false -> not primt
    
    while (i * i <= num){
        if (num % i == 0)
            return 0;
        i++;
    }
    return (1);
}
/**
 * @def: Take a positive integer as arg and display sum of all prime numbers <= arg and newline
 * @param: positive integer
 * @return: sum of all prime numbers <= positive_int
*/
#include <stdio.h>

int main(int argc, char **argv){
    
    if (argc <= 1){
        write(1, "0\n", 2);
        exit(0);
    }
    
    int value = ft_atoi(argv[1]);
    if (value < 0){
        exit(1);
    }
    printf("value: %i\n", value);

    int sum = 0;
    //logical error here: How do I jump from prime number to next?
    int i = 1;
    
    printf("sum: %i\n", sum);
    //print sum with newline 
    // ft_putnbr(sum);
    return (sum);
}