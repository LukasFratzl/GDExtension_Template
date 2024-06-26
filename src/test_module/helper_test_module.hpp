#ifndef HELPER_TEST_MODULE_H
#define HELPER_TEST_MODULE_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

namespace test_module {
class HelperTestModule {
private:
  /* data */
public:
  HelperTestModule(/* args */) = delete;
  ~HelperTestModule() = delete;

  template <typename class_binding, typename get_function_binding,
            typename set_function_binding>
  static _FORCE_INLINE_ void add_property_single(
      class_binding static_class, const String &property_name,
      get_function_binding get_binding, set_function_binding set_binding,
      const Variant::Type property_type,
      const godot::PropertyHint property_hint = PROPERTY_HINT_NONE,
      const String &allow_class = "Texture2D") {
    const String &_set_name = "set_" + property_name;
    const String &_get_name = "get_" + property_name;
    ClassDB::bind_method(D_METHOD(_get_name), get_binding);
    ClassDB::bind_method(D_METHOD(_set_name, "Value"), set_binding);
    ClassDB::add_property(
        static_class,
        PropertyInfo(property_type, property_name, property_hint, allow_class),
        _set_name, _get_name);
  }
};
} // namespace test_module

#endif // HELPER_TEST_MODULE_H
