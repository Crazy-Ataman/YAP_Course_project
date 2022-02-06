#pragma once
#include "Main.h"
#include "GRB.h"
#include "LT.h"
#include "LexParsing.h"
#include "Log.h"

class my_stack_SHORT :public std::stack<short> {	// стек автомата
public:
	using std::stack<short>::c;
};

#define MFST_DIAGN_MAXSIZE 2*ERROR_MAXSIZE_MESSAGE
#define MFST_DIAGN_NUMBER 3
static int FST_TRACE_n = -1;
static char rbuf[205], sbuf[205], lbuf[1024];

#define MFST_TRACE_START	stream_out << std::setw(4) << std::left << "Шаг" << ": "\
							<< std::setw(30) << std::left << "Правило"\
							<< std::setw(30) << std::left << "Входная лента"\
							<< std::setw(20) << std::left << "Стек"\
							<< std::endl;

#define MFST_TRACE1			stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": " \
							<< std::setw(30) << std::left << rule.getCRule(rbuf, nrulechain)\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE2			stream_out << std::setw(4) << std::left << FST_TRACE_n << ": "\
							<< std::setw(30) << std::left << " "\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE3			stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": "\
							<< std::setw(30) << std::left << " "\
							<< std::setw(30) << std::left << getCLenta(lbuf, lenta_position)\
							<< std::setw(20) << std::left << getCSt(sbuf)\
							<< std::endl;

#define MFST_TRACE4(c)		stream_out << std::setw(4) << std::left << ++FST_TRACE_n << ": " << std::setw(20) << std::left << c << std::endl;
#define MFST_TRACE5(c)		stream_out << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << std::endl;
#define MFST_TRACE6(c, k)	stream_out << std::setw(4) << std::left << FST_TRACE_n << ": " << std::setw(20) << std::left << c << k << std::endl;
#define MFST_TRACE7			stream_out << std::setw(4) << std::left << state.lenta_position << ": "\
							<< std::setw(20) << std::left << rule.getCRule(rbuf, state.nrulechain)\
							<< std::endl;

typedef my_stack_SHORT MFSTSTSTACK;
namespace MFST {
	struct MfstState {			// состояние автомата (для сохранения)
		short lenta_position;	// позиция на ленте
		short nrule;			// номер текущего правила
		short nrulechain;		// номер текущей цепочки, текущего правила
		MFSTSTSTACK st;			// стек автомата
		MfstState();			
		MfstState(
			short pposition,	// позиция на ленте
			MFSTSTSTACK pst,	// стек автомата
			short pnrulechain	// номер текущей цепочки, текущего правила
		);
		MfstState(
			short pposition,	// позиция на ленте
			MFSTSTSTACK pst,	// стек автомата
			short pnrule,		// стек автомата
			short pnrulechain	// номер текущей цепочки, текущего правила
		);
	};

	struct Mfst {				// магазинный автомат
		enum RC_STEP {			// код возврата функции step
			NS_OK,				// найдено правило и цепочка, цепочка записана в стек
			NS_NORULE,			// не найдено правило грамматики (ошибки в грамматике)
			NS_NORULECHAIN,		// не найдена подходящая цепочка правила (ошибки в исходном коде)
			NS_ERROR,			// неизвестный нетерминальный символ грамматики
			TS_OK,				// тек. символ ленты == вершине стека, продвинулась ланта, pop стека
			TS_NOK,				// тек. символ ленты != вершине стека, восстановленно состояние
			LENTA_END,			// текущая позиция ленты >= lenta_size
			SURPRISE,			// неожиданный код возврата (ошибка в step)
		};

		struct MfstDiagnosis {		// диагностика
			short lenta_position;	// позиция на ленте
			RC_STEP rc_step;		// код завершения шага
			short nrule;			// номер правила
			short nrule_chain;		// номер цепочки правила
			MfstDiagnosis();		
			MfstDiagnosis(				// диагностика
				short plenta_position,	// позиция на ленте
				RC_STEP prc_step,		// код завершения шага
				short pnrule,			// номер правила
				short pnrule_chain		// номер цепочки правила
			);
		}diagnosis[MFST_DIAGN_NUMBER];	// последние самые глубокие сообщения

		class my_stack_MfstState :public std::stack<MfstState> {	// стек автомата
		public:
			using std::stack<MfstState>::c;
		};

		GRBALPHABET* lenta;				// перекодированная (TS/NS) лента (из LEX)
		short lenta_position;			// текущая позиция на ленте
		short nrule;					// номер текущего правила
		short nrulechain;				// номер текущей цепочки, текущего правила
		short lenta_size;				// размер ленты
		GRB::Greibach greibach;			// грамматика Грейбах
		LT::LexTable lex;				// результат работы лексического анализатора
		MFSTSTSTACK st;					// стек автомата
		my_stack_MfstState storestate;	// стек для сохранения состояний
		Mfst();
		Mfst(
			LT::LexTable& plex,			// результат работы лексического анализатора
			GRB::Greibach pgreibach		// грамматика Грейбах
		);
		char* getCSt(char* buf);		// получить содержимое стека
		char* getCLenta(char* buf, short pos, short n = 25);	// лента: n символов с pos
		char* getDiagnosis(short n, char* buf);		// получить n-ую строку диагностики или 0x00
		bool savestate(std::ostream& stream_out);	// сохранить состояние автомата
		bool resetstate(std::ostream& stream_out);	// восстановить состояние автомата
		bool push_chain(				// поместить цепочку правила в стек	
			GRB::Rule::Chain chain		// цепочка правила
		);	
		RC_STEP step(std::ostream& stream_out);					// выполнить шаг автомата
		bool start(std::ostream& stream_out);					// запустить автомат
		bool saveddiagnosis(
			RC_STEP pprc_step			// код завершения шага
		);		
		void printrules(std::ostream& stream_out);				// вывести последовательность правил	

		struct Deducation {				// вывод
			short size;					// количество правил грамматики
			short* nrules;				// номера правил грамматики
			short* nrulechains;			// номера цепочек правил грамматики (nrules)
			Deducation() {
				size = 0;
				nrules = 0;
				nrulechains = 0;
			}
		}deducation;

		bool savededucation();			// сохранить дерево вывода
	};

	void SyntaxCheck(Lex::LEX lex, Log::LOG log, std::ostream& stream_out);
}