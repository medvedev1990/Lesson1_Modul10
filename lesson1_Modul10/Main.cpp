#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"Header.h"


void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int n, quit;
	do
	{
		printf("введите номер задания: ");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			NHL();
			break;
		case 2:
			tovarooborot();
			break;
		case 3:
			search_min_sale();
			break;
		case 4:
			studenti();
			break;
		default:
			break;
		}
		printf("continue? 1-Yes: ");
		scanf("%d", &quit);
		printf("\n");

	} while (quit == 1);
}