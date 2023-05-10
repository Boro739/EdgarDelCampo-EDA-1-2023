
#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue
		= (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// Esto es importante ver en operacion encolar
	queue->rear = capacity - 1;
	queue->array
		= (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}


int isFull(struct Queue* queue)
{
	return (queue->size == queue->capacity);
}

// Funcion para agregar un elemento a la cola.
// Cambia la parte trasera y el tamano.
void enqueue(struct Queue* queue, int item)
{
	if (isFull(queue))
		return;
    printf("%i antes\n",queue->rear);
	queue->rear = (queue->rear + 1) % queue->capacity;
	printf("despues %i\n",queue->rear);
    queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d agregado a la cola\n", item);
}

int main(){

struct Queue* queue = createQueue(1000);

	enqueue(queue, 10);
    enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

}
