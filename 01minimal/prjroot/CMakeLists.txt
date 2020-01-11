cmake_minimum_required(VERSION 3.10)

# 実行ファイルTutorialを出力するターゲットを宣言
project(Tutorial VERSION 1.0)

# makeの依存関係に相当しそうだがもう少し柔軟
add_executable(Tutorial tut.c)

# conf.h.inにバージョン情報等を埋め込んでconf.hをビルドディレクトリに
# 出力
configure_file(conf.h.in conf.h)

# conf.hはビルドディレクトリに出力されるので、ビルドディレクトリを
# includeの検索パスに追加
# ソースコードtut.cでincludeすることでバージョン番号を参照できるように
# なる
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

# すべてのターゲットでの準拠するC言語の方言のデフォルトを指定
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True) # 必ずC99でコンパイル
set(CMAKE_C_EXTENSIONS True) # GNU拡張を有効化

# compile_commands.jsonを出力する。書くだけ書いておけ。
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# ビルドディレクトリにTutorialという実行ファイルとconf.hというヘッダファ
# イルが出力される
