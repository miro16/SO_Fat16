#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2024-01-18 22:15:12.258524
#

cmake_minimum_required(VERSION 3.17)
project(project1 C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
      "-D_GNU_SOURCE"
      "-Wextra"
      "-std=c11"
      "-DINSIDE_DANTE"
      "-D_ANSI_OUTPUT"
      "-fdiagnostics-color"
      "-Wno-error=unused-parameter"
      "-Wno-error=implicit-fallthrough"
      "-Wno-parentheses"
      "-Werror"
      "-fmax-errors=5"
      "-Wno-error=parentheses"
      "-Werror=vla"
      "-Wall"
      "-pedantic"
      "-ggdb3"
      "-xc"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-Wl,-Map=main.map"
        "-Wl,-wrap,main"
        "-Wl,-cref"
        "-ggdb3"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(project1
        "main.c"
        "file_reader.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
)

# Dołącz niezbędne biblioteki
target_link_libraries(project1
        "m"
)