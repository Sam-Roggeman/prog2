/**
 * @file
 * Implementation for the class HolidayHome.
 * @author Thomas Avé
 */

#include "HolidayHome.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

HolidayHome::HolidayHome(Person& owner, unsigned int bedrooms) : House(owner, bedrooms) { COMP_MISC_MEMBER_TRACER; }

HolidayHome::~HolidayHome() { COMP_MISC_MEMBER_TRACER; }

HolidayHome::HolidayHome(const HolidayHome& h) : House(h), Rentable(h) { COMP_MISC_MEMBER_TRACER; }

HolidayHome::HolidayHome(HolidayHome&& h) : House(std::move(h)), Rentable(std::move(h)) { COMP_MISC_MEMBER_TRACER; }

HolidayHome& HolidayHome::operator=(const HolidayHome& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                House::operator=(other);
                Rentable::operator=(other);
        }
        return *this;
}

HolidayHome& HolidayHome::operator=(HolidayHome&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                House::operator=(std::move(other));
                Rentable::operator=(std::move(other));
        }
        return *this;
}

std::string HolidayHome::getName() const
{
        COMP_MISC_MEMBER_TRACER;
        return "HolidayHome";
}

void HolidayHome::addNeighbour(HolidayHome* neighbour)
{
        COMP_MISC_MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

} // namespace tracing_example_exam
