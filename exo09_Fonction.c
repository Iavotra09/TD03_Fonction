#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int entrer_chaine(char word[]);
void verification_chaine_carre(int longueur_mot, char word[]);

int main()
{
    int N;
    char mot[100];
    N=entrer_chaine(mot);
    verification_chaine_carre(N, mot);
    return(0);
}

int entrer_chaine(char word[])
{
    int longueur_mot;
    printf("Mot carré ou non:\n");
    printf("Entrez le mot: ");
    scanf("%s", word);
    longueur_mot=strlen(word);
    return longueur_mot;
}

void verification_chaine_carre(int longueur_mot, char word[])
{
    int i, j, compt=0;
    j=longueur_mot/2;
    for(i=0; i<longueur_mot/2; i++)
    {
        if(word[i]==word[j])
        {
            compt++;
            j++;
        }
        else
        {
            printf("Le mot \"%s\" n'est pas un carré.\n", word);
            break;
        }
    }
    if(compt==longueur_mot/2)
    {
        printf("Le mot \"%s\" est un carré.\n", word);
    }
}