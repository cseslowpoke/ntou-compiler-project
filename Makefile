# Makefile for a project using Flex, Bison, LLVM, and CMake

# Variables
CMAKE := cmake
CMAKE_BUILD_DIR := build
SRC_DIR := src
LEX_FILE := $(SRC_DIR)/lexer.l
YACC_FILE := $(SRC_DIR)/parser.y

# Flex and Bison output files
LEX_OUTPUT := $(SRC_DIR)/lex.yy.c
YACC_OUTPUT := $(SRC_DIR)/y.tab.c
YACC_HEADER := $(SRC_DIR)/y.tab.h

# LLVM and Clang variables
LLVM_CONFIG := llvm-config
CLANG := clang

# Targets
all: build

# build: $(CMAKE_BUILD_DIR)/Makefile
# 	$(MAKE) -C $(CMAKE_BUILD_DIR)

# $(CMAKE_BUILD_DIR)/Makefile: CMakeLists.txt $(LEX_OUTPUT) $(YACC_OUTPUT)
# 	@mkdir -p $(CMAKE_BUILD_DIR)
# 	cd $(CMAKE_BUILD_DIR) && $(CMAKE) ..

# $(LEX_OUTPUT): $(LEX_FILE)
# 	flex -o $(LEX_OUTPUT) $(LEX_FILE)

# $(YACC_OUTPUT): $(YACC_FILE)
# 	bison -d -o $(YACC_OUTPUT) $(YACC_FILE)

clean:
	$(MAKE) -C $(CMAKE_BUILD_DIR) clean
	rm -f $(LEX_OUTPUT) $(YACC_OUTPUT) $(YACC_HEADER)
	rm -rf $(CMAKE_BUILD_DIR)

.PHONY: all build clean
