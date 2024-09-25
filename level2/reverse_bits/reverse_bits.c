#include <unistd.h>

void	print_bits(unsigned char octet){
    int i = 8;
    unsigned char bit;

    while (i--){
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

/**
 * @def: Take a byte, reverse it, bit by bit
 * @return: result
*/
unsigned char	reverse_bits(unsigned char octet){
    unsigned int i = 8;
    unsigned char result = 0;

    while (i--){
        //result is either shift left by 1 bit OR give 1 if last bit is 1, 0 otherwise
        result = (result << 1) | (octet & 1);
        octet = octet >> 1;
    }
    return(result);
}

int main(){
    print_bits(2);
    write(1, "\n", 1);
    print_bits(reverse_bits(2));
    write(1, "\n\n", 2);

    print_bits(3);
    write(1, "\n", 1);
    print_bits(reverse_bits(3));
    write(1, "\n\n", 2);

    print_bits(4);
    write(1, "\n", 1);
    print_bits(reverse_bits(4));
    write(1, "\n\n", 2);
}