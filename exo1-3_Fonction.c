#include<stdio.h>
#include<stdlib.h>

int saisi_donnees(int tableau[]);
void triage_pair_impair(int taille, int tableau[]);
void affichage(int taille, int tableau[]);
int ajout_element(int taille, int tableau[]);
int suppr_element(int taille, int tableau[]);

int main()
{
    int N, T[50];
    N=saisi_donnees(T);
    triage_pair_impair(N, T);
    affichage(N, T);
    N=ajout_element(N, T);
    triage_pair_impair(N, T);
    affichage(N, T);
    N=suppr_element(N, T);
    affichage(N, T);
    return(0);
}

int saisi_donnees(int tableau[])
{
    int i, r, tnt=0, taille;
    do
    {
        printf("Entrez la taille du tableau: ");
        r=scanf("%d", &taille);
        if(r!=1)
        {
            while(getchar()!='\n');
        }
        if(taille<1 || taille>50 || r!=1)
        {
            printf("La taille doit être entre 1 et 50!\n");
            tnt++;
        }
        if(tnt==3 && (taille<1 || taille>50 || r!=1))
        {
            printf("Trop de tentatives!\n");
            exit(0);
        }
    }while(taille<1 || taille>50 || r!=1);
    
    printf("Veuillez entrer les éléments de T:\n");
    for(i=0; i<taille; i++)
    {
        printf("T[%d]=", i);
        scanf("%d", &tableau[i]);
    }
    return taille;
}

void triage_pair_impair(int taille, int tableau[])
{
    int i, j, nbr_a_trier, temp;
    nbr_a_trier=taille;
    for(i=0; i<nbr_a_trier; i++)
    {
        if(tableau[i]%2==1)// si l'élément est impair
        {
            temp=tableau[i]; //stocker l'élément dans un variable temporaire temp
            for(j=i; j<taille-1; j++)
            {
                tableau[j]=tableau[j+1]; //déplacer les éléments à partir de là vers la droite jusqu'à N-1
            }
            tableau[taille-1]=temp; //déplacer le nombre impair vers la fin du tableau
            nbr_a_trier--; //le nombre d'éléments à trier diminue de un
            i--; //pour que i revienne à 0 dans le cas où il y aurait des nombres impairs consécutifs
        }
    }
    printf("\n");
}

void affichage(int taille, int tableau[])
{
    int i;
    printf("Le tableau T après triage:\nT: ");
    for(i=0; i<taille; i++)
    {
        printf("%d  ", tableau[i]);
    }
    printf("\n\n");
}

//EXO n°02
int ajout_element(int taille, int tableau[])
{
    printf("Ajoutez un élément dans T:\n");
    taille=taille+1; //ajouter 1 à l'élément du tableau
    printf("T[%d]=", taille-1);
    scanf("%d", &tableau[taille-1]);
    return taille;
}

//Exo n°3
int suppr_element(int taille, int tableau[])
{
    int element_a_suppr, i, j;
    printf("Quel élémént voulez-vous supprimer? ");
    scanf("%d", &element_a_suppr);

    for(i=0; i<taille; i++)
    {
        if(tableau[i]==element_a_suppr)
        {
            for(j=i; j<taille-1; j++) //déplacer les autres éléments du tableau trié vers la gauche
            {
                tableau[j]=tableau[j+1];
            }
            taille--;//diminuer la taille du tableau de 
            i=-1;
        }
    }
    printf("\n");
    return taille;
}
