//
//  Carriable.hpp
//  surviveTheWinter
//
//  Created by David Stück on 9/3/18.
//  Copyright © 2018 David Stuck. All rights reserved.
//

#ifndef Carriable_hpp
#define Carriable_hpp

#include <stdio.h>

#include "VisibleGameObject.h"

template< class T >
class Carriable : virtual public T
{
public:
    bool pick_me_up(VisibleGameObject* carrier) {
        if(_carrier != NULL) {
            return false;
        }
        else{
            _carrier = carrier;
            return true;
        }
    };
    bool put_me_down(VisibleGameObject* carrier) {
        if(_carrier != carrier) {
            return false;
        }
        else {
            _carrier = NULL;
            return true;
        }
    };

    
private:
    VisibleGameObject* _carrier = NULL;
};

#endif /* Carriable_hpp */
