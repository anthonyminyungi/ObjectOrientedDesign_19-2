#include "unique_immut.h"

namespace ptr {
unique_immut::unique_immut() {
    _mgr = new mgr();
}

unique_immut::unique_immut(Object *obj) {
    _mgr = new mgr(obj);
}

unique_immut::unique_immut(const unique_immut &immut) {
    if (immut._mgr) {
        int val = immut._mgr->ptr->get();
        _mgr = new mgr(val);
    }
}

unique_immut::~unique_immut() {
    release();
}
Object* unique_immut::get() const
{
	if (_mgr == nullptr) {
		return nullptr;
	}
	else {
		return this->_mgr->ptr;
	}
}
void unique_immut::release()
{
	if (_mgr != nullptr) {
		_mgr->~mgr();
	}
}
unique_immut unique_immut::operator+(unique_immut& unique)
{
	int a = this->_mgr->ptr->get() + unique._mgr->ptr->get();
	this->release();
	unique.release();
	Object* b = new Object(a);
	return unique_immut(b);
}
unique_immut unique_immut::operator-(unique_immut& unique)
{
	int a = this->_mgr->ptr->get() - unique._mgr->ptr->get();
	this->release();
	unique.release();
	Object* b = new Object(a);
	return unique_immut(b);
}
unique_immut unique_immut::operator*(unique_immut& unique)
{
	int a = this->_mgr->ptr->get() * unique._mgr->ptr->get();
	this->release();
	unique.release();
	Object* b = new Object(a);
	return unique_immut(b);
}
unique_immut unique_immut::operator/(unique_immut& unique)
{
	int a = this->_mgr->ptr->get() / unique._mgr->ptr->get();
	this->release();
	unique.release();
	Object* b = new Object(a);
	return unique_immut(b);
}
Object* unique_immut::operator->()
{
	return this->_mgr->ptr;
}
unique_immut& unique_immut::operator=(unique_immut& r)
{
	if (this->_mgr == r._mgr)
	{
		return *this;
	}
	else {
		this->release();
		this->_mgr = r._mgr;
		return *this;
	}
}
} // end of namespace ptr

