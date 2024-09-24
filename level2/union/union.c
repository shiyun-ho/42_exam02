#include <unistd.h>

/**
 * @def: program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings
* @link: https://github.com/pasqualerossi/42-School-Exam-Rank-02/tree/main/Level%202/union
*/

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
    }

    if (argc == 3)
    {
        static char array[256];
        
        int i = 0;
        int index = 0;
        
        //./union argv[1] argv[2]
        while (argv[1][i] != '\0')
        {
            index = (unsigned char)argv[1][i]; 
            if (array[index] == 0)
            {
                //printing the char
                write(1, &argv[1][i], 1);
                array[index] = 1;
                i++;
            }
            else
            {
                i++;
            }
        }
        i = 0;
        while (argv[2][i] != '\0')
        {
            index = (unsigned char)argv[2][i];
            if (array[index] == 0)
            {
                //printing the char
                write(1, &argv[2][i], 1);
                array[index] = 1;
                i++;
            }
            else
            {
                i++;
            }
        }
        write(1, "\n", 1);
    }
}