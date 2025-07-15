#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int saisi_texte(char text[]);
void compteur(int taille, char text[]);

int main()
{
    int N;
    char texte[100];
    N=saisi_texte(texte);
    compteur(N, texte);
    return(0);
}

int saisi_texte(char text[])
{
    int longueur_texte;
    printf("Le nombre d'apparition de 'a' et ''es'' dans un texte:\n");
    do //tant que le texte ne se termine pas par un point
    {
        printf("Entrez le texte et veuillez le terminer par un point:\n");
        fgets(text, sizeof(text), stdin);
        longueur_texte=strlen(text);
    }while(text[longueur_texte-2]!='.'); //le dernier caractère saisit par l'utilisateur est en position N-2 car fgets inclut dans la chaîne le saut de ligne \n
}

void compteur(int taille, char text[])
{
    int i, a=0, es=0;
    for(i=0; i<taille; i++)
    {
        if(text[i]=='a')
        {
            a++;
        }
        else if(text[i]=='e' && text[i+1]=='s')
        {
            es++;
        }
    }
    printf("'a' apparait %d fois tandis que \"es\" apparait %d fois.\n", a, es);
}