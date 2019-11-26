#include "String.h"


 String::String(const std::string &str){
     this->_val = str;
}

std::string String::val(){
    return this->_val;
}
void String::set_val(const std::string &str){
    this->_val = str;
}

json_object* String::parse(const char * arr, int length, char base){
    _index += 1;
    std::string str;
    while(arr[_index] != base){
        str += arr[_index];
        _index += 1;
    }
    _index += 1;

    return new String(str);
}

json_object::_type String::type(){
    return STRING;
}
std::string String::to_string(){
    return "'" + this->_val + "'";
}
