set(TESTNAME tfun-test)

add_executable(${TESTNAME}
  concat.cc
  filter.cc
  quicksort.cc
  show.cc
  )

target_link_libraries(${TESTNAME}
  PRIVATE googlemock-main
  PRIVATE tfun)

add_custom_target(run-tfun-test COMMAND tfun-test)

