#ifndef _MESSAGEGENERATOR_H
#define _MESSAGEGENERATOR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_44771088_H
#define TOP_LEVEL_PREAMBLE_44771088_H
#include <functional>
#include <memory>
#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#endif
typedef struct {
    struct self_base_t base;
#line 17 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.h"
    #line 79 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    std::shared_ptr<MinimalPublisher> minimal_publisher;
    #line 80 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    int i;
#line 22 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.h"
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
} _messagegenerator_self_t;
_messagegenerator_self_t* new__messagegenerator();
#endif // _MESSAGEGENERATOR_H
