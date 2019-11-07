#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

    class vehicle {
    protected:
        bool has_name;
        int wheel_number;
        int max_speed;   
    public:
        vehicle();

        vehicle(int wheel_number, int max_speed);

        vehicle(int wheel_number, int max_speed, bool has_name);

        virtual int get_wheel_number();

        virtual int get_max_speed();

        virtual bool get_has_name();

        const char *get_class_name();

        virtual void set_wheel_number(int wheel_number);

        virtual void set_max_speed(int max_speed);

        virtual void set_has_name(bool has_name);
    };

#endif