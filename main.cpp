#include <iostream>
#include <sstream>
#include <string>
#include "ListaDeTarefas.h"

ListaDeTarefas lista_de_tarefas;

void menu();
void adiciona_tarefa();
void exclui_tarefa();
void lista_tarefas();
void altera_tarefa();

int main()
{
    menu();

    return 0;
}

void menu()
{
    bool programa_continua = true;
    int escolha_menu;
    std::string entrada;

    while (programa_continua)
    {
        while(true)
        {
            std::cout << "Escolha uma das opções abaixo:\n"
                << "1- Adicionar tarefa\n"
                << "2- Excluir tarefa\n"
                << "3- Mostrar lista de tarefas\n"
                << "4- Alterar estado de uma tarefa\n"
                << "0- Fechar programa\n";

            if (!std::getline(std::cin, entrada))
            {
                programa_continua = false;
                break;
            }

            std::stringstream ss(entrada);

            if ((ss >> escolha_menu) && (ss >> std::ws).eof() && escolha_menu >= 0 && escolha_menu <= 4)
            {
                break;
            }

            std::cout << "Entrada inválida. Digite uma das opções fornecidas.\n";
        }

        if (!programa_continua)
        {
            break;
        }

        switch (escolha_menu)
        {
        case 1:
            adiciona_tarefa();
            break;

        case 2:
            exclui_tarefa();
            break;

        case 3:
            lista_tarefas();
            break;
        
        case 4:
            altera_tarefa();
            break;
        
        default:
            programa_continua = false;
            break;
        }
    }
}

void adiciona_tarefa()
{
    std::string nome_tarefa;
    std::string estado_tarefa;
    
    std::cout << "Digite o nome da tarefa a ser incluída: ";
    std::getline(std::cin, nome_tarefa);

    std::cout << "Digite o estado da tarefa a ser incluída: ";
    std::getline(std::cin, estado_tarefa);

    tarefa nova_tarefa{nome_tarefa, estado_tarefa};
    lista_de_tarefas.adiciona_tarefa(nova_tarefa);

    std::cout << "Tarefa " << nome_tarefa << " adicionada com sucesso.\n";
}

void exclui_tarefa()
{
    std::string nome_tarefa;

    std::cout << "Digite o nome da tarefa a ser excluída: ";
    std::getline(std::cin, nome_tarefa);

    if (lista_de_tarefas.exclui_tarefa_por_titulo(nome_tarefa))
    {
        std::cout << "Tarefa " << nome_tarefa << " removida com sucesso.\n";
        return;
    }

    std::cout << "Tarefa não encontrada, voltando para o menu.\n";
}

void lista_tarefas()
{
    std::cout << "Tarefas:\n";

    const std::vector<tarefa>& tarefas = lista_de_tarefas.getLista();
    for (const tarefa& item : tarefas)
    {
        std::cout << item.titulo << ": " << item.estado << "\n";
    }
}

void altera_tarefa()
{
    std::string nome_tarefa;

    std::cout << "Digite o nome da tarefa a ter seu estado alterado: ";
    std::getline(std::cin, nome_tarefa);

    std::cout << "Digite o novo estado da tarefa: ";
    std::string novo_estado;
    std::getline(std::cin, novo_estado);

    if (lista_de_tarefas.altera_estado_tarefa(nome_tarefa, novo_estado))
    {
        std::cout << "Estado da tarefa mudado com sucesso.\n";
        return;
    }

    std::cout << "Tarefa não encontrada, voltando para o menu.\n";
}