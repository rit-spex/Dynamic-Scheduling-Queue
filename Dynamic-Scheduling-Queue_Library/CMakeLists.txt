add_library(DsqLib SHARED
            DSQ.h
            DSQ.cpp
            Queue.h
            Routine.cpp
            Routine.h)

target_include_directories(DsqLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
