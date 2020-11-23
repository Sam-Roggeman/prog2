# Adding new tracing exercises

1. Copy an existing file in `prog2/main/cpp/objtracer/` and rename it, e.g. `test_trace.cpp`
2. Inside the file rename the name of the function containing the trace to name of the file: `test_trace()`
3. Add the file to the sources in [`prog2/main/cpp/objtracer/CMakeLists.txt`](CMakeLists.txt) on lines 53-55
4. Add the function to the projects in [`prog2/main/cpp/objtracer/CMakeLists.txt`](CMakeLists.txt) on lines 63-64
5. In [`demos.h`](demos.h), add your new trace function: `int test_trace();`
6. In [`app_exec.cpp`](app_exec.cpp), add your function to the function register: `f_reg["test_trace"] = test_trace`;
7. Rerun make all; make install; make test;.
8. When executing `app_exec` now, your file should be one of the options to trace and you output the trace of your file!
