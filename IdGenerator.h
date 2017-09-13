/*
 * =====================================================================================
 *
 *       Filename:  IdGenerator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/2017 10:39:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _ID_GENERATOR_H_
#define _ID_GENERATOR_H_

class IdGenerator{
private:
    int id;

public:
    IdGenerator(){
        id = 0;
    }

    int createNewId(){
        return this->id++;
    }

    int getCurrentId(){
        return this->id;
    }

    void clear(){
        id = 0;
    }
};

#endif
