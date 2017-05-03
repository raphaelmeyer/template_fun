set(TESTNAME tfun-test)

add_executable(${TESTNAME} tfun.cc)
target_link_libraries(${TESTNAME}
  PRIVATE googlemock-main
  PRIVATE tfun)

