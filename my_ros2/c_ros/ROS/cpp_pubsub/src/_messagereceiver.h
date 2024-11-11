#ifndef _MESSAGERECEIVER_H
#define _MESSAGERECEIVER_H
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
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;
    int source_id;
    string value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _messagereceiver_ros_message_a_t;
typedef struct {
    struct self_base_t base;
#line 34 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.h"
    #line 135 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    std::shared_ptr<MinimalSubscriber> minimal_subscriber;
#line 37 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.h"
    _messagereceiver_ros_message_a_t _lf_ros_message_a;
    reaction_t _lf__reaction_0;
    reaction_t _lf__reaction_1;
    reaction_t _lf__reaction_2;
    reaction_t _lf__reaction_3;
    trigger_t _lf__t;
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    trigger_t _lf__shutdown;
    reaction_t* _lf__shutdown_reactions[1];
    trigger_t _lf__ros_message_a;
    reaction_t* _lf__ros_message_a_reactions[1];
} _messagereceiver_self_t;
_messagereceiver_self_t* new__messagereceiver();
#endif // _MESSAGERECEIVER_H
