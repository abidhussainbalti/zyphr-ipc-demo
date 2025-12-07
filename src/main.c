#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

/* Stack size and queue size */
#define STACK_SIZE 512
#define QUEUE_SIZE 10
#define NUM_MESSAGES 15  // Limit for demo

/* Message queue definition */
K_MSGQ_DEFINE(my_msgq, sizeof(int), QUEUE_SIZE, 4);

/* Producer thread */
void producer_thread(void *p1, void *p2, void *p3)
{
    for (int data = 0; data < NUM_MESSAGES; data++) {
        printk("Producer: sending %d\n", data);
        k_msgq_put(&my_msgq, &data, K_NO_WAIT);
        k_sleep(K_MSEC(500));
    }
    printk("Producer: finished sending messages\n");
}

/* Consumer thread */
void consumer_thread(void *p1, void *p2, void *p3)
{
    int data;
    for (int i = 0; i < NUM_MESSAGES; i++) {
        k_msgq_get(&my_msgq, &data, K_FOREVER);
        printk("Consumer: received %d\n", data);
    }
    printk("Consumer: finished receiving messages\n");
}

/* Define threads */
K_THREAD_DEFINE(producer_id, STACK_SIZE, producer_thread, NULL, NULL, NULL, 7, 0, 0);
K_THREAD_DEFINE(consumer_id, STACK_SIZE, consumer_thread, NULL, NULL, NULL, 7, 0, 0);

/* Main function */
void main(void)
{
    printk("IPC Example Started\n");
}

