/**
 * @file
 * Example tracing exam
 * @author Thomas Avé (IDLab/UA)
 */

#include "objtracer/demobj.h"
#include "objtracer/demos.h"
#include "tracer/tracer.h"
#include <iostream>
#include <stdexcept>

#include "HolidayHome.h"
#include "Person.h"

using namespace tracing_example_exam;

int app_example_exam()
{
        COMP_MISC_FUNCTION_TRACER;
        {
                COMP_MISC_BLOCK_TRACER("First block");
                COMP_MISC_LOG_TRACER("statement: Person p1(\"Steve\");");
                Person p1("Steve"); // Note that this is tracing_exam::Person, not ODemo::Person!

                COMP_MISC_LOG_TRACER("statement: Person p2(\"Peter\");");
                Person p2("Peter");

                COMP_MISC_LOG_TRACER("statement: HolidayHome h1(p1, 1);");
                HolidayHome h1(p1, 1);

                COMP_MISC_LOG_TRACER("statement: HolidayHome* h2 = new HolidayHome(p2, 2)");
                HolidayHome* h2 = new HolidayHome(p2, 2);

                COMP_MISC_LOG_TRACER("statement: h1 = *h2;");
                h1 = *h2;

                COMP_MISC_LOG_TRACER("statement: Building* h3 = &h1;");
                Building* h3 = &h1;

                COMP_MISC_LOG_TRACER("statement: h3 = h2;");
                h3 = h2;

                COMP_MISC_LOG_TRACER("statement: h3->addNeighbour(&h1);");
                h3->addNeighbour(&h1);

                COMP_MISC_LOG_TRACER("statement: h1.addNeighbour(h2);");
                h1.addNeighbour(h2);

                COMP_MISC_LOG_TRACER("statement: h1.info();");
                h1.info();

                COMP_MISC_LOG_TRACER("statement: h1 = std::move(*h2);");
                h1 = std::move(*h2);

                COMP_MISC_LOG_TRACER("statement: delete h2;");
                delete h2;

                COMP_MISC_LOG_TRACER("End of the first block");
        }
        {
                COMP_MISC_BLOCK_TRACER("Second block");
                try {
                        COMP_MISC_BLOCK_TRACER("Try block");

                        COMP_MISC_TRACER_OUTPUT_OFF; // Temporarily setting  the  log  output OFF
                        Person p1("Steve");          // Should not produce any logs
                        Person p2("Peter");          // Should not produce any logs
                        Person p3("Harry");          // Should not produce any logs
                        HolidayHome h(p1, 1);        // Should not produce any logs
                        COMP_MISC_TRACER_OUTPUT_ON;  // Setting  the  log  output back ON,
                                                     // including for objects created when it was OFF

                        COMP_MISC_LOG_TRACER("statement: h.rent(p2);");
                        h.rent(p2);

                        COMP_MISC_LOG_TRACER("statement: h.rent(p3);");
                        h.rent(p3);

                        COMP_MISC_LOG_TRACER("statement: h.info();");
                        h.info();

                } catch (std::runtime_error& e) {
                        COMP_MISC_LOG_TRACER(e.what());
                }

                COMP_MISC_LOG_TRACER("End of the second block");
        }
        COMP_MISC_LOG_TRACER("statement: return 0;");
        return 0;
}
