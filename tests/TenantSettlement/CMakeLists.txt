# Specify the required C++ standard
#set(CMAKE_CXX_STANDARD 14)

#Do tests here like:

#add_executable(name .cpp)
#target_link_libraries(name
#   gtest
#   gmock_main
#   tenant_settlement)
#add_test(NAME name COMMAND name of exec)
 
add_executable(bill_tests bill_test.cpp)
target_link_libraries(bill_tests gtest gtest_main tenant_settlement)
