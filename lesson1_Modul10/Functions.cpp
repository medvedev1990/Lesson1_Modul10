#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include"Header.h"
#include"Game.h"
#include"Obrazovanie.h"
#include"Person.h"
#include"Tovar.h"

int i;

char* MassFamiliya()
{
	char *massFamiliya[] = { "Francis", "Ethel", "Audrey", "Jorge", "Glenda", "Alvin", "Alberto" };
	char *Familiya = *(massFamiliya + (0 + rand() % 7));
	return Familiya;
}
char *zavod()
{
	char *zavod[] = { "ETKON","AksayNan","Maslodel","Coca-Cola","Roshen","Zhiguli_Beer" };
	char *zavod1 = *(zavod + (0 + rand() % 6));
	return  zavod1;
}
char *POST()
{
	char *postal[] = { "Engener", "Laborant", "Administrator", "BOSS", "General", "Secretar", "Ofice-Manager" };
	return *(postal + (0 + rand() % 7));
}
char *VUZ()
{
	char *univer[] = { "Bakalavr","Magistratura","PhD Doctorantura" };
	return *(univer + (0 + rand() % 3));
}
char *naimenovanie()
{
	char *tovarr[] = { "kolbasa","Coca-cola","Sugar","Konfeti","Beer","Oil","Broad" };
	return  *(tovarr + (0 + rand() % 7));
}
void NHL()
{
	game *player = (game*)calloc(10, sizeof(game));
	if (player != NULL)
	{

		for (i = 0;i < 10;i++)
		{
			strcpy((player + i)->familiya, MassFamiliya());
			(player + i)->Game = 1 + rand() % 30;
			(player + i)->gol = 5 + rand() % 95;
			(player + i)->vozrast = 18 + rand() % 20;
			if ((player + i)->vozrast < 25)
				printf("#%d %s\nVozrast: %d\nGame: %d\nGol: %d\n", i + 1, (player + i)->familiya, (player + i)->vozrast, (player + i)->Game, (player + i)->gol);
		}
	}
	else
		printf("no memmpry\n");
	free(player);
}
void tovarooborot()
{
	/*Определить общую стоимость всех товаров, выпущенных в текущем году и вывести сведения об этих товарах.*/
	int summ = 0;
	tovar *product = (tovar*)calloc(10, sizeof(tovar));
	if (product != NULL)
	{
		for (i = 0;i < 10;i++)
		{
			strcpy((product + i)->proizvoditel, zavod());
			strcpy((product + i)->naimenovanie, naimenovanie());
			(product + i)->kolichestvo = 10 + rand() % 10000;
			(product + i)->god_Vipuska = 2016 + rand() % 3;
			(product + i)->Sale = 160 + rand() % 2000;
			if ((product + i)->god_Vipuska == 2018)
			{
				summ += ((product + i)->Sale*(product + i)->kolichestvo);
				printf("#%d Naimenovanie: %s\nSale: %d\nGod Vipuska: %d\nProizvoditel: %s\n Na sklade: %d\n\n", i + 1, (product + i)->naimenovanie,
					(product + i)->Sale,
					(product + i)->god_Vipuska,
					(product + i)->proizvoditel,
					(product + i)->kolichestvo);
			}
		}
		printf("общая стоимость товаров = %d\n", summ);
	}
	else
	{
		printf("no memmory");
	}
	free(product);
}
void search_min_sale()
{
	float summ = 0;
	int kol_vo = 0;
	int min=10000;
	tovar *product = (tovar*)calloc(10, sizeof(tovar));
	if (product != NULL)
	{
		for (i = 0;i < 10;i++)
		{
			strcpy((product + i)->proizvoditel, zavod());
			strcpy((product + i)->naimenovanie, naimenovanie());
			(product + i)->kolichestvo = 10 + rand() % 10000;
			(product + i)->god_Vipuska = 2016 + rand() % 3;
			(product + i)->Sale = 160 + rand() % 2000;
			summ += (product + i)->Sale;
			kol_vo += (product + i)->kolichestvo;
			if ((product + i)->Sale < min)
			{
				min = (product + i)->Sale;
			}
		}
		printf("цена минимального товара = %d\n", min);
		printf("средняя стоимость товаров = %4.2f\n", summ / kol_vo);
	}
	else
	{
		printf("no memmory");
	}
	free(product);
}
void studenti()
{
	int min = 1970;
	obrazovanie *student = (obrazovanie*)calloc(10, sizeof(obrazovanie));
	if (student != NULL)
	{
		for (i = 0;i < 10;i++)
		{
			strcpy((student + i)->student.familiya, MassFamiliya());
			(student + i)->student.vozrast = 1970 + rand() % 30;
			(student + i)->student.zarplata = 10000 + rand() % 60000;
			strcpy((student + i)->student.dolzhnost, POST());
			strcpy((student + i)->Obrazovanie, VUZ());
			if ((student + i)->student.vozrast > min)
				min = (student + i)->student.vozrast;
		}
		for (i = 0;i < 10;i++)
		{
			if ((student + i)->student.vozrast=min)
				printf("Name: %s\nVozrast: %d\nZarplata: %d\nPoast: %s\nObrazovanie: %s\n", (student + i)->student.familiya, (student + i)->student.vozrast, 
				(student + i)->student.zarplata, (student + i)->student.dolzhnost, (student + i)->Obrazovanie);
		}
	}
	else
		printf("no memmpry\n");
	free(student);
}