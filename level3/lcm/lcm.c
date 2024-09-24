#include <stdio.h>
#include <stddef.h>

/**
 * @def: Function which takes two unsigned int and returns computed Lowest Common Multiple
 * @param: unsigned int a, unsigned int b
 * @return: (unsigned int) lowest common multiple
*/
unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int answer;
    unsigned int absolute_value;
    
    //invalid parameter handling
    if (a == 0 || b == 0)
    {
        answer = 0;
        return (answer);
    }

    //finding abs value of a * b
    a = (a >= 0) ? a : -a;
    b = (b >= 0) ? b : -b;
    absolute_value = a * b;

    int i = (a > b) ? b : a;
    while (!((a % i == 0) && (b % i) == 0)){
        i--;
    }
    int hcf = i;
    
    answer = absolute_value / hcf;
    return (answer);
}

#include <assert.h>
int main()
{
    printf("lcm(NULL, 5)  = %i\n", lcm(0, 5));
    printf("lcm(5, NULL)  = %i\n", lcm(5, 0));

    printf("lcm(23, 47)  = %i\n", lcm(23, 47));
    printf("lcm(89, 123)  = %i\n", lcm(89, 123));
    printf("lcm(34, 56)  = %i\n", lcm(34, 56));
    printf("lcm(67, 89)  = %i\n", lcm(67, 89));
    printf("lcm(12, 45)  = %i\n", lcm(12, 45));
    printf("lcm(78, 90)  = %i\n", lcm(78, 90));
    printf("lcm(25, 36)  = %i\n", lcm(25, 36));
    printf("lcm(54, 72)  = %i\n", lcm(54, 72));
    printf("lcm(81, 108)  = %i\n", lcm(81, 108));
    printf("lcm(15, 24)  = %i\n", lcm(15, 24));

    // Assertions to verify the correctness of the LCM function
    assert(lcm(12, 45) == 180);
    assert(lcm(78, 90) == 1170);
    assert(lcm(25, 36) == 900);
    assert(lcm(54, 72) == 216);
    assert(lcm(81, 108) == 324);
    assert(lcm(15, 24) == 120);
    assert(lcm(12, 45) == 180);
    assert(lcm(78, 90) == 1170);
    assert(lcm(25, 36) == 900);
    assert(lcm(54, 72) == 216);
    assert(lcm(81, 108) == 324);
    assert(lcm(15, 24) == 120);

    printf("===== Passed all test cases! ====\n");
}