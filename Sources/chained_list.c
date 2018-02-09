/*
 * chained_list.c
 *
 *  Created on: Feb 9, 2018
 *      Author: Thomas
 */
#include "chained_list.h"

#define NB_ELEMS (10)

static T_elem_list_process elems[NB_ELEMS];


void chained_list_pop_first(T_elem_list_process **list){
	(*list) = (*list)->next;
	
}


void chained_list_append(T_elem_list_process *list, T_elem_list_process *elem){
	/* on va à la fin de la liste*/
	while(list->next){
		list = list->next;
	}
	/* on ajoute elem à la fin */	
	list->next = elem;
	elem->next = NULL;
	
}

T_elem_list_process *chained_list_create_element(T_process *process){
	static unsigned char elem_index = 0;
	T_elem_list_process *elem = &elems[elem_index++];
	elem->process = process;
	elem->next = NULL;
	return elem;
}
