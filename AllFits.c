#include <stdio.h>
#define MAX 25

// Function Prototypes
void first_fit(int b[], int f[], int nb, int nf);
void best_fit(int b[], int f[], int nb, int nf);
void worst_fit(int b[], int f[], int nb, int nf);
void next_fit(int b[], int f[], int nb, int nf);

int main() {
    int b[MAX], f[MAX], nb, nf, choice;

    printf("Memory Management Schemes\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("4. Next Fit\n");

    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of files: ");
    scanf("%d", &nf);

    printf("\nEnter the size of the blocks:\n");
    for (int i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    printf("\nEnter the size of the files:\n");
    for (int i = 0; i < nf; i++) {
        printf("File %d: ", i + 1);
        scanf("%d", &f[i]);
    }

    do {
        printf("\nSelect the allocation scheme (1-4, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                first_fit(b, f, nb, nf);
                break;
            case 2:
                best_fit(b, f, nb, nf);
                break;
            case 3:
                worst_fit(b, f, nb, nf);
                break;
            case 4:
                next_fit(b, f, nb, nf);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1-4 or 0 to exit.\n");
        }
    } while (choice != 0);

    return 0;
}

// First Fit Algorithm
void first_fit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};

    printf("\nFirst Fit Allocation\n");
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nb; j++) {
            if (!bf[j] && b[j] >= f[i]) { // If block is free and fits the file
                ff[i] = j + 1;
                frag[i] = b[j] - f[i];
                bf[j] = 1; // Mark block as allocated
                break;
            }
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i]) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }
}

// Best Fit Algorithm
void best_fit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};

    printf("\nBest Fit Allocation\n");
    for (int i = 0; i < nf; i++) {
        int best_index = -1;

        for (int j = 0; j < nb; j++) {
            if (!bf[j] && b[j] >= f[i]) {
                if (best_index == -1 || b[j] < b[best_index]) {
                    best_index = j;
                }
            }
        }

        if (best_index != -1) {
            ff[i] = best_index + 1;
            frag[i] = b[best_index] - f[i];
            bf[best_index] = 1;
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i]) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }
}

// Worst Fit Algorithm
void worst_fit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};

    printf("\nWorst Fit Allocation\n");
    for (int i = 0; i < nf; i++) {
        int worst_index = -1;

        for (int j = 0; j < nb; j++) {
            if (!bf[j] && b[j] >= f[i]) {
                if (worst_index == -1 || b[j] > b[worst_index]) {
                    worst_index = j;
                }
            }
        }

        if (worst_index != -1) {
            ff[i] = worst_index + 1;
            frag[i] = b[worst_index] - f[i];
            bf[worst_index] = 1;
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i]) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }
}

// Next Fit Algorithm
void next_fit(int b[], int f[], int nb, int nf) {
    int frag[MAX], bf[MAX] = {0}, ff[MAX] = {0};
    int last_allocated = 0;

    printf("\nNext Fit Allocation\n");
    for (int i = 0; i < nf; i++) {
        int allocated = 0;

        for (int j = last_allocated; j < nb + last_allocated; j++) {
            int index = j % nb;
            if (!bf[index] && b[index] >= f[i]) {
                ff[i] = index + 1;
                frag[i] = b[index] - f[i];
                bf[index] = 1;
                last_allocated = index + 1;
                allocated = 1;
                break;
            }
        }

        if (!allocated) {
            frag[i] = -1; // Mark as not allocated
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tFragment\n");
    for (int i = 0; i < nf; i++) {
        if (ff[i]) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, f[i], ff[i], frag[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, f[i]);
        }
    }
}
