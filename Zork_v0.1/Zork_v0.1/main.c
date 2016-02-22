#include <stdio.h>

int main(){

	enum place {
		a = 1, b, c,
		d, e, f,
		g, h, i
	};
	enum place position = e;
	int quit = 0;


	while (quit != 1){

		switch (position){
		case b:
			printf("You are in the kitchen\n");
			break;
		case c:
			printf("You are in the pantry\n");
			break;
		case e:
			printf("You are in the dinning room\n");
			break;
		case f:
			printf("You are in the bathroom\n");
			break;
		case h:
			printf("You are in the bedroom\n");
			break;
		}

		printf("Which direction you want to go (n/s/e/w/q)? > ");

		char input;
		scanf_s("%c", &input, 1);
		getchar();

		switch (input){
		case 'n':
			if (position - 3 != 1 && position - 3 != 4 && position - 3 != 7 && position - 3 != 9){
				position -= 3;
			}
			else{
				printf("You can't go in that direction\n");
			}
			break;
		case 's':
			if (position + 3 != 1 && position + 3 != 4 && position + 3 != 7 && position + 3 != 9){
				position += 3;
			}
			else{
				printf("You can't go in that direction\n");
			}
			break;
		case 'e':
			if (position + 1 != 1 && position + 1 != 4 && position + 1 != 7 && position + 1 != 9){
				position += 1;
			}
			else{
				printf("You can't go in that direction\n");
			}
			break;
		case 'w':
			if (position - 1 != 1 && position - 1 != 4 && position - 1 != 7 && position - 1 != 9){
				position -= 1;
			}
			else{
				printf("You can't go in that direction\n");
			}
			break;
		case 'q':
			quit = 1;
			break;

		}
	}

	getchar();
}