#ifndef	TASK_H
#define	TASK_H
#include <stdint.h>

typedef struct TCB TCB;
struct TCB{
	TCB	*next;
	char *name;
	void (*task)(void);
	uint8_t *stackPointer;
	uint8_t *stackBegin;
	uint32_t stackSize;
	uint32_t execReturnCode;	// LR on interrupt
};

typedef struct LinkedList LinkedList;
struct LinkedList {
	TCB *head;
	TCB *tail;
  int length;
};


TCB *initKernel(char *mainThreadName);
TCB *createThread(char *name, void (*task)(void), uint32_t size);
LinkedList *createLinkedList();
TCB *removeElementFromFront(LinkedList *list);
void addElementToBack(LinkedList *list, TCB *element);
TCB *peepFront(LinkedList *list);
#endif	// TASK_H
