// Code generated by the Lingua Franca compiler from:
// file://workspaces/lf-workshop/my_cpp_ros2/ROS/BasicROS.lf
#define LOG_LEVEL 4

#include <limits.h>
#include "low_level_platform/api/low_level_platform.h"
#include "include/api/schedule.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/threaded/scheduler.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
int main(int argc, const char* argv[]) {
    return lf_reactor_c_main(argc, argv);
}
const char* _lf_default_argv[] = { "dummy", "-k", "true" };
void lf_set_default_command_line_options() {
        default_argc = 3;
        default_argv = _lf_default_argv;
}
#include "_messagegenerator.h"
#include "_messagereceiver.h"
#include "_basicros_main.h"
typedef enum {
    basicros_main,
    _num_enclaves
} _enclave_id;
// The global array of environments associated with each enclave
environment_t envs[_num_enclaves];
// 'Create' and initialize the environments in the program
void lf_create_environments() {
    environment_init(&envs[basicros_main],"BasicROS",basicros_main,_lf_number_of_workers,2,2,2,0,1,0,0,0,NULL);
}
// Update the pointer argument to point to the beginning of the environment array
// and return the size of that array
int _lf_get_environments(environment_t ** return_envs) {
   (*return_envs) = (environment_t *) envs;
   return _num_enclaves;
}
void _lf_initialize_trigger_objects() {
    int startup_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(startup_reaction_count);
    int shutdown_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(shutdown_reaction_count);
    int reset_reaction_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(reset_reaction_count);
    int timer_triggers_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(timer_triggers_count);
    int modal_state_reset_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_state_reset_count);
    int modal_reactor_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(modal_reactor_count);
    int watchdog_count[_num_enclaves] = {0}; SUPPRESS_UNUSED_WARNING(watchdog_count);
    int bank_index;
    SUPPRESS_UNUSED_WARNING(bank_index);
    int watchdog_number = 0;
    SUPPRESS_UNUSED_WARNING(watchdog_number);
    _basicros_main_main_self_t* basicros_main_self[1];
    SUPPRESS_UNUSED_WARNING(basicros_main_self);
    _messagegenerator_self_t* basicros_sender_self[1];
    SUPPRESS_UNUSED_WARNING(basicros_sender_self);
    _messagereceiver_self_t* basicros_receiver_self[1];
    SUPPRESS_UNUSED_WARNING(basicros_receiver_self);
    // ***** Start initializing BasicROS of class BasicROS
    basicros_main_self[0] = new__basicros_main();
    basicros_main_self[0]->base.environment = &envs[basicros_main];
    bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
    
    {
        _basicros_main_main_self_t *self = basicros_main_self[0];
        // ***** Start initializing BasicROS.sender of class MessageGenerator
        basicros_sender_self[0] = new__messagegenerator();
        basicros_sender_self[0]->base.environment = &envs[basicros_main];
        bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
        envs[basicros_main].startup_reactions[startup_reaction_count[basicros_main]++] = &basicros_sender_self[0]->_lf__reaction_0;
        envs[basicros_main].shutdown_reactions[shutdown_reaction_count[basicros_main]++] = &basicros_sender_self[0]->_lf__reaction_2;
        { // For scoping
            static int _initial = 0;
            basicros_sender_self[0]->i = _initial;
        } // End scoping.
        // Initiaizing timer BasicROS.sender.t.
        basicros_sender_self[0]->_lf__t.offset = 0;
        basicros_sender_self[0]->_lf__t.period = MSEC(500);
        // Associate timer with the environment of its parent
        envs[basicros_main].timer_triggers[timer_triggers_count[basicros_main]++] = &basicros_sender_self[0]->_lf__t;
        basicros_sender_self[0]->_lf__t.mode = NULL;
    
        basicros_sender_self[0]->_lf__reaction_0.deadline = NEVER;
        basicros_sender_self[0]->_lf__reaction_1.deadline = NEVER;
        basicros_sender_self[0]->_lf__reaction_2.deadline = NEVER;
        //***** End initializing BasicROS.sender
    }
    {
        _basicros_main_main_self_t *self = basicros_main_self[0];
        // ***** Start initializing BasicROS.receiver of class MessageReceiver
        basicros_receiver_self[0] = new__messagereceiver();
        basicros_receiver_self[0]->base.environment = &envs[basicros_main];
        bank_index = 0; SUPPRESS_UNUSED_WARNING(bank_index);
        envs[basicros_main].startup_reactions[startup_reaction_count[basicros_main]++] = &basicros_receiver_self[0]->_lf__reaction_0;
        envs[basicros_main].shutdown_reactions[shutdown_reaction_count[basicros_main]++] = &basicros_receiver_self[0]->_lf__reaction_3;
        // Initiaizing timer BasicROS.receiver.t.
        basicros_receiver_self[0]->_lf__t.offset = 0;
        basicros_receiver_self[0]->_lf__t.period = MSEC(500);
        // Associate timer with the environment of its parent
        envs[basicros_main].timer_triggers[timer_triggers_count[basicros_main]++] = &basicros_receiver_self[0]->_lf__t;
        basicros_receiver_self[0]->_lf__t.mode = NULL;
        // Initializing action BasicROS.receiver.ros_message_a
        basicros_receiver_self[0]->_lf__ros_message_a.offset = 0;
        basicros_receiver_self[0]->_lf__ros_message_a.period = -1;
        basicros_receiver_self[0]->_lf__ros_message_a.last_tag = NEVER_TAG;
        basicros_receiver_self[0]->_lf__ros_message_a.mode = NULL;
        _lf_initialize_template((token_template_t*)
                &(basicros_receiver_self[0]->_lf__ros_message_a),
        sizeof(string));
        basicros_receiver_self[0]->_lf__ros_message_a.status = absent;
        basicros_receiver_self[0]->_lf__reaction_0.deadline = NEVER;
        basicros_receiver_self[0]->_lf__reaction_1.deadline = NEVER;
        basicros_receiver_self[0]->_lf__reaction_2.deadline = NEVER;
        basicros_receiver_self[0]->_lf__reaction_3.deadline = NEVER;
        //***** End initializing BasicROS.receiver
    }
    //***** End initializing BasicROS
    // **** Start deferred initialize for BasicROS
    {
    
    
    
        // **** Start deferred initialize for BasicROS.sender
        {
        
            basicros_sender_self[0]->_lf__reaction_0.name = "BasicROS.sender reaction 0";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_1 of BasicROS.sender.
            basicros_sender_self[0]->_lf__reaction_0.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 0 of BasicROS.sender
            basicros_sender_self[0]->_lf__reaction_1.name = "BasicROS.sender reaction 1";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_2 of BasicROS.sender.
            basicros_sender_self[0]->_lf__reaction_1.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 1 of BasicROS.sender
            basicros_sender_self[0]->_lf__reaction_2.name = "BasicROS.sender reaction 2";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_3 of BasicROS.sender.
            basicros_sender_self[0]->_lf__reaction_2.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 2 of BasicROS.sender
        
        }
        // **** End of deferred initialize for BasicROS.sender
        // **** Start deferred initialize for BasicROS.receiver
        {
        
            basicros_receiver_self[0]->_lf__reaction_0.name = "BasicROS.receiver reaction 0";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_1 of BasicROS.receiver.
            basicros_receiver_self[0]->_lf__reaction_0.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 0 of BasicROS.receiver
            basicros_receiver_self[0]->_lf__reaction_1.name = "BasicROS.receiver reaction 1";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_2 of BasicROS.receiver.
            basicros_receiver_self[0]->_lf__reaction_1.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 1 of BasicROS.receiver
            basicros_receiver_self[0]->_lf__reaction_2.name = "BasicROS.receiver reaction 2";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_3 of BasicROS.receiver.
            basicros_receiver_self[0]->_lf__reaction_2.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 2 of BasicROS.receiver
            basicros_receiver_self[0]->_lf__reaction_3.name = "BasicROS.receiver reaction 3";
            // Total number of outputs (single ports and multiport channels)
            // produced by reaction_4 of BasicROS.receiver.
            basicros_receiver_self[0]->_lf__reaction_3.num_outputs = 0;
            {
                int count = 0; SUPPRESS_UNUSED_WARNING(count);
            }
            
            // ** End initialization for reaction 3 of BasicROS.receiver
        
        }
        // **** End of deferred initialize for BasicROS.receiver
    }
    // **** End of deferred initialize for BasicROS
    // **** Start non-nested deferred initialize for BasicROS
    {
    
    
    
        // **** Start non-nested deferred initialize for BasicROS.sender
        {
        
        
        
        
        }
        // **** End of non-nested deferred initialize for BasicROS.sender
        // **** Start non-nested deferred initialize for BasicROS.receiver
        {
        
        
        
        
        }
        // **** End of non-nested deferred initialize for BasicROS.receiver
    }
    // **** End of non-nested deferred initialize for BasicROS
    // Connect inputs and outputs for reactor BasicROS.
    // Connect inputs and outputs for reactor BasicROS.sender.
    // Connect inputs and outputs for reactor BasicROS.receiver.
    {
    }
    {
        // Add action BasicROS.receiver.ros_message_a to array of is_present fields.
        envs[basicros_main].is_present_fields[0 + (0) * 1]
                = (bool *) &basicros_receiver_self[0]->_lf__ros_message_a.status;
        #ifdef FEDERATED_DECENTRALIZED
        // Add action BasicROS.receiver.ros_message_a to array of intended_tag fields.
        envs[basicros_main]._lf_intended_tag_fields[0 + (0) * 1]
                = &basicros_receiver_self[0]->_lf_ros_message_a.intended_tag;
        #endif // FEDERATED_DECENTRALIZED
    }
    
    // Set reaction priorities for ReactorInstance BasicROS
    {
    
        // Set reaction priorities for ReactorInstance BasicROS.sender
        {
            // index is the OR of level 0 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_sender_self[0]->_lf__reaction_0.index = lf_combine_deadline_and_level(9223372036854775807, 0);
            // index is the OR of level 1 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_sender_self[0]->_lf__reaction_1.index = lf_combine_deadline_and_level(9223372036854775807, 1);
            // index is the OR of level 2 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_sender_self[0]->_lf__reaction_2.index = lf_combine_deadline_and_level(9223372036854775807, 2);
        }
    
    
        // Set reaction priorities for ReactorInstance BasicROS.receiver
        {
            // index is the OR of level 0 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_receiver_self[0]->_lf__reaction_0.index = lf_combine_deadline_and_level(9223372036854775807, 0);
            // index is the OR of level 1 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_receiver_self[0]->_lf__reaction_1.index = lf_combine_deadline_and_level(9223372036854775807, 1);
            // index is the OR of level 2 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_receiver_self[0]->_lf__reaction_2.index = lf_combine_deadline_and_level(9223372036854775807, 2);
            // index is the OR of level 3 and 
            // deadline 9223372036854775807 shifted left 16 bits.
            basicros_receiver_self[0]->_lf__reaction_3.index = lf_combine_deadline_and_level(9223372036854775807, 3);
        }
    
    }
    
    // Initialize the scheduler
    size_t num_reactions_per_level[4] = 
        {2, 2, 2, 1};
    sched_params_t sched_params = (sched_params_t) {
                            .num_reactions_per_level = &num_reactions_per_level[0],
                            .num_reactions_per_level_size = (size_t) 4};
    lf_sched_init(
        &envs[basicros_main],
        envs[basicros_main].num_workers,
        &sched_params
    );
    #ifdef EXECUTABLE_PREAMBLE
    _lf_executable_preamble(&envs[0]);
    #endif
    #ifdef FEDERATED
    initialize_triggers_for_federate();
    #endif // FEDERATED
}
void logical_tag_complete(tag_t tag_to_send) {
 #ifdef FEDERATED_CENTRALIZED
     lf_latest_tag_confirmed(tag_to_send);
 #else
     (void) tag_to_send;
 #endif // FEDERATED_CENTRALIZED

}
#ifndef FEDERATED
void lf_terminate_execution(environment_t* env) {
    (void) env;
}
#endif
