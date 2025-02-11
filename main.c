#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stringLength(char *string) {
    static int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }
    return counter;
}

void swap(char *firstChar, char *secondChar) {
    char tempChar = *firstChar;
    *firstChar = *secondChar;
    *secondChar = tempChar;
}

void permutate(char *string, int firstIndex, int lastIndex, char **array, int *count) {
    array[*count] = (char *)malloc((stringLength(string) + 1) * sizeof(char));
    
    if (firstIndex == lastIndex) {
        strcpy(array[*count], string);
        (*count)++;
        return;
    }

    for (int i = firstIndex; i <= lastIndex; i++) {
        swap(&string[firstIndex], &string[i]);
        permutate(string, firstIndex + 1, lastIndex, array, count);
        swap(&string[firstIndex], &string[i]);
    }
}

long factorial(int length) {
    long factorial = 1;
    for(int i = 1; i <= length; i++) {
        factorial = factorial * i;
    }

    return factorial;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid arguements\n");
        return 0;
    }

    char *string = argv[1];
    
    int length = stringLength(string);
    int combinations = factorial(length);
    int count = 0;
    
    char **storage = (char **)malloc(combinations * sizeof(char *));
    
    if(length > 10) {
        printf("cannot be more than 10 characters.invalid\n");
        return 0;
    }

    printf("All permutations of the string %s are: ", string);
    permutate(string, 0, length - 1, storage, &count);
    printf("\n");

    for(int i = 0; i < combinations; i++) {
        printf("%s ", storage[i]);
    }
    printf("\n");

    free(storage);

    return 0;
}
