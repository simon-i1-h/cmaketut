add_library(libmymath mymath.c)
target_include_directories(libmymath INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# インストール命令。make installっぽいことをやる。
# TARGETS -> 指定したターゲットの成果物をインストール
# FILES -> 指定したファイルをインストール
install(TARGETS libmymath DESTINATION lib)
install(FILES mymath.h DESTINATION include)
