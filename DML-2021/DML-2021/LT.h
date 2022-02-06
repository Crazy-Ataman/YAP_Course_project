#pragma once
#include "In.h"
#include "Error.h"
#include "Parm.h"
#include <fstream>
#define LEXEMA_FIXSIZE	1
#define LT_MAXSIZE		4096
#define LT_TI_NULLIDX	0xffffffff

#define LEX_UINT		't' // uint
#define LEX_STR			't' // str

#define LEX_ID			'i' // identificator
#define LEX_LITERAL		'l' // literal
#define LEX_FUNCTION	'f' // function

#define LEX_MAIN		'm' // main
#define LEX_VAR			'd' // var
#define LEX_RET			'r' // ret
#define LEX_PRINT		'p' // print

#define LEX_IF			'?' // if
#define LEX_ELSE		'e' // else

#define LEX_SEMICOLON	';'	// ;
#define LEX_COMMA		',' // ,
#define LEX_LEFTBRACE	'{' // {
#define LEX_BRACELET	'}' // }
#define LEX_LEFTHESIS	'(' // (
#define LEX_RIGHTHESIS	')' // )
#define LEX_EQUAL		'=' // =

#define LEX_MORE		'v' // >
#define LEX_LESS		'v' // <
#define	LEX_EQMORE		'v' // ^
#define LEX_EQLESS		'v' // :
#define LEX_EQUALS		'v' // &
#define LEX_NEQUALS		'v' // !

#define LEX_PLUS		'v' // +
#define LEX_MINUS		'v' // -
#define LEX_STAR		'v' // *
#define LEX_DIRSLASH	'v' // /

#define LEX_OPERATOR	'v'

namespace LT		// таблица лексем
{
	enum operations {
		OPLUS = 1,
		OMINUS,
		OMUL,
		ODIV,
		OMORE,
		OLESS,
		OMOREEQ,
		OLESSEQ,
		OEQUALS,
		ONOTEQUALS
	};

	struct Entry	// строка таблицы лексем
	{
		char			lexema;					// лексема
		int				sn;						// номер строки в исходном тексте
		int				idxTI;					// индекс в таблице идентификаторов (или LT_TI_NULLIDX)
		int				priority;
		operations		op;
	};

	struct LexTable // экземпл€р таблицы лексем
	{
		int		maxsize;				// емкость таблица лексем < LT_MAXSIZE
		int		size;					// текущий размер таблица лексем < maxsize
		Entry* table;					// массив строк таблицы лексем
	};

	LexTable Create(					// создание таблица лексем
		int size						// предполагаема€ емкость таблицы лексем < LT_MAXSIZE
	);

	void Add(							// добавление строки в таблицу лексем
		LexTable& lextable,				// экземпл€р таблица лексем
		Entry entry						// строка дл€ добавлени€ в таблицу лексем
	);

	Entry GetEntry(						// получение строки из таблицы лексем
		LexTable& lextable,				// экземпл€р таблицы лексем
		int n							// строка таблицы лексем
	);

	void Delete(						// удаление таблицы лексем (освобождение пам€ти)
		LexTable& lextable				// экземпл€р таблицы лексем
	);

	Entry WriteEntry(Entry& entry, char lexema, int indx, int line);

	void ShowTable(LexTable lextable, std::ostream& stream_out);
}
