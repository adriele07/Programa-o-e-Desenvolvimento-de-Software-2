// CadastroLivro.hpp
#ifndef CADASTRO_LIVRO_HPP
#define CADASTRO_LIVRO_HPP

#include <vector>
#include <fstream>
#include <sstream>
#include "Livro.hpp"

class CadastroLivro {
public:
    CadastroLivro() : proximoId(1) {}

    void adicionarLivro(const Livro& livro) {
        livros.push_back(livro);
        proximoId++;
        salvarLivrosEmArquivo(livro);
    }

    int getProximoId() const {
        return proximoId;
    }

    void salvarLivrosEmArquivo(const Livro& livro) const {
        std::ofstream arquivo("livros.txt", std::ios::app);
        arquivo << livro.getId() << '\n'
            << livro.getTitulo() << '\n'
            << livro.getAutor() << '\n'
            << livro.getAno() << '\n';
        arquivo.close(); // Fechar o arquivo após escrever nele
    }

    Livro* procurarLivro(const std::string& titulo) {
        std::ifstream arquivo("livros.txt");
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::string id = linha;
            std::getline(arquivo, linha);
            std::string tituloArquivo = linha;
            std::getline(arquivo, linha);
            std::string autor = linha;
            std::getline(arquivo, linha);
            std::string ano = linha;
            if (tituloArquivo == titulo) {
                arquivo.close(); // Fechar o arquivo antes de retornar
                return new Livro(std::stoi(id), tituloArquivo, autor, std::stoi(ano));
            }
        }
        arquivo.close(); // Fechar o arquivo caso não encontre o livro
        return nullptr;
    }

private:
    std::vector<Livro> livros;
    int proximoId;
};

#endif // CADASTRO_LIVRO_HPP