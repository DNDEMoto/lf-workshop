#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/BasicROS/MessageReceiver.h"
#include "_messagereceiver.h"
// *********** From the preamble, verbatim:
#line 109 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
class MinimalSubscriber : public rclcpp::Node {
  public:
    MinimalSubscriber(void* physical_action)
    : Node("minimal_subscriber"), physical_action_(physical_action) {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
    }

  private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const {
      char* writable_string = (char*)malloc(msg->data.length() + 1);
      strcpy(writable_string, msg->data.c_str());
      // writable_string[msg->data.length()] = '\0'; // Terminate with 0
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      std::cout << "At tag (" << lf_time_logical_elapsed() << ","
            << lf_tag().microstep << ") calling schedule_value with value "
            << writable_string << " and length " << msg->data.length()
            << "." << std::endl;
      lf_schedule_copy(physical_action_, 0, &(writable_string), msg->data.length() + 1);
      // std::cout << "Done calling schedule_value." << std::endl;
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    void* physical_action_;
};
#line 32 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _messagereceiverreaction_function_0(void* instance_args) {
    _messagereceiver_self_t* self = (_messagereceiver_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _messagereceiver_ros_message_a_t* ros_message_a = &self->_lf_ros_message_a;
    #line 140 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    // std::cout << "Executing startup." << std::endl;
    self->minimal_subscriber = std::make_shared<MinimalSubscriber>(ros_message_a);
#line 44 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _messagereceiverreaction_function_1(void* instance_args) {
    _messagereceiver_self_t* self = (_messagereceiver_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    lf_critical_section_enter(self->base.environment);
    // Expose the action struct as a local variable whose name matches the action name.
    _messagereceiver_ros_message_a_t* ros_message_a = &self->_lf_ros_message_a;
    // Set the fields of the action struct to match the current trigger.
    ros_message_a->is_present = (bool)self->_lf__ros_message_a.status;
    ros_message_a->has_value = ((self->_lf__ros_message_a.tmplt.token) != NULL && (self->_lf__ros_message_a.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)ros_message_a, (self->_lf__ros_message_a.tmplt.token));
    if (ros_message_a->has_value) {
        ros_message_a->value = *(string*)(self->_lf__ros_message_a.tmplt.token)->value;
    }
    lf_critical_section_exit(self->base.environment);
    #line 145 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    std::cout << "Physical action triggered." << std::endl;
    printf("Received: %s.\n", ros_message_a->value);
#line 64 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _messagereceiverreaction_function_2(void* instance_args) {
    _messagereceiver_self_t* self = (_messagereceiver_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 150 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    rclcpp::spin_some(self->minimal_subscriber);
        // std::cout << "Timer triggered." << std::endl;
#line 74 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _messagereceiverreaction_function_3(void* instance_args) {
    _messagereceiver_self_t* self = (_messagereceiver_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 155 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    // std::cout << "Executing shutdown reaction." << std::endl;
    rclcpp::shutdown();
#line 84 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagereceiver.c"
}
#include "include/api/reaction_macros_undef.h"
_messagereceiver_self_t* new__messagereceiver() {
    _messagereceiver_self_t* self = (_messagereceiver_self_t*)lf_new_reactor(sizeof(_messagereceiver_self_t));
    self->_lf_ros_message_a._base.trigger = &self->_lf__ros_message_a;
    self->_lf_ros_message_a.parent = (self_base_t*)self;
    self->_lf_ros_message_a.source_id = -1;
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _messagereceiverreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _messagereceiverreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _messagereceiverreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__reaction_3.number = 3;
    self->_lf__reaction_3.function = _messagereceiverreaction_function_3;
    self->_lf__reaction_3.self = self;
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    self->_lf__reaction_3.STP_handler = NULL;
    self->_lf__reaction_3.name = "?";
    self->_lf__reaction_3.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    self->_lf__t.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__t.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last_tag = NEVER_TAG;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__shutdown.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__shutdown_reactions[0] = &self->_lf__reaction_3;
    self->_lf__shutdown.last_tag = NEVER_TAG;
    self->_lf__shutdown.reactions = &self->_lf__shutdown_reactions[0];
    self->_lf__shutdown.number_of_reactions = 1;
    self->_lf__shutdown.is_timer = false;
    self->_lf__ros_message_a.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__ros_message_a.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__ros_message_a_reactions[0] = &self->_lf__reaction_1;
    self->_lf__ros_message_a.reactions = &self->_lf__ros_message_a_reactions[0];
    self->_lf__ros_message_a.number_of_reactions = 1;
    #ifdef FEDERATED
    self->_lf__ros_message_a.physical_time_of_arrival = NEVER;
    #endif // FEDERATED
    self->_lf__ros_message_a.is_physical = true;
    
    self->_lf__ros_message_a.tmplt.type.element_size = sizeof(string);
    self->_lf_ros_message_a.type.element_size = sizeof(string);
    return self;
}
