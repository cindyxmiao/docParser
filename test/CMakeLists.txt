add_executable(
	tests
	test_runner.cpp
	test_parser.cpp
)

target_link_libraries(tests PRIVATE GTest::GTest)