#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUMBER_ELEMENTS 10

struct Element{
    char* key;
    int value;
    struct Element *next;
    
};

struct HashTable{
   struct Element * buffer[NUMBER_ELEMENTS]; 
};


int hash(char key[]){
    int v_hash = 0;
    for (int j=0; key[j] != '\0'; j++){
        v_hash += key[j];

    }
    return v_hash % NUMBER_ELEMENTS;

}


struct Element* create_element(char* key, int value){
    struct Element* new_element = malloc(sizeof(struct Element));
    new_element->key = malloc((strlen(key)+1)*sizeof(char)); 
    strcpy(new_element->key, key); //copies the \0 too
    new_element->value=value;
    new_element->next=NULL;
    return new_element;
}

struct HashTable create_table(){
    struct HashTable new_table;
    for (int j=0; j<10; j++){
        new_table.buffer[j] = NULL;
    }
    return new_table;
}

int get(char* key, struct HashTable* table, int* found){
    unsigned int index = hash(key);
    if (table->buffer[index] == NULL) {*found = 0; return -1;}
    struct Element* element = table->buffer[index];
    *found = 1;

     //see if the key already exists
    while (element != NULL) {
        if (strcmp(element->key, key) == 0) {
            *found = 1;
            return element->value;
        }
        element = element->next;
    }

    *found = 0;
    return -1;
}

void introduce_component(struct HashTable* table, char* key, int value){
    unsigned int index = hash(key);
    if (table->buffer[index] == NULL) {table->buffer[index] = create_element(key, value); return;}
    struct Element* element = table->buffer[index];
    
    while (1) {
        if (strcmp(element->key, key) == 0) {
            element->value = value;
            return;
        }
        if (element->next == NULL) break;
        element = element->next;
    }
    element->next = create_element(key, value);
    return;
}

void delete_component(struct HashTable* table, char* key){
    unsigned int index = hash(key);
    if (table->buffer[index] == NULL) return;
    struct Element* element = table->buffer[index];
    struct Element* previous_element = NULL;
    
    do{ //see if the key already exists
        if(strcmp(element->key, key) == 0) {
            if (previous_element == NULL) { //first element
                table->buffer[index] = element->next;
            } else {
                previous_element->next = element->next;
            }
            free(element->key);
            free(element);
            return;
        }
        previous_element = element;
        element = element->next;

    } while (element != NULL);
    return;
}


void print_table(struct HashTable* table) {
    printf("\n--- ESTADO DE LA HASH TABLE ---\n");
    for (int i = 0; i < NUMBER_ELEMENTS; i++) {
        printf("Bucket [%d]: ", i);
        struct Element* current = table->buffer[i];
        if (current == NULL) {
            printf("NULL\n");
        } else {
            while (current != NULL) {
                printf("(%s : %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
    printf("-------------------------------\n");
}



int main(){ //debug - menu

    struct HashTable table = create_table();
    int choice;
    char key[1000];
    int value;

    do {
        printf("\n=== MENU HASH TABLE ===\n");
        printf("1. Añadir / Actualizar elemento\n");
        printf("2. Buscar elemento (Get)\n");
        printf("3. Eliminar elemento\n");
        printf("4. Imprimir tabla\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Entrada no valida.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Introduce la clave (string): ");
                scanf("%s", key);
                printf("Introduce el valor (entero): ");
                scanf("%d", &value);
                introduce_component(&table, key, value);
                printf("Elemento guardado.\n");
                break;

            case 2: {
                printf("Introduce la clave a buscar: ");
                scanf("%s", key);
                int found = 0;
                int val = get(key, &table, &found);
                if (found) {
                    printf("¡Encontrado! Valor: %d\n", val);
                } else {
                    printf("Clave '%s' no encontrada.\n", key);
                }
                break;
            }

            case 3:
                printf("Introduce la clave a eliminar: ");
                scanf("%s", key);
                delete_component(&table, key);
                break;

            case 4:
                print_table(&table);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opcion no valida. Intenta de nuevo.\n");
        }
    } while (choice != 5);


}


