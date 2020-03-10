/*
 * Bulbs.c
 *
 * Created on: Nov 3, 2018
 * Author: Aleksander Grzybowski
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define P 30
#define PLIK "leaderboard.txt"

int main (void)
{
	srand (time(0));
	FILE *plik = fopen("leaderboard.txt", "ab+"); fclose(plik); //utworzenie pliku z tablicą wyników

	/* Deklaracja zmennych */
	int N, M; // Wymiary planszy
	char naglowek = 0; int naglowek2 = 0; // Zakres wprowadzanych danych
	int i=0, j=0, k=0, l=0; // Pętle i pętle w pętlach
	char menu = 0, powrot = 0, kolumna = 0;
	int wiersz=0, nrkolumna=0, zgaszone=0, zapalone=0, wynik=0, warunek=0, licznik=0, rozmiar=0, gotowe=0;
	char name[P] = {'\0'}, gracz[P][P] = {{'\0'},{'\0'}};
	int wynikgracza[P] = {'\0'};

/* Menu Główne */
for (;;)
{
	N=0;M=0;
	printf ("              Main menu\n"
			"Type a number and confirm using 'Enter'.\n\n"
			"1 - New Game\n"
			"2 - Leaderboard\n"
			"3 - Quit\n");
	scanf ("%s", &menu);
	printf ("\n");

/* Zależnie od  wyboru, dzieje się jakaś opcja */
switch (menu)
{
	case '1': //Nowa Gra
	{
		/* Podanie nicku przez gracza */
		printf ("What's your nickname?\n");
		for (i=0;i<P;i++)
		{
			scanf ("%s", &name[i]);
			if (getchar() == '\n') break;
		}

		/* Podanie wielkości planszy przez gracza */
		printf ("Choose game format.\n"
					"The larger format you choose, the more points you earn.\n"
					"(max 10x12): ");
		scanf ("%dx%d", &N, &M);
		if (N<1 || N>10 || M<1 || M>12)
		{
			wiersz = 'x';
			licznik=0;
			warunek=0;
			wynik=0;
			break;
		}
		N++; M++; // powiększenie planszy o nagłówki

		/* Utworzenie planszy */
		char plansza [N][M];
		/* Tworzenie nagłówków tabeli */
			plansza[0][0]= 'X';
			plansza[0][1] = 'A';
			plansza[0][2] = 'B';
			plansza[0][3] = 'C';
			plansza[0][4] = 'D';
			plansza[0][5] = 'E';
			plansza[0][6] = 'F';
			plansza[0][7] = 'G';
			plansza[0][8] = 'H';
			plansza[0][9] = 'I';
			plansza[0][10] = 'J';
			plansza[0][11] = 'K';
			plansza[0][12] = 'L';
			plansza[1][0] = '0';
			plansza[2][0] = '1';
			plansza[3][0] = '2';
			plansza[4][0] = '3';
			plansza[5][0] = '4';
			plansza[6][0] = '5';
			plansza[7][0] = '6';
			plansza[8][0] = '7';
			plansza[9][0] = '8';
			plansza[10][0] = '9';
		/* Losowanie położenia zapalonych świateł */
			for (i=1;i<N;i++)
			{
				for (j=1;j<M;j++)
				{
					if(rand()%2==0) plansza [i][j] = '*';
					else plansza [i][j] = ' ';
				}
			}
			licznik = 0; // zerowanie licznika ruchów
		printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		/* Start gry (do, while) */
		do
		{
			/* Wstęp i instrukcja */
			printf ("Welcome to the best logic game in the world!\n"
					"Your goal is to turn all the lights off.\n"
					"The thing is, that when you turn the light on (*),\n"
					"all other lights that are nearby are turning off ( ).\n"
					"The same goes with turning the light off.\n"
					"When you reach 5000 moves, you lose.\n"
					"Good luck!\n");

			/* Rysowanie aktualnej tabelki */
			for (i=0;i<N;i++)
			{
				for (j=0;j<M;j++)
				{
					if (i==0 && j==0)
					{
						if (M==13) printf (" ___________________________________________________\n|"), naglowek = 'L';
						else if (M==12) printf (" _______________________________________________\n|"), naglowek = 'K';
						else if (M==11) printf (" ___________________________________________\n|"), naglowek = 'J';
						else if (M==10) printf (" _______________________________________\n|"), naglowek = 'I';
						else if (M==9) printf (" ___________________________________\n|"), naglowek = 'H';
						else if (M==8) printf (" _______________________________\n|"), naglowek = 'G';
						else if (M==7) printf (" ___________________________\n|"), naglowek = 'F';
						else if (M==6) printf (" _______________________\n|"), naglowek = 'E';
						else if (M==5) printf (" ___________________\n|"), naglowek = 'D';
						else if (M==4) printf (" _______________\n|"), naglowek = 'C';
						else if (M==3) printf (" ___________\n|"), naglowek = 'B';
						else if (M==2) printf (" _______\n|"), naglowek = 'A';
					} // Różne wielkości tabeli
					printf (" %c |", plansza [i][j]);
					if (j==M-1)
						{
						if (M==13) printf ("\n|___________________________________________________|\n");
						else if (M==12) printf ("\n|_______________________________________________|\n");
						else if (M==11) printf ("\n|___________________________________________|\n");
						else if (M==10) printf ("\n|_______________________________________|\n");
						else if (M==9) printf ("\n|___________________________________|\n");
						else if (M==8) printf ("\n|_______________________________|\n");
						else if (M==7) printf ("\n|___________________________|\n");
						else if (M==6) printf ("\n|_______________________|\n");
						else if (M==5) printf ("\n|___________________|\n");
						else if (M==4) printf ("\n|_______________|\n");
						else if (M==3) printf ("\n|___________|\n");
						else if (M==2) printf ("\n|_______|\n");
						}
					if (j==M-1 && i!=N-1) printf ("|");
				}
			}
			switch (N-1)
			{
			case 10: naglowek2 = 9; break;
			case 9: naglowek2 = 8; break;
			case 8: naglowek2 = 7; break;
			case 7: naglowek2 = 6; break;
			case 6: naglowek2 = 5; break;
			case 5: naglowek2 = 4; break;
			case 4: naglowek2 = 3; break;
			case 3: naglowek2 = 2; break;
			case 2: naglowek2 = 1; break;
			case 1: naglowek2 = 0; break;
			default: naglowek2 = 9; break;
			}
			/* Indeks dolny planszy */
			printf ("\nMoves: %d               To exit, press 'x' and 'Enter'\n\n", licznik);

		/* Interfejs gracza */
			/* Wprowadzanie kolumny */
			printf ("Which light do you want to switch? Type a column [A-%c]: ", naglowek);
			scanf ("%s", &kolumna);
			if (kolumna == 'x' || kolumna == 'X') // Możliwe wyjście z programu
			{
				warunek = 1;
				wynik = 0;
				break;
			}
			if (kolumna >= 'a' && kolumna <= 'l') kolumna = kolumna - 32; // można też małymi
			/* Zamienianie wartości nagłówków na współrzędne tabeli */
			if (kolumna <'A' || kolumna > 'Z') nrkolumna = 'M';
			else if (kolumna >= 'A' && kolumna <= 'L')
			{
			switch (kolumna)
			{
				case 'A' : nrkolumna = 1; break;
				case 'B' : nrkolumna = 2; break;
				case 'C' : nrkolumna = 3; break;
				case 'D' : nrkolumna = 4; break;
				case 'E' : nrkolumna = 5; break;
				case 'F' : nrkolumna = 6; break;
				case 'G' : nrkolumna = 7; break;
				case 'H' : nrkolumna = 8; break;
				case 'I' : nrkolumna = 9; break;
				case 'J' : nrkolumna = 10; break;
				case 'K' : nrkolumna = 11; break;
				case 'L' : nrkolumna = 12; break;
				case 'M' : nrkolumna = 0; break;
				default: licznik = licznik +0; break; // coś spoza zakresu nic nie zmienia
			}
			switch (naglowek)
			{
			case 'A' : naglowek = 1; break;
			case 'B' : naglowek = 2; break;
			case 'C' : naglowek = 3; break;
			case 'D' : naglowek = 4; break;
			case 'E' : naglowek = 5; break;
			case 'F' : naglowek = 6; break;
			case 'G' : naglowek = 7; break;
			case 'H' : naglowek = 8; break;
			case 'I' : naglowek = 9; break;
			case 'J' : naglowek = 10; break;
			case 'K' : naglowek = 11; break;
			case 'L' : naglowek = 12; break;
			}
			if (nrkolumna > naglowek) nrkolumna = nrkolumna+200;
			/* Jeżeli litera jest z zakresu, to kontynuacja */
			if (1 <= nrkolumna && nrkolumna <= 12)
			{
				/* Wprowadzanie wiersza */
				printf ("Now type a row [0-%d]: ", naglowek2);
				scanf ("%d", &wiersz);
				if (wiersz == 'x' || kolumna == 'X') // Możliwe wyjście z programu
				{
					warunek = 1;
					wynik = 0;
					break;
				}
				wiersz = wiersz +1;
				if (wiersz < 1 && wiersz > naglowek2+1) licznik = licznik +0;
				if (1 <= wiersz && wiersz <= naglowek2+1)
				{
					printf ("\nToggle %c%d.\n\n\n", kolumna, wiersz - 1);

				/* Zapalanie i gaszenie świateł */
					if (plansza[wiersz][nrkolumna] == '*')
					{
						plansza [wiersz][nrkolumna] = ' ';
						if (plansza [wiersz+1][nrkolumna] == '*') plansza [wiersz+1][nrkolumna] = ' ';
						else if (plansza [wiersz+1][nrkolumna] == ' ') plansza [wiersz+1][nrkolumna] = '*';

						if (plansza [wiersz-1][nrkolumna] == '*') plansza [wiersz-1][nrkolumna] = ' ';
						else if (plansza [wiersz-1][nrkolumna] == ' ') plansza [wiersz-1][nrkolumna] = '*';

						if (plansza [wiersz][nrkolumna+1] == '*') plansza [wiersz][nrkolumna+1] = ' ';
						else if (plansza [wiersz][nrkolumna+1] == ' ') plansza [wiersz][nrkolumna+1] = '*';

						if (plansza [wiersz][nrkolumna-1] == '*') plansza [wiersz][nrkolumna-1] = ' ';
						else if (plansza [wiersz][nrkolumna-1] == ' ') plansza [wiersz][nrkolumna-1] = '*';
					}

					else if (plansza[wiersz][nrkolumna] == ' ')
					{
						plansza[wiersz][nrkolumna] = '*';
						if (plansza [wiersz+1][nrkolumna] == '*') plansza [wiersz+1][nrkolumna] = ' ';
						else if (plansza [wiersz+1][nrkolumna] == ' ') plansza [wiersz+1][nrkolumna] = '*';

						if (plansza [wiersz-1][nrkolumna] == '*') plansza [wiersz-1][nrkolumna] = ' ';
						else if (plansza [wiersz-1][nrkolumna] == ' ') plansza [wiersz-1][nrkolumna] = '*';

						if (plansza [wiersz][nrkolumna+1] == '*') plansza [wiersz][nrkolumna+1] = ' ';
						else if (plansza [wiersz][nrkolumna+1] == ' ') plansza [wiersz][nrkolumna+1] = '*';

						if (plansza [wiersz][nrkolumna-1] == '*') plansza [wiersz][nrkolumna-1] = ' ';
						else if (plansza [wiersz][nrkolumna-1] == ' ') plansza [wiersz][nrkolumna-1] = '*';
					}
						printf ("\n\n");
						licznik++;
						if (licznik>4999) warunek = 1;
				}
			}
			}
			/* Sprawdzenie warunku wygranej */
			if (wiersz != 'x' || wiersz != 'X' || kolumna != 'x' || kolumna != 'X')
			{
				zapalone = 0;
				zgaszone = (N-1)*(M-1);
				for (i=1;i<N;i++) for (j=1;j<M;j++)
				{
					if (plansza[i][j] == ' ') zgaszone = zgaszone - 1;
					else if (plansza[i][j] == '*') zapalone = zapalone + 1;
				}
				/* Jeśli warunek spełniony - liczenie punktów */
				if (zgaszone == 0)
				{
					rozmiar = (N-1) * (M-1);
					if (rozmiar == 120) rozmiar = 12;
					else if (rozmiar < 120 && rozmiar >= 100) rozmiar = 11;
					else if (rozmiar < 110 && rozmiar >= 100) rozmiar = 10;
					else if (rozmiar < 100 && rozmiar >= 90) rozmiar = 9;
					else if (rozmiar < 90 && rozmiar >= 80) rozmiar = 8;
					else if (rozmiar < 80 && rozmiar >= 70) rozmiar = 7;
					else if (rozmiar < 70 && rozmiar >= 60) rozmiar = 6;
					else if (rozmiar < 60 && rozmiar >= 50) rozmiar = 5;
					else if (rozmiar < 50 && rozmiar >= 40) rozmiar = 4;
					else if (rozmiar < 40 && rozmiar >= 30) rozmiar = 3;
					else if (rozmiar < 30 && rozmiar >= 20) rozmiar = 2;
					else if (rozmiar < 20 && rozmiar >= 10) rozmiar = 1;
					else if (rozmiar < 10 && rozmiar >= 5) rozmiar = 0;
					else if (rozmiar < 5 && rozmiar > 0) rozmiar = -1;

					switch (rozmiar)
					{
						case 12: wynik = (5000 - licznik), warunek = 1; break;
						case 11: wynik = (4500 - licznik), warunek = 1; break;
						case 10: wynik = (4000 - licznik), warunek = 1; break;
						case 9: wynik = (3500 - licznik), warunek = 1; break;
						case 8: wynik = (3000 - licznik), warunek = 1; break;
						case 7: wynik = (2500 - licznik), warunek = 1; break;
						case 6: wynik = (2000 - licznik), warunek = 1; break;
						case 5: wynik = (1500 - licznik), warunek = 1; break;
						case 4: wynik = (1000 - licznik), warunek = 1; break;
						case 3: wynik = (500 - licznik), warunek = 1; break;
						case 2: wynik = (400 - licznik), warunek = 1; break;
						case 1: wynik = (300 - licznik), warunek = 1; break;
						case 0: wynik = (200 - licznik), warunek = 1; break;
						case -1: wynik = (100 - licznik), warunek = 1; break;
						default: warunek = 0; break;
					}
				}
			}
		}
		while (warunek==0);
		warunek = 0;

	/* Rysuje aktualną tabelkę */
	printf ("\n");
	for (i=0;i<N;i++)
	{
		for (j=0;j<M;j++)
		{
			if (i==0 && j==0)
			{
				if (M==13) printf (" ___________________________________________________\n|");
				else if (M==12) printf (" _______________________________________________\n|");
				else if (M==11) printf (" ___________________________________________\n|");
				else if (M==10) printf (" _______________________________________\n|");
				else if (M==9) printf (" ___________________________________\n|");
				else if (M==8) printf (" _______________________________\n|");
				else if (M==7) printf (" ___________________________\n|");
				else if (M==6) printf (" _______________________\n|");
				else if (M==5) printf (" ___________________\n|");
				else if (M==4) printf (" _______________\n|");
				else if (M==3) printf (" ___________\n|");
				else if (M==2) printf (" _______\n|");
			}
			printf (" %c |", plansza [i][j]);
			if (j==M-1)
			{
				if (M==13) printf ("\n|___________________________________________________|\n");
				else if (M==12) printf ("\n|_______________________________________________|\n");
				else if (M==11) printf ("\n|___________________________________________|\n");
				else if (M==10) printf ("\n|_______________________________________|\n");
				else if (M==9) printf ("\n|___________________________________|\n");
				else if (M==8) printf ("\n|_______________________________|\n");
				else if (M==7) printf ("\n|___________________________|\n");
				else if (M==6) printf ("\n|_______________________|\n");
				else if (M==5) printf ("\n|___________________|\n");
				else if (M==4) printf ("\n|_______________|\n");
				else if (M==3) printf ("\n|___________|\n");
				else if (M==2) printf ("\n|_______|\n");
			}
			if (j==M-1 && i!=N-1) printf ("|");
		}
	}
		printf ("\nGame over! Your score: %d\n\n", wynik), zapalone = 120, zgaszone = 0; //koniec gry, podanie wyniku

/* Zapis wyniku do pliku */
		/* Odczyt dotychczasowych liderów */
		plik = fopen (PLIK, "r");
		if (plik == NULL)
		{
			perror ("Error occurred: ");
			continue;
		}

		j=0;
		for (i=0;i<P;i++)
		{
			fscanf (plik,  "\n%d\n", &wynikgracza [i]);
			fscanf (plik, "%s\n", &gracz[i][j]);
		}
		fclose (plik);
		/* Sprawdzenie czy wynik danego gracza jest lepszy od pozostałych */
		gotowe = 0;
		for (j=1;j<P;j++)
		{
			if (wynik > wynikgracza [0])
			{
				for (i=29;i>0;i--)
				{
					wynikgracza[i] = wynikgracza[i-1];
					for (k=0;k<P;k++)
					gracz[i][k] = gracz [i-1][k];
				}
				wynikgracza[0] = wynik;

				for (i=0;i<P;i++)
					gracz[0][i] = name[i];
				gotowe = 1;
			}
			else if (wynik > wynikgracza[j] && wynik < wynikgracza[j-1])
			{
				for (i=29-j;i>j;i--)
				{
					wynikgracza[i] = wynikgracza[i-1];
					for (k=0;k<P;k++)
					gracz[i][k] = gracz [i-1][k];
				}
					wynikgracza[j] = wynik;

				for (i=0;i<P;i++)
					gracz[j][i] = name[i];
				gotowe = 1;
			}
		}
		if (gotowe == 0)
		{
		for (l = 29;l>=0;l--)
		{
			if (wynik == wynikgracza[l])
			{
				for (i=29;i>l;i--)
				{
					wynikgracza[i] = wynikgracza[i-1];
					for (k=0;k<P;k++)
						gracz[i][k] = gracz [i-1][k];
				}
				wynikgracza[l+1] = wynik;

				for (i=0;i<P;i++)
					gracz[l+1][i] = name[i];
			}
		}
		}

		/* Zapis nowych liderów */
		plik = fopen (PLIK, "w");
		if (plik == NULL)
		{
			perror ("Error occurred: ");
			continue;
		}
		for (i=0;i<P;i++)
		{
			fprintf (plik, "\n%d\n", wynikgracza[i]);
			for(j=0;j<P;j++)
				fprintf (plik, "%c", gracz[i][j]);
		}
		fclose (plik);

		/* Opcje końcowe */
		printf ("x - Quit\n"
				"Type anything (except x) to back to Main Menu\n");
		scanf ("%s", &powrot);
		if (powrot == 'x' || powrot == 'X') return 0;
		else continue;

	break;
	}

	case '2': // tabela wyników
	{
		for (i=0;i<P;i++)
		{
			for (j=0;j<P;j++)
			{
				gracz[i][j] = '\0';
			}
			wynikgracza[i] = '\0';
		}
		printf ("Leaderboard:\n\n");

		/* Wczytanie listy rekordów z pliku */
		plik = fopen (PLIK, "r");
		if (plik == NULL)
		{
			perror ("Error occurred: ");
			continue;
		}
		for (i=0;i<P;i++)
		{
			fscanf (plik,  "\n%d\n", &wynikgracza [i]);
			fscanf (plik, "%s", &gracz[i-1][j]);
		}
		fclose (plik);

		/* Wyświetlenie listy */
		l = 1;
		for(i=0;i<9;i++)
		{
			printf (" %d.  %d.............", l, wynikgracza[i]);
			for (j=0;j<P;j++)
			{
				printf ("%c", gracz[i][j]);
			}
			printf ("\n");
			l++;
		}
		for(i=9;i<P;i++)
		{
			printf ("%d.  %d.............", l, wynikgracza[i]);
			for (j=0;j<P;j++)
			{
				printf ("%c", gracz[i][j]);
			}
			printf ("\n");
			l++;
		}
		printf ("\n\n");

		/* Opcje końcowe */
		printf ("x - Quit\n"
				"Type anything (except x) to back to Main Menu\n");
		scanf ("%s", &powrot);
		if (powrot == 'x' || powrot == 'X') return 0;
		else break;
		break;
	}
	case '3': // wyjście
	{
		return 0;
	}
	default: continue;
}
}
return 0;
}
