add_library(labs lab3/backup.cpp lab3/backup.h)

target_sources(labs
  PRIVATE
        lab3/consolelog.cpp
        lab3/backup.cpp
  PUBLIC
        lab3/lab3_functions.h
        lab3/backup.h
  )

target_include_directories(labs
  PUBLIC
        .
  )
target_link_libraries(labs PUBLIC elzip)

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
    PUBLIC
      "--coverage"
    )
  target_link_options(labs
    INTERFACE
      "--coverage"
    )
endif()
