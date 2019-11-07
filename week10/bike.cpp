#include "bike.h"
#include <iostream>

    bike::bike(){

    }
    bike::bike(int wheel_number, int max_speed){
        this->wheel_number = wheel_number;
	    this->max_speed = max_speed;	
    }
    bike::bike(int wheel_number, int max_speed, char* bike_name){
        this->wheel_number = wheel_number;
	    this->max_speed = max_speed;
	    this->bike_name = bike_name;
    }
    bike::bike(int wheel_number, int max_speed, char* bike_name, int bike_number){
        this->wheel_number = wheel_number;
	    this->max_speed = max_speed;
	    this->bike_name = bike_name;
        this->bike_number = bike_number;
    }
    bike::bike(int wheel_number, int max_speed, char* bike_name, int bike_number, bool has_name){
        this->wheel_number = wheel_number;
	    this->max_speed = max_speed;
	    this->bike_name = bike_name;
        this->bike_number = bike_number;
	    this->has_name = has_name;
    }
	char* bike::get_bike_name(){
        return this->bike_name;
    }
    int bike::get_bike_number(){
        return this->bike_number;
    }

    void bike::set_bike_number(int bike_number){
        this->bike_number = bike_number;
    }
    void bike::set_bike_name(char* bike_name){
        this->bike_name = bike_name;
    }
	const char* bike::get_class_name(){
        return "bike";
    }
