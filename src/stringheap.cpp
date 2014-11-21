#include "stringheap.h"
#include "fake.h"

stringheap::stringheap(fake * fk) : m_fk(fk), m_shh(fk)
{
}

stringheap::~stringheap()
{
	clear();
}

void stringheap::clear()
{
    for (const stringhashmap<stringele*>::ele * p = m_shh.first(); p != 0; p = m_shh.next())
    {
        stringele * e = p->t;
        safe_fkfree(m_fk, e->s);
        safe_fkfree(m_fk, e);
    }
	m_shh.clear();
}

stringele * stringheap::allocstring(const char * str)
{
    stringele ** p = m_shh.get(str);
    if (p)
    {
		return *p;
	}
	stringele * pe = (stringele*)safe_fkmalloc(m_fk, sizeof(stringele));
	stringele & e = *pe;
	e.update = 0;
	e.sz = strlen(str);
	e.s = stringdump(m_fk, str, e.sz);
	m_shh.add(str, pe);
	return pe;
}

void stringheap::checkgc()
{
	if ((int)m_shh.size() > m_fk->cfg.string_heap_num)
	{
	    gc();
	}
}

void stringheap::gc()
{
	clear();
}