set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB langproc_SRC
    "*.h"
    "*.cpp"
)

add_executable(language_processing ${langproc_SRC})