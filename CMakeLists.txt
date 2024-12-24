cmake_minimum_required(VERSION 3.16)
project(PomoTask LANGUAGES CXX)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Verzeichnisse
set(SRCDIR src)
set(TESTDIR tests)
set(APPDIR app)

# Quellen und Header
file(GLOB_RECURSE SOURCES "${SRCDIR}/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "${TESTDIR}/*.cpp")
list(FILTER TEST_SOURCES EXCLUDE REGEX "${TESTDIR}/AllTests.cpp")
file(GLOB APP_SOURCES "${APPDIR}/*.cpp")

# AllTests Quelle
set(ALL_TESTS_SOURCE "${TESTDIR}/AllTests.cpp")

# Ziel für die CLI-Anwendung
add_executable(PomoTask ${SOURCES} ${APP_SOURCES})
target_include_directories(PomoTask PRIVATE ${APPDIR})
target_link_libraries(PomoTask PRIVATE sqlite3)

# Ziel für die Tests
add_executable(run_tests ${SOURCES} ${TEST_SOURCES} ${ALL_TESTS_SOURCE})
target_include_directories(run_tests PRIVATE ${TESTDIR} /usr/local/include/CppUTest)
target_link_libraries(run_tests PRIVATE CppUTest CppUTestExt sqlite3)

# Tests hinzufügen
enable_testing()
add_test(NAME AllTests COMMAND run_tests)

# Clean-Ziel
set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${CMAKE_BINARY_DIR}/CMakeFiles;${CMAKE_BINARY_DIR}/Makefile;${CMAKE_BINARY_DIR}/cmake_install.cmake")