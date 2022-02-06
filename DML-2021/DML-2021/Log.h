#pragma once
#pragma warning(disable : 4996)
#include "Main.h"
#include "Error.h"
#include <fstream>
#include "Parm.h"
#include "In.h"
#include "LT.h"
#include "IT.h"
#define TEMPSIZE 100


namespace Log
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];
		std::ofstream* stream;						// потоковый вывод ofstream из <fstream>
	};

	static const LOG INITLOG = { L"", NULL };		// инициализаци€ LOG
	LOG	 getlog(wchar_t logfile[]);					// формирование структуры
	void WriteLine(LOG log, const wchar_t* c, ...); // вывод конкатенации строк
	void WriteLine(LOG log, const char* c, ...);	// вывод конкатенации строк
	void WriteLog(LOG log);							// вывод заголовка
	void WriteParm(LOG log, Parm::PARM parm);		// информаци€ о входных параметрах
	void WriteIn(LOG log, In::IN in);				// информаци€ о входном потоке
	void WriteError(LOG log, Error::ERROR error);	// протокол об ошибке
	void Close(LOG log);							// закрытие потока
	void WriteLex(LOG log, LT::LexTable lex, Parm::PARM parm);
	void WriteIT(LOG log, IT::IdTable idt, Parm::PARM parm);
	void WriteLexTableLog(LT::LexTable& lextable, std::ostream& out);
}
