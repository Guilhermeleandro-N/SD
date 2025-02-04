#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define TIMEOUT_SECONDS 3600
#define MAX_NUMBERS 5000
#define MAX_THREADS 4

typedef struct {
    int *numbers;
    int target;
    int start;
    int end;
    int count;
} ThreadData;

void *countSubsets(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int *numbers = data->numbers;
    int target = data->target;
    int start = data->start;
    int end = data->end;
    int count = 0;
    
    int totalSubsets = 1 << (end - start + 1);
    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        for (int j = 0; j <= end - start; j++) {
            if (mask & (1 << j)) {
                sum += numbers[start + j];
            }
        }
        if (sum == target) count++;
    }
    
    data->count = count;
    pthread_exit(NULL);
}

int readNumbersFromFile(const char *filePath, int *numbers) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%d", &numbers[count]) == 1 && count < MAX_NUMBERS) {
        count++;
    }
    fclose(file);
    return count;
}

int generateRandomTarget() {
    return rand() % 901 + 100;
}

int findSubsetCount(int *numbers, int length, int target, int numThreads) {
    pthread_t threads[MAX_THREADS];
    ThreadData threadData[MAX_THREADS];
    int segmentSize = length / numThreads;
    int remainder = length % numThreads;
    int total = 0;
    int start = 0;
    
    for (int i = 0; i < numThreads; i++) {
        int end = start + segmentSize + (i < remainder ? 1 : 0) - 1;
        if (end >= length) end = length - 1;
        threadData[i] = (ThreadData){numbers, target, start, end, 0};
        pthread_create(&threads[i], NULL, countSubsets, &threadData[i]);
        start = end + 1;
    }
    
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
        total += threadData[i].count;
    }
    
    return total;
}

int main() {
    srand(time(NULL));
    int numbers[MAX_NUMBERS];
    int length = readNumbersFromFile("inst100a.txt", numbers);
    
    if (length == 0) {
        printf("Nenhum número lido do arquivo.\n");
        return 1;
    }
    printf("Lidos %d números do arquivo.\n", length);
    
    int target = generateRandomTarget();
    printf("\nSoma alvo: %d\n", target);
    
    printf("\nTestando com diferentes quantidades de threads:\n");
    for (int threads = 1; threads <= MAX_THREADS; threads++) {
        clock_t start = clock();
        int count = findSubsetCount(numbers, length, target, threads);
        clock_t end = clock();
        printf("Threads: %d, Subconjuntos encontrados: %d, Tempo gasto: %.3f segundos\n",
               threads, count, (double)(end - start) / CLOCKS_PER_SEC);
    }
    
    return 0;
}
