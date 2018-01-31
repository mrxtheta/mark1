#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

void matrix_init(void)
{
    unselect_rows();
    init_cols();
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}


static void  init_cols(void)
{
    DDRF  &= ~(1<<7 | 1<<6 | 1<< 5 | 1<<4 | 1<<1 | 1<<0);
    PORTF |=  (1<<7 | 1<<6 | 1<< 5 | 1<<4 | 1<<1 | 1<<0);
    DDRB  &= ~(1<<6);
    PORTB |=  (1<<6);
    DDRD  &= ~(1<<7 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTD |=  (1<<7 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    DDRC  &= ~(1<<7 | 1<<6);
    PORTC |=  (1<<7 | 1<<6);
}

static matrix_row_t read_cols(void)
{
    return (PIND&(1<<5) ? 0 : (1<<0)) |
           (PINC&(1<<7) ? 0 : (1<<1)) |
           (PINC&(1<<6) ? 0 : (1<<2)) |
           (PIND&(1<<4) ? 0 : (1<<3)) |
           (PIND&(1<<0) ? 0 : (1<<4)) |
           (PINB&(1<<6) ? 0 : (1<<5)) |
           (PINF&(1<<0) ? 0 : (1<<6)) |
           (PINF&(1<<1) ? 0 : (1<<7)) |
           (PINF&(1<<4) ? 0 : (1<<8)) | 
           (PINF&(1<<5) ? 0 : (1<<9)) |
           (PINF&(1<<6) ? 0 : (1<<10)) |
           (PINF&(1<<7) ? 0 : (1<<11)) |
           (PIND&(1<<7) ? 0 : (1<<12)) |
           (PIND&(1<<3) ? 0 : (1<<13)) |
           (PIND&(1<<1) ? 0 : (1<<14)) |
           (PIND&(1<<2) ? 0 : (1<<15));;
}

static void unselect_rows(void)
{
    DDRB  &= ~0b00111111;
    PORTB &= ~0b00111111;
}

static void select_row(uint8_t row)
{
    switch (row) {
        case 0:
            DDRB  |= (1<<0);
            PORTB &= ~(1<<0);
            break;
        case 1:
            DDRB  |= (1<<1);
            PORTB &= ~(1<<1);
            break;
        case 2:
            DDRB  |= (1<<2);
            PORTB &= ~(1<<2);
            break;
        case 3:
            DDRB  |= (1<<3);
            PORTB &= ~(1<<3);
            break;
        case 4:
            DDRB  |= (1<<4);
            PORTB &= ~(1<<4);
            break;
        case 5:
            DDRB  |= (1<<5);
            PORTB &= ~(1<<5);
            break;
    }
}
