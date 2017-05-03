#
# googletest
#
add_library(googletest googletest/googletest/src/gtest-all.cc)

target_include_directories(googletest
  PUBLIC googletest/googletest/include
  PRIVATE googletest/googletest
  )

#
# googlemock
#
add_library(googlemock googletest/googlemock/src/gmock-all.cc)

target_include_directories(googlemock
  PUBLIC googletest/googlemock/include
  PRIVATE googletest/googlemock
  )

target_link_libraries(googlemock googletest)

add_library(googlemock-main googletest/googlemock/src/gmock_main.cc)
target_link_libraries(googlemock-main
  googlemock
  pthread
  )
