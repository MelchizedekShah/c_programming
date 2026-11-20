#include <stdio.h>
#include "myutils.h"

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};

    printf("Length: %zu\n", ARRAY_LENGTH(arr));

    return 0;
}
