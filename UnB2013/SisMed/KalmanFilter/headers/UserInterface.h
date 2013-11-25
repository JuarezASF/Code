/*
 * UserInterface.h
 *
 *  Created on: 24/10/2013
 *      Author: juarez
 *
 *  -define métodos para comunicação com o usuário
 *  -baseado na metodolia de camadas vistas em POO, 2º/2013, UnB
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void reportGood(const char* msg);

void reportBad(const char* msg);

void report(const char* msg);

void reportAttention(const char* msg);

#endif /* USERINTERFACE_H_ */
