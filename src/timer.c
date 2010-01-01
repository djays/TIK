#include<timer.h>
#include<screen.h>

/* How many ticks have gone by */
int timer_ticks = 0;

void timer_handler(struct regs *r)
{
    timer_ticks++;              // 1 Tick is every 0.0548 second
    if (timer_ticks % 36 == 0)  // 18 Ticks ~  1 Second
    {
    puts("2sec\n");
    }
}

void timer_wait(int ticks)
{
    unsigned long eticks;
    eticks = timer_ticks + ticks;
    while(timer_ticks < eticks);
}

void timer_setup()
{
    irq_set_handler(0, timer_handler);
}
