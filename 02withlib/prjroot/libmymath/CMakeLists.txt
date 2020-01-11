# 上位のCMakeファイルでadd_subdirectoryなどでこのディレクトリが対象に
# なったときに実行される。

# ライブラリlibmymathを宣言。ディレクトリ名と一致する必要があるのかは
# わからない。
add_library(libmymath mymath.c)
