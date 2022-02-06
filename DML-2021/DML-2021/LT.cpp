#include "LT.h"
#include "FST.h"
#include "Error.h"
#include "Log.h"
#include "IT.h"
#include "Graphs.h"
#include "LexParsing.h"


namespace LT {

	LexTable Create(int size)
	{
		LexTable* table = new LexTable;
		if (size > LT_MAXSIZE) 
			throw ERROR_THROW(201);
		table->maxsize = size;
		table->size = 0;
		table->table = new Entry[size];
	}

	void Add(LexTable& lex, Entry entry)
	{
		if (lex.size == lex.maxsize) 
			throw ERROR_THROW(202);
		lex.table[lex.size] = entry;
		lex.size++;
	}

	Entry GetEntry(LexTable& lex, int n)
	{
		return lex.table[n];
	}

	void Delete(LexTable& lex)
	{
		delete[] lex.table;
	}

	Entry WriteEntry(Entry& entry, char lexema, int indx, int line) {
		entry.lexema = lexema;
		entry.idxTI = indx;
		entry.sn = line;
		return entry;
	}

	void ShowTable(LexTable lextable, std::ostream& stream_out) {
		int line = 2;
		stream_out << "\n\t\tПромежуточное представление\n";
		stream_out << "0001| ";
		for (int i = 0; i < lextable.size; i++) {
			if (lextable.table[i].lexema == ';') {
				stream_out << lextable.table[i].lexema << std::endl;
				if (i + 1 == lextable.size) break;
				line > 999 ? stream_out << line << "| " : line > 99 ? stream_out << "0" << line << "| " : line > 9 ? stream_out << "00" << line <<
					"| " : stream_out << "000" << line << "| ";
				line++;
			}
			else stream_out << lextable.table[i].lexema;
		}
	}
}