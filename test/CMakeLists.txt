set(TESTNAME tfun-test)

add_executable(${TESTNAME}
  concat.cc
  filter.cc
  show.cc
  )
target_link_libraries(${TESTNAME}
  PRIVATE googlemock-main
  PRIVATE tfun)

