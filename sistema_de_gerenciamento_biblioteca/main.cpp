#include <iostream>
#include <fstream>
#include "Administrador.hpp"
#include "CadastroAluno.hpp"

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

    // Registrar um novo aluno
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

    return 0;
}