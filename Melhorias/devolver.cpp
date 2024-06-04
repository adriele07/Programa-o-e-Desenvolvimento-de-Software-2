#include "devolver.hpp"
#include <fstream>
#include <sstream>

// Constructor
Devolver::Devolver(Emprestimo& emprestimo) : emprestimo(emprestimo) {
    // No setup needed in this case
}

// realizarDevolucao method
void Devolver::realizarDevolucao() {
    std::ifstream arquivo("emprestimos.txt");
    std::ofstream temp("temp.txt");
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        std::getline(ss, campo, ',');  // ID do livro

        // If the line does not correspond to the returned book, write it to the temporary file
        if (std::stoi(campo) != emprestimo.getLivro().getId()) {
            temp << linha << "\n";
        }
    }

    // Close the files
    arquivo.close();
    temp.close();

    // Delete the original file and rename the temporary file
    remove("emprestimos.txt");
    rename("temp.txt", "emprestimos.txt");
}