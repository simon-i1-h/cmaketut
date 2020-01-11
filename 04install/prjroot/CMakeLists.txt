cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

add_executable(Tutorial tut.c)

option(USE_MYMATH "use mymath?" ON)

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

# インストール命令。make installっぽいことをやる。
# TARGETS -> 指定したターゲットの成果物をインストール
# FILES -> 指定したファイルをインストール
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/conf.h" DESTINATION include)


# チュートリアルによると、なんと、CMakeには謎のテスト機構がある！！！！
# (？？？？)
# けど今回は飛ばします
