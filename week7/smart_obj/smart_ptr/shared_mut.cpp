//
// Created by 김혁진 on 14/10/2019.
//

#include "shared_mut.h"

namespace ptr {
	
	shared_mut::shared_mut() {
    _mgr = new mgr();
	}

	shared_mut::shared_mut(const shared_mut& mut)
	{
		this->_mgr = mut._mgr;
		this->increase();
	}

shared_mut::shared_mut(Object* _obj) {
    _mgr = new mgr(_obj);
}

shared_mut::~shared_mut() {
    release();
}
Object* shared_mut::get() const
{
	if (_mgr == nullptr) {
		return nullptr;
	}
	else {
		return _mgr->ptr;
	}
}
void shared_mut::increase()
{
	_mgr->count += 1;

}
void shared_mut::release()
{
	this->_mgr->count -= 1;
	if (this->_mgr->count == 0) {
		this->_mgr->~mgr();
	}
	this->_mgr = new mgr();
	
	
	
}
int shared_mut::count()
{
	return _mgr->count;
}
shared_mut shared_mut::operator+(const shared_mut& shared)
{
	int i = this->_mgr->ptr->get() + shared._mgr->ptr->get();
	return shared_mut(new Object(i));
}
shared_mut shared_mut::operator-(const shared_mut& shared)
{
	int i = this->_mgr->ptr->get() - shared._mgr->ptr->get();
	return shared_mut(new Object(i));
}
shared_mut shared_mut::operator*(const shared_mut& shared)
{
	int i = this->_mgr->ptr->get() * shared._mgr->ptr->get();
	return shared_mut(new Object(i));
}
shared_mut shared_mut::operator/(const shared_mut& shared)
{
	int i = this->_mgr->ptr->get() / shared._mgr->ptr->get();
	return shared_mut(new Object(i));
}
Object* shared_mut::operator->()
{
	return this->_mgr->ptr;
}
shared_mut& shared_mut::operator=(const shared_mut& r)
{
	this->release();
	this->_mgr = r._mgr;
	this->increase();

	return *this;
}
} // end of namespace ptr
