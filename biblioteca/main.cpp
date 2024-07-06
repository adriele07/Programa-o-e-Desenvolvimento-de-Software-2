#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "CadastroAdministrador.hpp"
#include "CadastroAluno.hpp"
#include "LoginAdministrador.hpp"
#include "LoginAluno.hpp"
#include "Livro.hpp"
#include "CadastroLivro.hpp"
#include "Emprestimo.hpp"
#include "devolver.hpp"
#include <string>
#include <ctime>
#include <iomanip> 


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

    LoginAdministrador loginAdmin(administradores); // Inicializar a variável "loginAdmin" fora do switch

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
            std::cout << "Digite o nome de usuario do aluno: ";
            std::getline(std::cin, nomeDeUsuario);
            std::cout << "Digite a senha do aluno: ";
            std::getline(std::cin, senha);

            if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
                std::cout << "Autenticacao bem-sucedida como aluno." << std::endl;
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
                        std::cout << "Digite o titulo do livro que voce quer emprestar: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro nao encontrado." << std::endl;
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
                        std::cout << "Digite o nome de usuario do aluno que vai devolver o livro: ";
                        std::getline(std::cin, nomeDeUsuario);

                        Aluno* aluno = nullptr;
                        for (auto& a : alunos) {
                            if (a.nomeDeUsuario == nomeDeUsuario) {
                                aluno = &a;
                                break;
                            }
                        }

                        if (aluno == nullptr) {
                            std::cout << "Aluno nao encontrado." << std::endl;
                            break;
                        }
                        std::string titulo;
                        std::cout << "Digite o titulo do livro que voce quer devolver: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro nao encontrado." << std::endl;
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
                        std::cout << "Digite o titulo do livro que voce quer consultar: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro nao encontrado." << std::endl;
                            break;
                        }

                        std::cout << "Titulo: " << livro->getTitulo() << std::endl;
                        std::cout << "Autor: " << livro->getAutor() << std::endl;
                        std::cout << "Ano: " << livro->getAno() << std::endl;
                        break;
                    }
                    case 4: {
                        return 0;  // Sair do programa
                    }
                    default:
                        std::cout << "Opcao invalida. Tente novamente.\n";
                    }
                }
            }
            else {
                std::cout << "Erro: Autenticacao falhou." << std::endl;
            }
            break;
        }
        case 2: {
            // Autenticar um administrador
            std::cout << "Digite o nome de usuario do administrador: ";
            std::getline(std::cin, nomeDeUsuario);
            std::cout << "Digite a senha do administrador: ";
            std::getline(std::cin, senha);

            LoginAdministrador loginAdmin(administradores);
            if (loginAdmin.autenticar(nomeDeUsuario, senha)) {
                std::cout << "Autenticacao bem-sucedida como administrador." << std::endl;
                while (true) {
                    std::cout << "Escolha uma opcao:\n";
                    std::cout << "1. Cadastrar aluno\n";
                    std::cout << "2. Cadastrar livro\n";
                    std::cout << "3. Emprestar livro\n";
                    std::cout << "4. Devolver livro\n";
                    std::cout << "5. Editar livro/Excluir livro\n";
                    std::cout << "6. Editar Aluno/Excluir Aluno\n";
                    std::cout << "7. Sair\n";

                    int opcaoAdmin;
                    std::cin >> opcaoAdmin;
                    std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                    switch (opcaoAdmin) {
                    case 1: {
                        // Cadastrar um novo aluno
                        std::cout << "Digite o nome de usuario do aluno: ";
                        std::getline(std::cin, nomeDeUsuario);

                        if (isAlunoRegistrado(alunos, nomeDeUsuario)) {
                            std::cout << "Erro: Aluno ja registrado." << std::endl;
                        }
                        else {
                            std::cout << "Digite a senha do aluno: ";
                            std::getline(std::cin, senha);
                            std::cout << "Digite o numero de matricula do aluno: ";
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
                        std::cout << "Digite o titulo do livro: ";
                        std::getline(std::cin, titulo);
                        std::cout << "Digite o autor do livro: ";
                        std::getline(std::cin, autor);
                        std::cout << "Digite o ano de publicacao do livro: ";
                        std::cin >> ano;
                        std::cin.ignore();  // Ignora o '\n' que fica no buffer após a leitura do número

                        Livro livro(livroId, titulo, autor, ano);
                        cadastroLivro.adicionarLivro(livro);

                        std::cout << "Livro cadastrado com sucesso." << std::endl;
                        break;
                    }
                    case 3: {
                        // Emprestar um livro

                        std::cout << "Digite o nome de usuario do aluno que vai emprestar o livro: ";
                        std::getline(std::cin, nomeDeUsuario);

                        Aluno* aluno = nullptr;
                        for (auto& a : alunos) {
                            if (a.nomeDeUsuario == nomeDeUsuario) {
                                aluno = &a;
                                break;
                            }
                        }

                        if (aluno == nullptr) {
                            std::cout << "Aluno nao encontrado." << std::endl;
                            break;
                        }

                        std::string titulo;
                        std::cout << "Digite o titulo do livro que voce quer emprestar: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro nao encontrado." << std::endl;
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
                        std::cout << "Digite o nome de usuario do aluno que vai devolver o livro: ";
                        std::getline(std::cin, nomeDeUsuario);

                        Aluno* aluno = nullptr;
                        for (auto& a : alunos) {
                            if (a.nomeDeUsuario == nomeDeUsuario) {
                                aluno = &a;
                                break;
                            }
                        }

                        if (aluno == nullptr) {
                            std::cout << "Aluno nao encontrado." << std::endl;
                            break;
                        }

                        std::string titulo;
                        std::cout << "Digite o titulo do livro que voce quer devolver: ";
                        std::getline(std::cin, titulo);

                        Livro* livro = cadastroLivro.procurarLivro(titulo);
                        if (livro == nullptr) {
                            std::cout << "Livro nao encontrado." << std::endl;
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
                    case 5:{
                        std::string nomeArquivo = "livros.txt";

                        // Ler livros
                        std::vector<std::vector<std::string>> livros;
                        std::ifstream arquivo(nomeArquivo);
                        std::string linha;
                        while (std::getline(arquivo, linha)) {
                            std::vector<std::string> livro;
                            livro.push_back(linha);

                            std::getline(arquivo, linha);
                            livro.push_back(linha);

                            std::getline(arquivo, linha);
                            livro.push_back(linha);

                            std::getline(arquivo, linha);
                            livro.push_back(linha);

                            livros.push_back(livro);
                        }

                        // Editar ou excluir livro
                        int id;
                        std::cout << "Digite o ID do livro que deseja editar ou excluir: ";
                        std::cin >> id;

                        std::cout << "Escolha uma opção:\n";
                        std::cout << "1. Editar livro\n";
                        std::cout << "2. Excluir livro\n";

                        int opcao;
                        std::cin >> opcao;

                        if (opcao == 1) {
                            std::string nome;
                            std::string autor;
                            std::string ano;

                            std::cout << "Digite o novo nome do livro: ";
                            std::cin >> nome;

                            std::cout << "Digite o novo nome do autor: ";
                            std::cin >> autor;

                            std::cout << "Digite o novo ano do livro: ";
                            std::cin >> ano;

                            for (auto& livro : livros) {
                                if (std::stoi(livro[0]) == id) {
                                    livro[1] = nome;
                                    livro[2] = autor;
                                    livro[3] = ano;
                                    break;
                                }
                            }
                        } else if (opcao == 2) {
                            livros.erase(std::remove_if(livros.begin(), livros.end(), [id](const std::vector<std::string>& livro) { return std::stoi(livro[0]) == id; }), livros.end());
                        } else {
                            std::cout << "Opcao invalida. Tente novamente.\n";
                            break;
                        }

                        // Salvar livros
                        std::ofstream arquivoOut(nomeArquivo);
                        for (const auto& livro : livros) {
                            arquivoOut << livro[0] << '\n' << livro[1] << '\n' << livro[2] << '\n' << livro[3] << '\n';
                        }
                        break;
                        return 0;  // Sair do programa
                    }
                    case 6: {
                            // Editar ou excluir aluno
                            std::string nomeArquivoAlunos = "alunos.txt";

                            // Ler alunos
                            std::vector<std::vector<std::string>> alunos;
                            std::ifstream arquivoAlunos(nomeArquivoAlunos);
                            std::string linhaAluno;
                            while (std::getline(arquivoAlunos, linhaAluno)) {
                                std::vector<std::string> aluno;
                                aluno.push_back(linhaAluno);

                                std::getline(arquivoAlunos, linhaAluno);
                                aluno.push_back(linhaAluno);

                                std::getline(arquivoAlunos, linhaAluno);
                                aluno.push_back(linhaAluno);

                                alunos.push_back(aluno);
                            }

                            // Editar ou excluir aluno
                            std::string nomeDeUsuario;
                            std::cout << "Digite o nome de usuario do aluno que deseja editar ou excluir: ";
                            std::cin >> nomeDeUsuario;

                            std::cout << "Escolha uma opcao:\n";
                            std::cout << "1. Editar aluno\n";
                            std::cout << "2. Excluir aluno\n";

                            int opcaoAluno;
                            std::cin >> opcaoAluno;

                            if (opcaoAluno == 1) {
                                std::string novoNome;
                                std::string novaSenha;
                                std::string novoNumeroMatricula;

                                std::cout << "Digite o novo nome do aluno: ";
                                std::cin >> novoNome;

                                std::cout << "Digite a nova senha do aluno: ";
                                std::cin >> novaSenha;

                                std::cout << "Digite o novo numero de matricula do aluno: ";
                                std::cin >> novoNumeroMatricula;

                                for (auto& aluno : alunos) {
                                    if (aluno[0] == nomeDeUsuario) {
                                        aluno[1] = novaSenha;
                                        aluno[2] = novoNumeroMatricula;
                                        break;
                                    }
                                }
                            } else if (opcaoAluno == 2) {
                                alunos.erase(std::remove_if(alunos.begin(), alunos.end(), [nomeDeUsuario](const std::vector<std::string>& aluno) {
                                    return aluno[0] == nomeDeUsuario;
                                }), alunos.end());
                            } else {
                                std::cout << "Opção invalida. Tente novamente.\n";
                                break;
                            }

                            // Salvar alunos
                            std::ofstream arquivoOutAlunos(nomeArquivoAlunos);
                            for (const auto& aluno : alunos) {
                                for (const auto& info : aluno) {
                                    arquivoOutAlunos << info << std::endl;
                                }
                            }
                            break;
                        }
                        case 7: {
                            return 0;  // Sair do programa
                        }
                    default:
                        std::cout << "Opção invalida. Tente novamente.\n";
                    }

                }
            }
            else {
                std::cout << "Erro: Autenticacao falhou." << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Saindo do sistema..." << std::endl;
            return 0;
        }
        default:
            std::cout << "Opção invalida. Tente novamente.\n";
        }
    }
}
        
            
        
