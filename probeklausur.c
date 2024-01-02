#include <stdio.h>
#include <ctype.h>
#include "advanced_console_output.h"

int checkForMinSize(char pw[]);
int checkForCapitalLetter(char pw[]);
int checkForDigit(char pw[]);

int main()
{
	int criteriaFullfilled = 0;
	char password [51]; // 51 für '\0' am Ende des Passworts
	set_fg_color("blue");
    while(!criteriaFullfilled){
	    printf("Please enter a password: ");
		scanf("%s50", password);
		criteriaFullfilled = 1;
    }
    printf("%s\n", password);
}

int checkForMinSize(char pw[]){
	char currentChar;
	int idx = 0;
	while(currentChar != '\0'){ // Man könnte auch mit strlen() arbeiten wenn man "string.h" inkludiert
		currentChar = pw[idx];
		idx++;
	}
	if(idx >= 5){
		return 1;
	}else{
		return 0;
	}
}
int checkForCapitalLetter(char pw[]){
	char currentChar;
	int idx = 0;
	char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	printf("A:%d, Z:%d", 'A', 'Z');
	// Wenn man ASCII Tabelle nicht mehr weiß: printf("A:%d, Z:%d", 'A', 'Z') 
	while(currentChar != '\0'){ // Man könnte auch mit strlen() arbeiten wenn man "string.h" inkludiert
		currentChar = pw[idx];
		idx++;
		for(int i = 0; i<26; i++){ // Man kann auch mit ASCII-Tabelle arbeiten ((int)pw[i] >= 65 && (int)pw[i] = 90)
			if (currentChar == alphabet[i]){
				return 1;
			}
		}
	}
	return 0;
}
int checkForDigit(char pw[]){
	while(currentChar != '\0'){ // Man könnte auch mit strlen() arbeiten wenn man "string.h" inkludiert
		currentChar = pw[idx];
		idx++;
		char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
		printf("0:%d, 9:%d", '0', '9');
		for (int i = 0; i<10, i++){
			if (currentChar == digits[i]){
				return 1;
			}
		}
	}
	return 0;
}