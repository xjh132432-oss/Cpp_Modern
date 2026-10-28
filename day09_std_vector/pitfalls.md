# Pitfalls

## Day 09：std::vector 项目构建失败

### 问题现象

在 macOS（AppleClang + CMake + Unix Makefiles）环境下，执行 `cmake --build build` 时构建失败。

报错信息：

`CMakeFiles/run.dir/build.make:76: *** target pattern contains no '%'. Stop.`

同时出现：

`make[1]: *** [CMakeFiles/run.dir/all] Error 2`

`make: *** [all] Error 2`

### 已尝试的操作

1. 首次执行 `cmake -S . -B build`，配置与生成阶段成功，但构建失败。
2. 执行 `rm -rf build/` 删除构建目录。
3. 重新执行 `cmake -S . -B build`，配置与生成阶段仍然成功。
4. 再次执行 `cmake --build build`，依然出现相同错误。

### 排查线索

- 源代码目录名称为 `day09_std::vector`，包含特殊字符 `::`。
- 删除并重新生成 `build` 目录后，错误仍然存在。
- 当前错误发生在 Makefile 构建阶段，而不是 C++ 编译阶段。
- 目录名中的冒号可能影响生成的 Makefile 规则解析，但尚未通过检查 `build.make` 第 76 行确认根因。

### 后续排查

1. 将目录名改为 `day09_std_vector`，避免路径中出现 `::`。
2. 删除旧的 `build` 目录，重新配置并构建。
3. 如果仍然失败，执行 `sed -n '68,82p' build/CMakeFiles/run.dir/build.make`，检查报错位置附近的实际构建规则。

### 本次经验

CMake 配置成功不代表项目一定能够构建成功。遇到 Makefile 语法错误时，应检查生成的构建规则和项目路径，而不是直接认定为 C++ 源代码问题。