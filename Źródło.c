#define _CRT_SECURE_NO_WARNINGS //to pomog�o, aby nie pojawia�y si� b��dy np. ze scanf, znalezione w internecie
#include <stdio.h>				//standardowe wej�cie/wyj�cie
#include <stdlib.h>				//standardowe funkcje, rand(), malloc(), realloc(), itd.
#include <time.h>				//do funkcji obs�ugi czasu
#include <math.h>				//do funkcji matematycznych 
#include <locale.h>				//do funkcji setlocale()
#include <string.h>				//do funkcji strlen

//zabezpieczenie przed wprowadzaniem znak�w i liter
int czy_liczba_int(char napis[], int n) //przekazujemy do tej funkcji tablice znak�w i jej d�ugo�� 
{
		int x;
		for (int i = 0; i < n; i++)
		{
			if (napis[i] >= 48 && napis[i] <= 57)	//sprawdzamy czy napis jest pomi�dzy warto�ciami liczbowymi w ASCII
			{
				x = atoi(napis);					//funkcja atoi konwertuje napis na typ int
			}
			else
			{
				x = -1;								//je�li to nie napis zwracamy -1
			}
		}
	return x;										//zwracamy x, po konwersji
}

double czy_liczba_double(char napis[], int n) //przekazujemy do tej funkcji tablice znak�w i jej d�ugo�� 
{
	int x;
	for (int i = 0; i < n; i++)
	{
		if (napis[i] >= 48 && napis[i] <= 57)	//czy napis jest pomi�dzy warto�ciami liczbowymi w ASCII
		{
			x = atof(napis);					//funkcja atoi konwertuje napis na typ double
		}
		else
		{
			x = -1;								//je�li to nie napis zwracamy -1
		}
	}
	return x;									//zwracamy x, po konwersji
}

int wielkosc_tablicy()			//ta funkcja ustala rozmiar tablicy wynikowej
{
	printf("Prosz� poda� wielko�� tablicy wynikowej:\n");
	int wielkosc;				//musi by� zdefiniowany przed p�tl�
	char napis[20];				
	do							//wybra�am p�tl� do...while, poniewa� daje najbardziej optymalne rozwi�zanie
	{
		printf("Wielko�� tablicy wynikowej:\n");
		scanf("%s", &napis);					//podanie liczby typu int z klawiatury
		int n = strlen(napis);					//funkcja strlen oblicza d�ugo�� �a�cucha napis
		wielkosc = czy_liczba_int(napis, n);	//sprawdzamy czy podany �ancuch to liczba
		if (wielkosc <= 0)						// sprawdzenie czy rozmiar tablicy jest wi�kszy od zera (zabezpieczenie)
			printf("Wielko�ci� tablicy powinna byc liczba wieksza od zera, prosz� wpisac ponownie. \n");

	} while (wielkosc <= 0);	//wykonuj dop�ki wielko�� b�dzie liczb� dodatni� (u�ytkownik poda poprawn� warto��)

	return wielkosc;			//zwr�� wielko�� tam, gdzie funkcja by�a wywo�ana
}

void wspolczynniki_funkcji (double wspolczynniki[]) //funkcja generujaca wspolczynniki funkcji, void nie przekazuje nic, nie potrzeba return;
{
	printf("Funkcja dla kt�rej b�d� potrzebne wsp�czynniki: y=Asin(Bx+C)+D\nProsz� poda� wsp�czynniki A,B,C,D oraz za ka�dym razem potwierdzi� klawiszem enter\n");
	printf("Wsp�czynnik A: ");
	//do ka�dego wsp�czynnika daj� zabezpieczenia
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[0] = czy_liczba_double(napis, n);
		if (wspolczynniki[0] <= 0)
		{
			printf("B��D - Niepoprawna warto��.\n");
			printf("Podaj wsp�czynnik A jako liczb� wi�ksz� od 0: \n");
		}
	} while (wspolczynniki[0] <= 0);

	printf("Wsp�czynnik B: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[1] = czy_liczba_double(napis, n);
		if (wspolczynniki[1] <= 0)
		{
			printf("B��D - Niepoprawna warto��.\n");
			printf("Podaj wsp�czynnik B jako liczb� wi�ksz� od 0: \n");
		}
	} while (wspolczynniki[1] <= 0);

	printf("Wsp�czynnik C: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[2] = czy_liczba_double(napis, n);
		if (wspolczynniki[2] < 0)
		{
			printf("B��D - Niepoprawna warto��.\n");
			printf("Podaj wsp�czynnik C jako liczb� wi�ksz� od 0 lub r�wn� 0: \n");
		}
	} while (wspolczynniki[2] < 0);

	printf("Wsp�czynnik D: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[3] = czy_liczba_double(napis, n);
		if (wspolczynniki[3] < 0)
		{
			printf("B��D - Niepoprawna warto��.\n");
			printf("Podaj wsp�czynnik D jako liczb� wi�ksz� od 0 lub r�wn� 0: \n");
		}
	} while (wspolczynniki[3] < 0);
}

void dziedzina_funkcji(double *wskaznik_min, double *wskaznik_max)	//funkcja generuj�ca dziedzin� funkcji sin
{
	double min, max;												//to mo�e by� liczba zmiennoprzecinkowa wi�c double
	printf("Prosz� poda� zakres dziedziny (minimum oraz maksimum) oraz potwierdzi� klawiszem enter\n");
	printf("Minimum:\n");
	//tu r�wnie� zabezpieczenia
	do
	{
		char napis[20];
		scanf("%s", &napis);	//wprowadzane z klawiatury, obieramy nowe warto�ci min i max
		int n = strlen(napis);
		min = czy_liczba_double(napis, n);
		if (min <= 0)
			printf("To nie liczba. Prosz� poda� liczb� wi�ksz� od 0.\n");
	} while (min <= 0);
										
	printf("Maksimum:\n");
	do
	{
		char napis[20];
		scanf("%s", &napis);	
		int n = strlen(napis);
		max = czy_liczba_double(napis, n);
		if (max <= 0 || min >= max)
			printf("Zakres maksymalny musi byc wi�kszy od zera i wi�kszy od minimalnego. Prosz� poda� warto�� maksimum ponownie:\n");
	} while (max <= 0 && min >= max);						//wykonuj tak d�ugo a� max b�dzie > 0 i max > min

	*wskaznik_min = min;									//u�ywamy wska�nik�w, �eby m�c u�ywa� tych danych poza funkcj�
	*wskaznik_max = max;									//zmiana warto�ci pod adresem ze wska�nika
}

void generuj_funkcje(double wspolczynniki[], double min, double max, double wyniki[], int wielkosc)  //funkcja generuj�ca sygna� sinusa
{
	double x, y;
	double A, B, C, D;
	
	wspolczynniki_funkcji(wspolczynniki);					//przechodzimy do funkcji ustalaj�cej wsp�czynniki, nazwa tablicy jest wska�nikiem na jej pierwsze pole
	A = wspolczynniki[0];
	B = wspolczynniki[1];
	C = wspolczynniki[2];
	D = wspolczynniki[3];

	dziedzina_funkcji(&min, &max);							//wywo�ujemy funkcj� dziedzina_funkcji i przekazujemy jej adresy min i max

	int i = 0;
	double odleglosc = (max - min) / wielkosc;				//odleg�o�� mi�dzy kolejnymi pr�bkami sygna�u, �eby ten sinus si� troch� rozci�gn��
	do
	{
		x = min + i * odleglosc;							//s� to kolejne liczby na osi x (w przedziale dziedziny)
		y = A * sin(B * x + C) + D;							//warto�� funkcji dla kolejnych liczb x 
		wyniki[i] = y;										// w tej tablicy zapisuj� si� kolejne warto�ci funkcji
		i = i + 1;
	} while (i < wielkosc);									//p�tl� wykonujemy do momentu gdy i b�dzie r�wne rozmiarowi tablicy
}


void generuj_szum(double wyniki[], double szum[], int wielkosc)	//argumenty nazywam tak samo, �atwiej mi si� po�apa�
{		
	printf("Wybierz:\n1. Losowy szum z zakresu.\n2. Losowy szum bez okre�lania zakresu.\n");
	int wybor;

	//zabezpieczenie przed wprowadzaniem liter
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wybor = czy_liczba_int(napis, n);
		if (wybor <= 0)
			printf("To nie liczba. Prosz� poda� liczb� z menu od 1 do 2.\n");
	} while (wybor <= 0);

	switch (wybor)
	{
	case 1:
	{
		printf("Wyb�r 1. Losowy szum z zakresu liczb ca�kowitych. Zakres nie powinnien by� zbyt rozleg�y. Prosz� poda� zakres.\n");
		int min, max;
		printf("Wprowad� warto�� minimaln�:\n");
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			min = czy_liczba_int(napis, n);
			if (min <= 0)
				printf("Prosz� poda� liczb� wi�ksz� od 0.\n");
		} while (min <= 0);

		printf("Wprowad� warto�� maksymaln�:\n");					//zakres nie powinien by� zbyt rozleg�y, wtedy szum mo�e okaza� si� bardzo du�y, co nie b�dzie mia�o sensu na wykresie
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			max = czy_liczba_int(napis, n);
			if (max <= 0 || max <= min)
				printf("Prosz� poda� liczb� wi�ksz� od 0 i wi�ksz� od warto�ci minimalnej.\n");
		} while (max <= 0 || max <= min);

		for (int i = 0; i < wielkosc; i = i + 1)
		{
			double szum_pomocniczy1;
			szum_pomocniczy1 = min + (rand() % (max - min + 1));	//wz�r znaleziony w odch�ani internetu, oznacza losow� liczb� z danego zakresu
			double wlasciwy_szum1;
			wlasciwy_szum1 = wyniki[i] + szum_pomocniczy1;
			szum[i] = wlasciwy_szum1;								//tablica z wynikami szumu
		}
		printf("\nPokazuj� wyniki po wygenerowaniu szumu: ");
		for (int i = 0; i < wielkosc; i = i + 1)					//wype�niamy tablic� wynikami
		{
			printf("%0.5lf;  ", szum[i]);							//do 5 miejsca po przecinku, %lf do double
		}
		break;
	}
	case 2:
	{
		printf("Wyb�r 2. Losowy szum bez okre�lania zakresu.");
		for (int i = 0; i < wielkosc; i = i + 1)
		{
			double szum_pomocniczy2;
			szum_pomocniczy2 = (rand() % 10) / 5.;					//losowy szum z zakresu od 1 do 10, podzielony przez 5, wybra�am taki, bo wychodzi�y liczby, kt�re mia�y sens na wykresie
			double wlasciwy_szum2;
			wlasciwy_szum2 = wyniki[i] + szum_pomocniczy2;
			szum[i] = wlasciwy_szum2;								//tablica z wynikami szumu
		}
		printf("\nPokazuj� wyniki po wygenerowaniu szumu: ");
		for (int i = 0; i < wielkosc; i = i + 1)					//wype�niamy tablic� wynikami
		{
			printf("%0.5lf;  ", szum[i]);							//do 5 miejsca po przecinku, %lf do double
		}
		break;
	}
	default:
	{
		printf("Niestety takiej liczby nie ma w menu wyboru. Prosz� poda� ponownie:\n");
		break;
	}
	}
}

void zapis_wynikow(double wyniki[], double szum[], int wielkosc)			//nazywam tak samo, jest mi �atwiej
{
	int i;
	FILE* plik;																//utworzenie struktury FILE* (uchwytu, identyfikatora) pliku, do kt�rego b�dziemy si� odwo�ywa�
	plik = fopen("zapis_wynikow.csv", "w");									//nazwa pliku � tablica znak�w char*; w tym miejscu mo�na poda� pe�n� �cie�k� pliku lub sam� nazw� pliku -> wtedy lokalizuje tam, gdzie jest program
																			//tryb obs�ugi pliku - do wyboru jest kilka predefiniowanych tryb�w, na przyk�ad: "w" � otwiera / tworzy plik do zapisu, usuwa jego star� tre��
	if (!plik)																//sprawdzamy czy plik istnieje
	{
		printf("B��d. Niestety nie uda�o si� otworzy� tego pliku. Zapis pliku nie b�dzie mo�liwy.\n");
	}

	else																	//je�li istnieje to zapisujemy warto�ci tablicy wynik�w oraz tablicy wynik�w zaszumionych kolejno w kom�rkach Excela
	{
		for (i = 0; i < wielkosc; i++)
		{																	//%lf bo double
			fprintf(plik, " %lf ; %lf \n", wyniki[i], szum[i]);				//u�ywa si� podobnie jak printf(), r�nic� jest konieczno�� przekazania uchwytu do pliku
		}																	//w kolejnych komorkach w excelu zapisane sa wartosci tablicy wynikow i wynikow zaszumionych
																			//�rednik to tzw. separator pola, oznacza to przej�cie do kolejnej kom�rki
																			//wi�c dane b�d� zapisywa� si� obok siebie, jedna pod drug�, jedna kolumna b�dzie dla wynik�w, druga dla wynik�w szumu
		fclose(plik);														//zamkni�cie pliku czy�ci bufory danych powi�zane z nim, zwalnia uchwyt oraz pozwala na otwieranie pliku na zewn�trz lub jego usuni�cie;
		printf("Zaszumione wyniki zapisano do pliku.\n");					//zalecane jest zamykanie pliku za ka�dym razem w przypadku nieprawid�owego zako�czenia programu
	}
}

void odczyt_wynikow(double* wyniki, double* szum)							//nazywam argumenty tak samo jak w main
{																			//wska�niki, bo: Algorytm ma polega� na sprawdzaniu w p�tli czy plik si� nie sko�czy� po przej�ciu do ka�dej linii.
																			//Je�li nie, to tablice mog� zosta� realokowane o 1 element a dane mog� zosta� odczytane i wpisane do nich.
	FILE* plik;																//utworzenie struktury FILE* (uchwytu, identyfikatora) pliku, do kt�rego b�dziemy si� odwo�ywa�
	plik = fopen("zapis_wynikow.csv", "r");									//funkcja fopen() otwiera plik, kt�rego nazwa podana jest w pierwszym argumencie, drugi argument "r" � otwiera plik do odczytu

	if (!plik)																//sprawdzamy, czy plik istnieje
	{
		printf("B��d. Niestety nie uda�o si� otworzy� tego pliku. Zapis pliku nie b�dzie mo�liwy.\n");
	}

	else
	{
		int n = 0;															//zdeklarowane przed p�tl�
		while (fgetc(plik) != EOF)											//fgets zwraca znak z aktualnej pozycji w pliku i przestawia pozycj� o 1
		{																	//EOF oznacza koniec pliku (end of file)
			fseek(plik, -1, SEEK_CUR);										//sugestia z maila, aby nie by�o 0 na pocz�tku kolejnych wers�w; 
																			//przesuwa pozycj� w pliku o podan� liczb� znak�w(int) (-1) wzgl�dem aktualnego miejsca (SEEK_CUR)
			fscanf(plik, " %lf ; %lf \n", &wyniki[n], &szum[n]);			//odczytujemy kom�rki, kt�re by�y zapisane w pliku
			printf(" %lf ; %lf \n", wyniki[n], szum[n]);					//tu drukujemy uzyskane wyniki w programie

			n++;															//a p�tla leci dalej
		}

		fclose(plik);														//zamkni�cie pliku, wyja�nione czemu w funkcji zapis_wynikow
	}
}

void filtr_sredniej_ruchomej(double* szum, double* odszumienie, int wielkosc) //wska�niki, bo to tablice
{
	double pomocnicza[5];					//pomocnicza tablica w ktorej zapisywane sa dane probki
	odszumienie[0] = szum[0];				//przepisanie dw�ch pierwszych i ostatnich wyraz�w tabeli do tabeli odszumionych danych
	odszumienie[1] = szum[1];
	odszumienie[wielkosc - 1] = szum[wielkosc - 1];
	odszumienie[wielkosc - 2] = szum[wielkosc - 2];

	printf("\nPokazuj� wyniki po odszumieniu sygna�u:  ");
	printf("%0.5lf; ", odszumienie[0]);			//do 5 miejsca po przecinku, %lf do double
	printf("%0.5lf; ", odszumienie[1]);
	
	for (int j = 2; j < wielkosc - 2; j = j + 1)  //p�tla s�u��ca do wype�nienia wszystkich innych danych wi�kszych od/r�wnych 2 i mniejszych od wielkosc - 2, bo te ju� mamy wy�ej
	{
		pomocnicza[0] = szum[j - 2];
		pomocnicza[1] = szum[j - 1];
		pomocnicza[2] = szum[j];
		pomocnicza[3] = szum[j + 1];
		pomocnicza[4] = szum[j + 2];

		double srednia;
		srednia = (pomocnicza[0] + pomocnicza[1] + pomocnicza[2] + pomocnicza[3] + pomocnicza[4]) / 5;
		odszumienie[j] = srednia;
		
	}
	for (int j = 2; j < wielkosc - 2; j++)
	{
		printf("%0.5lf; ", odszumienie[j]);
	}

	printf("%0.5lf; ", odszumienie[wielkosc - 1]);
	printf("%0.5lf; ", odszumienie[wielkosc - 2]);
}

void filtr_medianowy(double* szum, double* odszumienie, int wielkosc) //argumenty nazywam tak samo, �atwiej mi si� po�apa�
{
	double temp;				//pomocnicza zmienna
	int szerokosc_okna = 5;
	double pomocnicza[5];		//pomocnicza tablica w ktorej zapisywane sa dane probki
	odszumienie[0] = szum[0];	//przepisanie dw�ch pierwszych i ostatnich wyraz�w tabeli do tabeli odszumionych danych
	odszumienie[1] = szum[1];
	odszumienie[wielkosc - 1] = szum[wielkosc - 1];
	odszumienie[wielkosc - 2] = szum[wielkosc - 2];

	printf("\nPokazuj� wyniki po odszumieniu sygna�u:  ");
	printf("%0.5lf; ", odszumienie[0]);			//do 5 miejsca po przecinku, %lf do double
	printf("%0.5lf; ", odszumienie[1]);

	for (int j = 2; j < wielkosc - 2; j = j + 1)	//p�tla s�u��ca do wygenerowania wszystkich innych danych wi�kszych od/r�wnych 2 i mniejszych od wielkosc - 2, bo te ju� mamy wy�ej
	{
		pomocnicza[0] = szum[j - 2];				//dwie poprzednie liczby i dwie kolejne
		pomocnicza[1] = szum[j - 1];
		pomocnicza[2] = szum[j];
		pomocnicza[3] = szum[j + 1];
		pomocnicza[4] = szum[j + 2];
		do														//sortowanie b�belkowe, spos�b wykonania znaleziony w internecie
		{
			for (int i = 0; i < szerokosc_okna - 1; i = i + 1)  //szerokosc_okna - 1, bo szeroko�� okna to 5, a tablice liczymy od warto�ci na miejscu 0
			{
				if (pomocnicza[i] > pomocnicza[i + 1])			//sortowanie, je�li warto�� np. pr�bki 1 jest wi�ksza od warto�ci pr�bki 2 to zamiana warto�ci
				{
					temp = pomocnicza[i + 1];
					pomocnicza[i + 1] = pomocnicza[i];
					pomocnicza[i] = temp;
				}
			}
			szerokosc_okna = szerokosc_okna - 1;			//zmniejszamy szeroko�� okna, �eby zaw�zi� te poszukiwania, program wykonuje p�tle dalej
		} while (szerokosc_okna > 1);						//wykonuj, a� szeroko�� okna nie b�dzie r�wna 1, bo o to nam chodzi
		
		odszumienie[j] = pomocnicza[2];						//2 to wyraz �rodkowy
	}

	for (int j = 2; j < wielkosc - 2; j++)
	{
		printf("%0.5lf; ", odszumienie[j]);
	}

	printf("%0.5lf; ", odszumienie[wielkosc - 1]);
	printf("%0.5lf; ", odszumienie[wielkosc - 2]);
}

int main()
{
	double wspolczynniki[4];						//tablica o rozmiarze 4 liczb typu double, potrzebna do przekazania funkcji wspolczynniki_funkcji
	double min = 0, max = 0;						//musimy zainicjowa� te warto�ci, aby p�niej je przekaza� do funkcji
	int i, wielkosc;
	int sprawdzenie = 0;							//ograniczenie: ta liczba jest po to, �eby m�c sprawdzi� co mo�na zrobi� w programie, przyk�adowo nie mo�na uruchomi� opcji szumu na sygnale, je�li nie mamy sygna�u
	srand(time(NULL));

	double *wyniki;									//tablica wyniki + ni�ej jej rozmiar, tak mo�na robi� zamiast double wyniki[1];
	wyniki = malloc(1 * sizeof(double));			//przydzia� pamieci w bajtach
	if (wyniki == NULL)								//zabezpieczenie przed utrat� danych i wyciekiem pami�ci, szczeg�lnie wa�ne to b�dzie przy funkcji realloc()
	{
		printf("B��d alokacji, przerwanie dzia�ania.\n");
		return 1;
	}

	double *szum;						//tu zrobi�am to samo co wy�ej
	szum = malloc(1 * sizeof(double));	//przydzia� pami�ci w bajtach, ta tablica r�wnie� powi�ksza si� w zale�no�ci od wprowadzonego rozmiaru tablicy przez u�ytkownika
	if (szum == NULL)
	{
		printf("B��d alokacji, przerwanie dzia�ania.\n");
		return 1;
	}

	double *odszumienie;				//to samo co wy�ej
	odszumienie = malloc(1 * sizeof(double));
	if (odszumienie == NULL)
	{
		printf("B��d alokacji, przerwanie dzia�ania.\n");
		return 1;
	}

	setlocale(LC_ALL, "polish_poland"); //aby da�o si� odczyta� wyniki z Excela (przecinki zamiast kropek) oraz do polskich znak�w w programie, znalezione w instrukcji 2
										
	int wybor_uzytkownika;
	do
	{
		printf("				MENU WYBORU\nProsz� wybra� jedn� z poni�szych opcji i zatwierdzi� klawiszem enter:\n");
		printf("1. Generacja funkcji.\n2. Generacja szumu funkcji.\n3. Zapisanie do pliku.\n4. Odczyt z pliku.\n5. Wyprostowanie zaszumionego sygna�u.\n6. Zako�czenie pracy w programie.\n"); //menu
		//zabezpieczenie przed wprowadzeniem liter i znak�w
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			wybor_uzytkownika = czy_liczba_int(napis, n);
			if (wybor_uzytkownika <= 0)
				printf("Prosz� poda� liczb� z menu od 1 do 6.\n");
		} while (wybor_uzytkownika <= 0);
		
		switch (wybor_uzytkownika)
		{
		case 1:
		{
			printf("Wyb�r: 1. Generacja funkcji.\n");
			wielkosc = wielkosc_tablicy();										//wywo�ujemy funkcj� wielkosc_tablicy()
			double* wyniki_tymczasowe;
			wyniki_tymczasowe = realloc(wyniki, wielkosc * sizeof(double));		//nowy przydzia� pami�ci, powi�ksza si� obszar tablicy, pierwszy parametr to adres pocz�tku tablicy utworzonej za pomoc� funkcji malloc(), drugi to nowy rozmiar pami�ci w bajtach
			if (wyniki_tymczasowe != NULL)										//bardzo wa�ne zabezpieczenie przed utrat� danych
			{
				wyniki = wyniki_tymczasowe;
			}
			else
			{
				printf("Nie uda�o si� powi�kszy� tablicy.\n");
				wyniki = malloc(1 * sizeof(double));							//nie uda�o si� powi�kszy�, a wi�c tablica ma jeden element
			}

			generuj_funkcje(wspolczynniki, min, max, wyniki, wielkosc);			//wywo�ujemy funkcj� generuj_funkcje()
			printf("\nPokazuj� wyniki:  ");										//wype�niamy tabel� wynik�w
			for (i = 0; i < wielkosc; i = i + 1)
			{
				printf("%0.5lf; ", wyniki[i]);	//wydruk wynik�w do 5 miejsca po przecinku, mo�na dowolnie zmienia�
			}
			sprawdzenie = 1;					//ta liczba jest po to, �eby m�c sprawdzi� co mo�na zrobi� w programie, przyk�adowo nie mo�na uruchomi� opcji szumu na sygnale, je�li nie mamy sygna�u
			break;
		}
		case 2:
		{
			printf("Wyb�r: 2. Generacja szumu funkcji.\n");
			if (sprawdzenie >= 1)								//ten wyb�r mo�e si� dokona� tylko gdy sprawdzenie b�dzie > lub = 1, tylko wtedy mamy pewno��, �e istnieje wygenerowana funkcja
			{													//nowy przydzia� pami�ci, powi�ksza si� obszar tablicy, jak w case 1
				double* szum_tymczasowy;
				szum_tymczasowy = realloc(szum, wielkosc * sizeof(double));		//nowy przydzia� pami�ci, powi�ksza si� obszar tablicy, pierwszy parametr to adres pocz�tku tablicy utworzonej za pomoc� funkcji malloc(), drugi to nowy rozmiar pami�ci w bajtach
				if (szum_tymczasowy != NULL)									//bardzo wa�ne zabezpieczenie przed utrat� danych
				{
					szum = szum_tymczasowy;
				}
				else
				{
					printf("Nie uda�o si� powi�kszy� tablicy.\n");
					szum = malloc(1 * sizeof(double));
				}
				generuj_szum(wyniki, szum, wielkosc);			//wywo�ujemy funkcj� generuj_szum
				sprawdzenie = 2;								//to oznacza, �e program mo�e teraz odszumia� wyniki, zapisywa� je itp.
				break;
			}
			else
			{
				printf("Nie wygenerowano funkcji, prosz� wybra� opcj� 1.\n");
				break;
			}
		}
		case 3:
		{
			printf("Wyb�r: 3. Zapisanie do pliku.\n");
			if (sprawdzenie >= 2)						//b�dzie dzia�a� tylko, gdy wcze�niej funkcja zosta�a zaszumiona
			{
				zapis_wynikow(wyniki, szum, wielkosc);
				sprawdzenie = 3;
				break;
			}
			else
			{
				printf("Nie wygenerowano funkcji, prosz� wybra� opcj� 1.\n");
				break;
			}
		}

		case 4:
		{
			printf("Wyb�r: 4. Odczytanie z pliku.\n");
			if (sprawdzenie == 3)						//zadzia�a tylko, gdy mamy ju� wcze�niej utworzony plik
			{
				odczyt_wynikow(wyniki, szum);
				break;
			}
			else
			{
				printf("Nie zapisano �adnego pliku, prosz� najpierw wybra� opcj� 3.\n");
				break;
			}
		}
		
		case 5:
		{
			printf("Wyb�r: 5. Odszumianie wynik�w.\n");
			if (sprawdzenie >= 2)						//ten wyb�r mo�e si� dokona� tylko gdy sprawdzenie b�dzie > lub = 2, tylko wtedy mamy pewno��, �e istnieje wygenerowana funkcja i szum do niej
			{

				double* odszumienie_tymczasowe;
				odszumienie_tymczasowe = realloc(odszumienie, wielkosc * sizeof(double));		//nowy przydzia� pami�ci, powi�ksza si� obszar tablicy, pierwszy parametr to adres pocz�tku tablicy utworzonej za pomoc� funkcji malloc(), drugi to nowy rozmiar pami�ci w bajtach
				if (odszumienie_tymczasowe != NULL)												//bardzo wa�ne zabezpieczenie przed utrat� danych
				{
					odszumienie = odszumienie_tymczasowe;
				}
				else
				{
					printf("Nie uda�o si� powi�kszy� tablicy.\n");
					odszumienie = malloc(1 * sizeof(double));
				}

				int wybor;
				printf("\nProsz� wybra� liczb� z menu:\n1. Filtr medianowy.\n2. Filtr �redniej ruchomej.\n");
				do
				{
					char napis[20];
					scanf("%s", &napis);
					int n = strlen(napis);
					wybor = czy_liczba_int(napis, n);
					if (wybor <= 0)
						printf("To nie liczba. Prosz� poda� liczb� z menu od 1 do 2.\n");
				} while (wybor <= 0);

				switch (wybor)
				{
				case 1:
				{
					printf("Wyb�r 1. Filtr medianowy.\n");
					filtr_medianowy(szum, odszumienie, wielkosc);				//wywo�anie funkcji 
					break;
				}
				case 2:
				{
					printf("Wyb�r 2. Filtr �redniej ruchomej.\n");
					filtr_sredniej_ruchomej(szum, odszumienie, wielkosc);		//wywo�anie funkcji
					break;
				}
				}
				break;
			}

			else
			{
				printf("Nie wygenerowano funkcji, prosz� wybra� opcj� 1.\n");
				break;
			}
		}

		case 6:
		{
				printf("Wyb�r: 6. Zako�czenie pracy w programie.\n");
				sprawdzenie = 6;				//tu musi by� w ten spos�b, bo dopiero wtedy przerywamy p�tl� do...while
				break;
		}

		default:								//oznacza blok instrukcji wykonywany dla wszystkich pozosta�ych warto�ci zmiennej
		{
				printf("Niestety takiej liczby nie ma w menu wyboru. Prosz� poda� ponownie:\n");
		}
		}
		printf("\n");								//nowa linia
	} while (sprawdzenie != 6);						//menu b�dzie wy�wietlane do momentu wyboru numeru 6 - zako�czenia pracy programu

	free(wyniki);									//jest to uwolnienie zaalokowanej pamieci, trzeba zwolni�, �eby m�c kiedy� u�y� j� do czego� innego
	free(szum);										//trzeba to zrobi�, poniewa� je�li kod programu w jakikolwiek spos�b powoduje wycieki pami�ci, jest kodem b��dnym
	free(odszumienie);

	return 0;
}