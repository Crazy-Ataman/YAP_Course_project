#pragma once
#include "Main.h"
#include "LT.h"
#include "IT.h"
#include "Log.h"
#include "In.h"

namespace Lex {
	struct LEX {
		IT::IdTable idtable;
		LT::LexTable lextable;
	};

	LEX LexParsing(Log::LOG log, In::IN in);
	void Synchronization(Lex::LEX& lex);
}