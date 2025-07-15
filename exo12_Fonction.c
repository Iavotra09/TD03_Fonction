#include<stdio.h>
#include<stdlib.h>

int nbr_ligne_colonne();
void element_tableau(int nombre, int tableau[][50]);
int calcul_somme(int tableau[][50], int somme[], int nombre, char indice1, char indice2, int indice3);
void verification_carre_magique(int nombre, int somme[]);

int main()
{
    int N, k=0, T[50][50], S[50];
    N=nbr_ligne_colonne();
    element_tableau(N, T);
    k=calcul_somme(T, S, N, 'i', 'j', k);
    k=calcul_somme(T, S, N, 'j', 'i', k);
    verification_carre_magique(N, S);
    return(0);
}

int nbr_ligne_colonne()
{
    int tnt=0, r, nombre;
    printf("Carré magique ou non:\n"); 
    do
    {
        printf("Entrez le nombre de lignes et de colonnes: ");
        r=scanf("%d", &nombre);
        if(r!=1)
        {
            while(getchar()!='\n');
        }
        if(r!=1 || nombre<1 || nombre>50)
        {
            printf("Entrez un nombre entre 1 et 50!\n");
            tnt++;
        }
        if(tnt==3 && (r!=1 || nombre<1 || nombre>50))
        {
            printf("Trop de tentatives!\n");
            exit(0);
        }
    }while(r!=1 || nombre<1 || nombre>50);
    return nombre;
}

void element_tableau(int nombre, int tableau[][50])
{
    int i, j;
    printf("Entrez les éléments du tableau:\n");
    for(i=0; i<nombre; i++)
    {
        for(j=0; j<nombre; j++)
        {
            printf("T[%d][%d]=",i,j);
            scanf("%d", &tableau[i][j]);
        }
    }
}

int calcul_somme(int tableau[][50], int somme[], int nombre, char indice1, char indice2, int indice3)
{
    int i, j;
    somme[indice3]=0;
    for(i=0; i<nombre; i++)
    {
        for(j=0; j<nombre; j++)
        {
            somme[indice3]=somme[indice3]+tableau[indice1][indice2];
        }
        printf("%d\n", somme[indice3]);
        indice3++;
    }
    return indice3;
}

void verification_carre_magique(int nombre, int somme[])
{
    int i, compt=0;
    for(i=0; i<nombre+nombre-1; i++)
    {
        if(somme[i]!=somme[i+1])
        {
            printf("Ce n'est pas un carré magique!\n");
            exit(0);
        }
        else
        {
            compt++;
        }
    }
    printf("comt=%d, %d", compt, nombre+nombre-1);
    if(compt==(nombre+nombre-1))
    {
        printf("C'est un carré magique!\n");
    }
}