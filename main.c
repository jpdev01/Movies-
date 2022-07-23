#include <stdio.h>
#include "Movie.c"

int scanModule();
void renderMenu();
void insert();
void saveDirector();
void saveData();

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
    struct Director director;
    saveDirector(&director);
    struct Data data;
    saveData(&data);

}

void saveDirector(struct Director *director) {
    printf("Informe o nome do diretor: \n");
    scanf("%s", &director -> name);
    //gets(director -> name);

    printf("Informe a nacionalidade do diretor: \n");
    scanf("%s", &director -> nacionality);
}

void saveData(struct Data *data) {
    printf("Informe o dia de lançamento: ");
    scanf("%i", &data -> day);

    printf("Informe o mês de lançamento: ");
    scanf("%i", &data -> month);

    printf("Informe o ano de lançamento: ");
    scanf("%i", &data -> year);
}