#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"

struct pq {
    Event **events;
    size_t size;
    size_t capacity;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    PQ *pq = malloc(sizeof(PQ));
    pq->events = malloc(sizeof(Event *) * max_N);
    pq->capacity = max_N;
    pq->size = 0;

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    for(int i = 0; i < pq->size; i++)
        destroy_event(pq->events[i]);
    free(pq->events);
    free(pq);
}

void __swap(Event **arr, int i, int j) {
    Event *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void __heapify_up(PQ *pq, int i) {
    int parent = (i - 1) / 2;

    while(parent != 0 && compare(pq->events[parent], pq->events[i]) > 0) {
        __swap(pq->events, i, parent);
        i = parent;
        parent = (i - 1) / 2;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    if(pq->size == pq->capacity) {
        pq->capacity <<= 1;
        pq->events = realloc(pq->events, sizeof(Event *) * pq->capacity);
    }

    pq->events[pq->size++] = e;
    
    __heapify_up(pq, pq->size-1);
}


void __heapify_down(PQ *pq, int i) {
    while((i<<1) + 1 <= pq->size) {
        int j = i<<1;
        if(j < pq->size && compare(pq->events[j], pq->events[j+1]) < 0)
            j++;
        if(compare(pq->events[j], pq->events[i]) >= 0)
            break;

        __swap(pq->events, i, j);
    }
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    Event *to_remove = pq->events[0];
    pq->events[0] = pq->events[pq->size--];

    __heapify_down(pq, 0);

    return to_remove;
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    return pq->size == 0;
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    return pq->size;
}
