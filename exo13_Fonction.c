#include<stdio.h>
#include<stdlib.h>

int degre_triangle();
void debut_triangle(int degre, int tableau[][50]);
void remplir_triangle(int degre, int tableau[][50]);
void affichage(int degre, int tableau[][50]);

int main()
{
    int i, j, N;
    int T[50][50]; 
    N=degre_triangle();
    debut_triangle(N, T);
    remplir_triangle(N, T);
    affichage(N, T);
    return(0);
}

int degre_triangle()
{
    int r, degre, tnt=0;
    do
    {
        printf("Triangle de Pascal:\n");
        printf("Entrez le degré du triangle: ");
        r=scanf("%d", &degre);
        if(r!=1)
        {
            while(getchar()!='\n');
        }
        if(r!=1 || degre<1 || degre>50)
        {
            printf("Entrez une valeur entre 1 et 50!\n");
            tnt++;
        }
        if(tnt==3 && (r!=1 || degre<1 || degre>50))
        {
            printf("Trop de tentatives!\n");
            exit(0);
        }
    }while(r!=1 || degre<1 || degre>50);
    return degre;
}

void debut_triangle(int degre, int tableau[][50])
{
    int i;
    for(i=0; i<=degre; i++) //initialiser le début de toutes les colonnes à 0
    {
        tableau[i][0]=1;
    }
}

void remplir_triangle(int degre, int tableau[][50])
{
    int i, j;
    for(i=1; i<=degre; i++) //on commence à la deuxième ligne car la première colonne est déja le premier 1
    {
        for(j=1; j<=i+1; j++) //on commence à la deuxième colonne  ca la première est aussi 1
        {
            tableau[i][j]=tableau[i-1][j-1]+tableau[i-1][j];
        }
    }
}

void affichage(int degre, int tableau[][50])
{
    int i, j;
    for(i=0; i<=degre; i++)
    {
        for(j=0; j<i+1; j++)
        {
            printf("%d\t", tableau[i][j]);
        }
        printf("\n");
    }
}