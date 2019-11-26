
#include "json_list.h"
#include "json_dict.h"
#include "data/Integer.h"
#include "data/String.h"

json_list::json_list()
{
}
json_object *json_list::parse(const char *arr, int length)
{
    _index += 1;
    int cmcnt = 0;
    json_list *res = new json_list();

    while (_index < length)
    {
        if (arr[_index] >= 48 && arr[_index] <= 57)
        {
            res->v.push_back(Integer::parse(arr, length));
        }
        else if (arr[_index] == '{')
        {
            res->v.push_back(json_dict::parse(arr, length));
        }
        else if (arr[_index] == '[')
        {
            res->v.push_back(json_list::parse(arr, length));
        }
        else if (arr[_index] == '"' || arr[_index] == '\'')
        {
            res->v.push_back(String::parse(arr, length, arr[_index]));
        }
        else if (arr[_index] == ']')
        {
            _index += 1;
            if ((cmcnt == res->v.size() && cmcnt != 0) || res->v.empty())
            {
                res->v.push_back(nullptr);
            }
            return res;
        }
        else if (arr[_index] == ',')
        {
            cmcnt += 1;
            _index += 1;
        }
        else
        {
            _index += 1;
        }
    }
    return res;
}
json_object *json_list::operator[](int key) const
{
    return this->v[key];
}
json_object::_type json_list::type()
{
    return LIST;
}
std::string json_list::to_string()
{
    if (v[0] == nullptr)
        return "[]";
    std::string str = "[";

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != nullptr)
        {
            str += v[i]->to_string();
            if (i != v.size() - 1)
            {
                str += ", ";
            }
        }
        else
        {
            if (i != v.size() - 1)
                str += " ";
        }
    }
    return str + "]";
}