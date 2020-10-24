//
//  hub.hpp
//  projeto_03
//
//  Created by Paulo Bessa on 23/10/20.
//  Copyright © 2020 Paulo Bessa. All rights reserved.
//

#ifndef hub_hpp
#define hub_hpp

#include <stdio.h>
#include <string>
#include "catalogo.hpp"

using namespace std;

class Hub{
public:
    Hub();
    
    void hub(Catalogo);
    Catalogo addUsuarioFilme(Catalogo);
    
};

#endif /* hub_hpp */
