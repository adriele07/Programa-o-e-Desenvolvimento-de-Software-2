## Sistema Bibliotecário 
### Universidade Federal de Minas Gerais 
### Programação e Desenvolvimento de Software II – Prof.Evellyn Soares Cavalcante 
### Grupo 10
- Marcella Almeida 
- Laila Tavares
- Julia Reis 
- Luiza Souza
- Adriele
- Yasmim Lopes 
### Objetivo
O funcionamento de uma biblioteca está completamente relacionado a um sistema eficiente para o controle de empréstimos, cadastros de livros e alunos, bem como a organização dos dados. O sistema desenvolvido visa facilitar e otimizar a gestão de uma biblioteca, oferecendo funcionalidades essenciais para alunos e bibliotecários, com o objetivo central de garantir um ambiente de aprendizado e pesquisa mais dinâmico e acessível.

### Funcionalidades
O sistema deve ser capaz de realizar todas as ações básicas de uma biblioteca. As funcionalidades do sistema podem ser separadas de acordo com o tipo de usuário:

Alunos têm permissão para realizar seu próprio cadastro, consultar os livros disponíveis, alugar livros e renovar empréstimos.

Administradores, além de todas as funções de um aluno, podem cadastrar, editar e deletar livros, cadastrar, editar e deletar alunos, gerenciar devoluções, além de terem acesso ao repositório com os dados armazenados. 
### Soluçôes Implementadas  
•	biblioteca/: Diretório raiz do projeto.

•	main.cpp: Arquivo principal que executa o programa.

•	CadastroAdministrador.hpp/cpp: Define a classe Administrador e funções relacionadas.

•	CadastroAluno.hpp/cpp: Define a classe Aluno e funções relacionadas.

•	CadastroLivro.hpp: Define a classe CadastroLivro e funções relacionadas.

•	Emprestimo.hpp/cpp: Define a classe Emprestimo e funções relacionadas.

•	devolver.hpp/cpp: Define a classe Devolver e funções relacionadas.

•	LoginAdministrador.hpp/cpp: Define a classe LoginAdministrador e funções relacionadas.

•	LoginAluno.hpp: Define a classe LoginAluno e funções relacionadas.

•	Livro.hpp: Define a classe Livro.

•	administradores.txt: Armazena os dados dos administradores.

•	alunos.txt: Armazena os dados dos alunos.

•	livros.txt: Armazena os dados dos livros.

•	emprestimos.txt: Armazena os dados dos empréstimos.

 
### Arquitetura do Sistema 

- **Classes e Estruturas de Dados:** O sistema utiliza várias classes e estruturas de dados para representar diferentes entidades na biblioteca. Por exemplo, a classe "Livro" representa um livro na biblioteca, enquanto a estrutura "Aluno" representa um aluno. Essas classes e estruturas de dados são fundamentais para a organização do código, facilitando a compreensão e manutenção do sistema.

- **Armazenamento em Arquivos de Texto:** O sistema faz uso de arquivos de texto para armazenar dados persistentes, como a lista de livros disponíveis na biblioteca e a relação de usuários. Isso garante que as informações sejam mantidas mesmo após o encerramento do programa, proporcionando um registro completo das operações realizadas.

- **Autenticação de Usuários:** Para autenticar os usuários, o sistema emprega as classes "LoginAdministrador" e "LoginAluno". Essas classes são responsáveis por verificar se o nome de usuário e a senha fornecidos correspondem a um administrador ou aluno registrado no sistema, garantindo assim o acesso seguro às funcionalidades.

- **Gerenciamento de Empréstimos:** O sistema utiliza a classe "Emprestimo" para gerenciar os empréstimos de livros. Essa classe realiza verificações para determinar se um livro está disponível para empréstimo antes de efetuar a operação, além de atualizar o status do livro após o empréstimo ser realizado. Essas funcionalidades são essenciais para o controle eficiente dos recursos da biblioteca.
  
### Instalação e Manual de Uso 
#### Instalação 
O sistema é um programa C++ e requer um compilador C++ para ser executado. Aqui estão as etapas para instalar e executar o sistema:
1.	Instale um compilador C++, como o GCC.
2.	Clone o repositório do projeto.
3.	Navegue até o diretório do projeto.
4.	Compile o programa com o comando g++ -o biblioteca main.cpp.
5.	Execute o programa com o comando ./biblioteca.
#### Manual de Uso 
**1. Introdução**

Este manual fornece instruções detalhadas sobre como usar o Sistema de Gerenciamento de Biblioteca. O sistema permite que os usuários se autentiquem como Aluno ou Administrador, cada um com diferentes níveis de acesso e funcionalidades.

**2. Iniciando o Sistema**

Para iniciar o sistema, navegue até o diretório do projeto no terminal e execute o comando ./biblioteca. Isso iniciará o programa.

**3. Autenticação**

Ao iniciar o programa, você será solicitado a se autenticar como Aluno ou Administrador. Insira o nome de usuário e a senha correspondentes para se autenticar.

**4. Interface do Administrador**

Como Administrador, você terá a capacidade de adicionar novos livros ao sistema. Para adicionar um novo livro, siga as instruções fornecidas pelo sistema. Você precisará fornecer detalhes como o título do livro, o autor e o número de cópias disponíveis.

**5. Interface do Aluno**

Como Aluno, você pode emprestar e devolver livros. Para emprestar um livro, siga as instruções fornecidas pelo sistema. Você precisará fornecer o título do livro que deseja emprestar. O sistema verificará se o livro está disponível e, se estiver, o empréstimo será processado.
Para devolver um livro, siga as instruções fornecidas pelo sistema. Você precisará fornecer o ID do livro que deseja devolver. O sistema verificará se o livro foi emprestado por você e, se for, a devolução será processada.

**6. Sair do Sistema**

Para sair do sistema, siga as instruções fornecidas pelo sistema. Certifique-se de sair corretamente para garantir que todas as suas ações sejam salvas corretamente.

### Desafios do desenvolvimento 
Algumas das principais dificuldades encontradas durante o desenvolvimento do projeto incluem:

 •	Gerenciamento de arquivos: O sistema precisa ler e escrever em vários arquivos de texto para manter um registro de livros, usuários e empréstimos. Isso exigiu um bom entendimento de como trabalhar com arquivos em C++.
 
 •	Autenticação de usuários: O sistema precisa autenticar usuários como alunos ou administradores. Isso exigiu a implementação de lógica de autenticação e a manutenção de uma lista de usuários.
 
 •	Gerenciamento de empréstimos: O sistema precisa manter um registro de quais livros foram emprestados e por quem. Isso exigiu a implementação de lógica para emprestar e devolver livros, bem como para verificar se um livro já foi emprestad
