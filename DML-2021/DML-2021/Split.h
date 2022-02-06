#pragma once
#include "Main.h"
#include "Log.h"

#define max_word 1000
#define size_word 20

char** splitText(char source[], int size);
void cleanup(char origin[], int size, Log::LOG logfile);