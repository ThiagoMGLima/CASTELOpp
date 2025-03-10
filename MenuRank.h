#pragma once

#include "Ente.h"
#include "Fundo.h"

#define MAXIMO_PONTUACOES 6

namespace CASTELOpp {
    namespace Menu {
        class MenuRank :
            public Ente
        {
        private:
            Parallax::Fundo fundo;
            
            sf::Font fonte;
            std::vector<sf::Text*> vtexto;
            std::vector<float> rank;

        public:
            //MenuRank(std::vector<float> vpontuacao, std::vector<std::string> vnomes) {};
            MenuRank(std::vector<float*>* vpontuacao);
            ~MenuRank();
            void addPontuacao(float pontuacao,std::string nome);
            void addPontuacao(float* pontuacao);
            int posicaoRank(float pontuacao);
            void Atualizar(double t);
            void desenha();
            void criarFundo(); //add caminho fundo
        };
    }
}