#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

int json_object::_index = 0;

json_object *json_object::parse(const char *arr, int length)
{

    while (_index < length)
    {
        // if (arr[_index] == '0' || arr[_index] == '1' || arr[_index] == '2' || arr[_index] == '3' || arr[_index] == '4' || arr[_index] == '5' || arr[_index] == '6' || arr[_index] == '7' || arr[_index] == '8' || arr[_index] == '9')
        if (arr[_index] >= 48 && arr[_index] <= 57)
        {
            return Integer::parse(arr, length);
        }
        else if (arr[_index] == '{')
        {
            return json_dict::parse(arr, length);
        }
        else if (arr[_index] == '[')
        {
            return json_list::parse(arr, length);
        }
        else if (arr[_index] == '"' || arr[_index] == '\'')
        {
            return String::parse(arr, length, arr[_index]);
        }
        else
        {
            _index += 1;
        }
    }
}
json_object *json_object::parse(const std::string &str)
{
    json_object::_index = 0;
    return json_object::parse(str.c_str(), str.length());
}