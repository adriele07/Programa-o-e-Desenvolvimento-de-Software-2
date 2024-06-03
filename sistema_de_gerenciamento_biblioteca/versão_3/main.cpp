#include <iostream>
#include <fstream>
#include "CadastroAdministrador.hpp"
#include "CadastroAluno.hpp"
#include "LoginAdministrador.hpp"
#include "Livro.hpp"
#include "CadastroLivro.hpp"
#include "Emprestimo.hpp"
#include "devolver.hpp"

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

    CadastroLivro cadastroLivro;

    while (true) {
        std::cout << "Escolha uma opção:\n";
        std::cout << "1. Autenticar administrador\n";
        std::cout << "2. Registrar administrador\n";
        std::cout << "3. Registrar aluno\n";
        std::cout << "4. Adicionar livro\n";
        std::cout << "5. Procurar livro\n";
        std::cout << "6. Emprestar livro\n";
        std::cout << "7. Devolver Livro\n";
        std::cout << "8. Sair\n";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

        switch (opcao) {
            case 1: {
                // Autenticar um administrador
                std::cout << "Digite o nome de usuário do administrador: ";
                std::getline(std::cin, nomeDeUsuario);
                std::cout << "Digite a senha do administrador: ";
                std::getline(std::cin, senha);

                LoginAdministrador loginAdmin(administradores);
                if (loginAdmin.autenticar(nomeDeUsuario, senha)) {
                    std::cout << "Autenticação bem-sucedida." << std::endl;
                } else {
                    std::cout << "Erro: Autenticação falhou." << std::endl;
                }
                break;
            }
            case 2: {
                // Registrar um novo administrador
                std::cout << "Digite o nome de usuário do administrador: ";
                std::getline(std::cin, nomeDeUsuario);

                if (isAdministradorRegistrado(administradores, nomeDeUsuario)) {
                    std::cout << "Erro: Administrador já registrado." << std::endl;
                } else {
                    std::cout << "Digite a senha do administrador: ";
                    std::getline(std::cin, senha);

                    administradores.push_back({nomeDeUsuario, senha});
                    salvarAdministradoresEmArquivo(administradores);

                    std::cout << "Administrador registrado com sucesso." << std::endl;
                }
                break;
            }
            case 3: {
                // Registrar um novo aluno
                std::cout << "Digite o nome de usuário do aluno: ";
                std::getline(std::cin, nomeDeUsuario);

                if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
                    std::cout << "Erro: Aluno já registrado." << std::endl;
                } else {
                    std::cout << "Digite a senha do aluno: ";
                    std::getline(std::cin, senha);
                    std::cout << "Digite o número de matrícula do aluno: ";
                    std::getline(std::cin, numeroMatricula);

                    alunos.push_back({nomeDeUsuario, senha, numeroMatricula});
                    salvarAlunosEmArquivo(alunos);

                    std::cout << "Aluno registrado com sucesso." << std::endl;
                }
                break;
            }
            case 4: {
                // Adicionar um novo livro
                std::string titulo, autor;
                int ano;
                std::cout << "Digite o título do livro: ";
                std::getline(std::cin, titulo);
                std::cout << "Digite o autor do livro: ";
                std::getline(std::cin, autor);
                std::cout << "Digite o ano do livro: ";
                std::cin >> ano;
                std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                int id = cadastroLivro.getProximoId();
                cadastroLivro.adicionarLivro({id, titulo, autor, ano});

                std::cout << "Livro registrado com sucesso." << std::endl;
                break;
            }
            case 5: {
                // Procurar um livro
                std::string titulo;
                std::cout << "Digite o título do livro que você quer procurar: ";
                std::getline(std::cin, titulo);

                Livro* livro = cadastroLivro.procurarLivro(titulo);
                if (livro != nullptr) {
                    std::cout << "Livro encontrado: " << livro->getTitulo() << ", " << livro->getAutor() << ", " << livro->getAno() << std::endl;
                } else {
                    std::cout << "Livro não encontrado." << std::endl;
                }
                break;
            }
            case 6: {
                // Emprestar um livro
                std::cout << "Digite o nome de usuário do aluno que vai emprestar o livro: ";
                std::getline(std::cin, nomeDeUsuario);

                Aluno* aluno = nullptr;
                for (auto& a : alunos) {
                    if (a.nomeDeUsuario == nomeDeUsuario) {
                        aluno = &a;
                        break;
                    }
                }

                if (aluno == nullptr) {
                    std::cout << "Aluno não encontrado." << std::endl;
                    break;
                }

                std::string titulo;
                std::cout << "Digite o título do livro que você quer emprestar: ";
                std::getline(std::cin, titulo);

                Livro* livro = cadastroLivro.procurarLivro(titulo);
                if (livro == nullptr) {
                    std::cout << "Livro não encontrado." << std::endl;
                    break;
                }

                std::string dataEmprestimo = "2022-01-01"; // Assume 'dataEmprestimo' is the current date in string format
                Emprestimo emprestimo(*livro, *aluno, dataEmprestimo);
                emprestimo.realizarEmprestimo();
                std::cout << "Livro emprestado com sucesso." << std::endl;
                break;
            }
            case 7: {
        // Devolver um livro
        std::cout << "Digite o nome de usuário do aluno que vai devolver o livro: ";
        std::getline(std::cin, nomeDeUsuario);
    
        Aluno* aluno = nullptr;
        for (auto& a : alunos) {
            if (a.nomeDeUsuario == nomeDeUsuario) {
                aluno = &a;
                break;
            }
        }
    
        if (aluno == nullptr) {
            std::cout << "Aluno não encontrado." << std::endl;
            break;
        }
    
        std::string titulo;
        std::cout << "Digite o título do livro que você quer devolver: ";
        std::getline(std::cin, titulo);
    
        Livro* livro = cadastroLivro.procurarLivro(titulo);
        if (livro == nullptr) {
            std::cout << "Livro não encontrado." << std::endl;
            break;
        }
    
        // Assume 'dataDevolucao' is the current date in string format
        std::string dataDevolucao = "2022-01-01"; 
        Emprestimo emprestimo(*livro, *aluno, dataDevolucao);
        Devolver devolver(emprestimo);
        devolver.realizarDevolucao();
        std::cout << "Livro devolvido com sucesso." << std::endl;
        break;
    }
        case 8:{
                return 0;  // Sair do programa
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
    return 0;
}