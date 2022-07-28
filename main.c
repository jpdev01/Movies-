#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Movie.c"

int scanModule();

void renderMenu();

int insert();

void saveMovie();
void list();
void findMovie();
int removeMovie();

void main() {
    struct Movie **movies = malloc(sizeof(struct Movie **) * 1);
    int numberOfMovies = 0;

    int finish = 0;
    while (!finish) {
        int module = scanModule();
        if (module == 1) {
            numberOfMovies = insert(movies, numberOfMovies);
        }else if (module == 2) {
            numberOfMovies = removeMovie(movies, numberOfMovies);
        } else if (module == 3) {
            list(movies, numberOfMovies);
        } else if (module == 4) {
            findMovie(movies, numberOfMovies);
        } else if (module == 5) {
            finish = 1;
        }
    }

    printf("----- PROGRAMA ENCERRADO -------.");
}

int scanModule() {
    int isValid = 1, module;
    do {
        if (!isValid) printf("Opção inválida. Tente novamente\n");
        renderMenu();
        scanf("%i", &module);
        if (module != 1 && module != 2 && module != 3 && module != 4 && module != 5) {
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
    printf("5 - Encerrar o programa\n");
}

int insert(struct Movie **movies, int numberOfMovies) {
    printf("---- ADICIONAR NOVO REGISTRO ------\n");
    movies = realloc(movies, sizeof(struct Movie **) * numberOfMovies + 1);
    saveMovie(movies, numberOfMovies);
    numberOfMovies++;

    return numberOfMovies;
}

void renderizaCabecalhoDeFilme() {
    printf("Filme \t|\tDiretor \t|\tNacionalidade\t|\t\tCadastramento\n");
}

void saveMovie(struct Movie **movies, int index) {
    movies[index] = malloc(sizeof(struct Movie *) * 1);
    printf("Informe o nome do filme: \n");
    // nao pode ter repetido criar validacao
    scanf("%s", &movies[index]->name);

    printf("Informe a duração do filme (em minutos): \n");
    scanf("%i", &movies[index]->length);

    printf("Informe o estilo do filme: \n");
    scanf("%s", &movies[index] -> style);

    movies[index] -> director = malloc(sizeof(struct Director*) * 1);
    printf("Informe o nome do diretor: \n");
    scanf("%s", &movies[index] -> director -> name);

    printf("Informe a nacionalidade do diretor: \n");
    scanf("%s", &movies[index] -> director -> nacionality);

    printf("%s", movies[0] -> name);

    movies[index] -> data = malloc(sizeof(struct Data*) * 1);
    printf("Informe o dia de lançamento: ");
    scanf("%i", &movies[index] -> data -> day);

    printf("Informe o mês de lançamento: ");
    scanf("%i", &movies[index] -> data -> month);

    printf("Informe o ano de lançamento: ");
    scanf("%i", &movies[index] -> data -> year);
}

void printMovie(struct Movie *movie) {
    printf("%s \t", movie->name);
    printf("\t%s\t ", movie->director->name);
    printf("\t\t\t%s \t\t\t\t", movie->director->nacionality);
    printf("%i/%i/%i\n",
           movie->data->day,
           movie->data->month,
           movie->data->year);
}

void list(struct Movie **movies, int numberOfMovies) {
    printf("----Listagem de Filmes Cadastrados----\n");

    renderizaCabecalhoDeFilme();
    for (int i = 0; i < numberOfMovies; i++) {
        printMovie(movies[i]);
        printf("-------------------------------------------------------------------------------------------\n\n");
    }
}

struct Movie* getMovie(struct Movie** movies, int numberOfMovies, char name[]) {
    for (int index = 0; index < numberOfMovies; index++) {
        if (strcmp(movies[index] -> name, name) == 0) {
            return movies[index];
        }
    }
    return NULL;
}

void findMovie(struct Movie** movies, int numberOfMovies) {
    char nome[50];
    printf("Informe o nome do filme");
    scanf("%s", &nome);

    struct Movie *movie = getMovie(movies, numberOfMovies, nome);
    if (movie) {
        printMovie(movie);
        return;
    }

    printf("Nao encontrado!");
}

int removeMovie(struct Movie** movies, int numberOfMovies) {
    char name[50];
    printf("Informe o nome do filme");
    scanf("%s", &name);
    struct Movie *movie = getMovie(movies, numberOfMovies, name);
    if (movie == NULL) {
        printf("Nao encontrado!");
        return numberOfMovies;
    }

    int latestIndex = 0;
    for (int index = 0; index < numberOfMovies; index++) {
        if (strcmp(movies[index] -> name, name) == 0) {
            movies[index] = NULL;
            free(movies[index]);
            numberOfMovies--;
        } else {
            movies[latestIndex] = movies[index];
            latestIndex++;
        }
    }

    return numberOfMovies;
}