//
//  Parser.hpp
//  can_server
//
//  Created by Alex Angelov on 26/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <iostream>
#include "CANMSG.hpp"
#include "Bus.hpp"

#define BUFFER_SIZE 256

class Parser {
    
    char buffer[BUFFER_SIZE];
    int buffer_length;
    
    
    uint32_t parse_str_to_uint(char *buf, char*str, uint8_t from, uint8_t to, uint8_t base);
    void parse_buffer(char *str, ssize_t len);
    void parse_message(CANMSG msg);
    void print_msg(CANMSG msg);
    
public:
    Parser();
    void parse_string(char *str, ssize_t len);
    BusB *busB;
    
};

#endif /* Parser_hpp */
