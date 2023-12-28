#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string_1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char string_2[] = "Hello";
    printf("%s\n", string_1);
    printf("%s\n", string_2);
    return 0;
}