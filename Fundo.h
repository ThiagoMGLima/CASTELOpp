#pragma once
#include <stdlib.h>

#include "Ente.h"
#include "ID.h"

#include "Camada.h"

namespace CASTELOpp {

    namespace Parallax {

        class Fundo : public Ente {
        private:
            sf::Vector2f posAnteriorCamera;
            std::vector<Camada*> camadas;
        
        public:
            Fundo(const ID ID);
            ~Fundo();
            void desenhar();
            void addCamada(const char* caminhoTextura, const float vel);
            void Atualizar(double t);
        };

    }

}