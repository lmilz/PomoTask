CLANG_TIDY = clang-tidy
CLANG_FORMAT = clang-format
FORMAT_FLAGS = -style=file:.clang-format

SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
TODO_DIR = $(SRC_DIR)/ToDo
POMODORO_DIR = $(SRC_DIR)/Pomodoro

APP_SOURCES = $(wildcard $(APP_DIR)/src/*.cpp) $(wildcard $(APP_DIR)/include/*.h)
TODO_SOURCES = $(wildcard $(TODO_DIR)/src/*.cpp) $(wildcard $(TODO_DIR)/include/*.h)
POMODORO_SOURCES = $(wildcard $(POMODORO_DIR)/src/*.cpp) $(wildcard $(POMODORO_DIR)/include/*.h)

# clang-tidy
tidy: $(APP_SOURCES) $(TODO_SOURCES) $(POMODORO_SOURCES)
	@for file in $(APP_SOURCES) $(TODO_SOURCES) $(POMODORO_SOURCES); do \
		$(CLANG_TIDY) $$file --; \
	done

# clang-format
format:
	$(CLANG_FORMAT) $(FORMAT_FLAGS) -i $(APP_SOURCES) $(TODO_SOURCES) $(POMODORO_SOURCES)

.PHONY: format tidy
all: format tidy