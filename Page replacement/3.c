#include <stdio.h>

int main() {
    int n, f;
    printf("Enter the number of pages and frame size: ");
    scanf("%d %d", &n, &f);
    int arr[n], frame[f], ref[f];
    for(int i = 0; i<n; i++)
        scanf("%d", &arr[i]);
    int pf = 0, hit = 0;
    for(int i = 0; i<f; i++){
        frame[i] = 0;
        ref[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int page = arr[i];
        int found = 0;

        for (int j = 0; j < f; j++) {
            if (frame[j] == page) {
                ref[j] = 1;
                found = 1;
                hit++;
                break;
            }
        }

        if (!found) {
            int old = 0;
            int old_p = ref[0];

            for (int j = 1; j < f; j++) {
                if (ref[j] < old_p) {
                    old = j;
                    old_p = ref[j];
                }
            }

            frame[old] = page;
            ref[old] = 1;
            pf++;
        }
    }

    float hits = ((float)hit / n) * 100;
    printf("Page fault = %d\n", pf);
    printf("Hit = %d\n", hit);
    printf("Hit percentage = %.2f%%\n", hits);

    return 0;
}