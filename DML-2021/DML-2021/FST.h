#pragma once
#include "Main.h"
#include "Error.h"

namespace FST {

	struct RELATION {			// ребро:символ -> вершина графа переходов КА
		char symbol;			// символ перехода
		short nnode;			// номер смежной вершины
		RELATION(
			char c = 0x00,		// символ перехода 
			short ns = NULL		// новое состояние
		);
	};

	struct NODE {				// вершина графа переходов
		short n_relation;		// количество инциндентных ребер
		RELATION* relations;	// инцидентные ребра
		NODE();
		NODE(
			short n,			// количество инциндентных ребер
			RELATION rel, ...	// список ребер
		);
	};


	struct FST {
		const char* string;		// цепочка
		short position;			// текущая позиция в цепочке
		short nstates;			// количество состояний автомата
		NODE* nodes;			// граф переходов: [0] - начальное состояние, [nstate-1] - конечное состояние
		short* rstates;			// возможные состояния на данной позиции
		FST(
			char* s,
			short ns,
			NODE n, ...
		);
	};

	bool step(FST& fst, short*& rstates);

	bool execute(				// выполнить распознавание цепочки
		FST fst				// недетерминированный конечный автомат
	);
}