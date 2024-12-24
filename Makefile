# Verzeichnisse
SRCDIR = src
OBJDIR = obj
LIBDIR = lib
BINDIR = bin
TESTDIR = tests
APPDIR = app

# Compiler und Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -I/usr/include -I/usr/local/include/CppUTest -I$(APPDIR) $(foreach dir, $(shell find $(SRCDIR) -type d), -I$(dir))
LDFLAGS = -L$(LIBDIR) -lsqlite3 -lPomoTask -lCppUTest -lCppUTestExt

# Ziel-Bibliothek
TARGET = $(LIBDIR)/libPomoTask.a

# Testausführbare Datei
TEST_TARGET = $(BINDIR)/run_tests

# CLI-Anwendung
APP_TARGET = $(BINDIR)/PomoTask

# Finde alle .cpp-Dateien
SOURCES = $(wildcard $(SRCDIR)/**/*.cpp)
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp)
TEST_SOURCES_NO_MAIN = $(filter-out $(TESTDIR)/AllTests.cpp, $(TEST_SOURCES))
APP_SOURCES = $(wildcard $(APPDIR)/*.cpp)

# Erstelle eine Liste der .o-Dateien im obj-Verzeichnis
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TEST_SOURCES_NO_MAIN))
ALL_TESTS_OBJ = $(OBJDIR)/AllTests.o
APP_OBJECTS = $(patsubst $(APPDIR)/%.cpp, $(OBJDIR)/App_%.o, $(APP_SOURCES))

# Standardziel
all: $(TARGET)

# Erstelle die statische Bibliothek aus den .o-Dateien
$(TARGET): $(OBJECTS) | $(LIBDIR)
	ar rcs $(TARGET) $(OBJECTS)

# Kompiliere .cpp-Dateien aus dem src-Verzeichnis zu .o-Dateien
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Kompiliere .cpp-Dateien aus dem test-Verzeichnis zu .o-Dateien, außer AllTests.cpp
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Kompiliere AllTests.cpp
$(ALL_TESTS_OBJ): $(TESTDIR)/AllTests.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $(TESTDIR)/AllTests.cpp -o $@

# Kompiliere .cpp-Dateien aus dem app-Verzeichnis zu .o-Dateien
$(OBJDIR)/App_%.o: $(APPDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linke Testausführbare Datei
$(TEST_TARGET): $(TEST_OBJECTS) $(ALL_TESTS_OBJ) $(TARGET) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(ALL_TESTS_OBJ) $(LDFLAGS) -o $@

# Linke CLI-Anwendung
$(APP_TARGET): $(APP_OBJECTS) $(TARGET) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $(APP_OBJECTS) $(LDFLAGS) -o $@

# Verzeichnisse erstellen
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# Clean-Ziel
clean:
	rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

# Tests ausführen
test: $(TEST_TARGET)
	$(TEST_TARGET)
	
# CLI-Anwendung erstellen
app: $(APP_TARGET)

# Phony-Ziele
.PHONY: all clean test