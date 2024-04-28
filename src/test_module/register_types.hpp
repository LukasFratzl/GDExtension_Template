/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef TEST_MODULE_REGISTER_TYPES_H
#define TEST_MODULE_REGISTER_TYPES_H

#include "godot_cpp/core/class_db.hpp"

using namespace godot;

void initialize_test_module(ModuleInitializationLevel p_level);
void uninitialize_test_module(ModuleInitializationLevel p_level);

#endif // TEST_MODULE_REGISTER_TYPES_H
