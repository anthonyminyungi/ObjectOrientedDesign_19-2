#include "Integer.h"
#include "../json_list.h"
#include "../json_dict.h"
#include "../json_object.h"
#include "String.h"

Integer::Integer(int value)
{
    this->_val = value;
}

int Integer::val()
{
    return this->_val;
}
void Integer::set_val(const int &value)
{
    this->_val = value;
}

json_object *Integer::parse(const char *arr, int length)
{
    std::string str;
    while (true)
    {
        if (47 < arr[_index] && arr[_index] < 58) {
			str += arr[_index];
		}
		else {
			break;
		}
		_index++;
        
    }
    return new Integer(std::stoi(str));
}
json_object::_type Integer::type()
{
    return INT;
}
std::string Integer::to_string()
{
    return std::to_string(this->_val);
}
