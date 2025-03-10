#pragma once
#include "Fase.h"

#define NUM_MAX_INI 4

namespace CASTELOpp {
    namespace Fase {
        class Floresta :
            public Fase
        {
        private:
            void InstanciaEnt(int numJogadores);
        public:
            Floresta(int numJogadores);
            ~Floresta();
            void criarFundo();
            bool acabouFase();
        };
    }
}


