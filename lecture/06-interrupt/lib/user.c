#include "os.h"

#define DELAY 2000

extern void trap_test(void);

void user_task0(void)
{
	uart_puts("Task 0: Created!\n");
	while (1) {
		uart_puts("Task 0: Running...\n");
		// trap_test();
		task_delay(DELAY);
		task_yield();
	}
}

void user_task1(void)
{
	// int c = 0;
	uart_puts("Task 1: Created!\n");
	while (1) {
		uart_puts("Task 1: Running...\n");
		task_delay(DELAY);
		task_yield();
		// if (++c > 3){
		// 	task_exit();
		// }
	}
}

/* NOTICE: DON'T LOOP INFINITELY IN main() */
void os_main(void)
{
	task_create(user_task0, NULL, 100);
	task_create(user_task1, NULL, 101);
}

