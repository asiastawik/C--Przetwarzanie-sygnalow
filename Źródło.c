#define _CRT_SECURE_NO_WARNINGS //to pomog³o, aby nie pojawia³y siê b³êdy np. ze scanf, znalezione w internecie
#include <stdio.h>				//standardowe wejœcie/wyjœcie
#include <stdlib.h>				//standardowe funkcje, rand(), malloc(), realloc(), itd.
#include <time.h>				//do funkcji obs³ugi czasu
#include <math.h>				//do funkcji matematycznych 
#include <locale.h>				//do funkcji setlocale()
#include <string.h>				//do funkcji strlen

//zabezpieczenie przed wprowadzaniem znaków i liter
int czy_liczba_int(char napis[], int n) //przekazujemy do tej funkcji tablice znaków i jej d³ugoœæ 
{
		int x;
		for (int i = 0; i < n; i++)
		{
			if (napis[i] >= 48 && napis[i] <= 57)	//sprawdzamy czy napis jest pomiêdzy wartoœciami liczbowymi w ASCII
			{
				x = atoi(napis);					//funkcja atoi konwertuje napis na typ int
			}
			else
			{
				x = -1;								//jeœli to nie napis zwracamy -1
			}
		}
	return x;										//zwracamy x, po konwersji
}

double czy_liczba_double(char napis[], int n) //przekazujemy do tej funkcji tablice znaków i jej d³ugoœæ 
{
	int x;
	for (int i = 0; i < n; i++)
	{
		if (napis[i] >= 48 && napis[i] <= 57)	//czy napis jest pomiêdzy wartoœciami liczbowymi w ASCII
		{
			x = atof(napis);					//funkcja atoi konwertuje napis na typ double
		}
		else
		{
			x = -1;								//jeœli to nie napis zwracamy -1
		}
	}
	return x;									//zwracamy x, po konwersji
}

int wielkosc_tablicy()			//ta funkcja ustala rozmiar tablicy wynikowej
{
	printf("Proszê podaæ wielkoœæ tablicy wynikowej:\n");
	int wielkosc;				//musi byæ zdefiniowany przed pêtl¹
	char napis[20];				
	do							//wybra³am pêtlê do...while, poniewa¿ daje najbardziej optymalne rozwi¹zanie
	{
		printf("Wielkoœæ tablicy wynikowej:\n");
		scanf("%s", &napis);					//podanie liczby typu int z klawiatury
		int n = strlen(napis);					//funkcja strlen oblicza d³ugoœæ ³añcucha napis
		wielkosc = czy_liczba_int(napis, n);	//sprawdzamy czy podany ³ancuch to liczba
		if (wielkosc <= 0)						// sprawdzenie czy rozmiar tablicy jest wiêkszy od zera (zabezpieczenie)
			printf("Wielkoœci¹ tablicy powinna byc liczba wieksza od zera, proszê wpisac ponownie. \n");

	} while (wielkosc <= 0);	//wykonuj dopóki wielkoœæ bêdzie liczb¹ dodatni¹ (u¿ytkownik poda poprawn¹ wartoœæ)

	return wielkosc;			//zwróæ wielkoœæ tam, gdzie funkcja by³a wywo³ana
}

void wspolczynniki_funkcji (double wspolczynniki[]) //funkcja generujaca wspolczynniki funkcji, void nie przekazuje nic, nie potrzeba return;
{
	printf("Funkcja dla której bêd¹ potrzebne wspó³czynniki: y=Asin(Bx+C)+D\nProszê podaæ wspó³czynniki A,B,C,D oraz za ka¿dym razem potwierdziæ klawiszem enter\n");
	printf("Wspó³czynnik A: ");
	//do ka¿dego wspó³czynnika dajê zabezpieczenia
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[0] = czy_liczba_double(napis, n);
		if (wspolczynniki[0] <= 0)
		{
			printf("B£¥D - Niepoprawna wartoœæ.\n");
			printf("Podaj wspó³czynnik A jako liczbê wiêksz¹ od 0: \n");
		}
	} while (wspolczynniki[0] <= 0);

	printf("Wspó³czynnik B: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[1] = czy_liczba_double(napis, n);
		if (wspolczynniki[1] <= 0)
		{
			printf("B£¥D - Niepoprawna wartoœæ.\n");
			printf("Podaj wspó³czynnik B jako liczbê wiêksz¹ od 0: \n");
		}
	} while (wspolczynniki[1] <= 0);

	printf("Wspó³czynnik C: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[2] = czy_liczba_double(napis, n);
		if (wspolczynniki[2] < 0)
		{
			printf("B£¥D - Niepoprawna wartoœæ.\n");
			printf("Podaj wspó³czynnik C jako liczbê wiêksz¹ od 0 lub równ¹ 0: \n");
		}
	} while (wspolczynniki[2] < 0);

	printf("Wspó³czynnik D: ");
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wspolczynniki[3] = czy_liczba_double(napis, n);
		if (wspolczynniki[3] < 0)
		{
			printf("B£¥D - Niepoprawna wartoœæ.\n");
			printf("Podaj wspó³czynnik D jako liczbê wiêksz¹ od 0 lub równ¹ 0: \n");
		}
	} while (wspolczynniki[3] < 0);
}

void dziedzina_funkcji(double *wskaznik_min, double *wskaznik_max)	//funkcja generuj¹ca dziedzinê funkcji sin
{
	double min, max;												//to mo¿e byæ liczba zmiennoprzecinkowa wiêc double
	printf("Proszê podaæ zakres dziedziny (minimum oraz maksimum) oraz potwierdziæ klawiszem enter\n");
	printf("Minimum:\n");
	//tu równie¿ zabezpieczenia
	do
	{
		char napis[20];
		scanf("%s", &napis);	//wprowadzane z klawiatury, obieramy nowe wartoœci min i max
		int n = strlen(napis);
		min = czy_liczba_double(napis, n);
		if (min <= 0)
			printf("To nie liczba. Proszê podaæ liczbê wiêksz¹ od 0.\n");
	} while (min <= 0);
										
	printf("Maksimum:\n");
	do
	{
		char napis[20];
		scanf("%s", &napis);	
		int n = strlen(napis);
		max = czy_liczba_double(napis, n);
		if (max <= 0 || min >= max)
			printf("Zakres maksymalny musi byc wiêkszy od zera i wiêkszy od minimalnego. Proszê podaæ wartoœæ maksimum ponownie:\n");
	} while (max <= 0 && min >= max);						//wykonuj tak d³ugo a¿ max bêdzie > 0 i max > min

	*wskaznik_min = min;									//u¿ywamy wskaŸników, ¿eby móc u¿ywaæ tych danych poza funkcj¹
	*wskaznik_max = max;									//zmiana wartoœci pod adresem ze wskaŸnika
}

void generuj_funkcje(double wspolczynniki[], double min, double max, double wyniki[], int wielkosc)  //funkcja generuj¹ca sygna³ sinusa
{
	double x, y;
	double A, B, C, D;
	
	wspolczynniki_funkcji(wspolczynniki);					//przechodzimy do funkcji ustalaj¹cej wspó³czynniki, nazwa tablicy jest wskaŸnikiem na jej pierwsze pole
	A = wspolczynniki[0];
	B = wspolczynniki[1];
	C = wspolczynniki[2];
	D = wspolczynniki[3];

	dziedzina_funkcji(&min, &max);							//wywo³ujemy funkcjê dziedzina_funkcji i przekazujemy jej adresy min i max

	int i = 0;
	double odleglosc = (max - min) / wielkosc;				//odleg³oœæ miêdzy kolejnymi próbkami sygna³u, ¿eby ten sinus siê trochê rozci¹gn¹³
	do
	{
		x = min + i * odleglosc;							//s¹ to kolejne liczby na osi x (w przedziale dziedziny)
		y = A * sin(B * x + C) + D;							//wartoœæ funkcji dla kolejnych liczb x 
		wyniki[i] = y;										// w tej tablicy zapisuj¹ siê kolejne wartoœci funkcji
		i = i + 1;
	} while (i < wielkosc);									//pêtlê wykonujemy do momentu gdy i bêdzie równe rozmiarowi tablicy
}


void generuj_szum(double wyniki[], double szum[], int wielkosc)	//argumenty nazywam tak samo, ³atwiej mi siê po³apaæ
{		
	printf("Wybierz:\n1. Losowy szum z zakresu.\n2. Losowy szum bez okreœlania zakresu.\n");
	int wybor;

	//zabezpieczenie przed wprowadzaniem liter
	do
	{
		char napis[20];
		scanf("%s", &napis);
		int n = strlen(napis);
		wybor = czy_liczba_int(napis, n);
		if (wybor <= 0)
			printf("To nie liczba. Proszê podaæ liczbê z menu od 1 do 2.\n");
	} while (wybor <= 0);

	switch (wybor)
	{
	case 1:
	{
		printf("Wybór 1. Losowy szum z zakresu liczb ca³kowitych. Zakres nie powinnien byæ zbyt rozleg³y. Proszê podaæ zakres.\n");
		int min, max;
		printf("WprowadŸ wartoœæ minimaln¹:\n");
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			min = czy_liczba_int(napis, n);
			if (min <= 0)
				printf("Proszê podaæ liczbê wiêksz¹ od 0.\n");
		} while (min <= 0);

		printf("WprowadŸ wartoœæ maksymaln¹:\n");					//zakres nie powinien byæ zbyt rozleg³y, wtedy szum mo¿e okazaæ siê bardzo du¿y, co nie bêdzie mia³o sensu na wykresie
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			max = czy_liczba_int(napis, n);
			if (max <= 0 || max <= min)
				printf("Proszê podaæ liczbê wiêksz¹ od 0 i wiêksz¹ od wartoœci minimalnej.\n");
		} while (max <= 0 || max <= min);

		for (int i = 0; i < wielkosc; i = i + 1)
		{
			double szum_pomocniczy1;
			szum_pomocniczy1 = min + (rand() % (max - min + 1));	//wzór znaleziony w odch³ani internetu, oznacza losow¹ liczbê z danego zakresu
			double wlasciwy_szum1;
			wlasciwy_szum1 = wyniki[i] + szum_pomocniczy1;
			szum[i] = wlasciwy_szum1;								//tablica z wynikami szumu
		}
		printf("\nPokazujê wyniki po wygenerowaniu szumu: ");
		for (int i = 0; i < wielkosc; i = i + 1)					//wype³niamy tablicê wynikami
		{
			printf("%0.5lf;  ", szum[i]);							//do 5 miejsca po przecinku, %lf do double
		}
		break;
	}
	case 2:
	{
		printf("Wybór 2. Losowy szum bez okreœlania zakresu.");
		for (int i = 0; i < wielkosc; i = i + 1)
		{
			double szum_pomocniczy2;
			szum_pomocniczy2 = (rand() % 10) / 5.;					//losowy szum z zakresu od 1 do 10, podzielony przez 5, wybra³am taki, bo wychodzi³y liczby, które mia³y sens na wykresie
			double wlasciwy_szum2;
			wlasciwy_szum2 = wyniki[i] + szum_pomocniczy2;
			szum[i] = wlasciwy_szum2;								//tablica z wynikami szumu
		}
		printf("\nPokazujê wyniki po wygenerowaniu szumu: ");
		for (int i = 0; i < wielkosc; i = i + 1)					//wype³niamy tablicê wynikami
		{
			printf("%0.5lf;  ", szum[i]);							//do 5 miejsca po przecinku, %lf do double
		}
		break;
	}
	default:
	{
		printf("Niestety takiej liczby nie ma w menu wyboru. Proszê podaæ ponownie:\n");
		break;
	}
	}
}

void zapis_wynikow(double wyniki[], double szum[], int wielkosc)			//nazywam tak samo, jest mi ³atwiej
{
	int i;
	FILE* plik;																//utworzenie struktury FILE* (uchwytu, identyfikatora) pliku, do którego bêdziemy siê odwo³ywaæ
	plik = fopen("zapis_wynikow.csv", "w");									//nazwa pliku – tablica znaków char*; w tym miejscu mo¿na podaæ pe³n¹ œcie¿kê pliku lub sam¹ nazwê pliku -> wtedy lokalizuje tam, gdzie jest program
																			//tryb obs³ugi pliku - do wyboru jest kilka predefiniowanych trybów, na przyk³ad: "w" – otwiera / tworzy plik do zapisu, usuwa jego star¹ treœæ
	if (!plik)																//sprawdzamy czy plik istnieje
	{
		printf("B³¹d. Niestety nie uda³o siê otworzyæ tego pliku. Zapis pliku nie bêdzie mo¿liwy.\n");
	}

	else																	//jeœli istnieje to zapisujemy wartoœci tablicy wyników oraz tablicy wyników zaszumionych kolejno w komórkach Excela
	{
		for (i = 0; i < wielkosc; i++)
		{																	//%lf bo double
			fprintf(plik, " %lf ; %lf \n", wyniki[i], szum[i]);				//u¿ywa siê podobnie jak printf(), ró¿nic¹ jest koniecznoœæ przekazania uchwytu do pliku
		}																	//w kolejnych komorkach w excelu zapisane sa wartosci tablicy wynikow i wynikow zaszumionych
																			//œrednik to tzw. separator pola, oznacza to przejœcie do kolejnej komórki
																			//wiêc dane bêd¹ zapisywaæ siê obok siebie, jedna pod drug¹, jedna kolumna bêdzie dla wyników, druga dla wyników szumu
		fclose(plik);														//zamkniêcie pliku czyœci bufory danych powi¹zane z nim, zwalnia uchwyt oraz pozwala na otwieranie pliku na zewn¹trz lub jego usuniêcie;
		printf("Zaszumione wyniki zapisano do pliku.\n");					//zalecane jest zamykanie pliku za ka¿dym razem w przypadku nieprawid³owego zakoñczenia programu
	}
}

void odczyt_wynikow(double* wyniki, double* szum)							//nazywam argumenty tak samo jak w main
{																			//wskaŸniki, bo: Algorytm ma polegaæ na sprawdzaniu w pêtli czy plik siê nie skoñczy³ po przejœciu do ka¿dej linii.
																			//Jeœli nie, to tablice mog¹ zostaæ realokowane o 1 element a dane mog¹ zostaæ odczytane i wpisane do nich.
	FILE* plik;																//utworzenie struktury FILE* (uchwytu, identyfikatora) pliku, do którego bêdziemy siê odwo³ywaæ
	plik = fopen("zapis_wynikow.csv", "r");									//funkcja fopen() otwiera plik, którego nazwa podana jest w pierwszym argumencie, drugi argument "r" – otwiera plik do odczytu

	if (!plik)																//sprawdzamy, czy plik istnieje
	{
		printf("B³¹d. Niestety nie uda³o siê otworzyæ tego pliku. Zapis pliku nie bêdzie mo¿liwy.\n");
	}

	else
	{
		int n = 0;															//zdeklarowane przed pêtl¹
		while (fgetc(plik) != EOF)											//fgets zwraca znak z aktualnej pozycji w pliku i przestawia pozycjê o 1
		{																	//EOF oznacza koniec pliku (end of file)
			fseek(plik, -1, SEEK_CUR);										//sugestia z maila, aby nie by³o 0 na pocz¹tku kolejnych wersów; 
																			//przesuwa pozycjê w pliku o podan¹ liczbê znaków(int) (-1) wzglêdem aktualnego miejsca (SEEK_CUR)
			fscanf(plik, " %lf ; %lf \n", &wyniki[n], &szum[n]);			//odczytujemy komórki, które by³y zapisane w pliku
			printf(" %lf ; %lf \n", wyniki[n], szum[n]);					//tu drukujemy uzyskane wyniki w programie

			n++;															//a pêtla leci dalej
		}

		fclose(plik);														//zamkniêcie pliku, wyjaœnione czemu w funkcji zapis_wynikow
	}
}

void filtr_sredniej_ruchomej(double* szum, double* odszumienie, int wielkosc) //wskaŸniki, bo to tablice
{
	double pomocnicza[5];					//pomocnicza tablica w ktorej zapisywane sa dane probki
	odszumienie[0] = szum[0];				//przepisanie dwóch pierwszych i ostatnich wyrazów tabeli do tabeli odszumionych danych
	odszumienie[1] = szum[1];
	odszumienie[wielkosc - 1] = szum[wielkosc - 1];
	odszumienie[wielkosc - 2] = szum[wielkosc - 2];

	printf("\nPokazujê wyniki po odszumieniu sygna³u:  ");
	printf("%0.5lf; ", odszumienie[0]);			//do 5 miejsca po przecinku, %lf do double
	printf("%0.5lf; ", odszumienie[1]);
	
	for (int j = 2; j < wielkosc - 2; j = j + 1)  //pêtla s³u¿¹ca do wype³nienia wszystkich innych danych wiêkszych od/równych 2 i mniejszych od wielkosc - 2, bo te ju¿ mamy wy¿ej
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

void filtr_medianowy(double* szum, double* odszumienie, int wielkosc) //argumenty nazywam tak samo, ³atwiej mi siê po³apaæ
{
	double temp;				//pomocnicza zmienna
	int szerokosc_okna = 5;
	double pomocnicza[5];		//pomocnicza tablica w ktorej zapisywane sa dane probki
	odszumienie[0] = szum[0];	//przepisanie dwóch pierwszych i ostatnich wyrazów tabeli do tabeli odszumionych danych
	odszumienie[1] = szum[1];
	odszumienie[wielkosc - 1] = szum[wielkosc - 1];
	odszumienie[wielkosc - 2] = szum[wielkosc - 2];

	printf("\nPokazujê wyniki po odszumieniu sygna³u:  ");
	printf("%0.5lf; ", odszumienie[0]);			//do 5 miejsca po przecinku, %lf do double
	printf("%0.5lf; ", odszumienie[1]);

	for (int j = 2; j < wielkosc - 2; j = j + 1)	//pêtla s³u¿¹ca do wygenerowania wszystkich innych danych wiêkszych od/równych 2 i mniejszych od wielkosc - 2, bo te ju¿ mamy wy¿ej
	{
		pomocnicza[0] = szum[j - 2];				//dwie poprzednie liczby i dwie kolejne
		pomocnicza[1] = szum[j - 1];
		pomocnicza[2] = szum[j];
		pomocnicza[3] = szum[j + 1];
		pomocnicza[4] = szum[j + 2];
		do														//sortowanie b¹belkowe, sposób wykonania znaleziony w internecie
		{
			for (int i = 0; i < szerokosc_okna - 1; i = i + 1)  //szerokosc_okna - 1, bo szerokoœæ okna to 5, a tablice liczymy od wartoœci na miejscu 0
			{
				if (pomocnicza[i] > pomocnicza[i + 1])			//sortowanie, jeœli wartoœæ np. próbki 1 jest wiêksza od wartoœci próbki 2 to zamiana wartoœci
				{
					temp = pomocnicza[i + 1];
					pomocnicza[i + 1] = pomocnicza[i];
					pomocnicza[i] = temp;
				}
			}
			szerokosc_okna = szerokosc_okna - 1;			//zmniejszamy szerokoœæ okna, ¿eby zawêziæ te poszukiwania, program wykonuje pêtle dalej
		} while (szerokosc_okna > 1);						//wykonuj, a¿ szerokoœæ okna nie bêdzie równa 1, bo o to nam chodzi
		
		odszumienie[j] = pomocnicza[2];						//2 to wyraz œrodkowy
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
	double min = 0, max = 0;						//musimy zainicjowaæ te wartoœci, aby póŸniej je przekazaæ do funkcji
	int i, wielkosc;
	int sprawdzenie = 0;							//ograniczenie: ta liczba jest po to, ¿eby móc sprawdziæ co mo¿na zrobiæ w programie, przyk³adowo nie mo¿na uruchomiæ opcji szumu na sygnale, jeœli nie mamy sygna³u
	srand(time(NULL));

	double *wyniki;									//tablica wyniki + ni¿ej jej rozmiar, tak mo¿na robiæ zamiast double wyniki[1];
	wyniki = malloc(1 * sizeof(double));			//przydzia³ pamieci w bajtach
	if (wyniki == NULL)								//zabezpieczenie przed utrat¹ danych i wyciekiem pamiêci, szczególnie wa¿ne to bêdzie przy funkcji realloc()
	{
		printf("B³¹d alokacji, przerwanie dzia³ania.\n");
		return 1;
	}

	double *szum;						//tu zrobi³am to samo co wy¿ej
	szum = malloc(1 * sizeof(double));	//przydzia³ pamiêci w bajtach, ta tablica równie¿ powiêksza siê w zale¿noœci od wprowadzonego rozmiaru tablicy przez u¿ytkownika
	if (szum == NULL)
	{
		printf("B³¹d alokacji, przerwanie dzia³ania.\n");
		return 1;
	}

	double *odszumienie;				//to samo co wy¿ej
	odszumienie = malloc(1 * sizeof(double));
	if (odszumienie == NULL)
	{
		printf("B³¹d alokacji, przerwanie dzia³ania.\n");
		return 1;
	}

	setlocale(LC_ALL, "polish_poland"); //aby da³o siê odczytaæ wyniki z Excela (przecinki zamiast kropek) oraz do polskich znaków w programie, znalezione w instrukcji 2
										
	int wybor_uzytkownika;
	do
	{
		printf("				MENU WYBORU\nProszê wybraæ jedn¹ z poni¿szych opcji i zatwierdziæ klawiszem enter:\n");
		printf("1. Generacja funkcji.\n2. Generacja szumu funkcji.\n3. Zapisanie do pliku.\n4. Odczyt z pliku.\n5. Wyprostowanie zaszumionego sygna³u.\n6. Zakoñczenie pracy w programie.\n"); //menu
		//zabezpieczenie przed wprowadzeniem liter i znaków
		do
		{
			char napis[20];
			scanf("%s", &napis);
			int n = strlen(napis);
			wybor_uzytkownika = czy_liczba_int(napis, n);
			if (wybor_uzytkownika <= 0)
				printf("Proszê podaæ liczbê z menu od 1 do 6.\n");
		} while (wybor_uzytkownika <= 0);
		
		switch (wybor_uzytkownika)
		{
		case 1:
		{
			printf("Wybór: 1. Generacja funkcji.\n");
			wielkosc = wielkosc_tablicy();										//wywo³ujemy funkcjê wielkosc_tablicy()
			double* wyniki_tymczasowe;
			wyniki_tymczasowe = realloc(wyniki, wielkosc * sizeof(double));		//nowy przydzia³ pamiêci, powiêksza siê obszar tablicy, pierwszy parametr to adres pocz¹tku tablicy utworzonej za pomoc¹ funkcji malloc(), drugi to nowy rozmiar pamiêci w bajtach
			if (wyniki_tymczasowe != NULL)										//bardzo wa¿ne zabezpieczenie przed utrat¹ danych
			{
				wyniki = wyniki_tymczasowe;
			}
			else
			{
				printf("Nie uda³o siê powiêkszyæ tablicy.\n");
				wyniki = malloc(1 * sizeof(double));							//nie uda³o siê powiêkszyæ, a wiêc tablica ma jeden element
			}

			generuj_funkcje(wspolczynniki, min, max, wyniki, wielkosc);			//wywo³ujemy funkcjê generuj_funkcje()
			printf("\nPokazujê wyniki:  ");										//wype³niamy tabelê wyników
			for (i = 0; i < wielkosc; i = i + 1)
			{
				printf("%0.5lf; ", wyniki[i]);	//wydruk wyników do 5 miejsca po przecinku, mo¿na dowolnie zmieniaæ
			}
			sprawdzenie = 1;					//ta liczba jest po to, ¿eby móc sprawdziæ co mo¿na zrobiæ w programie, przyk³adowo nie mo¿na uruchomiæ opcji szumu na sygnale, jeœli nie mamy sygna³u
			break;
		}
		case 2:
		{
			printf("Wybór: 2. Generacja szumu funkcji.\n");
			if (sprawdzenie >= 1)								//ten wybór mo¿e siê dokonaæ tylko gdy sprawdzenie bêdzie > lub = 1, tylko wtedy mamy pewnoœæ, ¿e istnieje wygenerowana funkcja
			{													//nowy przydzia³ pamiêci, powiêksza siê obszar tablicy, jak w case 1
				double* szum_tymczasowy;
				szum_tymczasowy = realloc(szum, wielkosc * sizeof(double));		//nowy przydzia³ pamiêci, powiêksza siê obszar tablicy, pierwszy parametr to adres pocz¹tku tablicy utworzonej za pomoc¹ funkcji malloc(), drugi to nowy rozmiar pamiêci w bajtach
				if (szum_tymczasowy != NULL)									//bardzo wa¿ne zabezpieczenie przed utrat¹ danych
				{
					szum = szum_tymczasowy;
				}
				else
				{
					printf("Nie uda³o siê powiêkszyæ tablicy.\n");
					szum = malloc(1 * sizeof(double));
				}
				generuj_szum(wyniki, szum, wielkosc);			//wywo³ujemy funkcjê generuj_szum
				sprawdzenie = 2;								//to oznacza, ¿e program mo¿e teraz odszumiaæ wyniki, zapisywaæ je itp.
				break;
			}
			else
			{
				printf("Nie wygenerowano funkcji, proszê wybraæ opcjê 1.\n");
				break;
			}
		}
		case 3:
		{
			printf("Wybór: 3. Zapisanie do pliku.\n");
			if (sprawdzenie >= 2)						//bêdzie dzia³aæ tylko, gdy wczeœniej funkcja zosta³a zaszumiona
			{
				zapis_wynikow(wyniki, szum, wielkosc);
				sprawdzenie = 3;
				break;
			}
			else
			{
				printf("Nie wygenerowano funkcji, proszê wybraæ opcjê 1.\n");
				break;
			}
		}

		case 4:
		{
			printf("Wybór: 4. Odczytanie z pliku.\n");
			if (sprawdzenie == 3)						//zadzia³a tylko, gdy mamy ju¿ wczeœniej utworzony plik
			{
				odczyt_wynikow(wyniki, szum);
				break;
			}
			else
			{
				printf("Nie zapisano ¿adnego pliku, proszê najpierw wybraæ opcjê 3.\n");
				break;
			}
		}
		
		case 5:
		{
			printf("Wybór: 5. Odszumianie wyników.\n");
			if (sprawdzenie >= 2)						//ten wybór mo¿e siê dokonaæ tylko gdy sprawdzenie bêdzie > lub = 2, tylko wtedy mamy pewnoœæ, ¿e istnieje wygenerowana funkcja i szum do niej
			{

				double* odszumienie_tymczasowe;
				odszumienie_tymczasowe = realloc(odszumienie, wielkosc * sizeof(double));		//nowy przydzia³ pamiêci, powiêksza siê obszar tablicy, pierwszy parametr to adres pocz¹tku tablicy utworzonej za pomoc¹ funkcji malloc(), drugi to nowy rozmiar pamiêci w bajtach
				if (odszumienie_tymczasowe != NULL)												//bardzo wa¿ne zabezpieczenie przed utrat¹ danych
				{
					odszumienie = odszumienie_tymczasowe;
				}
				else
				{
					printf("Nie uda³o siê powiêkszyæ tablicy.\n");
					odszumienie = malloc(1 * sizeof(double));
				}

				int wybor;
				printf("\nProszê wybraæ liczbê z menu:\n1. Filtr medianowy.\n2. Filtr œredniej ruchomej.\n");
				do
				{
					char napis[20];
					scanf("%s", &napis);
					int n = strlen(napis);
					wybor = czy_liczba_int(napis, n);
					if (wybor <= 0)
						printf("To nie liczba. Proszê podaæ liczbê z menu od 1 do 2.\n");
				} while (wybor <= 0);

				switch (wybor)
				{
				case 1:
				{
					printf("Wybór 1. Filtr medianowy.\n");
					filtr_medianowy(szum, odszumienie, wielkosc);				//wywo³anie funkcji 
					break;
				}
				case 2:
				{
					printf("Wybór 2. Filtr œredniej ruchomej.\n");
					filtr_sredniej_ruchomej(szum, odszumienie, wielkosc);		//wywo³anie funkcji
					break;
				}
				}
				break;
			}

			else
			{
				printf("Nie wygenerowano funkcji, proszê wybraæ opcjê 1.\n");
				break;
			}
		}

		case 6:
		{
				printf("Wybór: 6. Zakoñczenie pracy w programie.\n");
				sprawdzenie = 6;				//tu musi byæ w ten sposób, bo dopiero wtedy przerywamy pêtlê do...while
				break;
		}

		default:								//oznacza blok instrukcji wykonywany dla wszystkich pozosta³ych wartoœci zmiennej
		{
				printf("Niestety takiej liczby nie ma w menu wyboru. Proszê podaæ ponownie:\n");
		}
		}
		printf("\n");								//nowa linia
	} while (sprawdzenie != 6);						//menu bêdzie wyœwietlane do momentu wyboru numeru 6 - zakoñczenia pracy programu

	free(wyniki);									//jest to uwolnienie zaalokowanej pamieci, trzeba zwolniæ, ¿eby móc kiedyœ u¿yæ j¹ do czegoœ innego
	free(szum);										//trzeba to zrobiæ, poniewa¿ jeœli kod programu w jakikolwiek sposób powoduje wycieki pamiêci, jest kodem b³êdnym
	free(odszumienie);

	return 0;
}