#include <unistd.h>

int ft_strlen(char *str){
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}

/**
 * @param: string (big string)
 * @param: letter (to be searched)
 * @param: letter (to replace in the searc)
*/
int main(int argc, char **argv){

    int strlen_arg2 = ft_strlen(argv[2]);
    int strlen_arg3 = ft_strlen(argv[3]);

    if (argc != 4){
        write(1, "\n", 1);
        return (0);
    }

    if (strlen_arg2 != 1 || strlen_arg3 != 1){
        write(1, "\n", 1);
        return (0);
    }

    int i = 0;
    int j = 0;
    int k = 0;
    while(argv[1][i] != '\0'){
        if (argv[1][i] == argv[2][j]){
            argv[1][i] = argv[3][k];
        }
        i++;   
    }

    i = 0;
    while(argv[1][i] != '\0'){
        write(1, &argv[1][i++], 1);
    }
}