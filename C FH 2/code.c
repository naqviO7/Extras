#include <stdio.h>
#include <stdlib.h>


void RemoveEmptyLine(FILE*, FILE *);
int countcharacters(char* line, char num);


int main() {

    FILE* fp;
    char ch;
    char line[100];
    int num = 0, lin = 0;

    printf("Opening the file.txt in Reading Mode\n");
    fp = (fopen_s(&fp, "file", "r"));
    if (fp == NULL) {
        printf("Could not open file.txt!\n");
        return 1;
    }

    printf("Reading the file test.txt!\n");
    countcharacters(line, num);

    if (fopen_s(&fp, "file.txt", "r") == 0) {
        printf_s("\nEnter Number of character you want to read: ");
        scanf_s("%d", &num);

        while ((ch = fgetc(fp)) != EOF) {
            if (num >= ch) {
                lin++;
                printf("%d is greater than characters in line", num);
                break;
            }
            else if (num <= ch) {
                printf("%c", ch);
                break;
            }
        }
        fclose(fp);
    }
    RemoveEmptyLine("file1.txt","file2.txt");

    return 0;
}


void RemoveEmptyLine(FILE* fp1,FILE *fp2) {
    char line[100];
    fp1 = (fopen_s(&fp1, "file1", "r"));

    printf("\nOpening the file1.txt in Reading Mode\n");
    printf("\nReading the file1.txt!\n");

    if (fopen_s(&fp1, "file1.txt", "r") == 0) {
        while (fgets(line, sizeof(line), fp1) != NULL) {
            if (line != "\n") {
                printf_s("\nThere is No Empty Line in File!\n");
                break;
            }
            else {
                printf_s("Skipping Empty Line of File!\n");
                continue;
            }
        }
        fclose(fp1);
    }


    fp2 = (fopen_s(&fp2, "file2", "r"));

    printf("\nOpening the file2.txt in Reading Mode\n");
    printf("\nReading the file2.txt!\n");

    if (fopen_s(&fp2, "file2.txt", "r") == 0) {
        while (fgets(line, sizeof(line), fp2) != NULL) {
            if (line != "\n") {
                printf_s("\nThere is No Empty Line in File!\n");
                break;
            }
            else {
                printf_s("Skipping Empty Line of File!\n");
                continue;
            }
        }
        fclose(fp2);
    }
}

int countcharacters(char* line, char num) {
    FILE* fp;
    fp = (fopen_s(&fp, "file", "r"));

    char ch;
    int characters, words, lines; characters = words = lines = 0;
    if (fopen_s(&fp, "file.txt", "r") == 0) {
        if (fp == NULL) {
            printf("\nUnable to open file.\n");
            printf("Please check if file exists and you have read privilege.\n");

            exit(EXIT_FAILURE);
        }
        else {
            while ((ch = fgetc(fp)) != EOF) {
                characters++;
                if (ch == '\n' || ch == '\0')
                    lines++;
                if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
                    words++;
                printf("%c", ch);
            }
        }
        if (characters > 0) {
            words++;
            lines++;
        }

        printf("\n");
        printf("Total characters = %d\n", characters);
        printf("Total words      = %d\n", words);
        printf("Total lines      = %d\n", lines);
        fclose(fp);
    }

    return num;
}