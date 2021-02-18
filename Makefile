CXX := clang++
CXXFLAGS := -g -Wall
LDFLAGS := -lm

SRC_DIRS := ./src
BUILD_DIR := ./build
TARGET_EXEC := kray
MAIN_SRC := main.cpp

SRCS := $(shell find $(SRC_DIRS) -name *.cpp ! -name $(MAIN_SRC))
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.cpp.o: %.cpp %.h
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS) $(SRC_DIRS)/$(MAIN_SRC)
	$(CXX) $^ -o $@ $(LDFLAGS)

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCS) $(SRC_DIRS)/$(MAIN_SRC)
	$(CXX) -MM $^ > $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

run: $(BUILD_DIR)/$(TARGET_EXEC)
	./$(BUILD_DIR)/$(TARGET_EXEC)
