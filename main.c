#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_ID 50

struct atores
{
    char nome[50];
    int idade;


}ATORES [100];

struct filme
{
    char nome[50];
    int idade_minima,duracao;
    struct atores ATORES[50];
}FILME[50];

struct genero
{
    char nome[50];
    int numero_gen, numero_filme;
    struct filme FILME[50];
}GENERO[50];

struct cinema
{
    int numero_cinemas;
    char nome_cinema[TAM_NOME];
    struct genero GENERO[50];
    int num_cinema, numero_gen;
}CINEMA[50];


void listar_cinemas(int cinema);
void inserir_genero(int id_cin);
void listar_generos(int cinema);
void listar_todos_generos(int cinema);
void listar_generos_por_cinema(int id_cin);
void inserir_cinema(int cinema);
void clearScreen(void);
void inserir_filme(int id_filme);
void listar_filmes(int id_cin);
void editar_filmes(int id_filme);
void listar_todos_filmes(int id_filme);
void gravar_em_txt(int cinema);
void eliminarFilme(int filmes);





int main(int argc, const char * argv[]) {

    int opc;
    int cinema = 0,cin = 0,id_filme;

    do {
        printf("\n===============================");
        printf("\n=                             =");
        printf("\n=          Cinemas            =");
        printf("\n=                             =");
        printf("\n===============================\n");
        printf("\n[1]. Novo Cinema");
        printf("\n[2]. Mostrar Cinemas\n");
        printf("\n===============================");
        printf("\n=                             =");
        printf("\n=          Generos            =");
        printf("\n=                             =");
        printf("\n===============================\n");
        printf("\n[3]. Mostrar Generos");
        printf("\n[4]. Adicionar Genero\n");
        printf("\n===============================");
        printf("\n=                             =");
        printf("\n=          Filmes             =");
        printf("\n=                             =");
        printf("\n===============================\n");
        printf("\n[5]. Mostrar Filmes");
        printf("\n[6]. Adicionar Filme");
//printf("\n[7]. Gravar");
        printf("\n[7]. Editar Filme");
        printf("\n[8]. Apagar Filme\n\n");
        printf("\n[9]. Exit");
        printf("\n=============================");
        printf("\nInsira a sua opcao: ");
        fflush(stdin);
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
            if(cinema!=0)
                {
                    system("cls");
                    listar_cinemas(cinema);
                    printf("Insira um cinema que nao se encontre na lista!\n\n");
                }
                inserir_cinema(cinema);
                cinema++;
                break;

            case 2:
                system("cls");
                listar_cinemas(cinema);
                system( "read -n 1 -s -p \"Carrega numa tecla para voltar ao menu...\"" );
                break;

            case 3:
                system("cls");
                listar_generos(cinema);
                break;

            case 4:
                system("cls");
                listar_cinemas(cinema);
                printf("escolha o numero do cinema:  ");
                scanf("%d",&cin);
                system("cls");
                inserir_genero(cin);
                break;

            case 5:
                system("cls");
                listar_cinemas(cinema);
                printf("escolha o numero do cinema onde quer procurar o filme:  ");
                scanf("%d",&cin);
                system("cls");
                listar_generos_por_cinema(cin);
                printf("agora escolha o genero onde se encontra o/os filme/s:  ");
                scanf("%d",&id_filme);
                listar_filmes(id_filme);
                system("PAUSE");
                //system( "read -n 1 -s -p \"Carrega numa tecla para voltar ao menu...\"" );
                break;

            case 6:
                system("cls");
                listar_cinemas(cinema);
                printf("escolha o numero do cinema em que deseja inserir o filme:  ");
                scanf("%d",&cin);
                system("cls");
                listar_generos_por_cinema(cin);
                printf("escolha o numero do genero onde deseja inserir o filme:  ");
                scanf("%d",&id_filme);
                inserir_filme(id_filme);
                break;

            case 7:
                system("cls");
                editar_filmes(cinema);
                break;

            case 8:
                listar_cinemas(cinema);
                printf("escolha o numero do cinema em que deseja eliminar o filme:  ");
                scanf("%d",&cin);
                system("cls");
                listar_generos_por_cinema(cin);
                printf("escolha o numero do genero onde deseja eliminar o filme:  ");
                scanf("%d",&id_filme);
                eliminarFilme(id_filme);
            case 9:
                clearScreen();
                printf("Programa fechado.");
                return 0;
                break;
            default:
                printf("operaçao invalida");
        }
        if(opc!=0)
        {
            printf("\n\nPrima qualquer tecla para voltar ao menu...\n");
            getchar();
        }
    } while(opc!=0);

    return 0;
}

void inserir_cinema(int cinema)
{
    printf("Que nome deseja dar ao cinema numero: %d?\n-->", cinema+1);
    scanf("%s", CINEMA[cinema].nome_cinema);
    clearScreen();
}

void listar_cinemas(int cinema)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Lista de Cinemas        =");
    printf("\n=                             =");
    printf("\n===============================\n\n");
    int i;
    for (i=0; i<cinema; i++)
    {
        printf("Nome do cinema %d : %s \n\n",i+1, CINEMA[i].nome_cinema);  //i+1 pois decidimos que as categorias nao come¡am do numero 0 mas sim do 1
    }
}

void inserir_genero(int id_cin)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Inserir Genero          =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    int opc2,i;
    printf("Quantos generos deseja inserir?\n");
    scanf("%d",&opc2);

    for(i=0;i<opc2;i++)
    {
        printf("Qual o nome do genero %d?\n--> ",CINEMA[(id_cin-1)].numero_gen+1);
        scanf("%s",CINEMA[(id_cin-1)].GENERO[i].nome);
        CINEMA[(id_cin-1)].numero_gen++;
    }
    clearScreen();
}

void listar_generos(int cinema)
{
    int opc = -1,id_cin;

    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Lista de Generos        =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    while(opc!=0)
    {
        //printf("[1] -Listar Todos.\n");
        printf("[1] -Listar generos\n");
        printf("[2] -Voltar ao Menu Inicial\n");
        scanf("%d",&opc);

        switch(opc)
        {
                /*case 1:
                 clearScreen();
                 listar_todos_generos(cinema);
                 break;
                 */
            case 1:
                clearScreen();
                listar_cinemas(cinema);
                printf("Introduza o cinema que deseja ver:  ");
                scanf("%d",&id_cin);
                listar_generos_por_cinema(id_cin);
                system("PAUSE");
                //system( "read -n 1 -s -p \"Carrega numa tecla para voltar ao menu...\"" );
                return;
                break;

            case 2:
                return;
        }
    }
}

/*void listar_todos_generos(int cinema)
 {
 int i,j;

 for(i=0;i<cinema;i++)
 {
 printf("Nome do cinema %d - %s",i+1,CINEMA[cinema].nome_cinema);
 for(j=0;j<CINEMA[cinema].num_cinema;j++)
 {
 printf("Genero %d : %s \n", j+1,CINEMA[cinema].GENERO[j].nome);
 }
 }
 }*/

void listar_generos_por_cinema(int id_cin)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Lista de Generos        =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    int j;
    printf("Nome do Cinema  %d - %s\n",id_cin, CINEMA[(id_cin-1)].nome_cinema);
    for (j=0 ; j<CINEMA[(id_cin-1)].numero_gen;j++)
    {
        printf("Genero %d: %s \n",j+1, CINEMA[(id_cin-1)].GENERO[j].nome);
    }
    printf("\n\n\n");
}


void inserir_filme(int id_filme)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Adicionar Filme         =");
    printf("\n=                             =");
    printf("\n===============================\n\n");


    int i,qtd_filmes;
    printf("Quantos filmes deseja inserir?");
    scanf("%d",&qtd_filmes);
    for(i=0;i<qtd_filmes;i++)
    {
        printf("Qual o Nome do Filme?\n --> ");
        scanf(" %s",GENERO[id_filme-1].FILME[GENERO[(id_filme-1)].numero_filme].nome);
        printf("Qual a duracao do filme em minutos?:\n -->");
        scanf(" %d", &GENERO[id_filme-1].FILME[GENERO[(id_filme-1)].numero_filme].duracao);
        printf("Qual a idade minima de vizualizacao do filme?\n-->");
        scanf("%d", &GENERO[id_filme-1].FILME[GENERO[(id_filme-1)].numero_filme].idade_minima);
        GENERO[(id_filme-1)].numero_filme++;
    }
}

void listar_filmes(int id_filme)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Lista de Filmes         =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    int i;
    for(i=0;i<GENERO[id_filme-1].numero_filme;i++)
    {
        printf("Filme %d:\n\n Nome: %s\n Duraçao do Filme: %d\n Idade Minima: %d \n\n",i+1,GENERO[id_filme-1].FILME[i].nome,GENERO[id_filme-1].FILME[i].duracao,GENERO[id_filme-1].FILME[i].idade_minima);
    }
}


/*void listar_todos_filmes(int id_filme)
 {
 printf("\n===============================");
 printf("\n=                             =");
 printf("\n=     Lista de Filmes         =");
 printf("\n=                             =");
 printf("\n===============================\n\n");


 int i,j,w;
 for(i=0;i<id_filme;i++)
 {
 printf("Nome do Cinema %d : %s",(id_filme-1),CINEMA[(id_filme-1)].nome_cinema);
 for(j=0;j<CINEMA[(id_filme-1)].num_cinema;j++)
 {
 printf("Nome do Genero %d : %s",j+1,CINEMA[(id_filme-1)].GENERO[j].nome);
 for(w=0;w<GENERO[(id_filme-1)].numero_filme;w++)
 {
 printf("Filme %d:\n\n Nome : %s\n DuraÁ„o do Filme: %d\n Idade Minima: %d \n\n",i+1,GENERO[(id_filme-1)].FILME[i].nome,GENERO[(id_filme-1)].FILME[i].duracao,GENERO[(id_filme-1)].FILME[i].idade_minima);
 }
 }
 }
 }*/

void editar_filmes(int cinema)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=      Editar Filme           =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    int cin,id_filme;

    listar_cinemas(cinema);
    printf("Escolha o numero do cinema em que deseja alterar o filme\n");
    scanf("%d",&cin);
    listar_generos_por_cinema(cin);
    printf("Escolha o numero do genero onde deseja alterar o filme\n");
    scanf("%d",&id_filme);
    printf("Alterar Filme:\n\n");
    listar_filmes(id_filme);
    printf("Insira o numero do filme que deseja alterar:");
    scanf("%d",&id_filme);
    id_filme=id_filme-1;
    printf("Qual o Nome do Filme?:\n-->");
    scanf("  %s",GENERO[cinema].FILME[GENERO[id_filme].numero_filme].nome);
    printf("Qual a duracao do filme em minutos?:\n-->");
    scanf(" %d",&GENERO[cinema].FILME[GENERO[id_filme].numero_filme].duracao );
    printf("Qual a idade minima de vizualizacao do filme?\n-->");
    scanf(" %d",  &GENERO[cinema].FILME[GENERO[id_filme].numero_filme].idade_minima);
}

void eliminarFilme(int filmes)
{
    printf("\n===============================");
    printf("\n=                             =");
    printf("\n=     Eliminar Filme          =");
    printf("\n=                             =");
    printf("\n===============================\n\n");

    int id_genero, id_filme;

    listar_filmes(filmes);

    printf("Introduza o filme que quer eliminar ");

    scanf("%d", &id_filme);

    id_filme=id_filme-1;   //o numero inserido pelo utilizador corresponde a um valor acima do indice de posição do vetor FILME

    strcpy(GENERO[(filmes-1)].FILME[id_filme].nome, GENERO[(filmes-1)].FILME[GENERO[(filmes-1)].numero_filme-1].nome);


    GENERO[(filmes-1)].FILME[id_filme].duracao = GENERO[(filmes-1)].FILME[GENERO[(filmes-1)].numero_filme-1].duracao;

    GENERO[(filmes-1)].FILME[id_filme].idade_minima, GENERO[(filmes-1)].FILME[GENERO[filmes-1].numero_filme-1].idade_minima;





    strcpy(GENERO[filmes-1].FILME[GENERO[(filmes-1)].numero_filme].nome, "");

    GENERO[filmes-1].FILME[GENERO[(filmes-1)].numero_filme].duracao = 0;

    GENERO[filmes-1].FILME[GENERO[(filmes-1)].numero_filme].idade_minima = 0;



    GENERO[filmes-1].numero_filme = GENERO[id_genero].numero_filme - 1;

}





void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
