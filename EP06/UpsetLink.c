#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char name[100001];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    int i, len = strlen(name);
    int containsZelda = 0;

    // Convert the name to lowercase for case-insensitive comparison
    for (i = 0; i < len; i++) {
        name[i] = tolower(name[i]);
    }

    // Check if the name contains the substring "zelda"
    for (i = 0; i < len - 4; i++) {
        if (strncmp(name + i, "zelda", 5) == 0) {
            containsZelda = 1;
            break;
        }
    }

    // Output the result
    if (containsZelda) {
        printf("Link Bolado\n");
    } else {
        printf("Link Tranquilo\n");
    }

    return 0;
}
