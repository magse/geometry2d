#!/bin/sh

<<<<<<< HEAD
/bin/cp -f auto_tests.cpp.head auto_tests.hpp

grep "test_" ../include/vec2.hpp | cut -d ' ' -f 4 | cut -d '(' -f 1 | sed 's/\([a-z][a-z0-9_]*\)/  AUTO_TEST(\1);/'  >> auto_tests.hpp

/bin/cat auto_tests.cpp.foot >> auto_tests.hpp
=======
/bin/cp -f auto_tests.cpp.head auto_tests.cpp

grep "test_" ../include/vec2.hpp | cut -d ' ' -f 4 | cut -d '(' -f 1 | sed 's/\([a-z][a-z0-9_]*\)/  AUTO_TEST(\1);/'  >> auto_tests.cpp

/bin/cat auto_tests.cpp.foot >> auto_tests.cpp
>>>>>>> main
