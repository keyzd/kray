CXX := g++
CXXFLAGS := -g -Wall 
CXXFLAGS += -DINTERSECT_SPHERE_ALGEBRAIC
LDFLAGS := -lm

SRC_COMMON_DIR := ./src
SRC_CLIENT_DIR := $(SRC_COMMON_DIR)/client
SRC_SERVER_DIR := $(SRC_COMMON_DIR)/server

MAIN_CLIENT := main_client.cpp
MAIN_SERVER := main_server.cpp

BUILD_DIR := ./build

EXEC_CLIENT := client
EXEC_SERVER := server

SRCS_CLIENT := $(shell find $(SRC_COMMON_DIR) -name '*.cpp' ! -name $(MAIN_CLIENT) ! -path $(SRC_SERVER_DIR)'/*')
OBJS_CLIENT := $(SRCS_CLIENT:%=$(BUILD_DIR)/%.o)

SRCS_SERVER := $(shell find $(SRC_COMMON_DIR) -name '*.cpp' ! -name $(MAIN_SERVER) ! -path $(SRC_CLIENT_DIR)'/*')
OBJS_SERVER := $(SRCS_SERVER:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/%.cpp.o: %.cpp %.hpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/$(EXEC_CLIENT): $(OBJS_CLIENT) $(SRC_CLIENT_DIR)/$(MAIN_CLIENT)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(EXEC_SERVER): $(OBJS_SERVER) $(SRC_SERVER_DIR)/$(MAIN_SERVER)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(EXEC_CLIENT): $(BUILD_DIR)/$(EXEC_CLIENT)
$(EXEC_SERVER): $(BUILD_DIR)/$(EXEC_SERVER)

all: $(EXEC_CLIENT) $(EXEC_SERVER)

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCS_CLIENT) $(SRC_CLIENT_DIR)/$(MAIN_CLIENT) $(SRCS_SERVER) $(SRC_SERVER_DIR)/$(MAIN_SERVER)
	$(CXX) -MM $^ > $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
