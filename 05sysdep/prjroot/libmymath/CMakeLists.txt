add_library(libmymath mymath.c)
target_include_directories(libmymath
  INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}"
  # ライブラリやシンボルの確認方法1のつづき
  # conf.hを見れるようにするよ
  PRIVATE "${CMAKE_BINARY_DIR}"
  )

install(TARGETS libmymath DESTINATION lib)
install(FILES mymath.h DESTINATION include)

# ライブラリやシンボルの確認方法2
# conf.h経由じゃなくてコンパイラのコマンドライン引数経由でマクロを定義
# する方法

#include(CheckSymbolExists)
#set(CMAKE_REQUIRED_LIBRARIES "m")
#check_symbol_exists(reallocarray "stdlib.h" HAVE_REALLOCARRAY)

# reallocarrayシンボルが見つかったら、HAVE_REALLOCARRAYマクロを定義(お
# そらくCコンパイラのコマンドライン引数経由で渡される)
#if(HAVE_REALLOCARRAY)
#  target_compile_definitions(libmymath PRIVATE HAVE_REALLOCARRAY)
#endif()
