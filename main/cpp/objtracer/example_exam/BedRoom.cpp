/**
 * @file
 * Implementation for the class BedRoom.
 * @author Thomas Avé
 */

#include "BedRoom.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

BedRoom::BedRoom() { COMP_MISC_MEMBER_TRACER; }

BedRoom::BedRoom(const BedRoom& b) : Room(b) { COMP_MISC_MEMBER_TRACER; }

BedRoom::BedRoom(BedRoom&& b) : Room(std::move(b)) { COMP_MISC_MEMBER_TRACER; }

BedRoom::~BedRoom() { COMP_MISC_MEMBER_TRACER; }

BedRoom& BedRoom::operator=(const BedRoom& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(other);
        }
        return *this;
}

BedRoom& BedRoom::operator=(BedRoom&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(std::move(other));
        }
        return *this;
}

void BedRoom::info() const
{
        COMP_MISC_MEMBER_TRACER;
        COMP_MISC_LOG_TRACER("BedRoom");
}

} // namespace tracing_example_exam
