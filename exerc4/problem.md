
# Exercício 4 — Tabela Hash com Nome como Chave

Crie uma tabela hash para armazenar dados de alunos contendo as seguintes informações:

- Número USP
- Nome
- Curso

Nesta versão, **o nome do aluno é utilizado como chave da tabela hash**.

---

## Função Hash

A função hash deve seguir os passos abaixo:

### 1. Cálculo de `h₁`

Para cada caractere da string original (sem compressão), calcule:

\[
h_1 = \sum_{i=0}^{n-1} \left(\text{ascii}[i] \ll (i \mod 8)\right)
\]

Onde:

- `ascii[i]` é o valor ASCII do caractere na posição `i`
- `<<` representa o deslocamento de bits à esquerda
- `i mod 8` limita o deslocamento a no máximo 7 bits

---

### 2. Rotação à esquerda de 13 bits

Aplique uma **rotação à esquerda de 13 bits** sobre o valor total (`h₁`), movendo os bits para a esquerda em 13 posições. Os bits que "saem" pela esquerda devem retornar pela direita.

#### Exemplo (com 16 bits para facilitar a visualização):

```text
valor = 1011001110001111
```

Rotação à esquerda de 3 bits:

```text
rotl(valor, 3) = 1001110001111101
```

> Os três bits mais à esquerda (`101`) foram movidos para o final.

---

### 3. Cálculo de `h₂` (índice final)

O índice na tabela hash é obtido por:

```text
h₂ = h₁ mod m
```

Onde `m` é o tamanho atual da tabela hash.

---

## Tratamento de Colisões

Utilize a técnica de **encadeamento** (separate chaining):

- Cada posição da tabela deve conter uma **lista ligada**
- Cada nó da lista deve conter:
  - O nome do aluno
  - O número USP
  - O curso
  - Um ponteiro para o próximo nó (caso exista)

---

