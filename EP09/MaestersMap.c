#include <stdio.h>
#include <stdbool.h>

bool checkMap(char matrix[100][100], char* acceptableChars) {
    bool hasChest = false;

    for (int i = 0; matrix[i][0] != '\0'; i++) {
        for (int j = 0; matrix[i][j] != '\0'; j++) {
            if (matrix[i][j] == '*') {
                hasChest = true;
                continue;
            }

            bool isValidChar = false;
            for (int k = 0; acceptableChars[k] != '\0'; k++) {
                if (matrix[i][j] == acceptableChars[k]) {
                    isValidChar = true;
                    break;
                }
            }

            if (!isValidChar) {
                hasChest = false;
                break;
            }
        }
    }

    if (matrix[0][0] != '>') {
        return false;
    }

    return hasChest;
}

int main() {

    char mapMatrix[100][100];
    int height, width;
    char acceptableChars[] = "*^><v.";

    scanf("%d", &width);
    scanf("%d", &height);

    while (getchar() != '\n');

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            while ((mapMatrix[i][j] = getchar()) == '\n');
        }
    }

    if (checkMap(mapMatrix, acceptableChars)){
        printf("*\n");
    } else {
        printf("!\n");
    }

    return 0;
}
