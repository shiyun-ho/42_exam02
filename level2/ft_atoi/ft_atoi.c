/**
 * @def: Convert string argument to integer
 * @param: str
 * @return: integer
*/
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

#include <stdio.h>
int main(){
    printf("%i\n", ft_atoi("1"));
    printf("%i\n", ft_atoi("11"));
    printf("%i\n", ft_atoi("111"));
    printf("%i\n", ft_atoi("10"));
    printf("%i\n", ft_atoi("100"));

    printf("%i\n", ft_atoi("-1")); 
    printf("%i\n", ft_atoi("-11"));
    printf("%i\n", ft_atoi("-111"));
    printf("%i\n", ft_atoi("-10"));
    printf("%i\n", ft_atoi("-100"));
}