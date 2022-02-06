#include "IT.h"
#include "FST.h"
#include "Error.h"

namespace IT {


	IdTable Create(int size)
	{
		IdTable* table = new IdTable;
		if (size < IT_MAXSIZE) throw ERROR_THROW(203);
		table->maxsize = size;
		table->size = 0;
		table->table = new Entry[size];
		return *table;
	}

	void Add(IdTable& idt, Entry entry)
	{
		if (idt.size + 1 > idt.maxsize) throw ERROR_THROW(204);

		idt.table[idt.size] = entry;
		idt.size++;
	}


	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])
	{
		for (int i = 0; i < idtable.size; i++) 
		{
			if (strcmp(idtable.table[i].id, id) == 0) 
				return i;
		}

		return IT_NULLIDX;
	}

	void Delete(IdTable& idtable)
	{
		delete[] idtable.table;
	}

	void ShowTable(IdTable idt, std::ostream& stream_out)
	{
		int i, j, numberOP = 0;
		stream_out << "\n";
		stream_out << std::setfill('-') << std::setw(87) << '-' << std::endl;
		stream_out << "   #" << " | " << "Идентификатор" << " | " << "Тип данных" << " | " << "Тип идентификатора"
			<< " | " << "Индекс в ТЛ" << " | " << "Значение" << std::endl;
		stream_out << std::setw(87) << '-' << std::endl;

		for (i = 0, j = 0; i < idt.size; i++, j++) {
			stream_out << std::setfill('0') << std::setw(4) << std::right << j << " | ";
			stream_out << std::setfill(' ') << std::setw(13) << std::left << idt.table[i].id << " | ";

			if (idt.table[i].idtype == IT::OP) stream_out << std::setw(10) << std::left << "-" << " | ";
			else 
			{
				switch (idt.table[i].iddatatype) 
				{
				case STR:
					stream_out << std::setw(10) << std::left;
					stream_out << "str" << " | ";
					break;
				case UINT:
					stream_out << std::setw(10) << std::left;
					stream_out << "uint" << " | ";
					break;
				default:
					stream_out << std::setw(10) << std::left << "unknown" << " | ";
					break;
				}
			}

			switch (idt.table[i].idtype) {
			case V: stream_out << std::setw(18) << std::left << "переменная" << " | "; break;
			case F: stream_out << std::setw(18) << std::left << "функция" << " | "; break;
			case P: stream_out << std::setw(18) << std::left << "параметр" << " | "; break;
			case L: stream_out << std::setw(18) << std::left << "литерал" << " | "; break;
			case OP:
				stream_out << std::setw(18) << std::left << "оператор" << " | ";
				numberOP++;
				break;
			default: stream_out << std::setw(18) << std::left << "unknown" << " | "; break;
			}
			stream_out << std::setw(11) << std::left << idt.table[i].idxfirstLE << " | ";

			if (idt.table[i].iddatatype == UINT && (idt.table[i].idtype == V || idt.table[i].idtype == L))
				stream_out << std::setw(18) << std::left << idt.table[i].value.vuint;
			else if (idt.table[i].iddatatype == STR && (idt.table[i].idtype == V || idt.table[i].idtype == L))
				stream_out << "[" << idt.table[i].value.vstr.len << "]\"" << idt.table[i].value.vstr.str << "\"";
			else stream_out << "-";
			stream_out << std::endl;
		}

		stream_out << std::setfill('-') << std::setw(87) << "-" << std::endl;
		stream_out << "Количество идентификаторов: " << i << std::endl;
		stream_out << std::setw(87) << "-" << std::endl;

		
	}
}