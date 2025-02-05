# Relatório - Sistemas Distribuídos

## Autores
- Maria Clara Landim Braz
- Guilherme Leandro Nogueira

## Estrutura do Código em C

### Bibliotecas Usadas
O programa foi implementado em C++ e faz uso das seguintes bibliotecas:
- **`stdio.h`** e **`stdlib.h`**: Manipulação de entrada e saída, alocação de memória.
- **`pthread.h`**: Para implementação do paralelismo com threads.
- **`time.h`**: Para medir o tempo de execução.

### Principais Funções

#### `countSubsets()`
Função executada por cada thread, que percorre subconjuntos do segmento do vetor de entrada e verifica se a soma dos elementos equivale ao valor alvo.

#### `readNumbersFromFile()`
Lê um conjunto de números inteiros a partir de um arquivo e os armazena em um array.

#### `generateRandomTarget()`
Gera um valor aleatório entre 100 e 1000 para ser usado como soma alvo.

#### `findSubsetCount()`
- Divide o vetor de entrada em segmentos, distribuindo-os entre threads.
- Cria e executa as threads para processar os subconjuntos em paralelo.
- Aguarda a finalização das threads e soma os resultados.

#### `main()`
- Lê os dados do arquivo.
- Gera um valor alvo aleatório.
- Executa o algoritmo variando o número de threads de 1 a 4.
- Mede e exibe o tempo de execução e o número de subconjuntos encontrados.

---


## Resultados por Arquivo

### Arquivo: inst100a
- **Números Lidos**: 102
- **Soma Alvo**: 674

| Threads | Subconjuntos Encontrados | Tempo Gasto (ms) |
|---------|--------------------------|------------------|
| 1       | 16.332                  | 92               |
| 2       | 243                     | 1                |
| 3       | 34                      | 2                |
| 4       | 19                      | 1                |

### Arquivo: inst500a
- **Números Lidos**: 502
- **Soma Alvo**: 146

| Threads | Subconjuntos Encontrados | Tempo Gasto (ms) |
|---------|--------------------------|------------------|
| 1       | 7                        | 6                |
| 2       | 2                        | 0                |
| 3       | 2                        | 2                |
| 4       | 1                        | 1                |

### Arquivo: inst1000a
- **Números Lidos**: 1002
- **Soma Alvo**: 490

| Threads | Subconjuntos Encontrados | Tempo Gasto (ms) |
|---------|--------------------------|------------------|
| 1       | 6.115                   | 78               |
| 2       | 81                      | 1                |
| 3       | 27                      | 2                |
| 4       | 13                      | 0                |

### Arquivo: inst5000a
- **Números Lidos**: 5002
- **Soma Alvo**: 223

| Threads | Subconjuntos Encontrados | Tempo Gasto (ms) |
|---------|--------------------------|------------------|
| 1       | 18                      | 15               |
| 2       | 4                       | 3                |
| 3       | 3                       | 3                |
| 4       | 3                       | 8                |
