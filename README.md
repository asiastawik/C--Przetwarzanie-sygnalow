# Projekt: Przetwarzanie Sygnałów

## Opis Projektu

Celem projektu jest napisanie programu w języku C, który realizuje różne operacje na sygnałach matematycznych, takie jak generowanie, zaszumianie, filtrowanie i zapisywanie sygnału. Program zawiera funkcje do dynamicznego zarządzania tablicami sygnałów oraz obsługę plików CSV.

### Funkcjonalności programu:
1. **Generowanie przebiegu funkcji matematycznej**:
   - Funkcja przyjmuje jako parametry tablicę współczynników funkcji, zakres dziedziny, tablicę wynikową i jej wielkość.
   - Dla ambitnych: Generowanie funkcji piłokształtnej lub trójkątnej.

2. **Wczytywanie współczynników funkcji**:
   - Funkcja wczytuje współczynniki funkcji z konsoli i zapisuje je w tablicy.

3. **Wczytywanie zakresu dziedziny**:
   - Funkcja przyjmuje zakres dziedziny (min i max) jako dane wejściowe od użytkownika.

4. **Generowanie losowego szumu**:
   - Funkcja dodaje losowy szum do sygnału i zapisuje zaszumiony sygnał w osobnej tablicy.
   - Szum może być generowany z określoną amplitudą i prawdopodobieństwem.

5. **Zapis sygnału do pliku CSV**:
   - Funkcja zapisuje wartości tablicy (sygnał podstawowy, zaszumiony i odfiltrowany) do pliku CSV, który można otworzyć w arkuszu kalkulacyjnym.

6. **Wczytywanie rozmiaru tablicy wynikowej**:
   - Funkcja pobiera od użytkownika rozmiar tablicy wynikowej.

7. **Dynamiczna alokacja pamięci**:
   - Program dynamicznie alokuje pamięć dla tablicy wynikowej przy użyciu funkcji `malloc()` lub `calloc()`.

8. **Odczyt sygnału z pliku CSV**:
   - Funkcja odczytuje sygnał z pliku CSV.
   - Dla ambitnych: Użycie funkcji `realloc()` bez konieczności znajomości długości pliku.

9. **Filtrowanie sygnału z szumu**:
   - Program implementuje filtr medianowy oraz filtr średniej ruchomej do odfiltrowania szumu z sygnału.
   - Dla ambitnych: możliwość definiowania szerokości okna filtra.

10. **Zabezpieczenie przed błędnym wprowadzaniem danych**:
    - Program sprawdza poprawność danych wejściowych, takich jak zakres dziedziny i rozmiar tablic.

11. **Menu użytkownika**:
    - Program oferuje menu, które umożliwia generowanie sygnału, zaszumianie, filtrowanie oraz zapisywanie sygnałów w pliku CSV.
