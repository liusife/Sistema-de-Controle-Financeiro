# **Documento de Requisitos do Produto (PRD)**

**Equipe:** Ana Vitória, Kauã Cesar, Luis Henrique e Miguel Arcanjo

## **1\. Visão Geral do Produto**

O Sistema de Controle Financeiro é uma aplicação de linha de comando (CLI) desenvolvida em linguagem C. O objetivo é oferecer aos usuários uma ferramenta local, segura e rápida para registrar, monitorar e gerenciar suas finanças pessoais. A aplicação garante a privacidade dos dados por meio de um sistema de autenticação e armazenamento local isolado por usuário.

## **2\. Problema a ser Resolvido**

A falta de controle sobre receitas e despesas cotidianas gera insegurança financeira. Ferramentas existentes muitas vezes são complexas, exigem conexão constante com a internet ou expõem dados a servidores de terceiros. Este sistema resolve o problema oferecendo uma interface de terminal focada na agilidade do registro e na privacidade total dos dados.

## **3\. Requisitos Funcionais (O que o sistema fará)**

### **3.1. Módulo de Autenticação e Usuário**

* Cadastro de Usuário: O sistema deve permitir a criação de uma nova conta solicitando o CPF (que servirá como login exclusivo) e uma senha.  
* Login de Usuário: Apenas usuários cadastrados poderão acessar o sistema mediante validação do CPF e senha.  
* Isolamento de Dados: Todos os registros financeiros devem ser atrelados exclusivamente ao CPF logado, garantindo que nenhum usuário visualize as informações de outro.

### **3.2. Módulo de Gestão Financeira (Menu Principal)**

* Registro de Despesas e Receitas: O usuário poderá inserir novos valores informando a descrição e o montante.  
* Registro de Transações: O usuário poderá cadastrar movimentações especificando a forma de pagamento/recebimento: Pix, Crédito ou Débito.  
* Operações de Edição e Exclusão (UX baseada em ID):  
  * O sistema deve listar as receitas, despesas ou transações salvas, exibindo um número de identificação (ID) único para cada registro.  
  * O usuário deverá digitar o ID correspondente à ação desejada para editar o valor/descrição ou excluir o registro permanentemente.

### **3.3. Módulo de Saldo e Relatórios**

* Consulta de Saldo: O menu deve possuir a opção "Saldo", calculando em tempo real a diferença entre as receitas e as despesas/transações do usuário.  
* Geração de Relatórios:  
  * *Relatório Geral:* Uma visão consolidada (formato de fatura) contendo todas as movimentações do período.  
  * *Relatórios Específicos:* O usuário poderá escolher filtrar a visualização apenas por Despesas, apenas por Receitas ou apenas por Transações.

## **4\. Requisitos Não Funcionais (Como o sistema fará)**

* Linguagem de Programação: C (ANSI C).  
* Interface do Usuário (UI): Menu interativo no Terminal/Console. A navegação deve ser intuitiva. Estamos estudando como navegar na aplicação utilizando as setas.  
* Persistência de Dados (Banco de Dados Local): As informações (usuários e registros financeiros) deverão ser salvas em arquivos locais.  
* Desempenho: O sistema deve carregar e filtrar as informações quase instantaneamente, dado o processamento local.

## **5\. Roadmap e Funcionalidades Futuras**

As seguintes funcionalidades estão mapeadas para o ciclo de desenvolvimento futuro, após a entrega do Produto Mínimo Viável (MVP):

* Categorização Personalizada: Permitir que o usuário crie categorias customizadas para suas Despesas (ex: *Aluguel, Conta de Luz, Conta de Água, Combustível*) e Receitas (ex: *Salário, Freelance*), possibilitando relatórios analíticos mais detalhados.

*Obs: O Documento de Requisitos do Produto (PRD) pode ser atualizado a qualquer momento durante o processo.*