/**
 * @file
 * Implementation for the class Rentable.
 * @author Thomas Avé
 */

#include "Rentable.h"
#include "tracer/tracer.h"

#include <memory>
#include <stdexcept>

namespace tracing_example_exam {

Rentable::Rentable() : m_renter() { COMP_MISC_MEMBER_TRACER; }

Rentable::~Rentable() { COMP_MISC_MEMBER_TRACER; }

Rentable::Rentable(const Rentable& other) : m_renter(other.m_renter) { COMP_MISC_MEMBER_TRACER; }

Rentable::Rentable(Rentable&& other) : m_renter(std::move(other.m_renter)) { COMP_MISC_MEMBER_TRACER; }

Rentable& Rentable::operator=(const Rentable& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_renter = other.m_renter;
        }
        return *this;
}

Rentable& Rentable::operator=(Rentable&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_renter = std::move(other.m_renter);
        }
        return *this;
}

void Rentable::rent(Person& renter)
{
        COMP_MISC_MEMBER_TRACER;
        if (m_renter) {
                throw std::runtime_error("This Rentable is already being rented!");
        } else {
                m_renter = std::make_shared<Person>(renter);
        }
}

} // namespace tracing_example_exam
