cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

add_executable(Tutorial tut.c)

option(USE_MYMATH "use mymath?" ON)

# ライブラリやシンボルの確認方法1

# CMakeのユーティリティの追加
#include(CheckSymbolExists)
# なんすかこれ、libmが必須ってことなのか依存に追加するってことなのか。
# 多分前者。
#set(CMAKE_REQUIRED_LIBRARIES "m")
# こうやってシンボルの存在を確認できるんだって、すごいね。
# configure_fileに含めるため、それより前に呼び出す
#check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)

configure_file(conf.h.in conf.h)

if(USE_MYMATH)
  add_subdirectory(libmymath)
  list(APPEND EXTRA_LIBS libmymath)
endif()

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/conf.h" DESTINATION include)
