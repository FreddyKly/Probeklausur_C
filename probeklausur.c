#include <stdio.h>
#include <ctype.h>
#include "advanced_console_output.h"

int main()
{
	int criteriaFullfilled = 0;
	char password [50];
	set_fg_color("blue");
    while(!criteriaFullfilled){
	    printf("Please enter a password: ");
		scanf("%s50", password);
		criteriaFullfilled = 1;
    }
    printf("%s\n", password);
}