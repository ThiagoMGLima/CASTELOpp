#pragma once
#include "Ente.h"

namespace CASTELOpp {
    namespace Menu {
        class Botao :
            public Ente
        {
        private:
            sf::Font fonte;
            sf::Text Texto;
            
            bool Selecionado;
            bool aparecendo;

        public:
            Botao(sf::Vector2f Pos, std::string Texto);
            ~Botao();
            void setSelecionado(const bool selecionado = true);
            const bool getSelecionado() const;
            void desenhar();
            void Atualizar(double t){}
            std::string getString() const;
            sf::Vector2f getPosicao() const;
        };
    }
}


