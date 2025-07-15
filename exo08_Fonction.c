#include<stdio.h>
#include<string.h>

int entrer_chaine(char sentence[]);
void entrer_bigramme(char bigramme[]);
void verification_bigramme(int longueur_chaine, char sentence[], char bigramme[]);

int main()
{
    int N;
    char chaine[500], bgm[3];
    N=entrer_chaine(chaine);
    entrer_bigramme(bgm);
    verification_bigramme(N, chaine, bgm);
    return(0);
}

int entrer_chaine(char sentence[])
{
    int longueur_chaine=0, i;
    printf("Le nombre de bigrammes(une suite de deux lettres) dans un texte:\n");
    printf("Entrez le texte:\n");
    for(i=0; i<500; i++)
    {
        scanf("%c", &sentence[i]);
        longueur_chaine++;
        if(sentence[i]=='\n')
        {
            sentence[longueur_chaine]=='\0';
            break;
        }
    }
    return longueur_chaine;
}

void entrer_bigramme(char bigramme[])
{
    printf("\nQuel bigramme voulez-vous rechercher? ");
    fgets(bigramme, 3, stdin);
}

void verification_bigramme(int longueur_chaine, char sentence[], char bigramme[])
{
    int i, bi=0;
    for(i=0; i<longueur_chaine; i++)
    {
        if(sentence[i]==bigramme[0] && sentence[i+1]==bigramme[1])
        {
            bi++;
        }
    }
    printf("Le bigramme \"%s\" apparait %d fois dans le texte.\n", bigramme, bi);
}