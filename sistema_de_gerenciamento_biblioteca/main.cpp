#include <iostream>
#include <fstream>
#include "CadastroAdministrador.hpp"
#include "CadastroAluno.hpp"
#include "LoginAdministrador.hpp"
#include "Livro.hpp"
#include "CadastroLivro.hpp"

int main() {
    std::vector<Administrador> administradores;
    std::vector<Aluno> alunos;
    std::ifstream arquivoAdmin("administradores.txt");
    std::ifstream arquivoAluno("alunos.txt");
    std::string nomeDeUsuario, senha, numeroMatricula;

    // Ler administradores existentes do arquivo
    while (std::getline(arquivoAdmin, nomeDeUsuario) && std::getline(arquivoAdmin, senha)) {
        administradores.push_back({nomeDeUsuario, senha});
    }

    // Ler alunos existentes do arquivo
    while (std::getline(arquivoAluno, nomeDeUsuario) && std::getline(arquivoAluno, senha) && std::getline(arquivoAluno, numeroMatricula)) {
        alunos.push_back({nomeDeUsuario, senha, numeroMatricula});
    }

    // Autenticar um administrador
    std::cout << "Digite o nome de usuário do administrador: ";
    std::cin >> nomeDeUsuario;
    std::cout << "Digite a senha do administrador: ";
    std::cin >> senha;

    LoginAdministrador loginAdmin(administradores);
    if (loginAdmin.autenticar(nomeDeUsuario, senha)) {
        std::cout << "Autenticação bem-sucedida." << std::endl;
    } else {
        std::cout << "Erro: Autenticação falhou." << std::endl;
    }

    // Registrar um novo administrador
    std::cout << "Digite o nome de usuário do administrador: ";
    std::cin >> nomeDeUsuario;

    if (isAdministradorRegistrado(administradores, nomeDeUsuario)) {
        std::cout << "Erro: Administrador já registrado." << std::endl;
    } else {
        std::cout << "Digite a senha do administrador: ";
        std::cin >> senha;

        administradores.push_back({nomeDeUsuario, senha});
        salvarAdministradoresEmArquivo(administradores);

        std::cout << "Administrador registrado com sucesso." << std::endl;
    }

  
    std::cout << "Digite o nome de usuário do aluno: ";
    std::cin >> nomeDeUsuario;

    if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
        std::cout << "Erro: Aluno já registrado." << std::endl;
    } else {
        std::cout << "Digite a senha do aluno: ";
        std::cin >> senha;
        std::cout << "Digite o número de matrícula do aluno: ";
        std::cin >> numeroMatricula;

        alunos.push_back({nomeDeUsuario, senha, numeroMatricula});
        salvarAlunosEmArquivo(alunos);

        std::cout << "Aluno registrado com sucesso." << std::endl;
    }
    CadastroLivro cadastroLivro;


        // Adicionar um novo livro
        std::string titulo, autor;
        int ano;
        std::cout << "Digite o título do livro: ";
        std::cin >> titulo;
        std::cout << "Digite o autor do livro: ";
        std::cin >> autor;
        std::cout << "Digite o ano do livro: ";
        std::cin >> ano;

        int id = cadastroLivro.getProximoId();
        cadastroLivro.adicionarLivro({id, titulo, autor, ano});

        std::cout << "Livro registrado com sucesso." << std::endl;

        // Procurar um livro
        std::cout << "Digite o título do livro que você quer procurar: ";
        std::cin >> titulo;

        Livro* livro = cadastroLivro.procurarLivro(titulo);
        if (livro != nullptr) {
            std::cout << "Livro encontrado: " << livro->getTitulo() << ", " << livro->getAutor() << ", " << livro->getAno() << std::endl;
        } else {
            std::cout << "Livro não encontrado." << std::endl;
        }
    
    return 0;
}