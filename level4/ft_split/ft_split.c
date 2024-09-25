#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n){
    int i = -1;

    while (++i < n && s2[i]){
        s1[i] = s2[i];
    }
    s1[i] = '\0';
    return (s1);
}

static int  count_words(char *str){
    int word_count = 0;
    int i = 0;

    while (str[i] != '\0'){
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'){
            i++;
        }
        if (str[i]){
            word_count++;
        }
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')){
            i++;
        }
    }
    return (word_count);
}

/**
 * @def: Take a string, split into words, and return words as array of strings
 * @param: char *str - String
 * @return: NULL-terminated array of strings
 * @details: "Word" is defined as part of a string delimited by spaces, tabs, new lines, start/end of string
*/
#include <stdio.h>
char    **ft_split(char *str){
    char **array_str;

    //calculate number of words to insert in array
    int word_count = count_words(str);
    //allocate memory for array_str
    array_str = (char **)malloc((word_count + 1) * sizeof(char *));

    int i = 0;
    int j;
    int k = 0;
    while (str[i]){
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')){
            i++;
        }
        j = i;
        while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
            i++;
        //if str[i] is not a space
        if (i > j){
            //allocate space for the word
            //copy letter by letter to the 1st element word 
            array_str[k] = (char *)malloc(((i - j)) + 1 * sizeof(char));
            ft_strncpy(array_str[k++], &str[j], i - j);
        }
    }
    //null terminator for array_str;
    array_str[word_count] = NULL;
    return (array_str); 
}

#include <stdio.h> 
int main(){
    
    char *str = "   Rain    in Spa  in";
    // ft_split("Rain in spain");
}