// FrostWolfEngine.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "../ViewportOutput.h"
#include "SystemInput.h"
#include "Utils.h"

int main()
{
    ViewportOutput* outputModule = ViewportOutput::getInstance();
    SystemInput* inputModule = SystemInput::getInstance();
    outputModule->printToConsole("Hello World!", SystemOutput::outputLevel::INFO);
    inputModule->pause();

    outputModule->setMainViewport(FROSTWOLFLOGO_FILE);
    outputModule->printToLog("Hello\n there!");
    outputModule->printToLog("Press enter to continue");
    outputModule->printViewports();
    inputModule->pause();

    outputModule->setMainViewport(MAIN_VIEWPORT_FILE);
    outputModule->printToLog("This line should be divided in two or three lines.");
    outputModule->printToLog("Press Q to exit.");
    outputModule->printViewports();
    
    bool q_pressed = false;
    while (!q_pressed)
    {
        if (Utils::to_lower(inputModule->getKeyPressed()) == 'q')
            q_pressed = true;
    }

    outputModule->cls();
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
