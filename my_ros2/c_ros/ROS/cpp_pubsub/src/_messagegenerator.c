#include "include/api/schedule.h"
#include "low_level_platform/api/low_level_platform.h"
#include "include/BasicROS/MessageGenerator.h"
#include "_messagegenerator.h"
// *********** From the preamble, verbatim:
#line 68 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
class MinimalPublisher : public rclcpp::Node {
  public:
    MinimalPublisher()
    : Node("minimal_publisher")
    {
      publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};
#line 18 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.c"

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/reaction_macros.h"
void _messagegeneratorreaction_function_0(void* instance_args) {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 84 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    std::cout << "Executing startup." << std::endl;
    char *argv[] = {(char*)"BasicROSPub", NULL};
    rclcpp::init(1, argv);
    self->minimal_publisher = std::make_shared<MinimalPublisher>();
#line 32 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _messagegeneratorreaction_function_1(void* instance_args) {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 91 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    auto message = std_msgs::msg::String();
        std::cout << "Executing timer reaction." << std::endl;
        message.data = "Hello, world! " + std::to_string(self->i++);
        RCLCPP_INFO(self->minimal_publisher->get_logger(),
              "Sender publishing: '%s'", message.data.c_str());
        self->minimal_publisher->publisher_->publish(message);
        rclcpp::spin_some(self->minimal_publisher);
        std::cout << "Done executing timer reaction." << std::endl;
#line 48 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.c"
}
#include "include/api/reaction_macros_undef.h"
#include "include/api/reaction_macros.h"
void _messagegeneratorreaction_function_2(void* instance_args) {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 102 "/workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf"
    std::cout << "Executing shutdown reaction." << std::endl;
    rclcpp::shutdown();
#line 58 "/workspaces/lf-workshop/my_cpp_ros2/ROS/src-gen/BasicROS/_messagegenerator.c"
}
#include "include/api/reaction_macros_undef.h"
_messagegenerator_self_t* new__messagegenerator() {
    _messagegenerator_self_t* self = (_messagegenerator_self_t*)lf_new_reactor(sizeof(_messagegenerator_self_t));
    self->_lf__reaction_0.number = 0;
    self->_lf__reaction_0.function = _messagegeneratorreaction_function_0;
    self->_lf__reaction_0.self = self;
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    self->_lf__reaction_0.STP_handler = NULL;
    self->_lf__reaction_0.name = "?";
    self->_lf__reaction_0.mode = NULL;
    self->_lf__reaction_1.number = 1;
    self->_lf__reaction_1.function = _messagegeneratorreaction_function_1;
    self->_lf__reaction_1.self = self;
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    self->_lf__reaction_1.STP_handler = NULL;
    self->_lf__reaction_1.name = "?";
    self->_lf__reaction_1.mode = NULL;
    self->_lf__reaction_2.number = 2;
    self->_lf__reaction_2.function = _messagegeneratorreaction_function_2;
    self->_lf__reaction_2.self = self;
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    self->_lf__reaction_2.STP_handler = NULL;
    self->_lf__reaction_2.name = "?";
    self->_lf__reaction_2.mode = NULL;
    self->_lf__t.last_tag = NEVER_TAG;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
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
    self->_lf__shutdown_reactions[0] = &self->_lf__reaction_2;
    self->_lf__shutdown.last_tag = NEVER_TAG;
    self->_lf__shutdown.reactions = &self->_lf__shutdown_reactions[0];
    self->_lf__shutdown.number_of_reactions = 1;
    self->_lf__shutdown.is_timer = false;
    return self;
}
