cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

add_executable(Tutorial tut.c)

# libmymathを使うかどうかのオプション。CMake GUIやccmakeで設定可能(ら
# しい)
option(USE_MYMATH "use mymath?" ON)

# optionの後に実行しないとcmakedefineにoptionを反映できない
configure_file(conf.h.in conf.h)

if(USE_MYMATH)
  # ディレクトリlibmymathを加える(そのディレクトリのCMakeLists.txtを実
  # 行する)
  add_subdirectory(libmymath)
  # 追加のライブラリのリストに追加(後にtarget_link_libraries)で正式に
  # パスへ追加)
  list(APPEND EXTRA_LIBS libmymath)
  # 追加のライブラリのインクルードパス(mypath.hを探す)のリストに追加
  # (後にtarget_include_directoriesで正式にパスへ追加)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/libmymath")
endif()

# Tutorialプロジェクトにライブラリlibmymathをリンクするように設定
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(Tutorial PUBLIC
  "${PROJECT_BINARY_DIR}"
  ${EXTRA_INCLUDES}
  )

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS True)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)
