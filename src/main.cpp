#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Astronauta
{
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;

public:
    Astronauta(string cpf, string nome, int idade)
    {
        this->cpf = cpf;
        this->nome = nome;
        this->idade = idade;
        this->vivo = true;
        this->disponivel = true;
    }

    string getCpf() const
    {
        return cpf;
    }

    string getNome() const
    {
        return nome;
    }

    int getIdade() const
    {
        return idade;
    }

    bool estaVivo() const
    {
        return vivo;
    }

    bool estaDisponivel() const
    {
        return disponivel;
    }

    void embarcar()
    { // fica indisponivel
        disponivel = false;
    }

    void desembarcar()
    { // volta a ficar disponivel, se estiver vivo
        if (vivo)
        {
            disponivel = true;
        }
    }

    void morrer()
    { // fica morto e indisponivel
        vivo = false;
        disponivel = false;
    }

    void definirEstado(bool v, bool d)
    {
        vivo = v;
        disponivel = d;
    }
};

class Voo
{
private:
    int codigo;
    string estado;
    vector<string> cpfs;

public:
    Voo(int codigo)
    {
        this->codigo = codigo;
        this->estado = "planejado";
    }

    int getCodigo() const
    {
        return codigo;
    }

    string getEstado() const
    {
        return estado;
    }

    int getQuantidadeAstronautas() const
    {
        return (int)cpfs.size();
    }

    string getCpf(int posicao) const
    {
        return cpfs[posicao];
    }

    bool temAstronauta(string cpf) const
    {
        for (int i = 0; i < (int)cpfs.size(); i++)
        {
            if (cpfs[i] == cpf)
            {
                return true;
            }
        }
        return false;
    }

    void adicionarAstronauta(string cpf)
    {
        cpfs.push_back(cpf);
    }

    bool removerAstronauta(string cpf)
    { // false se o CPF nao estava no voo
        for (int i = 0; i < (int)cpfs.size(); i++)
        {
            if (cpfs[i] == cpf)
            {
                cpfs.erase(cpfs.begin() + i);
                return true;
            }
        }
        return false;
    }

    void lancar()
    {
        estado = "em curso";
    }

    void explodir()
    {
        estado = "finalizado com explosao";
    }

    void finalizar()
    {
        estado = "finalizado com sucesso";
    }
};

class Agencia
{
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;

    int buscarAstronauta(string cpf) const
    {
        for (int i = 0; i < (int)astronautas.size(); i++)
        {
            if (astronautas[i].getCpf() == cpf)
            {
                return i;
            }
        }
        return -1;
    }

    int buscarVoo(int codigo) const
    {
        for (int i = 0; i < (int)voos.size(); i++)
        {
            if (voos[i].getCodigo() == codigo)
            {
                return i;
            }
        }
        return -1;
    }

    void embarcarAstronautasDoVoo(int indiceVoo)
    {
        for (int i = 0; i < voos[indiceVoo].getQuantidadeAstronautas(); i++)
        {
            string cpf = voos[indiceVoo].getCpf(i);
            int indiceAstronauta = buscarAstronauta(cpf);
            astronautas[indiceAstronauta].embarcar();
        }
    }

    void morrerAstronautasDoVoo(int indiceVoo)
    {
        for (int i = 0; i < voos[indiceVoo].getQuantidadeAstronautas(); i++)
        {
            string cpf = voos[indiceVoo].getCpf(i);
            int indiceAstronauta = buscarAstronauta(cpf);
            astronautas[indiceAstronauta].morrer();
        }
    }

    void desembarcarAstronautasDoVoo(int indiceVoo)
    {
        for (int i = 0; i < voos[indiceVoo].getQuantidadeAstronautas(); i++)
        {
            string cpf = voos[indiceVoo].getCpf(i);
            int indiceAstronauta = buscarAstronauta(cpf);
            astronautas[indiceAstronauta].desembarcar();
        }
    }

public:
    void cadastrarAstronauta(string cpf, string nome, int idade)
    {
        if (buscarAstronauta(cpf) != -1)
        {
            cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
            return;
        }

        astronautas.push_back(Astronauta(cpf, nome, idade));

        cout << "OK: astronauta " << cpf << " cadastrado" << endl;
    }

    void cadastrarVoo(int codigo)
    {
        if (buscarVoo(codigo) != -1)
        {
            cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
            return;
        }

        voos.push_back(Voo(codigo));

        cout << "OK: voo " << codigo << " cadastrado" << endl;
    }

    void adicionarAstronauta(string cpf, int codigo)
    {
        int indiceAstronauta = buscarAstronauta(cpf);

        if (indiceAstronauta == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        int indiceVoo = buscarVoo(codigo);

        if (indiceVoo == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[indiceVoo].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (!astronautas[indiceAstronauta].estaVivo())
        {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }

        if (voos[indiceVoo].temAstronauta(cpf))
        {
            cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
            return;
        }

        voos[indiceVoo].adicionarAstronauta(cpf);

        cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
    }

    void removerAstronauta(string cpf, int codigo)
    {
        int indiceAstronauta = buscarAstronauta(cpf);

        if (indiceAstronauta == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        int indiceVoo = buscarVoo(codigo);

        if (indiceVoo == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[indiceVoo].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (!voos[indiceVoo].temAstronauta(cpf))
        {
            cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
            return;
        }

        voos[indiceVoo].removerAstronauta(cpf);

        cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
    }

    void lancarVoo(int codigo)
    {
        int indiceVoo = buscarVoo(codigo);

        if (indiceVoo == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[indiceVoo].getEstado() != "planejado")
        {
            cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
            return;
        }

        if (voos[indiceVoo].getQuantidadeAstronautas() == 0)
        {
            cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
            return;
        }

        for (int i = 0; i < voos[indiceVoo].getQuantidadeAstronautas(); i++)
        {
            string cpf = voos[indiceVoo].getCpf(i);
            int indiceAstronauta = buscarAstronauta(cpf);

            if (!astronautas[indiceAstronauta].estaVivo())
            {
                cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
                return;
            }

            if (!astronautas[indiceAstronauta].estaDisponivel())
            {
                cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
                return;
            }
        }

        embarcarAstronautasDoVoo(indiceVoo);

        voos[indiceVoo].lancar();

        cout << "OK: voo " << codigo << " lancado" << endl;
    }

    void explodirVoo(int codigo)
    {
        int indiceVoo = buscarVoo(codigo);

        if (indiceVoo == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[indiceVoo].getEstado() != "em curso")
        {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        morrerAstronautasDoVoo(indiceVoo);

        voos[indiceVoo].explodir();

        cout << "OK: voo " << codigo << " explodiu" << endl;
    }

    void finalizarVoo(int codigo)
    {
        int indiceVoo = buscarVoo(codigo);

        if (indiceVoo == -1)
        {
            cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
            return;
        }

        if (voos[indiceVoo].getEstado() != "em curso")
        {
            cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
            return;
        }

        desembarcarAstronautasDoVoo(indiceVoo);

        voos[indiceVoo].finalizar();

        cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
    }

    void listarVoos()
    {

        cout << "LISTA DE VOOS" << endl;

        string estados[] = {
            "planejado",
            "em curso",
            "finalizado com sucesso",
            "finalizado com explosao"};

        for (int e = 0; e < 4; e++)
        {
            cout << "== " << estados[e] << " ==" << endl;

            bool encontrou = false;

            for (int i = 0; i < (int)voos.size(); i++)
            {
                if (voos[i].getEstado() == estados[e])
                {
                    encontrou = true;

                    cout << "Voo " << voos[i].getCodigo() << ":";

                    if (voos[i].getQuantidadeAstronautas() == 0)
                    {
                        cout << " sem astronautas";
                    }
                    else
                    {
                        cout << " ";

                        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++)
                        {
                            string cpf = voos[i].getCpf(j);
                            int indiceAstronauta = buscarAstronauta(cpf);

                            if (j > 0)
                            {
                                cout << ", ";
                            }

                            cout << cpf << " " << astronautas[indiceAstronauta].getNome();
                        }
                    }

                    cout << endl;
                }
            }

            if (!encontrou)
            {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void listarMortos()
    {
        cout << "ASTRONAUTAS MORTOS" << endl;

        bool encontrou = false;

        for (int i = 0; i < (int)astronautas.size(); i++)
        {
            if (!astronautas[i].estaVivo())
            {
                encontrou = true;

                cout << astronautas[i].getCpf() << " "
                     << astronautas[i].getNome() << " - voos:";

                bool encontrouVoo = false;

                for (int j = 0; j < (int)voos.size(); j++)
                {
                    if (voos[j].getEstado() != "planejado" &&
                        voos[j].temAstronauta(astronautas[i].getCpf()))
                    {

                        cout << " " << voos[j].getCodigo();
                        encontrouVoo = true;
                    }
                }

                if (!encontrouVoo)
                {
                    cout << " nenhum";
                }

                cout << endl;
            }
        }

        if (!encontrou)
        {
            cout << "(nenhum)" << endl;
        }
    }

    void listarAstronautas()
    {
        cout << "LISTA DE ASTRONAUTAS" << endl;

        string grupos[] = {"disponiveis", "em voo", "mortos"};

        for (int g = 0; g < 3; g++)
        {
            cout << "== " << grupos[g] << " ==" << endl;

            bool encontrou = false;

            for (int i = 0; i < (int)astronautas.size(); i++)
            {
                bool entrar = false;
                int vooCodigo = -1;

                if (grupos[g] == "mortos")
                {
                    if (!astronautas[i].estaVivo())
                    {
                        entrar = true;
                    }
                }
                else if (astronautas[i].estaVivo())
                {
                    bool emVoo = false;
                    for (int j = 0; j < (int)voos.size(); j++)
                    {
                        if (voos[j].getEstado() == "em curso" && voos[j].temAstronauta(astronautas[i].getCpf()))
                        {
                            emVoo = true;
                            vooCodigo = voos[j].getCodigo();
                            break;
                        }
                    }
                    if (grupos[g] == "em voo" && emVoo) entrar = true;
                    if (grupos[g] == "disponiveis" && !emVoo) entrar = true;
                }

                if (entrar)
                {
                    encontrou = true;
                    cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " (" << astronautas[i].getIdade() << " anos)";
                    if (grupos[g] == "em voo")
                    {
                        cout << " - voo " << vooCodigo;
                    }
                    cout << endl;
                }
            }

            if (!encontrou)
            {
                cout << "(nenhum)" << endl;
            }
        }
    }

    void historico(string cpf)
    {
        int indice = buscarAstronauta(cpf);
        if (indice == -1)
        {
            cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
            return;
        }

        cout << "HISTORICO DE " << cpf << " " << astronautas[indice].getNome() << endl;

        bool encontrou = false;

        for (int j = 0; j < (int)voos.size(); j++)
        {
            if (voos[j].temAstronauta(cpf) && voos[j].getEstado() != "planejado")
            {
                cout << "voo " << voos[j].getCodigo() << ": " << voos[j].getEstado() << endl;
                encontrou = true;
            }
        }

        if (!encontrou)
        {
            cout << "(nenhum voo)" << endl;
        }
    }

    void salvar(string nomeArquivo)
    {
        ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "ERRO: nao foi possivel salvar em " << nomeArquivo << endl;
            return;
        }
        for (int i = 0; i < (int)astronautas.size(); i++)
        {
            arquivo << "ASTRONAUTA " << astronautas[i].getCpf() << " "
                    << astronautas[i].getNome() << " "
                    << astronautas[i].getIdade() << " "
                    << astronautas[i].estaVivo() << " "
                    << astronautas[i].estaDisponivel() << endl;
        }
        for (int i = 0; i < (int)voos.size(); i++)
        {
            arquivo << "VOO " << voos[i].getCodigo() << " " << voos[i].getEstado() << endl;
            for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++)
            {
                arquivo << "VOO_CPFS " << voos[i].getCodigo() << " " << voos[i].getCpf(j) << endl;
            }
        }
        arquivo.close();
        cout << "OK: dados salvos em " << nomeArquivo << endl;
    }

    void carregar(string nomeArquivo)
    {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "ERRO: nao foi possivel carregar de " << nomeArquivo << endl;
            return;
        }

        vector<Astronauta> tempAstronautas;
        vector<Voo> tempVoos;

        string line;
        while (getline(arquivo, line))
        {
            if (line.empty()) continue;

            vector<string> tokens;
            istringstream iss(line);
            string token;
            while (iss >> token) tokens.push_back(token);

            if (tokens[0] == "ASTRONAUTA")
            {
                string cpf = tokens[1];
                int idade = stoi(tokens[tokens.size() - 3]);
                bool vivo = stoi(tokens[tokens.size() - 2]) != 0;
                bool disponivel = stoi(tokens[tokens.size() - 1]) != 0;
                string nome = "";
                for (int i = 2; i < (int)tokens.size() - 3; i++)
                {
                    if (i > 2) nome += " ";
                    nome += tokens[i];
                }
                Astronauta a(cpf, nome, idade);
                a.definirEstado(vivo, disponivel);
                tempAstronautas.push_back(a);
            }
            else if (tokens[0] == "VOO")
            {
                int codigo = stoi(tokens[1]);
                string estado = "";
                for (int i = 2; i < (int)tokens.size(); i++)
                {
                    if (i > 2) estado += " ";
                    estado += tokens[i];
                }
                tempVoos.push_back(Voo(codigo));
                if (estado == "em curso") tempVoos.back().lancar();
                else if (estado == "finalizado com sucesso") tempVoos.back().finalizar();
                else if (estado == "finalizado com explosao") tempVoos.back().explodir();
            }
            else if (tokens[0] == "VOO_CPFS")
            {
                int codigo = stoi(tokens[1]);
                string cpf = tokens[2];
                int idx = -1;
                for (int i = 0; i < (int)tempVoos.size(); i++)
                {
                    if (tempVoos[i].getCodigo() == codigo)
                    {
                        idx = i;
                        break;
                    }
                }
                if (idx != -1)
                {
                    tempVoos[idx].adicionarAstronauta(cpf);
                }
            }
        }

        arquivo.close();

        astronautas = tempAstronautas;
        voos = tempVoos;

        cout << "OK: dados carregados de " << nomeArquivo << endl;
    }
};

int main()
{
    Agencia agencia;
    string comando;

    while (cin >> comando)
    {
        if (comando == "FIM")
            break;
        else if (comando == "CADASTRAR_ASTRONAUTA")
        {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);
            agencia.cadastrarAstronauta(cpf, nome, idade);
        }
        else if (comando == "CADASTRAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        }
        else if (comando == "ADICIONAR_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        }
        else if (comando == "REMOVER_ASTRONAUTA")
        {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        }
        else if (comando == "LANCAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        }
        else if (comando == "EXPLODIR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        }
        else if (comando == "FINALIZAR_VOO")
        {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        }
        else if (comando == "LISTAR_VOOS")
        {
            agencia.listarVoos();
        }
        else if (comando == "LISTAR_MORTOS")
        {
            agencia.listarMortos();
        }
        else if (comando == "LISTAR_ASTRONAUTAS")
        {
            agencia.listarAstronautas();
        }
        else if (comando == "HISTORICO")
        {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        }
        else if (comando == "SALVAR")
        {
            string nomeArquivo;
            cin >> nomeArquivo;
            agencia.salvar(nomeArquivo);
        }
        else if (comando == "CARREGAR")
        {
            string nomeArquivo;
            cin >> nomeArquivo;
            agencia.carregar(nomeArquivo);
        }
        else
        {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}