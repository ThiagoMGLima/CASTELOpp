#pragma once
#include "Fundo.h"
#include "Botao.h"

#include <string>

#include <vector>
using std::vector;

namespace CASTELOpp {
    namespace Menu {
        class Menu :
            public Ente
        {
        private:
            int numFase;

        protected:
            Parallax::Fundo fundo;
            std::vector<Botao*> vBotao;
            std::vector<Botao*> vBotaoAparece;
            std::vector<Botao*>::iterator ite;

        public:
            Menu();
            ~Menu();
            void addBotao(sf::Vector2f Pos, const std::string TEXTO);
            void moverCima();
            void moverBaixo();
            Botao* getBotaoSelecionado() const;
            void Atualizar(double t);
            virtual void criarFundo();
            void desenha();
            std::string getStringBotao() const;
            void addbotaoAparecer(Botao* Botao);
            void limpavBotaoAparece();
            Botao* getBotao(std::string string);
            
            void setIterator();

            void setNumFase(int num);
            int getNumFase() const;
        };
    }
}


