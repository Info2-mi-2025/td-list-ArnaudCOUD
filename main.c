#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ne pas modifier
void init_file()
{
    // data.txt
    FILE* f = fopen("data.txt", "w");
    if (f)
    {
        fprintf(f, "5\n12\n8\n1\n19\n");
        fclose(f);
    }

    // data2.txt
    f = fopen("data2.txt", "w");
    if (f)
    {
        fprintf(f, "10\n20\n30\n");
        fclose(f);
    }

    // data3.txt
    f = fopen("data3.txt", "w");
    if (f)
    {
        fprintf(f, "1\n2\n3\n4\n5\n");
        fclose(f);
    }

    // data_vide.txt
    f = fopen("data_vide.txt", "w");
    if (f)
    {
        fclose(f);  // fichier vide
    }
}



typedef struct Node
{
    int value;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

// Fonctions de base
void append(List* list, int value)
{
    Node* noeux = malloc(sizeof(Node));
    noeux->value = value;
    noeux->next = NULL;
    if (list->head == NULL) {
        list->head = noeux;
    }
    if (list->tail != NULL) {
        list->tail->next = noeux;
    }
    list->tail = noeux;
}

void free_list(List* list)
{
    list->head = NULL;
    list->tail = NULL;
}

void print_list(const List* list)
{
    printf("Liste :");
    Node* noeux_actuel = list->head;
    while(noeux_actuel!=NULL){
        printf(" %d ",noeux_actuel->value);
        noeux_actuel = noeux_actuel->next;
        if(noeux_actuel!=NULL)printf("->");
    }
}

void reverse_list(List* list)
{
}

int sum_list(const List* list)
{
    return 0;
}

int min_list(const List* list)
{
    return 0;
}

int max_list(const List* list)
{
    return 0;
}

void filter_list(List* list, int threshold)
{
}

void help()
{
    printf("Utilisation : ./app <fichier> [options]\n\n");
    printf("Options disponibles :\n");
    printf("  --reverse         Inverse l'ordre des éléments\n");
    printf("  --sum             Affiche la somme des éléments\n");
    printf("  --filter <val>    Filtre les éléments >= val\n");
    printf("  --add <val>       Ajoute une valeur à la fin du fichier\n");
    printf("  --help            Affiche ce message d'aide\n");
    printf("  --version, -v     Affiche la version du programme\n");
    printf("  --min             Affiche la valeur minimale de la liste\n");
    printf("  --max             Affiche la valeur maximale de la liste\n");
}

void version(){
    printf("version 1.0\n");
}
// Lecture fichier
bool read_file(const char* filename, List* list)
{
    FILE* f = fopen(filename, "r");
    if (!f) exit(2);
    int value;

    while (fscanf(f, "%d", &value) == 1) append(list, value);

    fclose(f);
    return true;
}

bool add_to_file(const char* filename, int value)
{
    FILE* f = fopen(filename, "a");
    if (!f) return false;
    fprintf(f, "%d\n", value);
    fclose(f);
    return true;
}

void check_argu(int argc, char* argv[], char* nom_fichier) {
    bool fichier_trouve = false;
    for (int i = 1; i < argc; i++) {
        if(sscanf(argv[i],"%s.txt")){
            fichier_trouve = true;
            break;
        }
    }
    if(!fichier_trouve){
        exit(1);
    }
}

int main(int argc, char* argv[])
{
    // Ne pas modifier
    init_file();
    // ---------------

    if(argc < 2) return 1;
    char nom_fichier[20]={0};
    check_argu(argc,argv,nom_fichier);
    printf("J'ai fini avec les arguments fichier : %s",nom_fichier);
    List liste={NULL};
    read_file(nom_fichier,&liste);

    print_list(&liste);


    for (int i = 1; i < argc; i++){
        if(!strcmp(argv[2],"--help")){
            help();
            return 0;
        }

        if(!strcmp(argv[2],"--version") || !strcmp(argv[2],"-v")){
            version();
            return 0;
        }
    }
    return 0;
}
