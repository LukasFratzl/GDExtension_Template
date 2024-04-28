/* godot-cpp integration testing project.
 *
 * This is free and unencumbered software released into the public domain.
 */

#include "register_types.hpp"

#include "my_custom_node.hpp"

using namespace godot;
using namespace test_module;

void initialize_test_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  GDREGISTER_CLASS(MyCustomNode);
}

void uninitialize_test_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT
test_module_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                         GDExtensionClassLibraryPtr p_library,
                         GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                                 r_initialization);

  init_obj.register_initializer(initialize_test_module);
  init_obj.register_terminator(uninitialize_test_module);
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE);

  return init_obj.init();
}
}
