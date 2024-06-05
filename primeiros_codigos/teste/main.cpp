// main.cpp
#include "EditarLivro.hpp"
#include "ExcluirLivro.hpp"
#include <iostream>

int main() {
    EditarLivro editor("livros.txt");
    ExcluirLivro excluir("livros.txt");

    int id;
    std::string nome;
    std::string autor;
    int ano;

    std::cout << "Digite o ID do livro que deseja editar: ";
    std::cin >> id;

    std::cout << "Digite o novo nome do livro: ";
    std::cin >> nome;

    std::cout << "Digite o novo nome do autor: ";
    std::cin >> autor;

    std::cout << "Digite o novo ano do livro: ";
    std::cin >> ano;

    Livro novoLivro = { id, nome, autor, ano };
    editor.editarLivro(id, novoLivro);

    std::cout << "Digite o ID do livro que deseja excluir: ";
    std::cin >> id;
    excluir.excluirLivro(id);

    return 0;
}

