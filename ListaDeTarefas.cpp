#include "ListaDeTarefas.h"
#include <algorithm>

ListaDeTarefas::ListaDeTarefas() {}

ListaDeTarefas::~ListaDeTarefas() {}

const std::vector<tarefa>& ListaDeTarefas::getLista() const
{
    return lista_tarefas;
}

void ListaDeTarefas::adiciona_tarefa(const tarefa& nova_tarefa)
{
    lista_tarefas.push_back(nova_tarefa);
}

bool ListaDeTarefas::exclui_tarefa_por_titulo(const std::string& titulo)
{
    const std::vector<tarefa>::iterator it = std::find_if(
        lista_tarefas.begin(),
        lista_tarefas.end(),
        [&](const tarefa& item) { return item.titulo == titulo; }
    );

    if (it == lista_tarefas.end())
    {
        return false;
    }

    lista_tarefas.erase(it);
    return true;
}

bool ListaDeTarefas::altera_estado_tarefa(const std::string& titulo, const std::string& novo_estado)
{
    const std::vector<tarefa>::iterator it = std::find_if(
        lista_tarefas.begin(),
        lista_tarefas.end(),
        [&](const tarefa& item) { return item.titulo == titulo; }
    );

    if (it == lista_tarefas.end())
    {
        return false;
    }

    it->estado = novo_estado;
    return true;
}
