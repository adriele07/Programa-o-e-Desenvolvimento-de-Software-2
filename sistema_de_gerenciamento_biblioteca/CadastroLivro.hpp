#ifndef CADASTRO_LIVRO_HPP
#define CADASTRO_LIVRO_HPP

#include <vector>
#include <fstream>
#include "Livro.hpp"

class CadastroLivro {
public:
    CadastroLivro() : proximoId(1) {}

    void adicionarLivro(const Livro& livro) {
        livros.push_back(livro);
        proximoId++;
    }

    int getProximoId() const {
        return proximoId;
    }

    void salvarLivrosEmArquivo() const {
        std::ofstream arquivo("livros.txt");
        for (const auto& livro : livros) {
            arquivo << livro.getId() << '\n'
                    << livro.getTitulo() << '\n'
                    << livro.getAutor() << '\n'
                    << livro.getAno() << '\n';
        }
    }

    Livro* procurarLivro(const std::string& titulo) {
        for (auto& livro : livros) {
            if (livro.getTitulo() == titulo) {
                return &livro;
            }
        }
        return nullptr;
    }

private:
    std::vector<Livro> livros;
    int proximoId;
};

#endif // CADASTRO_LIVRO_HPP