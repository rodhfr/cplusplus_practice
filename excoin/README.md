# Excoin: Transações em Criptomoedas

Simula transações de compra e venda de criptomoedas e utiliza BRL como moeda de troca franca. Permite a criacao de carteiras para armazenar moedas em BTC, ETH e BRL, assim como suas respectivas transações. 

## Compilando o Projeto:

- git clone repositório

### Linux:
#### Requisitos:
- Compilador de C++ (g++ ou clang) 
- Make 
```bash
# Ubuntu
sudo apt install build-essential
# Arch
sudo pacman -Syu make
```
```bash
cd ./excoin
make
./excoin
```
ou compile e rode diretamente:
```bash
cd ./excoin && make run
```
```bash
make clean
```
para limpar arquivos de compilacao.

### Windows:
#### Requisitos:
- Compilador de C++ (g++ ou clang) 
- Make 
```shell
# gnu make port for windows disponivel no winget
winget install ezwinports.make
# minimal gnu compiler for windows no gerenciador de pacotes chocolatey
choco install mingw
```
```shell
cd .\excoin
make
.\excoin
```
ou compile e rode diretamente:
```shell
cd .\excoin && make run
```
```shell 
make clean
```
para limpar arquivos de compilacao.

## Visão geral do código
### **Carteira**
A classe **Carteira** é responsável por armazenar informações relacionadas à conta do usuário, como o endereço da carteira e os saldos das moedas BTC, ETH e BRL. Ela oferece funcionalidades para realizar depósitos e saques de cada uma dessas moedas. Para garantir a integridade dos dados, o código valida a quantidade a ser depositada ou sacada, impedindo valores negativos ou saques superiores ao saldo disponível. O endereço da carteira é passado no momento da criação, e o saldo de cada moeda pode ser inicializado com valores específicos.

O construtor da classe aloca dinamicamente memória para armazenar o endereço da carteira, e o destruidor (`~Carteira`) garante a liberação da memória quando a instância da classe for destruída. Além disso, a classe possui um método `exibir_saldo()` que imprime o endereço da carteira e os saldos atuais das moedas BTC, ETH e BRL.

### **Transação**
A classe **Transação** representa uma operação de compra ou venda de criptomoedas entre duas carteiras. Cada transação inclui um tipo (compra ou venda), a moeda sendo comprada ou vendida, a quantidade de moeda envolvida e os preços unitários de BTC, ETH e BRL. O preço unitário é fixado dentro da classe (por exemplo, 1 BTC = 50.000 BRL e 1 ETH = 1.500 BRL).

A classe tem um construtor que inicializa os parâmetros da transação e determina a moeda de origem e destino com base no tipo de transação (compra ou venda). O método `executar_transacao()` é responsável por realizar a operação, verificando se a carteira de origem possui saldo suficiente para a transação e se a carteira de destino tem a quantidade de criptomoeda necessária. Caso a operação seja válida, o saldo das duas carteiras é atualizado, e a transação é concluída com sucesso. Caso contrário, uma mensagem de erro é exibida, informando o motivo da falha.

A transação também valida se o tipo da moeda fornecida (BTC ou ETH) é compatível com a operação. Para mapear a moeda, o código usa um método auxiliar (`mapear_moeda`), que converte o nome da moeda em um código numérico (500 para BRL, 600 para BTC e 700 para ETH).

### **Exchange**
A classe **Exchange** é o coração do sistema, responsável por gerenciar as carteiras e realizar transações entre elas. Ela armazena as carteiras em um array dinâmico e permite adicionar novas carteiras à exchange. A classe também tem um método `exibir_carteiras()` que exibe os saldos das carteiras cadastradas.

Quando uma transação é solicitada, o método `realizar_transacao()` cria uma nova instância da classe **Transação** e a executa. Após a execução da transação, ela é registrada na exchange em um array de transações.

O código simula a criação de três carteiras com diferentes saldos de BTC, ETH e BRL. A seguir, realiza diversas transações entre as carteiras, como compras e vendas de criptomoedas. O estado das carteiras é exibido antes e depois das operações, permitindo verificar as mudanças nos saldos.

### **Fluxo de Execução**
No programa principal, a exchange é inicializada, carteiras são criadas e adicionadas à exchange. Em seguida, são realizadas transações de compra e venda entre as carteiras, como:

- **Compra de BTC**: A carteira 3 compra 0.1 BTC da carteira 1.
- **Venda de ETH**: A carteira 2 vende 1 ETH para a carteira 3.
- **Tentativa de compra sem saldo suficiente**: A carteira 1 tenta comprar 2 BTC da carteira 2, mas falha devido ao saldo insuficiente.
- **Tentativa de venda com quantidade insuficiente**: A carteira 3 tenta vender 5 ETH para a carteira 2, mas a transação falha devido à quantidade insuficiente.
