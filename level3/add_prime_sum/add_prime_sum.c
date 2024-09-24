#include <unistd.h>

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

/**
 * @def: Take a positive integer as arg and display sum of all prime numbers <= arg and newline
 * @param: positive integer
 * @return: sum of all prime numbers <= positive_int
*/
int main(int argc, char **argv){
    
    if (argc <= 1){
        write(1, "0\n", 2);
        exit(0);
    }
    
    int value = ft_atoi(argv[1]);
    if (value < 0){
        exit(1);
    }

    int sum = 0;
    //logical error here: How do I jump from prime number to next?
    int i = 1;
    while(value % i == 0 && i <= value){
        sum = sum + i;
        i++;
    }

    return (sum);
}