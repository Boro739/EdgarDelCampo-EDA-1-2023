// Ejemplo de implementación de lista doblemente ligada
#include <stdio.h>
#include <stdlib.h>

// creación de nodo
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

void addToEmpty(struct Node** head, int data) {

  // asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se asigna dato al nuevo nodo
  newNode->data = data;

  // se asigna como head al nuevo nodo
  (*head) = newNode;

  // se crea enlace a si mismo
  (*head)->next = (*head);
  (*head)->prev = (*head);

}

// insertar nodo por el frente
void insertFront(struct Node** head, int data) {
  // asignar memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // hacer al nuevo nodo como la cabeza
  newNode->next = (*head)->next;

  // establecer next del nodo prev como nuevo nodo
  (*head)->next = newNode;

  // establecer prev del nuevo nodo al nodo previo
  newNode->prev = (*head);

  // establecer prev del nuevo nodo a next del nuevo nodo
  newNode->next->prev = newNode;

  // cabeza apunta al nuevo nodo
  (*head) = newNode;
}

// insertar un nodo después de un nodo específico
void insertAfter(struct Node* prev_node, int data) {

  // asignar memoria para el nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // establecer next del nuevo nodo al next del nodo prev
  newNode->next = prev_node->next;

  // establecer next del nodo prev como nuevo nodo
  prev_node->next = newNode;

  // establecer prev del nuevo nodo al nodo previo
  newNode->prev = prev_node;

  // establecer prev del nuevo nodo a next del nuevo nodo
    newNode->next->prev = newNode;
}

// insertar un nuevo nodo al final de la lista
void insertEnd(struct Node** head, int data) {
  // asignar memoria para el nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // asignar dato al nuevo nodo
  newNode->data = data;

  // asignar null al siguiente del nuevo nodo
  newNode->next = (*head);

  newNode->prev = (*head)->prev;

  (*head)->prev = newNode;

  newNode->prev->next = newNode;
 
}

// eliminar un nodo de la lista doblemente ligada
void deleteNode(struct Node** head, int key) {
  // si la lista ligada está vacía
  if (*head == NULL) return;
  // si la lista contiene solo un nodo
  if ((*head)->data == key && (*head)->next == *head ){
    free(*head);
    *head = NULL;
    return;
  }


  struct Node *temp = *head, *d;

  // si se va a eliminar el último
  if ((*head)->data == key) {
    // encontrar el nodo antes del último nodo
    while (temp->next != *head) temp = temp->next;

    // apuntar un nodo temporal al siguiente del último es decir el primer nodo
    temp->next = (*head)->next;
    free(*head);
    *head = temp->next;
  }

  // recorrido al nodo que va a ser eliminado
  while (temp->next != *head && temp->next->data != key) {
    temp = temp->next;
  }

  // si el nodo a eliminar se encuentra
  if (temp->next->data == key) {
    d = temp->next;
    temp->next = d->next;
    free(d);
  }
}


// imprimir la lista doblemente ligada

void traverse(struct Node* last) {
  struct Node* p;

  if (last == NULL) {
    printf("La lista esta vacia");
    return;
  }

  p = last->next;

  do {
  printf("%d ", p->data);
  p = p->next;

  } while (p != last->next);
}

int main() {
  // se inicializa un nodo vacío
  struct Node* head = NULL;

  addToEmpty(&head, 6);
  insertEnd(&head, 5);
  insertFront(&head, 1);
  insertEnd(&head, 9);

  // se inserta 11 después de cabeza
  insertAfter(head, 11);

  // se inserta 15 después del segundo nodo
  insertAfter(head->next, 15);

  traverse(head);

  // se borra el último nodo
  deleteNode(&head, 9);

  traverse(head);
}