
#include "ring_buffer.h"

//#define capacity (10)
//uint8_t ring_buffer[capacity];
//uint8_t head_ptr;
//uint8_t tail_ptr;
//uint8_t is_full;


void ring_buffer_init(ring_buffer_t *rb, uint8_t *mem_add, uint8_t cap)
{
	rb->buffer = mem_add;
	rb->capacity = cap;

	ring_buffer_reset(rb);
}

/**
 *@brief Esta funcion calcula los datos disponobles en el buffer
 *
 * @retval size: cantidad de datos dispobles
 */

//void ring_buffer_reset(void)
void ring_buffer_reset(ring_buffer_t *rb)
{
	//head = 0;
	//tail = 0;
	//is_full = 0;
	rb->head = 0;
	rb->tail = 0;
	rb->is_full = 0;

}

/*
 *@brief Esta funcion calcula los datos disponibles en el buffer
 *
 * @retval size: cantidad de datos disponibles
 */

/**
 *@brief Esta funcion revisa si el buffer esta lleno
 *
 *@retbal is_full: 0 si no esta lleno, 1 si esta lleno
 **/
uint8_t ring_buffer_is_full(ring_buffer_t *rb)
{
	return rb->is_full;
}

uint8_t ring_buffer_is_empty(ring_buffer_t *rb)
{
	return ((rb->head == rb->tail) && (rb->is_full == 0)) ? 1 : 0;

}

//void ring_buffer_write(uint8_t data)
void ring_buffer_write(ring_buffer_t *rb, uint8_t data)
{
    if (!ring_buffer_is_full(rb)) {
        rb->buffer[rb->head] = data;
        rb->head++;

        if (rb->head >= rb->capacity) {
            rb->head = 0;
        }

        if (rb->head == rb->tail) {
            rb->is_full = 1;
        }
    }
}


/**
 *@brief Esta funcion escribe un dato en el buffer circular
 *
 * @param data: la direccion donde se va a escribir el dato
 *
 * @retval 1: hay datos disponibles; 0 = no hay nada
 *
 **/

uint8_t ring_buffer_read(ring_buffer_t *rb,uint8_t *data) // 0x20
{
    if ((rb->is_full != 0) || (rb->head != rb->tail)) {
        *data = rb->buffer[rb->tail];
        rb->tail++;
        if (rb->tail >= rb->capacity) {
            rb->tail = 0;
        }
        rb->is_full = 0;
        return 1;
    }
    return 0;
}


