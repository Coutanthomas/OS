/*
 * OS_.h
 *
 *  Created on: Jan 19, 2018
 *      Author: Thomas
 */

#ifndef OS_H_
#define OS_H_

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define LED0 PTCD_PTCD0
#define LED1 PTCD_PTCD1
#define LED2 PTCD_PTCD2
#define LED3 PTCD_PTCD3
#define LED4 PTCD_PTCD4
#define LED5 PTCD_PTCD5

#define PROC_NAME_LENGTH 8
#define NB_PROCESS 4
#define NB_PRIORITY  64
#define NULL ((void*)0)
#if (NB_PRIORITY > 255)
#error max is 255
#endif 

typedef void (*T_fonction) (void);

typedef struct {
	unsigned char name[PROC_NAME_LENGTH];
	unsigned char priority;
	T_fonction fonction;
	unsigned long execution_time;
	unsigned long timer;
}T_process;

typedef struct _elem{
	struct _elem *next; /* prochain process de la liste */
	T_process *process;
}T_elem_list_process;


extern T_process process[NB_PROCESS];

void process_init(T_process *process,const unsigned char *name,const void (*fonction)(void));
void toto (void);
void os_init (void);
void os_sleep (unsigned long time);
void toto_func(void);
void titi_func(void);
void process_start(T_process *process);

#endif /* OS_H_ */
