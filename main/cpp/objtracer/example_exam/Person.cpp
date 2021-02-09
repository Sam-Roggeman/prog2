/**
 * @file
 * Implementation for the class Person.
 * @author Thomas Avé
 */

#include "Person.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

Person::Person(std::string name) : m_name(name) { COMP_MISC_MEMBER_TRACER; }

Person::Person(const Person& p) : m_name(p.m_name) { COMP_MISC_MEMBER_TRACER; }

Person::Person(Person&& p) : m_name(std::move(p.m_name)) { COMP_MISC_MEMBER_TRACER; }

Person::~Person() { COMP_MISC_MEMBER_TRACER; }

std::string Person::getName() const
{
        COMP_MISC_MEMBER_TRACER;
        return m_name;
}

Person& Person::operator=(const Person& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_name = other.m_name;
        }
        return *this;
}

Person& Person::operator=(Person&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_name = std::move(other.m_name);
        }
        return *this;
}

} // namespace tracing_example_exam
