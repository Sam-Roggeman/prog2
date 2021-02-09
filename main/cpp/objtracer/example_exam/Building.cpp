/**
 * @file
 * Implementation for the class Building.
 * @author Thomas Avé
 */

#include <algorithm>
#include <iostream>

#include "Building.h"
#include "tracer/tracer.h"

namespace tracing_example_exam {

Building::Building(Person& owner) : m_rooms(), m_neighbours(), m_owner(owner) { COMP_MISC_MEMBER_TRACER; }

Building::Building(const Person& owner) : m_rooms(), m_neighbours(), m_owner(owner) { COMP_MISC_MEMBER_TRACER; }

Building::Building(Person&& owner) : m_rooms(), m_neighbours(), m_owner(std::move(owner)) { COMP_MISC_MEMBER_TRACER; }

Building::Building(const Building& b) : m_rooms(), m_neighbours(), m_owner(b.m_owner)
{
        COMP_MISC_MEMBER_TRACER;
        m_rooms = b.m_rooms;
}

Building::Building(Building&& b) : m_rooms(), m_neighbours(), m_owner(std::move(b.m_owner))
{
        COMP_MISC_MEMBER_TRACER;
        m_rooms.clear();
        m_neighbours.clear();
        m_rooms = std::move(b.m_rooms);
        m_neighbours = std::move(b.m_neighbours);
}

Building::~Building() { COMP_MISC_MEMBER_TRACER; }

Building& Building::operator=(const Building& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_rooms = other.m_rooms;
                m_neighbours = other.m_neighbours;
                m_owner = Person(other.m_owner);
        }
        return *this;
}

Building& Building::operator=(Building&& other)
{
        COMP_MISC_MEMBER_TRACER;
        if (this != &other) {
                m_rooms.clear();
                m_neighbours.clear();
                m_neighbours = std::move(other.m_neighbours);
                m_rooms = std::move(other.m_rooms);
                m_owner = std::move(other.m_owner);
        }
        return *this;
}

void Building::info() const
{
        COMP_MISC_MEMBER_TRACER;
        COMP_MISC_LOG_TRACER(getName() + " containing " + std::to_string(m_rooms.size()) + " rooms:");
        for (auto room : m_rooms) {
                room->info();
        }
        COMP_MISC_LOG_TRACER("And " + std::to_string(m_neighbours.size()) + " neighbours");
}

std::string Building::getName() const
{
        COMP_MISC_MEMBER_TRACER;
        return "Generic Building";
}

Person& Building::getOwner()
{
        COMP_MISC_MEMBER_TRACER;
        return m_owner;
}

void Building::addNeighbour(Building* neighbour)
{
        COMP_MISC_MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

} // namespace tracing_example_exam
