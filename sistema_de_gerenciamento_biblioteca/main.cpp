#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Administrador {
    std::string nomeDeUsuario;
    std::string senha;
};

bool isAdministradorRegistrado(const std::vector<Administrador>& administradores, const std::string& nomeDeUsuario) {
    for (const auto& admin : administradores) {
        if (admin.nomeDeUsuario == nomeDeUsuario) {
            return true;
        }
    }
    return false;
}

void salvarAdministradoresEmArquivo(const std::vector<Administrador>& administradores) {
    std::ofstream arquivo("administradores.txt");

    for (const auto& admin : administradores) {
        arquivo << admin.nomeDeUsuario << "\n" << admin.senha << "\n";
    }
}

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