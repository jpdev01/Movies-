#include <stdio.h>
#include <stdlib.h>
#include "Movie.c"

int scanModule();
void renderMenu();
void insert();
 Director saveDirector();
 Data saveData();
 Movie addMovie();

void main() {
    Movie *movies = malloc(sizeof(Movie *) * 1);
    int numberOfMovies = 0;

    int finish = 0;
    while (!finish) {
        int module = scanModule();
        if (module == 1) {
            insert(movies, numberOfMovies);
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

void insert( Movie *movies, int numberOfMovies) {
    printf("---- ADICIONAR NOVO REGISTRO ------\n");

    Movie movie;
    movie = addMovie(movie);

    movies = realloc(movies, sizeof(Movie*) * numberOfMovies);
    movies[numberOfMovies] = movie;
    numberOfMovies++;
}

 Director saveDirector( Director director) {
    printf("Informe o nome do diretor: \n");
    scanf("%s", &director.name);

    printf("Informe a nacionalidade do diretor: \n");
    scanf("%s", &director.nacionality);

    return director;
}

Data saveData( Data data) {
    printf("Informe o dia de lançamento: ");
    scanf("%i", &data.day);

    printf("Informe o mês de lançamento: ");
    scanf("%i", &data.month);

    printf("Informe o ano de lançamento: ");
    scanf("%i", &data.year);

    return data;
}

Movie addMovie(Movie movie) {
    printf("Informe o nome do filme: \n");
    // nao pode ter repetido
    scanf("%s", &movie.name);

    printf("Informe a duração do filme (em minutos): \n");
    scanf("%i", &movie.length);

    printf("Informe o estilo do filme: \n");
    scanf("%s", &movie.style);

    saveDirector(movie.director);
    saveData(movie.data);

    return movie;
}