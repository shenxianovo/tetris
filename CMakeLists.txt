cmake_minimum_required(VERSION 3.22)
project(tetris)

set(CXX_STANDARD 20)

aux_source_directory(. src) #自动加入所在目录下的文件进入make列表 如不起作用，点击删除缓存兵重新配置
add_executable(tetris ${src})