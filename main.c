#include <stdio.h>
#include <stdlib.h>

int scanModule();
void renderMenu();
void insert();
char *saveDirector();

void main() {
    int module = scanModule();
    if (module == 1) {
        insert();
    }
}

int scanModule() {
    int isValid = 1, module;
    do {
        if (!isValid) printf("Opção inválida. Tente novamente\n");
        renderMenu();
        scanf("%i", &module);
        if (module != 1 && module != 2 && module != 3 && module != 4) {
            isValid = 0;
        }
    } while (isValid == 0);

    return module;
}

void renderMenu() {
    printf("---------- MENU ------------\n");
    printf("1 - Inserir novo registro\n");
    printf("2 - Remover registros existentes\n");
    printf("3 - Listar registros\n");
    printf("4 - Consultar por campo chave\n");
}

void insert() {
    printf("---- ADICIONAR NOVO REGISTRO ------\n");
    char *director = saveDirector();
}

char *saveDirector() {
    char *director = malloc(sizeof(char *) * 2);
    printf("Informe o nome do diretor: \n");
    scanf("%s", &director[0]);

    printf("Informe a nacionalidade do diretor: \n");
    scanf("%s", &director[1]);

    return director;
}