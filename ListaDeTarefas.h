#ifndef LISTADETAREFAS_H
#define LISTADETAREFAS_H

#include <vector>
#include <string>

struct tarefa
{
    std::string titulo;
    std::string estado;
};

class ListaDeTarefas
{
private:
    std::vector<tarefa> lista_tarefas;
public:
    ListaDeTarefas();
    ~ListaDeTarefas();

    const std::vector<tarefa>& getLista() const;
    void adiciona_tarefa(const tarefa& nova_tarefa);
    bool exclui_tarefa_por_titulo(const std::string& titulo);
    bool altera_estado_tarefa(const std::string& titulo, const std::string& novo_estado);
};

#endif