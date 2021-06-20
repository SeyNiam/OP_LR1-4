#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#endif

#define N 1000

#include <stdio.h>
#include <ctype.h>

int main() {
	int endFlag = 1; //a flag that stops the application

	int size = N;
	char c[N] = {0}; //current simbol from the stream
	int first = 1; //flag of the first letter in the word
	char letter1 = '\0'; //first letter of the word
	char glasn[] = "AEYUIO"; //vowels array
	int IsVowel = 0; //vowel flag

	//a global cycle that prevents the program from endting without the user's desire
	do {
		//a cycle for reading characters from a stream associated with the keyboard
		printf("Please type down your words:\n");
		for (int i = 0; i < size; i++) {
			scanf("%c", &c[i]);
			if (i >= 1) {
				if (c[i] == '\n') {
					size = i;
					i = size + 1;
				}
			}
		}
		
		//deleting '\n' in the beginning of a string
		if (c[0] == '\n') {
			for (int i = 0; i < size; i++) {
				c[i] = c[i+1];
			}
			size--;
		}
		
		for (int i = 0; i < size; i++) {
			if (c[i] == ' ' || c[i] == '.' || c[i] =='\0' || c[i] == '!' || 
				c[i] == '?' || c[i] == ';' || c[i] == ':' || c[i] == '_' || 
				c[i] == '(' || c[i] == ')' || c[i] == '[' || c[i] == ']' || 
				c[i] == '{' || c[i] == '}' || c[i] == '<' || c[i] == '>' || 
				c[i] == '«' || c[i] == '»' || c[i] == '”' || c[i] == '’' || 
				c[i] == '#' || c[i] == ',') {
				//separator found
				first = 1;
			}
			else {
				//letter found
				if (first == 1) {
					first = 0;
					letter1 = c[i];
					
					//checking if the first letter is a vowel
					for (int i = 0; glasn[i] != 0; i++)
					{
						if (toupper(letter1) == glasn[i])
						{
							IsVowel = 1;
							break;
						}
						else {
							IsVowel = 0;
						}
					}

					//a word starting with a vowel is being erased 
					if (IsVowel == 1) {
						int mark = i;
						IsVowel = 0;
						do {
							c[mark] = '\0';
							mark++;
						} while (c[mark] != ' ' && c[mark] != '.' && c[mark] != '\0' && c[mark] != '!' &&
							c[mark] != '?' && c[mark] != ';' && c[mark] != ':' && c[mark] != '_' &&
							c[mark] != '(' && c[mark] != ')' && c[mark] != '[' && c[mark] != ']' &&
							c[mark] != '{' && c[mark] != '}' && c[mark] != '<' && c[mark] != '>' &&
							c[mark] != '«' && c[mark] != '»' && c[mark] != '”' && c[mark] != '’' &&
							c[mark] != '#' && c[mark] != ',' && mark < size);
					}
				}
			}
		}

		printf("Your new sentence is: \'");
		for (int i = 0; i < size; i++) {
			printf("%c", c[i]);
		}
		printf("\'");

		//resetting the variables
		first = 1;
		letter1 = 0;
		size = N;
		IsVowel = 0;


		//suggesting to user to run program again or exit.
		printf("\n\nPlease choose from the following:\n\t1 - Count again.\n\t2 - Exit.\n");
		scanf("%d", &endFlag);
		switch (endFlag) {
		case 1: endFlag = 1; break;
		case 2: endFlag = 0; break;
		default: printf("Incorrect answer. The program will be closed."); endFlag = 0; break;
		}
	} while (endFlag); //if flag is 0, then exiting out of cycle 
	return 0;
}
