#include "Split.h"

char** splitText(char origin[], int size) { // Создаем массив строк, состоящий из лексем.
	char** words = new char* [max_word];
	for (int i = 0; i < max_word; i++)
		words[i] = new char[size_word] {NULL}; // Заполнение массив нулями.
	bool findSepSymb, findLiteral = false;
	int j = 0;
	char sepSymbArr[] = { " ,;(){}=+-*/|" };	// Массив символов сепараторов.
	for (int i = 0, k = 0; i < size - 1; i++, k++) {//sepSymbArr[t] == ' ' => true => k=-1+1=0
		findSepSymb = false;					// Флаг на нахождение апострафа.
		if (origin[i] == '\'')
			findLiteral = !findLiteral;		// Нашли кавычку, меняем значение на противоположное.
		for (int t = 0; t < sizeof(sepSymbArr) - 1; t++) 
		{
			if (origin[i] == sepSymbArr[t] && !findLiteral) { // findLiteral = false
				findSepSymb = true;			// Нашли сепаратор, меняем значение.
				if (words[j][0] != NULL) 
				{
					words[j++][k] = '\0';		// Переход на новую строку.
					k = 0;
				}
				if (sepSymbArr[t] == ' ')		// Пробелы пропускаем!
				{	
					k = -1;
					break;
				}
				words[j][k++] = sepSymbArr[t];// Не пробелы записываем.
				words[j++][k] = '\0';
				k = -1;
				break;
			}
		}
		if (!findSepSymb)
			words[j][k] = origin[i];
	}
	words[j] = NULL;
	for (int i = 0; i < j; i++)
		if (!strcmp((char*)words[i], ""))	// strcmp - осуществляет лексикографическую проверку двух строк.
			return NULL;					// strcmp - возвращает число, на сколько различаются.
	return words;
}

void cleanup(char source[], int size, Log::LOG logfile) {
	char Separators[] = { " ,;(){}=+-*/|" };
	bool findLiteral = false;
	int count = NULL;

	for (int i = 0; i < size; i++) {
		if (source[i] == '\'') {
			findLiteral = !findLiteral;
			count++;
		}

		if ((source[i] == ' ' || source[i] == '\t') && !findLiteral) 
		{
			for (int j = 0; j < sizeof(Separators) - 1; j++) 
			{
				if (source[i + 1] == Separators[j] || source[i - 1] == Separators[j] || i == 0) 
				{
					for (int k = i; k < size; k++) 
					{
						source[k] = source[k + 1];
					}
					i--;
					break;
				}
			}
		}
	}

	if (count % 2 != 0)
		Log::WriteError(logfile, Error::geterror(300));
}