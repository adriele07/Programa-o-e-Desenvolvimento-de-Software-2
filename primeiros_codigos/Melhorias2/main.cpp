#include <iostream>
#include <fstream>
#include <vector>
#include "CadastroAdministrador.hpp"
#include "CadastroAluno.hpp"
#include "LoginAdministrador.hpp"
#include "LoginAluno.hpp"
#include "Livro.hpp"
#include "CadastroLivro.hpp"
#include "Emprestimo.hpp"
#include "devolver.hpp"
#include "EditarLivro.hpp"
#include "ExcluirLivro.hpp"
#include <string>
#include <ctime>
#include <iomanip> // Para std::put_time

std::string getCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm localTime;
    localtime_r(&now, &localTime);
    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d");
    return oss.str();
}

int main() {
    std::vector<Administrador> administradores;
    std::vector<Aluno> alunos;
    std::ifstream arquivoAdmin("administradores.txt");
    std::ifstream arquivoAluno("alunos.txt");
    std::string nomeDeUsuario, senha, numeroMatricula;

    // Ler administradores existentes do arquivo
    while (arquivoAdmin >> nomeDeUsuario >> senha) {
        administradores.push_back({ nomeDeUsuario, senha });
    }

    // Ler alunos existentes do arquivo
    while (arquivoAluno >> nomeDeUsuario >> senha >> numeroMatricula) {
        alunos.push_back({ nomeDeUsuario, senha, numeroMatricula });
    }

    CadastroLivro cadastroLivro;

    std::cout << "Bem-vindo ao sistema de biblioteca!" << std::endl;

    while (true) {
        std::cout << "Escolha uma opcao:\n";
        std::cout << "1. Sou aluno\n";
        std::cout << "2. Sou administrador\n";
        std::cout << "3. Sair\n";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

        switch (opcao) {
        case 1: {
            // Autenticar um aluno
            std::cout << "Digite o nome de usuário do aluno: ";
            std::getline(std::cin, nomeDeUsuario);
            std::cout << "Digite a senha do aluno: ";
            std::getline(std::cin, senha);

            if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
                std::cout << "Autenticação bem-sucedida como aluno." << std::endl;
                while (true) {
                    std::cout << "Escolha uma opcao:\n";
                    std::cout << "1. Emprestar livro\n";
                    std::cout << "2. Devolver livro\n";
                    std::cout << "3. Consultar livro\n";
                    std::cout << "4. Sair\n";

                    int opcaoAluno;
                    std::cin >> opcaoAluno;
                    std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                    switch (opcaoAluno) {
                    case 1: {
                        // Emprestar um livro
                        std::string titulo;
                        std::cout << "Digite o título do livro que você quer emprestar: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro não encontrado." << std::endl;
                            break;
                        }

                        std::string dataEmprestimo = getCurrentDate();
                        Emprestimo emprestimo(*livro, alunos[0], dataEmprestimo);
                        emprestimo.realizarEmprestimo();
                        std::cout << "" << std::endl;
                        break;
                    }
                    case 2: {
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
                        Emprestimo emprestimo(*livro, alunos[0], dataDevolucao);
                        Devolver devolver(emprestimo);
                        devolver.realizarDevolucao();
                        std::cout << "Livro devolvido com sucesso." << std::endl;
                        break;
                    }
                    case 3: {
                        // Consultar um livro
                        std::string titulo;
                        std::cout << "Digite o título do livro que você quer consultar: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro não encontrado." << std::endl;
                            break;
                        }

                        std::cout << "Título: " << livro->getTitulo() << std::endl;
                        std::cout << "Autor: " << livro->getAutor() << std::endl;
                        std::cout << "Ano: " << livro->getAno() << std::endl;
                        break;
                    }
                    case 4: {
                        return 0;  // Sair do programa
                    }
                    default:
                        std::cout << "Opção inválida. Tente novamente.\n";
                    }
                }
            }
            else {
                std::cout << "Erro: Autenticação falhou." << std::endl;
            }
            break;
        }
        case 2: {
            // Autenticar um administrador
            std::cout << "Digite o nome de usuário do administrador: ";
            std::getline(std::cin, nomeDeUsuario);
            std::cout << "Digite a senha do administrador: ";
            std::getline(std::cin, senha);

            LoginAdministrador loginAdmin(administradores);
            if (loginAdmin.autenticar(nomeDeUsuario, senha)) {
                std::cout << "Autenticação bem-sucedida como administrador." << std::endl;
                while (true) {
                    std::cout << "Escolha uma opcao:\n";
                    std::cout << "1. Cadastrar aluno\n";
                    std::cout << "2. Cadastrar livro\n";
                    std::cout << "3. Emprestar livro\n";
                    std::cout << "4. Devolver livro\n";
                    std::cout << "5. Editar livro\n";
                    std::cout << "6. Excluir livro\n";
                    std::cout << "7. Sair\n";

                    int opcaoAdmin;
                    std::cin >> opcaoAdmin;
                    std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                    switch (opcaoAdmin) {
                    case 1: {
                        // Cadastrar um novo aluno
                        std::cout << "Digite o nome de usuário do aluno: ";
                        std::getline(std::cin, nomeDeUsuario);

                        if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
                            std::cout << "Erro: Aluno já registrado." << std::endl;
                        }
                        else {
                            std::cout << "Digite a senha do aluno: ";
                            std::getline(std::cin, senha);
                            std::cout << "Digite o número de matrícula do aluno: ";
                            std::getline(std::cin, numeroMatricula);

                            alunos.push_back({ nomeDeUsuario, senha, numeroMatricula });
                            salvarAlunosEmArquivo(alunos);

                            std::cout << "Aluno registrado com sucesso." << std::endl;
                        }
                        break;
                    }
                    case 2: {
                        // Adicionar um novo livro
                        std::string titulo, autor;
                        int ano;
                        int livroId = 1; // or generate an appropriate ID
                        std::cout << "Digite o título do livro: ";
                        std::getline(std::cin, titulo);
                        std::cout << "Digite o autor do livro: ";
                        std::getline(std::cin, autor);
                        std::cout << "Digite o ano de publicação do livro: ";
                        std::cin >> ano;
                        std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                        Livro livro(livroId, titulo, autor, ano);
                        cadastroLivro.adicionarLivro(livro);

                        std::cout << "Livro cadastrado com sucesso." << std::endl;
                        break;
                    }
                    case 3: {
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

                        std::string dataEmprestimo = getCurrentDate();
                        Emprestimo emprestimo(*livro, alunos[0], dataEmprestimo);
                        emprestimo.realizarEmprestimo();
                        std::cout << "" << std::endl;
                        break;
                    }
                    case 4: {
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
                        Emprestimo emprestimo(*livro, alunos[0], dataDevolucao);
                        Devolver devolver(emprestimo);
                        devolver.realizarDevolucao();
                        std::cout << "Livro devolvido com sucesso." << std::endl;
                        break;
                    }
                    case 5: {
                        // Editar um livro
                        std::cout << "Digite o ID do livro que deseja editar: ";
                        std::cin >> id;
                        std::cin.ignore();

                        std::cout << "Digite o novo nome do livro: ";
                        std::getline(std::cin, nome);

                        std::cout << "Digite o novo nome do autor: ";
                        std::getline(std::cin, autor);

                        std::cout << "Digite o novo ano do livro: ";
                        std::cin >> ano;
                        std::cin.ignore();

                        Livro novoLivro = { id, nome, autor, ano };
                        editor.editarLivro(id, novoLivro);

                        std::cout << "Livro editado com sucesso." << std::endl;
                        break;
                    }
                    case 6: {
                        // Excluir um livro
                        std::cout << "Digite o ID do livro que deseja excluir: ";
                        std::cin >> id;
                        std::cin.ignore();

                        excluir.excluirLivro(id);

                        std::cout << "Livro excluído com sucesso." << std::endl;
                        break;
                    }
                    case 7: {
                        return 0;  // Sair do programa
                    }
                    default:
                        std::cout << "Opção inválida. Tente novamente.\n";
                    }
                }
            }
            else {
                std::cout << "Erro: Autenticação falhou." << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Saindo do sistema..." << std::endl;
            return 0;
        }
        default:
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }
}
