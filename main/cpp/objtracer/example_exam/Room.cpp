/**
 * @file
 * Implementation for the class Room.
 * @author Thomas Avé
 */

#include "Room.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

Room::Room() { COMP_MISC_MEMBER_TRACER; }

Room::Room(const Room&) { COMP_MISC_MEMBER_TRACER; }

Room::Room(Room&&) { COMP_MISC_MEMBER_TRACER; }

Room::~Room() { COMP_MISC_MEMBER_TRACER; }

Room& Room::operator=(const Room&)
{
        COMP_MISC_MEMBER_TRACER;
        return *this;
}

Room& Room::operator=(Room&&)
{
        COMP_MISC_MEMBER_TRACER;
        return *this;
}

void Room::info() const
{
        COMP_MISC_MEMBER_TRACER;
        COMP_MISC_LOG_TRACER("Generic Room");
}

} // namespace tracing_example_exam
