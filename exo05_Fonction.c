#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int taille_tableau();
float calcul_moyenne(int taille, int tableau[]);
void element_plus_proche(int taille, int tableau[], float moyenne);

int main()
{
    int x, T[50];
    float M=1;
    x=taille_tableau();
    M=calcul_moyenne(x, T);
    element_plus_proche(x, T, M);
    return(0);
}

int taille_tableau()
{
    int taille, i, r, tnt=0;
    printf("L'élément le plus proche de la moyenne:\n");
    do
    {
        printf("Entrez la dimension du tableau d'entiers T: ");
        r=scanf("%d", &taille);

        if(r!=1)
        {
            while(getchar()!='\n'); //vider le tampon si x n'est pas un entier
        }
        if(r!=1 || taille<1 || taille>50)
        {
            printf("Entrez un nombre entre 1 et 50!\n");
            tnt++;
        }
        if(tnt==3 && (r!=1 || taille<1 || taille>50))//terminer l'exécution du programme si 3 fois d'affilé, x n'est pas valide
        {
            printf("Trop de tentatives!\n");
            exit(0);
        }
    }
    while(r!=1 || taille<1 || taille>50);
    return taille;
}

float calcul_moyenne(int taille, int tableau[])
{
    int i;
    float somme=0, moyenne=1;
    printf("Entrez les éléments de T:\n");
    for(i=0; i<taille; i++)
    {
        printf("T[%d]=", i);
        scanf("%d", &tableau[i]);
        somme=somme+tableau[i]; //pour avoir la somme des éléments de T
    }
    printf("\n");

    moyenne=somme/taille; //la moyenne est égale à la somme des éléments sur le nombre d'éléments
    printf("La moyenne est égale à %.2f.\n", moyenne);
    return moyenne;
}

void element_plus_proche(int taille, int tableau[], float moyenne)
{
    int difference, i; //trouver l'élément le plus proche en calculant la distance de l'élément par rapport à la moyenne
    difference=tableau[0]; 
    for(i=1; i<taille; i++)
    {
        if(fabs(tableau[i]-moyenne)<=fabs(difference-moyenne))
        {
            difference=tableau[i];
        }
    }
    printf("L'élément le plus proche de la moyenne est %d.\n\n", difference);
}