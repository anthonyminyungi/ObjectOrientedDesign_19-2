#include "json_dict.h"
#include "json_list.h"
#include "data/Integer.h"
#include "data/String.h"

void json_dict::put(json_object *key, json_object *val)
{
    int found = find(key);
    if (found != -1)
        v[found].second = val;
    else
        v.push_back(std::make_pair(key, val));
}
int json_dict::find(json_object *key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first->to_string() == key->to_string())
        {
            return i;
        }
    }
    return -1;
}
json_dict::json_dict()
{
}
json_object *json_dict::parse(const char *arr, int length)
{
    _index += 1;
    bool isVal = false;
    json_dict *res = new json_dict();
    json_object *key = nullptr;
    json_object *val = nullptr;

    while (_index < length)
    {
        if (arr[_index] >= 48 && arr[_index] <= 57)
        {
            if(isVal) val = Integer::parse(arr, length);
            else key = Integer::parse(arr, length);
        }

        else if (arr[_index] == '{')
        {
            val = json_dict::parse(arr, length);
        }
        else if (arr[_index] == '[')
        {
            val = json_list::parse(arr, length);
        }
        else if (arr[_index] == ':')
        {
            isVal = true;
            _index += 1;
        }
        else if (arr[_index] == ',')
        {
            isVal = false;
            res->put(key, val);
            _index += 1;
        }
        else if (arr[_index] == '"' || arr[_index] == '\'')
        {
            if (isVal)
                val = String::parse(arr, length, arr[_index]);
            else
                key = String::parse(arr, length, arr[_index]);
        }
        else if (arr[_index] == '}')
        {
            _index += 1;
            res->put(key, val);
        }
        else
        {
            _index += 1;
        }
    }
    res->put(key, val);
    return res;
}
json_object *json_dict::operator[](json_object *key) const
{
    int i = 0;
    for (; i < v.size(); i++)
    {
        if (v[i].first->to_string() == key->to_string())
        {
            return v[i].second;
        }
    }
    return nullptr;
}
json_object *json_dict::operator[](const std::string &key) const
{
    int i = 0;
    std::string str;
    for (; i < v.size(); i++)
    {
        if (v[i].first->type() == 3)
        {
            str = dynamic_cast<String *>(v[i].first)->val();
            if (str == key)
            {
                return v[i].second;
            }
        }
    }
    return nullptr;
}
json_object *json_dict::operator[](int key) const
{
    int i = 0;
    int temp;
    for (; i < v.size(); i++)
    {
        if (v[i].first->type() == 2)
        {
            temp = dynamic_cast<Integer *>(v[i].first)->val();
            if (temp == key)
            {
                return v[i].second;
            }
        }
    }
    return nullptr;
}

json_object::_type json_dict::type()
{
    return DICT;
}

std::string json_dict::to_string()
{
    std::string str = "{";
    for (int i = 0; i < v.size(); i++)
    {
        str += v[i].first->to_string() + ":" + v[i].second->to_string();
        if (i != v.size() - 1)
        {
            str += ", ";
        }
    }
    str += "}";
    return str;
}
