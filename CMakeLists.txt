cmake_minimum_required(VERSION 3.10)

project(cpoke C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 LLVM
find_package(LLVM REQUIRED CONFIG)

# 將 LLVM 的頭文件添加到項目中
include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
llvm_map_components_to_libnames(llvm_libs support core irreader)

# 查找 Flex 和 Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# 查找 Flex 庫
find_library(FL_LIBRARY NAMES fl PATHS /opt/homebrew/opt/flex/lib/)
if (NOT FL_LIBRARY)
  message(FATAL_ERROR "Could not find the Flex library (libfl.a)")
endif()

# Flex 和 Bison 輸入文件
set(LEX_FILE ${CMAKE_SOURCE_DIR}/src/lexer.l)
set(YACC_FILE ${CMAKE_SOURCE_DIR}/src/parser.y)

# 添加 Flex 和 Bison 目標
FLEX_TARGET(MyScanner ${LEX_FILE} ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/lexer.h)
BISON_TARGET(MyParser ${YACC_FILE} ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
             COMPILE_FLAGS -Wcounterexamples
             DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

# 將生成的文件添加到項目中
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src/include)
include_directories(${CMAKE_SOURCE_DIR}/src/lib)

# 查找所有的源文件和頭文件
file(GLOB_RECURSE SRC_FILES "src/*.cpp" "src/*.h" "src/*.hpp")

set(NO_RTTI "-fno-rtti")
add_definitions(${NO_RTTI})
# 確認 src/main.c 文件存在且路徑正確
add_executable(cpoke
  ${SRC_FILES}
  ${FLEX_MyScanner_OUTPUTS}
  ${BISON_MyParser_OUTPUTS}
  src/main.cpp
)



# 確保鏈接 Flex 和 Bison 庫
target_link_libraries(cpoke ${llvm_libs} ${FL_LIBRARY})
# llvm_update_compile_flag .s(poke)
# target_link_libraries(poke )

# # 顯示包含的源文件和庫
# message(STATUS "Source files: src/main.c ${FLEX_MyScanner_OUTPUTS} ${BISON_MyParser_OUTPUTS}")
# message(STATUS "Linking with: ${FL_LIBRARY}")


