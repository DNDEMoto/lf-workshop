cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

####################################### Lingua Franca
# Default to C++14, C++の標準をC++20に設定
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()
#########################################################

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


####################################### Lingua Franca

include_directories(src/tag/api) # for tag.h
include_directories(src/include/core) # for lf_types.h 
include_directories(src/include/core/utils) # for vector.h
include_directories(src/include/core/modal_models) 
include_directories(src/include/core/threaded)
include_directories(src/include/core/federated)
include_directories(src/low_level_platform/api) # for low_level_platform.h
include_directories(src/trace/api/types) # for trace_types.h
include_directories(src/logging/api) # logging_macros.h


add_compile_definitions(NUMBER_OF_WORKERS=4)

#add_library(platform_support src/core/platform/lf_linux_support.cpp)　# なにこれ
add_library(platform_support src/low_level_platform/impl/src/lf_linux_support.cpp)

add_executable(talker src/BasicROS.cpp) # パスあってるかこれ？

target_link_libraries(talker platform_support)
install(TARGETS platform_support DESTINATION lib)# なにこれ
#########################################################

# add_executable(talker src/publisher_member_function.cpp)
add_executable(listener src/subscriber_member_function.cpp)
ament_target_dependencies(listener rclcpp std_msgs)
ament_target_dependencies(talker rclcpp std_msgs)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})


# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
