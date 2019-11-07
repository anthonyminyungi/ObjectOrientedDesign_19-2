#include "vehicle.h"
#include <iostream>


    class bike : public vehicle {
    protected:
        char* bike_name;
        int bike_number;
    public:
        bike();
        bike(int wheel_number, int max_speed);
        bike(int wheel_number, int max_speed, char* bike_name);
        bike(int wheel_number, int max_speed, char* bike_name, int bike_number);
        bike(int wheel_number, int max_speed, char* bike_name, int bike_number, bool has_name);

	char* get_bike_name();
    int get_bike_number();

    void set_bike_number(int bike_number);
    void set_bike_name(char* bike_name);
	const char* get_class_name();

    };

