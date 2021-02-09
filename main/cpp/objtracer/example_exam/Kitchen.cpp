/**
 * @file
 * Implementation for the class Kitchen.
 * @author Thomas Avé
 */

#include "Kitchen.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

Kitchen::Kitchen() { COMP_MISC_MEMBER_TRACER; }

Kitchen::Kitchen(const Kitchen& k) : Room(k) { COMP_MISC_MEMBER_TRACER; }

Kitchen::Kitchen(Kitchen&& k) : Room(std::move(k)) { COMP_MISC_MEMBER_TRACER; }

Kitchen::~Kitchen() { COMP_MISC_MEMBER_TRACER; }

Kitchen& Kitchen::operator=(const Kitchen& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(other);
        }
        return *this;
}

Kitchen& Kitchen::operator=(Kitchen&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(std::move(other));
        }
        return *this;
}

void Kitchen::info() const
{
        COMP_MISC_MEMBER_TRACER;
        COMP_MISC_LOG_TRACER("Kitchen");
}

} // namespace tracing_example_exam
