#include "GerenciadorEventos.h"

CASTELOpp::Gerenciador::GerenciadorEventos* CASTELOpp::Gerenciador::GerenciadorEventos::pGerEventos = nullptr;

CASTELOpp::Gerenciador::GerenciadorEventos::GerenciadorEventos():
    pGerGrafico(pGerGrafico->getGerGrafico()),pGerEstado(pGerEstado->getGerenciadorEstado()) {
}

CASTELOpp::Gerenciador::GerenciadorEventos::~GerenciadorEventos()
{
    if (pGerEventos) {
        delete(pGerEventos);
        pGerEventos = nullptr;
    }
}




CASTELOpp::Gerenciador::GerenciadorEventos* CASTELOpp::Gerenciador::GerenciadorEventos::getGerEventos()
{
    if (pGerEventos == nullptr) {
        return (pGerEventos = new CASTELOpp::Gerenciador::GerenciadorEventos());
    }
    return pGerEventos;
}

void CASTELOpp::Gerenciador::GerenciadorEventos::TeclaPressionada(sf::Keyboard::Key tecla)
{   
    if (pGerEstado->getEstadoAtual()->getId() == ID::Castelo || pGerEstado->getEstadoAtual()->getId() == ID::Floresta) {

        Estado::EstadoJogar* pEstJogar = dynamic_cast<Estado::EstadoJogar*>(pGerEstado->getEstadoAtual());
        vector<Entidade::Entidade*> vEnti = pEstJogar->getJgdr();
        vector<Entidade::Personagens::Jogador::Jogador*>* pvJogador = new vector<Entidade::Personagens::Jogador::Jogador*>;

        for (unsigned int i = 0; i < vEnti.size(); i++) {
            Entidade::Personagens::Jogador::Jogador* pJog = (Entidade::Personagens::Jogador::Jogador*)vEnti.operator[](i);
            pvJogador->push_back(pJog);
        }


        if (pvJogador->size() > 0) {

            if (tecla == sf::Keyboard::A) {
                //pJogador->andar(true);
                pvJogador->operator[](0)->andar(true);
            }
            else if (tecla == sf::Keyboard::D)
                pvJogador->operator[](0)->andar(false);

            else if (tecla == sf::Keyboard::W) {
                pvJogador->operator[](0)->Pular();
            }
            else if (tecla == sf::Keyboard::Space) {
                pvJogador->operator[](0)->Atacar();
            }

            if (pvJogador->size() > 1) {
                if (tecla == sf::Keyboard::Left) {
                    pvJogador->operator[](1)->andar(true);
                }
                else if (tecla == sf::Keyboard::Right)
                    pvJogador->operator[](1)->andar(false);

                else if (tecla == sf::Keyboard::Up) {
                    pvJogador->operator[](1)->Pular();
                }
                else if (tecla == sf::Keyboard::RShift) {
                    pvJogador->operator[](1)->Atacar();
                }
            }
        }

        if (tecla == sf::Keyboard::Escape) {
            Fase::Fase* pfase = pEstJogar->getFase();
            pfase->clearvJogadores();
            pGerEstado->removerEstado();
        }
        
    }

    else if (pGerEstado->getEstadoAtual()->getId() == ID::Menu) {
        Estado::EstadoMenu* pEstMenu = dynamic_cast<Estado::EstadoMenu*>(pGerEstado->getEstadoAtual());
        Menu::Menu* pMenu = (pEstMenu->getMenu());

        if (tecla == sf::Keyboard::W) {
            pMenu->moverCima();
        }
        else if (tecla == sf::Keyboard::S) {
            pMenu->moverBaixo();
        }
        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "Jogar fase 1") {
            
            pMenu->limpavBotaoAparece();
            pMenu->addbotaoAparecer(pMenu->getBotao("1 Jogador"));
            pMenu->addbotaoAparecer(pMenu->getBotao("2 Jogadores"));
            pMenu->addbotaoAparecer(pMenu->getBotao("Voltar ao Menu"));
            pMenu->setIterator();
            
            pMenu->setNumFase(1);
        }
        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "Jogar fase 2") {
            
            pMenu->limpavBotaoAparece();
            pMenu->addbotaoAparecer(pMenu->getBotao("1 Jogador"));
            pMenu->addbotaoAparecer(pMenu->getBotao("2 Jogadores"));
            pMenu->addbotaoAparecer(pMenu->getBotao("Voltar ao Menu"));
            pMenu->setIterator();

            pMenu->setNumFase(2);
        }
        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "1 Jogador") {
            if (pMenu->getNumFase() == 1)
                pGerEstado->addEstado(ID::Floresta, 1);
            else if (pMenu->getNumFase() == 2)
                pGerEstado->addEstado(ID::Castelo, 1);
        }

        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "2 Jogadores") {
            if (pMenu->getNumFase() == 1)
                pGerEstado->addEstado(ID::Floresta, 2);
            else if (pMenu->getNumFase() == 2)
                pGerEstado->addEstado(ID::Castelo, 2);
        }
        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "Voltar ao Menu") {
            pMenu->limpavBotaoAparece();
            pMenu->addbotaoAparecer(pMenu->getBotao("Jogar fase 1"));
            pMenu->addbotaoAparecer(pMenu->getBotao("Jogar fase 2"));
            pMenu->addbotaoAparecer(pMenu->getBotao("Ranking"));
            pMenu->addbotaoAparecer(pMenu->getBotao("Sair"));
            pMenu->setIterator();
        }
        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "Ranking") {
            pGerEstado->addEstado(ID::Rank);
        }

        else if (tecla == sf::Keyboard::Enter && pMenu->getBotaoSelecionado()->getString() == "Sair" || tecla == sf::Keyboard::Escape) {
           
            pGerGrafico->FechaJanela();

        }
    }

    if (pGerEstado->getEstadoAtual()->getId() == ID::Rank) {
        if (tecla == sf::Keyboard::Escape) {
            pGerEstado->removerEstado();
        }
    }
}

void CASTELOpp::Gerenciador::GerenciadorEventos::TeclaSolta(sf::Keyboard::Key tecla)
{
    if (pGerEstado->getEstadoAtual()->getId() == ID::Castelo || pGerEstado->getEstadoAtual()->getId() == ID::Floresta) {
        
        Estado::EstadoJogar* pEstJogar = dynamic_cast<Estado::EstadoJogar*>(pGerEstado->getEstadoAtual());
        vector<Entidade::Entidade*> vEnti = pEstJogar->getJgdr();
        vector<Entidade::Personagens::Jogador::Jogador*>* pvJogador = new vector<Entidade::Personagens::Jogador::Jogador*>;

        for (int i = 0; i <(signed) vEnti.size(); i++) {
            Entidade::Personagens::Jogador::Jogador* pJog = (Entidade::Personagens::Jogador::Jogador*)vEnti.operator[](i);
            pvJogador->push_back(pJog);
        }
        if (pvJogador->size() > 0) {
            if (tecla == sf::Keyboard::A || tecla == sf::Keyboard::D)
                pvJogador->operator[](0)->parar();
            if (pvJogador->size() > 1) {
                if (tecla == sf::Keyboard::Left || tecla == sf::Keyboard::Right)
                    pvJogador->operator[](1)->parar();
            }
        }
    }  
}

void CASTELOpp::Gerenciador::GerenciadorEventos::executar() {
    
    sf::Event evento;

    while (pGerGrafico->getWindow()->pollEvent(evento)) {
        if (evento.type == sf::Event::KeyPressed)
            TeclaPressionada(evento.key.code);
        else if (evento.type == sf::Event::KeyReleased)
            TeclaSolta(evento.key.code);
        else if (evento.type == sf::Event::Closed)
            pGerGrafico->FechaJanela();
    }
}