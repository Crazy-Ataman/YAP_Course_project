#pragma once
#include "Main.h"
#include "LexParsing.h"
#include "Error.h"

namespace Polish {
	void StartPolish(Lex::LEX& lex);
	bool PolishNotation(int i, Lex::LEX& lex);
}