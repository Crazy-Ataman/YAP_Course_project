#pragma once
#include "LT.h"
#define ID_MAXSIZE		10
#define IT_MAXSIZE		4096
#define IT_INT_DEFAULT	0x00000000
#define IT_STR_DEFAULT	0x00
#define IT_NULLIDX		0xffffffff
#define IT_STR_MAXSIZE	255

namespace IT
{
	enum IDDATATYPE { UINT = 1, STR = 2};
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, OP = 5 };	// типы идентификаторов: переменная/функция/параметр/литерал/оператор

	struct Entry	// строка таблицы идентификаторов
	{
		int			idxfirstLE;		// индекс в таблице лексем
		char		id[ID_MAXSIZE];	// идентификатор (автоматически усекается до ID_MAXSIZE)
		IDDATATYPE	iddatatype;		// тип данных
		IDTYPE		idtype;			// тип идентификатора

		int			numbersystem;	// система счисления
		int			parmsamount;	// для вызовов: количество параметров

		int			index;					// глубина вхождения 
		char		function[ID_MAXSIZE];	// функция, которой принадлежит

		struct		// 
		{
			unsigned int vuint = 0;					// значение unsigned integer
			struct
			{
				int len;						// количество символов в string
				char str[IT_STR_MAXSIZE - 1]{};	// символы string
			}vstr;								// значение string
		}value;		// значение идентификатора
	};

	struct IdTable	// экземпляр таблицы идентификаторов
	{
		int			maxsize;		// емкость таблицы < TI_MAXSIZE
		int			size;			// текущий размер таблицы идентификаторов < maxsize
		Entry* table;			// массив строк таблицы идентификаторов
	};

	IdTable Create(					// создание таблицы идентификаторов
		int size					// предполагаемая емкость таблицы < TI_MAXSIZE
	);

	void Add(
		IdTable& idtable,			// экземпляр таблицы идентификаторов
		Entry entry					// добавляемая строка таблицы идентификаторов
	);

	Entry GetEntry(					// получение строки таблицы идентификаторов
		IdTable& idtable,			// экземпляр таблицы идентификаторов
		int n						// номер получаемой строки
	);

	int IsId(						// возврат номера строки (если нет - TI_NULLIDX)
		IdTable& idtable,			// экземпляр таблицы идентификаторов
		char id[ID_MAXSIZE]			// идентификатор
	);

	void Delete(					// удаление таблицы идентификаторов (освобождение памяти) 
		IdTable& idtable			// экземпляр таблицы идентификаторов
	);

	void ShowTable(
		IdTable idt,
		std::ostream& stream_out
	);
};
