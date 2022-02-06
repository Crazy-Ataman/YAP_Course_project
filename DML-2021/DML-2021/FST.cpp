#include "FST.h"

namespace FST {

	RELATION::RELATION(char c, short nn)
	{
		symbol = c;					// символ перехода
		nnode = nn;					// номер смежной вершины
	};

	NODE::NODE() {
		n_relation = 0;				// количество инциндентных ребер
		RELATION* relations = NULL;	// инцидентные ребра
	};

	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION* p = &rel;
		relations = new RELATION[n];
		for (int i = 0; i < n; i++)
			relations[i] = p[i];
	};

	FST::FST(char* s, short ns, NODE n, ...)
	{
		string = s;					// цепочка (строка, завршатся 0x00 )
		nstates = ns;				// количество состояний автомата
		nodes = new NODE[ns];		// граф переходов: [0] - начальное состояние, [nstate-1] - конечное 
		NODE* p = &n;
		for (int i = 0; i < ns; i++)
			nodes[i] = p[i];
		rstates = new short[nstates];// возможные состояния автомата на данной позиции
		memset(rstates, 0xff, sizeof(short) * nstates);// заполняет массив нулями
		rstates[0] = 0;
		position = -1;				// текущая позиция в цепочке
	}

	bool step(FST& fst, short*& rstates)
	{
		bool rc = false;
		std::swap(rstates, fst.rstates);
		for (short i = 0; i < fst.nstates; i++)
		{
			if (rstates[i] == fst.position)
				for (int j = 0; j < fst.nodes[i].n_relation; j++)
				{
					if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
					{
						fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
						rc = true;
					}
				};
		};
		return rc;
	};

	bool execute(FST fst)
	{
		short* rstates = new short[fst.nstates];			// массив размера nstates
		memset(rstates, 0xff, sizeof(short) * fst.nstates);	// заполняется нулями
		short lstring = strlen(fst.string);

		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}
		delete[] rstates;

		return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	};
}




