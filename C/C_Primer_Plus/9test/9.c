#include <stdio.h>
#define FIRST "copy files"
#define S "move files"
#define T "remove files"
void chart(void){
	printf("Please choose one of the following:\n1) copy files       2) move files\n3) remove files     4) quit\nEnter the number of your choice:\n");
}

int user(int down, int up){
	int user,judge;
	while ((judge = scanf("%d", &user)) == 1)
	{
		if ((user < down) || (user > up))
		{
			chart();
		}
		else
			break;
	}

	return user;
}

int main(void)
{
	int choice;
	chart();
	choice = user(1,4);
	switch(choice)
	{
		case 1: printf("%s\n", FIRST);
			break;
		case 2: printf("%s\n", S);
			break;
		case 3: printf("%s\n", T);
			break;
		default:break;
	}

	printf("Bye!\n");

	return 0;
}



