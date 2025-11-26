#include "ScalarConverter.hpp"

std::string trim(char *s)
{
	if(!s)
		return(NULL);
	int start = 0;
	int end = 0;
	int len = 0;
	int i = 0;

	while(s[end])
		end++;
	if (end == 0)
		return(NULL);
	end -= 1;
	while(s[end] == 32)
		end--;
	while(s[start] == 32)
		start++;
	if (start > end)
		return(NULL);
	len = end - start + 1;
	std::string st(len, ' ');
	while(i < len)
	{
		st[i] = s[start + i];
		i++;
	}
	return(st);
}

int	checker(std::string s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf"
		|| s == "+inff" || s == "-inff")
		return(1);
	else
		return(0);
}


// Schemat parsera scalar convertera
// Trim
// Usuń spacje z początku i końca stringa.
// Jeśli po trimie string jest pusty → konwersja niemożliwa.
// Checker pseudo-literals
// Sprawdź, czy string to nan, nanf, +inf, -inf, +inff, -inff.
// Jeśli tak → możesz od razu zwrócić wynik jako float/double.
// Sprawdzenie znaków w stringu
// Jeśli string ma spacje w środku → konwersja niemożliwa.
// Sprawdź, czy są tylko dozwolone znaki:
// cyfry 0-9
// kropka . (dla float/double)
// literka f na końcu (dla float)
// opcjonalny znak + lub - na początku
// Rozpoznanie typu literal
// char → długość = 1 i znak nie jest cyfrą
// int  same cyfry, ewentualnie +/- na początku
// float → cyfry + kropka + końcówka f
// double → cyfry + kropka, bez f
// Konwersja i castowanie
// Mając rozpoznany typ podstawowy, możesz przekonwertować na wszystkie inne typy (char, int, float, double) i przygotować do wyświetlenia.
// Wyświetlanie
// Zwracasz lub wyświetlasz wynik w odpowiednich formatach.
// Jeśli konwersja niemożliwa → komunikat typu „impossible” lub „non displayable” dla char.