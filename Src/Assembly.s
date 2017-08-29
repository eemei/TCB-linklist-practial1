  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb

  .global MY_TIM1_UP_IRQHandler


	/*
	Exception frame saved by the NVIC hardware onto stack:
	+------+
	|      | <- SP before interrupt (orig. SP)
	| xPSR |
	|  PC  |
	|  LR  |
	|  R12 |
	|  R3  |
	|  R2  |
	|  R1  |
	|  R0  | <- SP after entering interrupt (orig. SP + 32 bytes)
	+------+

	Registers saved by the software (MY_Timer_Handler):
	+------+
	|  R4  |
	|  R5  |
	|  R6  |
	|  R7  |
	|  R8  |
	|  R9  |
	| R10  |
	| R11  | <- Saved SP (orig. SP + 64 bytes)
	+------+
	*/
  .type MY_TIM1_UP_IRQHandler, %function
MY_TIM1_UP_IRQHandler:
  // Your task switching code will be started here
  push 	{R4-R11}			      // push R11 --> R4 into stack memory
  mov   r4, sp
  mov   r5, lr
  push 	{LR}
  ldr  	R1, =list
  ldr 	R1, [R1]
  mov 	R0, r1
  bl 	removeElementFromFront  //TCB *removeElementFromFront(LinkedList *list)
  str	r4, [R0, #12]
  str	r5, [R0, #24]
  mov 	r1, r0
  ldr 	r0, =list
  ldr 	r0, [r0]
  bl  	addElementToBack  //addElementToBack(LinkedList *list, TCB *element)
  ldr 	r0, =list
  ldr 	r0, [r0]
  bl 	peepFront;          //TCB *peepFront(LinkedList *list)
  pop 	{lr}
  ldr	sp, [R0, #12]
  ldr	lr, [R0, #24]
  pop	{R4-R11}
  b		TIM1_UP_IRQHandler

