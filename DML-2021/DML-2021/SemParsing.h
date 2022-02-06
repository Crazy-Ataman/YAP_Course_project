#pragma once
#include "Main.h"
#include "Log.h"
#include "LexParsing.h"

namespace Semantic {
	bool Parse(Lex::LEX lex, Log::LOG log);
}