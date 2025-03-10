#include "Menu.h"

CASTELOpp::Menu::Menu::Menu():
	Ente(ID::Menu), vBotao(),ite(),fundo(ID::Castelo),numFase(1)
{
    criarFundo();

    //add todos os botoes ja adicionando os botoes aparecer do menu principal
    addBotao(sf::Vector2f(500.0f, 400.0f), "Jogar fase 1");
    addbotaoAparecer(vBotao.operator[](0));

    addBotao(sf::Vector2f(500.0f, 500.0f), "Jogar fase 2");
    addbotaoAparecer(vBotao.operator[](1));

    addBotao(sf::Vector2f(500.0f, 600.0f), "Ranking");
    addbotaoAparecer(vBotao.operator[](2));
    
    addBotao(sf::Vector2f(500.0f, 700.0f), "Sair");
    addbotaoAparecer(vBotao.operator[](3));

    //botoes de menu escolha quantos jogadores para a fase
    addBotao(sf::Vector2f(500.0f, 400.0f), "1 Jogador");
    addBotao(sf::Vector2f(500.0f, 500.0f), "2 Jogadores");
    
    
    addBotao(sf::Vector2f(500.0f, 700.0f), "Voltar ao Menu");

    setIterator();
    (*ite)->setSelecionado(true);
}

CASTELOpp::Menu::Menu::~Menu() 
{

}

void CASTELOpp::Menu::Menu::addBotao(sf::Vector2f Pos, const std::string Texto)
{
    Botao* botao = new Botao(Pos, Texto);
    try {
        vBotao.push_back(botao);
    }
    catch (...) {
        std::cout << "ERROR::CASTELOpp::Menu::nao foi possivel criar um botao" << std::endl;
        exit(1);
    }
}

void CASTELOpp::Menu::Menu::moverCima()
{
    Botao* botao = *ite;
    botao->setSelecionado(false);
    
    if (ite == vBotaoAparece.begin()) {
        ite = vBotaoAparece.end();
    }
    ite--;
    botao = *ite;
    botao->setSelecionado(true);
}

void CASTELOpp::Menu::Menu::moverBaixo()
{
    Botao* botao = *ite;
    botao->setSelecionado(false);
    ite++;
    if (ite == vBotaoAparece.end()) {
        ite = vBotaoAparece.begin();
    }
    botao = *ite;
    botao->setSelecionado(true);
}

CASTELOpp::Menu::Botao* CASTELOpp::Menu::Menu::getBotaoSelecionado() const
{
    return *ite;
}

void CASTELOpp::Menu::Menu::Atualizar(double t)
{

    fundo.Atualizar(t);
    pGerGrafico->atualizaCamera(vBotaoAparece.operator[](0)->getPosicao());

    desenha();
}

void CASTELOpp::Menu::Menu::criarFundo()
{
    fundo.addCamada("./Imagens/Fundo/Fundo_mPrincipal.png", 0.00f);
}

void CASTELOpp::Menu::Menu::desenha()
{

    std::vector<Botao*>::iterator aux;
    for (aux = vBotaoAparece.begin(); aux != vBotaoAparece.end(); aux++) {
        Botao* botao = *aux;
        botao->desenhar();
        botao = nullptr;
    }
}

std::string CASTELOpp::Menu::Menu::getStringBotao() const
{
    return getBotaoSelecionado()->getString();
}

void CASTELOpp::Menu::Menu::addbotaoAparecer(Botao* Botao)
{
    try {
        vBotaoAparece.push_back(Botao);
    }
    catch (...) {
        std::cout << "ERROR::CASTELOpp::Menu::nao foi possivel add um botao no vBotaoAparece" << std::endl;
        exit(1);
    }
}

void CASTELOpp::Menu::Menu::limpavBotaoAparece()
{
    if(!vBotaoAparece.empty())
        vBotaoAparece.clear();
    else {
        std::cout << "CASTELOpp::Menu::Menu::limpavBotaoAparece vBoutaoAparece estava vazia ja"<<std::endl;
    }
}

CASTELOpp::Menu::Botao* CASTELOpp::Menu::Menu::getBotao(std::string string)
{
    std::vector<Botao*>::iterator aux;
    for (aux = vBotao.begin(); aux != vBotao.end(); aux++) {
        Botao* botao = *aux;
        if (botao->getString() == string)
            return botao;
    }
    std::cout << "CASTELOpp::Menu::Menu::getBotao Nao foi possivel localizar o botao pedido " << std::endl;
    return NULL;
}

void CASTELOpp::Menu::Menu::setIterator()
{
    ite = vBotaoAparece.begin();
}

void CASTELOpp::Menu::Menu::setNumFase(int num)
{
    numFase = num;
}

int CASTELOpp::Menu::Menu::getNumFase() const
{
    return numFase;
}
