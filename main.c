#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotecas/DynamicTitles.h"
#include "bibliotecas/AVL.h"
#include "bibliotecas/ReadTSVTitle.h"

int main() {
    TitleArray titles;
    node * n = NULL;

    initArray(&titles, 10);

    readTSVTitle("TSV/title.basics.tsv", &titles);

    for (size_t i = 0; i < titles.used; i++) {
        Title currentTitle = titles.array[i];
        insert(&n, &currentTitle, i);
    }

    int response = search(n, "tt9916754");
    printTitle(titles.array[response]);

    freeArray(&titles);

    return 0;
}