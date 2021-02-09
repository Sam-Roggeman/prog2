/**
 * @file
 * Implementation for the class House.
 * @author Thomas Avé
 */

#include "House.h"
#include "tracer/tracer.h"

#include "BedRoom.h"
#include <ios>
#include <memory>
#include <utility>

namespace tracing_example_exam {

House::House(Person owner, unsigned int bedrooms) : Building(std::move(owner)), m_kitchen()
{
        COMP_MISC_MEMBER_TRACER;

        for (unsigned int i = 0; i < bedrooms; i++) {
                m_rooms.emplace_back(std::make_shared<const BedRoom>());
        }
        m_rooms.emplace_back(m_bathroom);
}

House::House(const House& h) : Building(h), m_bathroom(h.m_bathroom), m_kitchen(h.m_kitchen)
{
        COMP_MISC_MEMBER_TRACER;
}

House::House(House&& h) : Building(std::move(h)), m_bathroom(std::move(h.m_bathroom)), m_kitchen(std::move(h.m_kitchen))
{
        COMP_MISC_MEMBER_TRACER;
}

House& House::operator=(const House& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(other);
                m_bathroom = other.m_bathroom;
                m_kitchen = other.m_kitchen;
        }
        return *this;
}

House& House::operator=(House&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(std::move(other));
                m_bathroom = std::move(other.m_bathroom);
                m_kitchen = std::move(other.m_kitchen);
        }
        return *this;
}

House::~House() { COMP_MISC_MEMBER_TRACER; }

std::string House::getName() const
{
        COMP_MISC_MEMBER_TRACER;
        return "House";
}

void House::addNeighbour(House* neighbour)
{
        COMP_MISC_MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

} // namespace tracing_example_exam
