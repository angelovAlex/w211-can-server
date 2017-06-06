//
//  Parser.cpp
//  can_server
//
//  Created by Alex Angelov on 26/05/2017.
//  Copyright © 2017 Alex Angelov. All rights reserved.
//

#include "Parser.hpp"
#include <iostream>

Parser::Parser()
{
    memset(buffer, 0, BUFFER_SIZE);
    buffer_length = -1;
}

void Parser::parse_string(char *str, ssize_t len)
{
    for (int i = 0; i < len; i++) {
        char v = str[i];
        if (v == 'm') {
            buffer_length = 0;
        }
        if (buffer_length >= 0){ //wait till we have the begging "m" symbol
            if (v == '\r') {
                parse_buffer(buffer, buffer_length);
            }
            if (v != '\n'){
                buffer[buffer_length++] = v;
            }
        }
    }
}

uint32_t Parser::parse_str_to_uint(char *buf, char*str, uint8_t from, uint8_t to, uint8_t base)
{
    memcpy(buf, str + from, to - from);
    buf[to - from] = '\0';
    try {
        return (uint32_t)std::stoul(buf,nullptr,base);
    } catch(...) {
        
    }
    return 0;
}

void Parser::parse_buffer(char *str, ssize_t len)
{
    if (str[0] != 'm') return;
    
    CANMSG msg = CANMSG();
    char buf[32];
    
    uint8_t from = 2;
    uint8_t to = 3;
    while (str[++to] != ' ');
    msg.time = parse_str_to_uint(buf, str, from, to, 10);
    
    from = to+1;
    to = to+1;
    while (str[++to] != ' ');
    msg.address = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+2;
    msg.len = parse_str_to_uint(buf, str, from, to, 10);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[0] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[1] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[2] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[3] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[4] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[5] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[6] = parse_str_to_uint(buf, str, from, to, 16);
    
    from = to+1;
    to = to+3;
    if (to < len) msg.data[7] = parse_str_to_uint(buf, str, from, to, 16);
    
    
    parse_message(msg);
}



void Parser::parse_message(CANMSG msg)
{
    busB->receive(msg);
}
