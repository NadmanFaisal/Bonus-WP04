#include <stdio.h>
#include <string.h>

void swap(char *firstChar, char *secondChar) {
    char tempChar = *firstChar;
    *firstChar = *secondChar;
    *secondChar = tempChar;
}

void permutate(char *string, int firstIndex, int lastIndex) {
    if (firstIndex == lastIndex) {
        printf("%s ", string);
        return;
    }

    for (int i = firstIndex; i <= lastIndex; i++) {
        swap(&string[firstIndex], &string[i]);
        permutate(string, firstIndex + 1, lastIndex);
        swap(&string[firstIndex], &string[i]);
    }
}

int *stringLength(char *string) {
    static int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }
    return &counter;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Invalid arguements\n");
        return 0;
    }

    char *string = argv[1];

    int *pLength = stringLength(string);

    if(*pLength > 10) {
        printf("cannot be more than 10 characters.invalid\n");
        return 0;
    }

    printf("All permutations of the string %s are: ", string);
    permutate(string, 0, *pLength - 1);
    printf("\n");

    return 0;
}
