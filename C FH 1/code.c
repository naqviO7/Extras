#include <stdio.h>
#include <stdlib.h>


void RemoveEmptyLine(FILE*, FILE*);

int main() {
	RemoveEmptyLine("file1.txt", "file2.txt");
    return 0;
}


void RemoveEmptyLine(FILE* fp1, FILE* fp2) {
    char line[100];
    char ch;

    //FILE1
    fp1 = (fopen_s(&fp1, "file1", "r"));
    printf("Displaying Content of file1.txt!\n");
    if (fopen_s(&fp1, "file1.txt", "r") == 0) {
        while ((ch = fgetc(fp1)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp1);
    }

    fp1 = (fopen_s(&fp1, "file1", "r"));
    if (fopen_s(&fp1, "file1.txt", "r") == 0) {
        while (fgets(line, sizeof(line), fp1) != NULL) {
            if (line != "\n") {
               
                printf_s("\n\nFile With Empty Lines!\n\n");
                break;
            }
            else {
               
                printf_s("Skipping Empty Line of File!\n");
                continue;
            }
        }
        fclose(fp1);
    }

    //FILE 2
    fp2 = (fopen_s(&fp2, "file2", "r"));
    printf("Displaying Content of file2.txt!\n");
    if (fopen_s(&fp2, "file2.txt", "r") == 0) {
        while ((ch = fgetc(fp2)) != EOF) {
            printf("%c", ch);
        }
        fclose(fp2);
    }

    fp2 = (fopen_s(&fp2, "file2", "r"));
    if (fopen_s(&fp2, "file2.txt", "r") == 0) {
        while (fgets(line, sizeof(line), fp2) != NULL) {
            if (line != "\n") {
               
                printf_s("\n\nThere is No Empty Line in File!\n");
                break;
            }
            else {
                printf_s("File Without Empty Lines!\n");
                continue;
            }
        }
        fclose(fp2);
    }
}