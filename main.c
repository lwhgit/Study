#include <stdio.h>
#include <string.h>

#define MAX_READ 100
#define MAX_WORD 100

int main() {

    FILE *fps[] = {
        fopen("C:\\Users\\W\\Desktop\\text1.txt", "r"),
        fopen("C:\\Users\\W\\Desktop\\text2.txt", "r")
    };

    char line[MAX_READ];
    char *words[2][MAX_WORD];

    int biggerWordCount = 0;

    if (fps[0] == NULL || fps[1] == NULL) {
        printf("File isnt exist.");
        return 0;
    }

    int i;
    int j;
    for (i = 0; i < 2; i ++) {
        int wordCount = 0;

        while (1) {
            char *c = fgets(line, MAX_READ, fps[i]);
            c = strtok(c, "\n");
            //printf("\t%s\n", c);

            if (c == NULL) {
                if (wordCount > biggerWordCount) {
                    biggerWordCount = wordCount;
                }
                printf("%d ", wordCount);
                break;
            }

            for (j = 0; j < MAX_WORD; j ++) {

                char *word = strtok(j == 0 ? line : NULL, " ");
                words[i][wordCount] = word;
                printf("\t\t%s %d %d \n", words[i][wordCount], i, wordCount);
                if (word == NULL) {
                    break;
                }
                wordCount ++;
            }
        }
    }
    printf("\n");

    // 출력
    for (i = 0; i < 2; i ++) {
        for (j = 0; j < MAX_WORD; j ++) {
            char *s = words[i][j];
            if (s == NULL) {
                break;
            }
            printf("%s %d %d\n", s, i, j);
        }
        printf("\n");
    }


    return 0;
}
