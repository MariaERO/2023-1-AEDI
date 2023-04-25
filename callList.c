#include <stdio.h>
#include <string.h>

// Defining stList before main() to use inside of OrderStudents function
char stList[100][21];

// Selection sort to sort students in alphabetical order
void OrderStudents(int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(stList[j], stList[min]) < 0) {
                min = j;
            }
        }
        // swapping stList[i] with min value
        if (min != i) {
            char temp[21];
            strcpy(temp, stList[i]);
            strcpy(stList[i], stList[min]);
            strcpy(stList[min], temp);
        }
    }
}

// Reads number of students, index of sorted student then executes selection sorting
int main() {
    int stNum, stSorted;
    scanf("%d %d", &stNum, &stSorted);
    
    for (int i = 0; i < stNum; i++) {
        scanf("%s", stList[i]);
    }
    
    OrderStudents(stNum);
    
    printf("%s\n", stList[stSorted - 1]);
    
    return 0;
}