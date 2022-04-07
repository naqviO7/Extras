#include <stdio.h>
#include<conio.h>
#include <sys/stat.h>

int count_char(FILE*); int count_words(FILE*);
int count_lines(FILE*);
void GetInputfrom_User(char, FILE*);
void DisplayNonEmpty_file(FILE*);

int main(int argc, char* argv[]){
	FILE* fp;
	fp = (fopen_s(&fp, "file.txt", "r"));

	printf_s("Opening file.txt to count characters, words and line!\n\n");
	
	GetInputfrom_User('l', fp);
	GetInputfrom_User('w', fp);
	GetInputfrom_User('c', fp);
	DisplayNonEmpty_file(fp);

	char ch;
	int charactr=-1;
	FILE* empfp;
	empfp = (fopen_s(&empfp, "emptyfile.txt", "r"));
	
	printf("Opening the emptyfile.txt in Reading Mode\n");
	if (fopen_s(&empfp, "emptyfile.txt", "r") == 0) {
		if (charactr<0) {
			printf("file is Empty\n");
		}
		else{
			printf("file is not Empty!\n");
		}
		fclose(empfp);
	}
	else {
		printf_s("emptyfile.txt is not opened correctly, Run Program Again!\n");
	}


	
	return 0;
}

void DisplayNonEmpty_file(FILE* f) {
	f = (fopen_s(&f, "file.txt", "r"));
	char ch;

	printf("Opening the file.txt in Reading Mode\n");
	printf("Displaing Content of file!\n");
	if (fopen_s(&f, "file.txt", "r") == 0) {
		while ((ch = fgetc(f)) != EOF) {
			printf_s("%c",ch);
		}
		printf_s("\nfile is not empty!\n\n");
	}
	
}

void GetInputfrom_User(char ch, FILE* f) {
	FILE* fp;
	fp = (fopen_s(&fp, "file.txt", "r"));

	if (ch == 'l' && f == fp) {
		count_lines(fp);
		printf("\n\n");
	}
	else if (ch == 'w' && f == fp) {
		count_words(fp);
		printf("\n\n");
	}
	else if(ch == 'c' && f == fp){
		count_char(fp);
		printf("\n\n");
	}
}


int count_lines(FILE* fp){
	
	int line = 0;
	char ch;

	printf("Opening the file.txt in Reading Mode\n");
	fp = (fopen_s(&fp, "file.txt", "r"));

	printf_s("Counting Number of Lines in File!\n");
	if (fopen_s(&fp, "file.txt", "r") == 0) {
		while ((ch = fgetc(fp)) != EOF) {
			if (ch == '\n' || ch == '\0')
				line++;
		}
		printf("Total lines Present in File: %d\n", line);
		fclose(fp);
	}
	else {
		printf_s("file.txt is not opened correctly, Run Program Again!\n");
	}
	return line;
}


int count_char(FILE* fp){
	char ch;
	int characters = 0;

	printf("Opening the file.txt in Reading Mode\n");
	fp = (fopen_s(&fp, "file.txt", "r"));

	printf_s("Counting Number of Characters in File!\n");

	if (fopen_s(&fp, "file.txt", "r") == 0) {
		while ((ch = fgetc(fp)) != EOF) {
			characters++;
		}
		printf("Total Characters Present in File: %d\n", characters);
		fclose(fp);
	}
	else {
		printf_s("file.txt is not opened correctly, Run Program Again!\n");
	}
	return characters;
}


int count_words(FILE* fp) {
	char ch;
	int words = 0;

	printf("Opening the file.txt in Reading Mode\n");
	fp = (fopen_s(&fp, "file.txt", "r"));

	printf_s("Counting Number of Words in File!\n");
	if (fopen_s(&fp, "file.txt", "r") == 0) {
		while ((ch = fgetc(fp)) != EOF) {
			if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
				words++;
		}
		printf("Total Words Present in File: %d\n", words);
		fclose(fp);
	}
	else {
		printf_s("file.txt is not opened correctly, Run Program Again!\n");
	}
	return words;
}