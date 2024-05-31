#include <string>
#include <vector>

struct Administrador {
    std::string nomeDeUsuario;
    std::string senha;
};

bool isAdministradorRegistrado(const std::vector<Administrador>& administradores, const std::string& nomeDeUsuario);
void salvarAdministradoresEmArquivo(const std::vector<Administrador>& administradores);