add_executable(tests
  test_runner.cpp
  test_parser.cpp
  test_element.cpp
)

target_link_libraries(tests
  PUBLIC
    parser
  PRIVATE
	GTest::GTest
)