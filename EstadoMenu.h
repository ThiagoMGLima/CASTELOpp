#pragma once
#include "Estado.h"
#include "Menu.h"

namespace CASTELOpp {
    namespace Estado {
        class EstadoMenu :
            public Estado
        {
        private:
            Menu::Menu* Menu;
        public:
            EstadoMenu();
            ~EstadoMenu();
            void Atualizar(double t);
            Menu::Menu* getMenu() const;
        };
    }
}


