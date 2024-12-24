CLANG_TIDY = clang-tidy
CLANG_FORMAT = clang-format
FORMAT_FLAGS = -style=file:.clang-format

SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
TODO_DIR = $(SRC_DIR)/ToDo
POMODORO_DIR = $(SRC_DIR)/Pomodoro

# Alle Quell-Dateien
APP_SOURCES = $(wildcard $(APP_DIR)/*/*.cpp) $(wildcard $(APP_DIR)/*/*.h)
TODO_SOURCES = $(wildcard $(TODO_DIR)/*/*.cpp) $(wildcard $(TODO_DIR)/*/*.h)
POMODORO_SOURCES = $(wildcard $(POMODORO_DIR)/*/*.cpp) $(wildcard $(POMODORO_DIR)/*/*.h)

# clang-tidy
tidy: $(APP_SOURCES) $(TODO_SOURCES) $(POMODORO_SOURCES_SOURCES)
	$(CLANG_TIDY) -p=. -checks=$(TIDY_CHECKS) $^

# clang-format
format:
	$(CLANG_FORMAT) $(FORMAT_FLAGS) -i $(APP_SOURCES) $(TODO_SOURCES) $(POMODORO_SOURCES)

.PHONY: format tidy
all: format tidy