#include <stdio.h>
#include <string.h>

int main() {
    char *a = "To je ena dolga poved z eno vejico, , , ki,ki";
    char *token = strtok(a, " ,");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ,");
    }
    return 0;
}
