I need to study enums https://www.w3schools.com/cpp/cpp_enum.asp

# Recursividade:
me explique esse programa
```c++
int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

int main() {
  int result = sum(10);
  cout << result;
  return 0;
} 
```

Esse programa é uma implementação recursiva de uma soma de números inteiros consecutivos de 1 até `k`.

### 1. Função `sum(int k)`:
- **Parâmetro**: `k` é o número até o qual queremos somar.
- **Lógica**:
  - Se `k` for maior que 0 (`k > 0`), a função retorna `k` somado ao valor da função `sum(k - 1)`. Ou seja, a função se chama recursivamente, diminuindo `k` a cada chamada.
  - Quando `k` chega a 0, a função retorna 0, que é o caso base da recursão (quando a recursão deve parar).
  
### 2. Função `main()`:
- Aqui, a função `sum(10)` é chamada, o que significa que a função vai somar os números de 10 até 1.
- A recursão começa com `k = 10`, então vai chamando `sum(9)`, `sum(8)`, e assim por diante, até chegar a `sum(0)`, que retorna 0.
- Quando a recursão retorna, os valores são somados: `10 + 9 + 8 + ... + 1`.

### Passo a passo da execução:
1. `sum(10)` chama `sum(9)` → `10 + sum(9)`
2. `sum(9)` chama `sum(8)` → `9 + sum(8)`
3. Isso continua até `sum(1)`, que chama `sum(0)` → `1 + sum(0)`
4. `sum(0)` retorna 0.
5. A recursão começa a retornar: `1 + 0 = 1`, `2 + 1 = 3`, e assim por diante até `10 + 45 = 55`.

### Resultado:
Portanto, o programa vai imprimir `55` no console, que é a soma de todos os números de 1 a 10.

### Resumo:
A função `sum(k)` soma todos os números de `k` até 1, usando recursão. O resultado final, ao chamar `sum(10)`, é 55.
