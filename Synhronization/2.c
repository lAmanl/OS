#include <stdio.h>

void phil(int i){
    int j = 0;
    while (1){
        if (j++ == 10)
            break;
        printf("Philosopher %d is Thinking\n", i);
        printf("Philosopher %d takes the forks\n", i);
        printf("Philosopher %d Eats\n", i);
        printf("Philosopher %d Puts the forks back\n", i);
    }
}

int main(){
    for (int i = 0; i < 5; i++){
        phil(i + 1);
    }
    return 0;
}