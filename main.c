#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _personagem{
    int id;
    char nome[20];
    char descricao[30];
}Personagem;

typedef struct _livro{
    int id;
    char titulo[25];
    int anoDePublicacao;
    char ISBN[20];
    Personagem *personagem[5];
    int numPersonagens;
}Livro;

typedef struct _autor{
    int id;
    char nome[20];
    int anoDeNacimento;
    char paisDeNacimento[15];
    Livro *livro[5];
    int numLivros;
}Autor;

void telaInicial(){
    printf("1 - Exibir autores\n");
    printf("2 - Adicionar autor\n");
    printf("3 - Exibir livros\n");
    printf("4 - adicionar livros\n");
    printf("5 - Exibir personagens\n");
    printf("6 - adicionar personagens\n");
    printf("7 - Adicionar livro para autor\n");//relacionar livro com autor
    printf("8 - Adicionar personagem para livro\n"); //relacionar personagem com livro
    printf("9 - Sair\n");
}

void listarAutores(Autor *autores[], int numAutores){
    printf("id     nome         nacimento         pais\n");
    for (int i = 0; i < numAutores; i++){
        printf("%d - %s          %d         %s\n",autores[i]->id ,autores[i]->nome, autores[i]->anoDeNacimento, autores[i]->paisDeNacimento);
    }
    printf("\n\n");
}

void listarLivros(Livro *livro[], int numLivros){
    printf("id     titulo         ano de publicacao         ISBN\n");
    for (int i = 0; i < numLivros; i++){
        printf("%d  -   %s          %d         %s\n", livro[i]->id, livro[i]->titulo, livro[i]->anoDePublicacao, livro[i]->ISBN);
    }
    printf("\n\n");
}

void listarLivrosDeAutores(Autor *autor){
    printf("id     titulo         ano de publicacao         ISBN\n");
    for (int i = 0; i < autor->numLivros; i++){
        printf("%d  -   %s          %d         %s\n", autor->livro[i]->id, autor->livro[i]->titulo, autor->livro[i]->anoDePublicacao, autor->livro[i]->ISBN);
    }
    printf("\n\n");
}

void listarPersonagens(Personagem *personagem[], int numPersonagens){
    printf("id     nome         descricao\n");
    for (int i = 0; i < numPersonagens; i++){
        printf("%d  -   %s          %s \n", personagem[i]->id, personagem[i]->nome, personagem[i]->descricao);
    }
    printf("\n\n");
}

void listarPersonagensdeLivros(Livro *livro){
    printf("id     nome         descricao\n");
    for (int i = 0; i < livro->numPersonagens; i++){
        printf("%d  -   %s          %s \n", livro->personagem[i]->id, livro->personagem[i]->nome, livro->personagem[i]->descricao);
    }
    printf("\n\n");
}

void addAutor(Autor *autor[], int numAutores){
    autor[numAutores] = malloc(sizeof(Autor));
    printf("Digite o nome do autor: ");
    scanf(" %[^\n]s", autor[numAutores]->nome);
    printf("Ano de nacimento: ");
    scanf("%d", &autor[numAutores]->anoDeNacimento);
    printf("pais de Nacimento: ");
    scanf(" %[^\n]s", autor[numAutores]->paisDeNacimento);
    printf("\nAutor adicionado com sucesso\n");
    autor[numAutores]->id = numAutores;
    autor[numAutores]->numLivros = 0;
}

void addLivro(Livro *livro[], int numLivros){
    livro[numLivros] = malloc(sizeof(Livro));
    livro[numLivros]->id = numLivros;
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]s", livro[numLivros]->titulo);
    printf("Digite o ano de publicação: ");
    scanf("%d", &livro[numLivros]->anoDePublicacao);
    printf("digite o ISBN do livro: ");
    scanf(" %[^\n]s", livro[numLivros]->ISBN);
    printf("\nLivro adicionado com sucesso\n");
    livro[numLivros]->numPersonagens = 0;
}

void addPersonagem(Personagem *personagem[], int numPersonagens){
    personagem[numPersonagens] = malloc(sizeof(Personagem));
    personagem[numPersonagens]->id = numPersonagens;
    printf("Digite o nome do personagem: ");
    scanf(" %[^\n]s", personagem[numPersonagens]->nome);
    printf("Digite a descricao do personagem: ");
    scanf(" %[^\n]s", personagem[numPersonagens]->descricao);
    printf("\n personagem adicionado com sucesso\n");
}

int main(){
    int c = 0, op = 0, op2, numAutores = 0, numLivros = 0, numPersonagens = 0, listIdAutor, listIdLivro;
    int autorOP, livroOP, personagemOP;
    Autor *autor[20];
    Livro *livro[20];
    Personagem *personagem[20];
    while(c!=9){
        telaInicial();
        scanf("%d", &op);
        switch(op){
        case 1://Exibir autores   FUNCIONANDO
           if (numAutores <= 0){
            printf("Nenhum autor foi adicionado\n");
           }
           else{
            listarAutores(autor, numAutores);
           }
        break;
        
        case 2://Adicionar autores   FUNCIONANDO
            
            addAutor(autor, numAutores);
            numAutores++;
        break;

        case 3://Exibir livros   FUNCIONANDO
            printf("1 - exibir todos os livros\n");
            printf("2 - exibir livros de um autor especifico\n");
            scanf("%d", &op2);
            switch(op2){
            case 1://exibir todos os livros
                if (numLivros <= 0){
                printf("Nenhum livro foi adicionado\n");
                }
                else{
                listarLivros(livro, numLivros);
                }
            break;
            case 2: // exibir livros de um autor especifico
                if (numAutores <= 0){
                   printf("Nenhum autor foi adicionado\n");
                   break;
                }
                else{
                   listarAutores(autor, numAutores);
                }
                printf("\n\n");
                printf("Digite o id do autor:");
                scanf("%d", &listIdAutor);
                
                if (autor[listIdAutor]->numLivros <= 0){
                printf("O Autor não possui nenhum livro adicionado\n");
                }
                else{
                listarLivrosDeAutores(autor[listIdAutor]);
                }
            break;
            }
        break;

        case 4://adicionar Livros  FUNCIONANDO
          addLivro(livro, numLivros);
          numLivros++;

        break;

        case 5://Exibir personagens FUNCIONANDO
            printf("1 - exibir todos os personagens\n");
            printf("2 - exibir personagens de um livro especifico\n");
            scanf("%d", &op2);
            switch(op2){
                case 1: // exibir todos os personagens
                    if (numPersonagens <= 0){
                        printf("Nenhum personagem foi adicionado\n");
                    }
                    else{
                        listarLivros(livro, numLivros);
                    }
                break;

                case 2:// exibir personagens de um livro especifico
                    if (numLivros <= 0){
                        printf("Nenhum livro foi adicionado\n");
                        break;
                    }
                    else{
                       listarLivros(livro, numLivros);
                    }
                    printf("\n\n");
                    printf("Digite o id do livro\n");
                    scanf("%d", &listIdLivro);
                    if (livro[listIdLivro]->numPersonagens <= 0){
                        printf("O livro não possui nenhum personagem adicionado\n");
                    }
                    else{
                        listarPersonagensdeLivros(livro[listIdLivro]);
                    }

                break;
            }
            
        break;

        case 6://Adicionar Personagens FUNCIONANDO
           addPersonagem(personagem, numPersonagens);
           numPersonagens++;
        break;

        case 7://relacionar livro com autor
            listarAutores(autor, numAutores);
            printf("\ndigite o id do autor que voce deseja relacionar um livro\n");
            scanf("%d", &autorOP);
            listarLivros(livro, numLivros);
            printf("\nDigite o id do livro do autor: ");
            scanf("%d", &livroOP);
            autor[autorOP]->livro[autor[autorOP]->numLivros] = livro[livroOP];
            autor[autorOP]->numLivros++;
            printf("livro relacionado com sucesso\n");
        break;

        case 8://relacionar personagem com livro
            listarLivros(livro, numLivros);
            printf("\nDigite o id do livro que voce deseja relacionar um personagem: ");
            scanf("%d", &livroOP);
            listarPersonagens(personagem, numPersonagens);
            printf("digite o id do personagem do livro: ");
            scanf("%d", &personagemOP);
            livro[livroOP]->personagem[livro[livroOP]->numPersonagens] = personagem[personagemOP];
            livro[livroOP]->numPersonagens++;
            printf("personagem relacionado com sucesso\n");
        break;

        case 9:
        c = 9;
        break;

        default:
        printf("Opção invalida\n");
            
        }
    }
return 0;
}
