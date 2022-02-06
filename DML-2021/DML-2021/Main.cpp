#include "Main.h"
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "Log.h"
#include "FST.h"
#include "Polish.h"
#include "LexParsing.h"
#include "MFST.h"
#include "GRB.h"
#include "SemParsing.h"
#include "Generation.h"

int wmain(int argc, wchar_t* argv[]) 
{
    setlocale(LC_ALL, "Rus");

    Log::LOG log = Log::INITLOG;

    try {
        Parm::PARM parm = Parm::getparm(argc, argv);
        log = Log::getlog(parm.log);
        Log::WriteLog(log);
        Log::WriteParm(log, parm);
        In::IN in = In::getin(parm);
        Log::WriteIn(log, in);
        Lex::LEX lex = Lex::LexParsing(log, in);

        MFST::SyntaxCheck(lex, log, *log.stream);
        if (!Semantic::Parse(lex, log)) 
        {
            std::cout << "Семантические ошибки. Для более подробной информации откройте лог файл.";
            exit(-1);
        }

        Polish::StartPolish(lex);
        Lex::Synchronization(lex);

        Log::WriteLexTableLog(lex.lextable, *log.stream);
        IT::ShowTable(lex.idtable, *log.stream);
        LT::ShowTable(lex.lextable, *log.stream);

        Gen::Generator Gener(lex.lextable, lex.idtable, parm.out);

        Log::Close(log);
    }
    catch (Error::ERROR e) {
        Log::WriteError(log, e);
    }
}
