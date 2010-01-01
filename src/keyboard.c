#include <keyboard.h>
#include <screen.h>
#include <base.h>

int SPECIAL_KEY = 0;

/* Default(standard US keyboard) Scancode Table.  */
unsigned char kbd_default[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8','9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0,			/* 29   - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,		/* Left shift */    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',   0,					/* Right shift */
    '*',
    0,	/* Alt */
  ' ',	/* Space bar */
    0,	/* Caps lock */
    0,	/* 59 - F1 key ... > */
    0,   0,   0,   0,   0,   0,   0,   0,
    0,	/* < ... F10 */
    0,	/* 69 - Num lock*/
    0,	/* Scroll Lock */
    0,	/* Home key */
    0,	/* Up Arrow */
    0,	/* Page Up */
  '-',
    0,	/* Left Arrow */
    0,
    0,	/* Right Arrow */
  '+',
    0,	/* 79 - End key*/
    0,	/* Down Arrow */
    0,	/* Page Down */
    0,	/* Insert Key */
    0,	/* Delete Key */
    0,   0,   0,
    0,	/* F11 Key */
    0,	/* F12 Key */
    0,	/* All other keys are undefined */
};

void keyboard_handler(struct regs *r)
{
    unsigned char scancode;

    /* Read from the keyboard's data buffer */
    scancode = inb(0x60);

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if(scancode & 0x80)
    {
        /* For  shift, alt, or control keys... */
        if (scancode == 170)
        {    
            SPECIAL_KEY=1;
        }
    }
    else
    {   /* Key is Pressed */
        if (SPECIAL_KEY && scancode!=170)
          {  
            printf("Pressed %d",scancode);
            SPECIAL_KEY=0;
          }
        else
          {
            put(kbd_default[scancode]);
          }
    }
}

void keyboard_setup()
{
    irq_set_handler(1, keyboard_handler);
}
