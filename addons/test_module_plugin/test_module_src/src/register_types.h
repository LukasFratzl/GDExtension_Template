/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#ifndef TESTMODULE_REGISTER_TYPES_H
#define TESTMODULE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_TestModule_module(ModuleInitializationLevel p_level);
void uninitialize_TestModule_module(ModuleInitializationLevel p_level);

#endif // TESTMODULE_REGISTER_TYPES_H
