add_library(libmymath mymath.c)

# INTERFACEは、ターゲット自身は使わないけどターゲットの利用者が使う設
# 定をしたい場合に指定するらしい。
# libmymathターゲットに依存するターゲットのインクルードパスに、
# libmypathのヘッダファイルがあるディレクトリを追加する。
# (しかし、通常はマクロなどを使うために外向けのヘッダファイルもインク
# ルードすると思うけどどうなんだこれ)
target_include_directories(libmymath INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
