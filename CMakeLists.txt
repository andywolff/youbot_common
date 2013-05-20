cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

## Check required prerequisites
FIND_PACKAGE(Boost REQUIRED COMPONENTS thread date_time filesystem system)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE Release)

rosbuild_init()

# Set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# Set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

## Set compiler flags
INCLUDE_DIRECTORIES(
  include
  ${Boost_INCLUDE_DIR}
)	

rosbuild_add_executable(youbot_oodl 
    src/youbot_oodl.cpp 
    src/YouBotOODLWrapper.cpp
    src/YouBotConfiguration.cpp
    src/joint_state_observer_oodl.cpp
)

target_link_libraries(youbot_oodl soem YouBotDriver ${Boost_LIBRARIES})

rosbuild_add_executable(youbot_arm_test 
    src/examples/youbot_arm_test.cpp 
)
rosbuild_add_executable(youbot_2nd_arm_test 
    src/examples/youbot_2nd_arm_test.cpp 
)

rosbuild_add_library(youbot_trajectory_action_server 
    src/youbot_trajectory_action_server/joint_trajectory_action.cpp
)
