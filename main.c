#include <stdio.h>

void swap(int *fristIndex, int *secondIndex, char *string) {

    int j = 0;
    char tempChar1 = string[*fristIndex];
    char tempChar2 = string[*secondIndex];
    
    string[*fristIndex] = tempChar2;
    string[*secondIndex] = tempChar1;

    printf("%s \n", string);
}

int *stringLength(char *string) {
    static int counter = 0;
    while(string[counter] != '\0') {
        string[counter];
        counter++;
    }

    return &counter;
}

int main(int argc, char *argv[]) {
    char *string = argv[1];
    printf("All permutatoins of the string %s are: ", string);
    printf("\n");

    int *pLength = stringLength(string);
    int i = 0;
    int *pI = &i;
    
    printf("Length of the string: %d\n", *pLength);

    swap(pI, pLength, string);


    printf("\n");

}