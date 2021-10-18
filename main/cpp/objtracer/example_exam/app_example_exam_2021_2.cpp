/**
 * @file
 * Tracing exam, August 2021
 * @author Thomas Avé (IDLab/UA)
 */

#include "objtracer/demobj.h"
#include "objtracer/demos.h"
#include "tracer/tracer.h"
#include <iostream>
#include <memory>
#include <stdexcept>

#include "HolidayHome.h"
#include "Building.h"
#include "Person.h"

using namespace tracing_example_exam;

namespace {
    void f(HolidayHome&) {
        COMP_MISC_FUNCTION_TRACER;
    }

    void f(const HolidayHome&) {
        COMP_MISC_FUNCTION_TRACER;
    }
    void f(House&) {
        COMP_MISC_FUNCTION_TRACER;
    }
    void f(const House&) {
        COMP_MISC_FUNCTION_TRACER;
        }

    // Make sure you provide the actual type T for each template instantiation
    // For example:   ---> function body: T copy(const T&) [with T = tracing_exam::Person]
    template<typename T>
    T copy(const T& t) {
        COMP_MISC_FUNCTION_TRACER;
        return T(t);
    }
}

int app_example_exam_2021_2()
{
    COMP_MISC_FUNCTION_TRACER;
    {
        COMP_MISC_BLOCK_TRACER("First block");

        COMP_MISC_LOG_TRACER("statement: const Person p1(\"Steve\");");
        Person p1("Steve"); // Note that this is tracing_exam::Person, not ODemo::Person!

        COMP_MISC_LOG_TRACER("statement: Building b1(p1);");
        Building b1(p1);

        COMP_MISC_LOG_TRACER("statement: Building b2(*std::make_shared<Person>(std::move(p1)));");
        Building b2(*std::make_shared<Person>(std::move(p1)));

        COMP_MISC_LOG_TRACER("statement: Building* b3 = copy(new Building(Person(b2.getOwner())));");
        Building* b3 = copy(new Building(Person(b2.getOwner())));


        COMP_MISC_LOG_TRACER("statement: Building* b4 = b3;");
        Building* b4 = b3;

        COMP_MISC_LOG_TRACER("statement: b2 = *b3;");
        b2 = *b3;

        COMP_MISC_LOG_TRACER("statement: b3 = &b1;");
        b3 = &b1;

        COMP_MISC_LOG_TRACER("statement: b1 = b2;");
        b1 = b2;


        COMP_MISC_LOG_TRACER("statement: delete b4;");
        delete b4;

        COMP_MISC_LOG_TRACER("End of the first block");
    }
    {
        COMP_MISC_BLOCK_TRACER("Second block");

        try {
            COMP_MISC_BLOCK_TRACER("Try block");

            COMP_MISC_LOG_TRACER("statement: Person p1(\"Dave\");");
            Person p1("Dave");

            COMP_MISC_LOG_TRACER("statement: Person p2(\"Peter\");");
            Person p2("Peter");

            COMP_MISC_LOG_TRACER("statement: Person p3(\"Harry\");");
            Person p3("Harry");

            COMP_MISC_LOG_TRACER("statement: HolidayHome* h1 = new HolidayHome(p1, 2);");
            HolidayHome* h1 = new HolidayHome(p1, 2);

            COMP_MISC_LOG_TRACER("statement: const HolidayHome* h2 = h1;");
            const HolidayHome* h2 = h1;

            COMP_MISC_LOG_TRACER("statement: House h3 = copy(*h1);");
            House h3 = copy(*h1);

            COMP_MISC_LOG_TRACER("statement: auto h4 = copy(h2);");
            auto h4 = copy(h2);

            COMP_MISC_LOG_TRACER("statement: auto h5 = copy<const House*>(h2);");
            auto h5 = copy<const House*>(h2);


            COMP_MISC_LOG_TRACER("statement: f(*h1);");
            f(*h1);

            COMP_MISC_LOG_TRACER("statement: f(*h2);");
            f(*h2);

            COMP_MISC_LOG_TRACER("statement: f(h3);");
            f(h3);

            COMP_MISC_LOG_TRACER("statement: f(House(h3));");
            f(House(h3));

            COMP_MISC_LOG_TRACER("statement: h1->rent(p2);");
            h1->rent(p2);

            COMP_MISC_LOG_TRACER("statement: h1->rent(p3);");
            h1->rent(p3);

            COMP_MISC_LOG_TRACER("statement: h3.info();");
            h3.info();

            COMP_MISC_LOG_TRACER("statement: delete h1;");
            delete h1;

        } catch (std::runtime_error& e) {
            COMP_MISC_LOG_TRACER(e.what());
        }

        COMP_MISC_LOG_TRACER("End of the second block");
    }
    COMP_MISC_LOG_TRACER("statement: return 0;");
    return 0;
}
