/*
 * UserInterface.c
 *
 *  Created on: 24/10/2013
 *      Author: juarez
 */

#include "../headers/UserInterface.h"

void reportGood(const char* msg){
	printf(ANSI_COLOR_GREEN  "%s" ANSI_COLOR_RESET "\n", msg);
}

void reportBad(const char* msg){
	printf(ANSI_COLOR_RED  "%s" ANSI_COLOR_RESET "\n", msg);
}

void report(const char* msg){
	printf(ANSI_COLOR_BLUE  "%s" ANSI_COLOR_RESET "\n", msg);
}

void reportAttention(const char* msg){
	printf(ANSI_COLOR_YELLOW  "%s" ANSI_COLOR_RESET "\n", msg);
}
