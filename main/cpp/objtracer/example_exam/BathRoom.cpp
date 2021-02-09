/**
 * @file
 * Implementation for the class BathRoom.
 * @author Thomas Avé
 */

#include "BathRoom.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

BathRoom::BathRoom() { COMP_MISC_MEMBER_TRACER; }

BathRoom::BathRoom(const BathRoom& b) : Room(b) { COMP_MISC_MEMBER_TRACER; }

BathRoom::BathRoom(BathRoom&& b) : Room(std::move(b)) { COMP_MISC_MEMBER_TRACER; }

BathRoom::~BathRoom() { COMP_MISC_MEMBER_TRACER; }

BathRoom& BathRoom::operator=(const BathRoom& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(other);
        }
        return *this;
}

BathRoom& BathRoom::operator=(BathRoom&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Room::operator=(std::move(other));
        }
        return *this;
}

void BathRoom::info() const
{
        COMP_MISC_MEMBER_TRACER;
        COMP_MISC_LOG_TRACER("BathRoom");
}

} // namespace tracing_example_exam
