#include <stdio.h>

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    while (numTestCases--) {
        int numLines;
        scanf("%d", &numLines);
        getchar(); // Consume the newline character after reading the integer

        int i, j;
        int hash = 0;
        
        for (i = 0; i < numLines; i++) {
            char input[52];
            fgets(input, sizeof(input), stdin);

            for (j = 0; input[j] != '\n'; j++) {
                int alphabetPosition = input[j] - 'A';
                int elementValue = i;
                int positionValue = j;
                int characterValue = alphabetPosition + elementValue + positionValue;
                hash += characterValue;
            }
        }
        
        printf("%d\n", hash);
    }

    return 0;
}
