#include <iostream>
#include <fstream>
#include "Administrador.hpp"

int main() {
    std::vector<Administrador> administradores;
    std::ifstream arquivo("administradores.txt");
    std::string nomeDeUsuario, senha;

    // Ler administradores existentes do arquivo
    while (std::getline(arquivo, nomeDeUsuario) && std::getline(arquivo, senha)) {
        administradores.push_back({nomeDeUsuario, senha});
    }

    // Registrar um novo administrador
    std::cout << "Digite o nome de usuário: ";
    std::cin >> nomeDeUsuario;

    if (isAdministradorRegistrado(administradores, nomeDeUsuario)) {
        std::cout << "Erro: Administrador já registrado." << std::endl;
    } else {
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        administradores.push_back({nomeDeUsuario, senha});
        salvarAdministradoresEmArquivo(administradores);

        std::cout << "Administrador registrado com sucesso." << std::endl;
    }

    return 0;
}