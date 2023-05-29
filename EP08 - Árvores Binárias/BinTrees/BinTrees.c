#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cel {
    int conteúdo;
    int chave;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel nó;
typedef nó *árvore;

árvore Insere(árvore r, nó *novo) {
    nó *f, *p;
    if (r == NULL)
        return novo;
    f = r;
    while (f != NULL) {
        p = f;
        if (f->chave > novo->chave)
            f = f->esq;
        else
            f = f->dir;
    }
    if (p->chave > novo->chave)
        p->esq = novo;
    else
        p->dir = novo;
    return r;
}

void Red(árvore r) {
    if (r != NULL) {
        printf("%d\n", r->conteúdo);
        Red(r->esq);
        Red(r->dir);
    }
}

void Erd(árvore r) {
    if (r != NULL) {
        Erd(r->esq);
        printf("%d\n", r->conteúdo);
        Erd(r->dir);
    }
}

void Edr(árvore r) {
    if (r != NULL) {
        Edr(r->esq);
        Edr(r->dir);
        printf("%d\n", r->conteúdo);
    }
}

nó *Busca(árvore r, int k) {
    if (r == NULL || r->chave == k)
        return r;
    if (r->chave > k)
        return Busca(r->esq, k);
    else
        return Busca(r->dir, k);
}

int main() {
    árvore r = NULL;
    char operation[10];
    int conteúdo;

    scanf("%s", operation);

    while (scanf("%s %d", operation, &conteúdo) != EOF) {
        if (strcmp(operation, "I") == 0) {
            r = Insere(r, novo);
        } else if (strcmp(operation, "P") == 0) {
            if (Busca(r, conteúdo))
                printf("%d existe\n", conteúdo);
            else
                printf("%d nao existe\n", conteúdo);
        } else if (strcmp(operation, "PREFIXA") == 0) {
            Red(r);
        } else if (strcmp(operation, "INFIXA") == 0) {
            Erd(r);
        } else if (strcmp(operation, "POSFIXA") == 0) {
            Edr(r);
        }
    }

    return 0;
}
