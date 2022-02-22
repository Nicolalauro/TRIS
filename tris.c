/*
    LAURO NICOLA "2C INF"
    TRACCIA: TRIS
*/
#include <stdio.h>
#include <stdlib.h>

//COSTANTI
#define MAX 3
#define PARITY 9
#define UNO 1

//DICHIARAZIONI FUORI DALL'INT MAIN
char tris[MAX][MAX];
char nome1[15], nome2[15];
int x, y, z; //z=contatore pareggio
int controllo1;

//TUTTE LE FUNZIONI
void menu();
void stampatris(); // stampa campo di gioco vuoto
void nomi();       // stampa nomi
void tampatrispieno();
void n_1();         // stampa giocatore 1
void n_2();         // stampoa giocatore 2
void controllo_x(); // controllo tris giocatore [X]
void controllo_o(); // controllo tris giocatore [O]
void controllo_c(); // controlla le coordinate es tris[4][2]

//INIZIALIZZAZIONE FUNZIONI
void stampatris()
{

    printf("\t\t\t\t    0    1    2\n");   

    for (int i = 0; i < MAX; i++)
    {
        printf("\t\t\t\t %d|_%c_|_%c_|_%c_|\n", i, tris[i][0], tris[i][1], tris[i][2]);
    }
}


void nomi()
{
    printf("COME TI CHIAMI GIOCATORE 1 [X]: ");
    scanf("%s", &nome1);
    printf("COME TI CHIAMI GIOCATORE 2 [O]: ");
    scanf("%s", &nome2);
}


void n_1()
{
    printf("\n\n");
    printf("%s \x82 IL TUO TURNO\n", nome1);
    printf("INSERISCI PRIMA LA RIGA: ");
    scanf("%d", &x);
    printf("INSERISCI LA COLONNA: ");
    scanf("%d", &y);
    if (x > 2 || y > 2 || x < 0 || y < 0)
    {
        printf("\nCOORDINATE NON VALIDE\n");
        n_1();
    }
    if (tris[x][y] == 'X' || tris[x][y] == 'O')
    {
        printf("\nCASELLA GIA OCCUPATA\n");
        n_1();
    }
    else
    {
        tris[x][y] = 'X';
        z++;
      
    }
    stampatris();
    controllo_x();
    controllo_o();
}




void n_2()
{
    printf("%s \x82 IL TUO TURNO\n", nome2);
    printf("INSERISCI PRIMA LA RIGA: ");
    scanf("%d", &x);
    printf("INSERISCI LA COLONNA [Y]: ");
    scanf("%d", &y);
    if (x > 2 || y > 2 || x < 0 || y < 0)
    {
        printf("\nCOORDINATE NON VALIDE\n");
        n_2();
    }
    if (tris[x][y] == 'X' || tris[x][y] == 'O')
    {
        printf("\nCASELLA GIA OCCUPATA\n");
        n_2();
    }
    else
    {
        tris[x][y] = 'O';
        z++;
       
    }

    stampatris();
    controllo_x();
    controllo_o();
}


void controllo_x()
{
    for (int i = 0; i < MAX; i++)
    {
        if (tris[i][0] == 'X' && tris[i][1] == 'X' && tris[i][2] == 'X')
        {
            printf("\n%s HA VINTO!\n", nome1);
            controllo1 = 1;
        }
        if (tris[0][i] == 'X' && tris[1][i] == 'X' && tris[2][i] == 'X')
        {
            printf("\n%s HA VINTO!\n", nome1);
            controllo1 = 1;
        }
    }
    if (tris[0][0] == 'X' && tris[1][1] == 'X' && tris[2][2] == 'O')
    {
        printf("\n%s HA VINTO!\n", nome1);
        controllo1 = 1;
    }

    if (tris[2][0] == 'X' && tris[1][1] == 'X' && tris[0][2] == 'O')
    {
        printf("\n%s HA VINTO!\n", nome1);
        controllo1 = 1;
    }
}



void controllo_o()
{
    for (int i = 0; i < MAX; i++)
    {
        if (tris[i][0] == 'O' && tris[i][1] == 'O' && tris[i][2] == 'O')
        {
            printf("\n%s HA VINTO!\n", nome2);
            controllo1 = 1;
        }
        if (tris[0][i] == 'O' && tris[1][i] == 'O' && tris[2][i] == 'O')
        {
            printf("\n%s HA VINTO!\n", nome2);
            controllo1 = 1;
        }
    }
    if (tris[0][0] == 'O' && tris[1][1] == 'O' && tris[2][2] == 'O')
    {
        printf("\n%s HA VINTO!\n", nome2);
        controllo1 = 1;
    }

    if (tris[2][0] == 'O' && tris[1][1] == 'O' && tris[0][2] == 'O')
    {
        printf("\n%s HA VINTO!\n", nome2);
        controllo1 = 1;
    }
}



//INT MAIN
int main()
{
    // STAMPA NOMI
    nomi();
    // STAMPA CAMPO DI GIOCO
    stampatris();
    // CONTROLLA CHI VINCE
    while (controllo1 != UNO || z != PARITY)
    {
        n_1();
        if (controllo1 == UNO || z == PARITY)
        {
            break;
        }
        n_2();
    }
    if (z == PARITY)
    {
        printf("PAREGGIO!!");
    }
    system("pause");
}