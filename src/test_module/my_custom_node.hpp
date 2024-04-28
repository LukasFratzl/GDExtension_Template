// #ifndef preferred over #pragma once
#ifndef MY_CUSTOM_NODE_H
#define MY_CUSTOM_NODE_H

#include "helper_test_module.hpp"
// include with <> preferred for godot types over ""
#include <godot_cpp/classes/node3d.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

namespace test_module {

// PascalCase for Classed and Nodes
class MyCustomNode : public Node3D {
  GDCLASS(MyCustomNode, Node3D)

public:
  int32_t int_value = 0;
  float_t float_value = 0;
  String string_value = "Hi";
  Ref<Texture2D> texture_value;

  int32_t get_my_int() const { return int_value; }
  void set_my_int(int32_t Value) { int_value = Value; }

  float_t get_my_float() const { return float_value; }
  void set_my_float(float_t Value) { float_value = Value; }

  const String &get_my_string() const { return string_value; }
  void set_my_string(const String &Value) { string_value = Value; }

  Ref<Texture2D> get_my_texture() const { return texture_value; }
  void set_my_texture(const Ref<Texture2D> Value) { texture_value = Value; }

public:
  // The start_test naming convention with snake_case
  // because it's a public function without Underscore
  void start_test() {
    UtilityFunctions::print("Hello from GDC Extensions ... :)");
  }
  void start_test_with_arguments(const String &message) {
    UtilityFunctions::print(message);
  }

protected:
  // the _bind_methods naming convention with snake_case
  // because it's a private/protected or virtual function with Underscores
  static void _bind_methods() {
    ClassDB::bind_method(D_METHOD("start_test"), &MyCustomNode::start_test);
    ClassDB::bind_method(D_METHOD("start_test_with_arguments"),
                         &MyCustomNode::start_test_with_arguments,
                         Variant::STRING);

    HelperTestModule::add_property_single(
        MyCustomNode::get_class_static(), "my_int", &MyCustomNode::get_my_int,
        &MyCustomNode::set_my_int, Variant::INT);

    HelperTestModule::add_property_single(
        MyCustomNode::get_class_static(), "my_float",
        &MyCustomNode::get_my_float, &MyCustomNode::set_my_float,
        Variant::FLOAT);

    HelperTestModule::add_property_single(
        MyCustomNode::get_class_static(), "my_string",
        &MyCustomNode::get_my_string, &MyCustomNode::set_my_string,
        Variant::STRING);

    HelperTestModule::add_property_single(
        MyCustomNode::get_class_static(), "my_texture",
        &MyCustomNode::get_my_texture, &MyCustomNode::set_my_texture,
        Variant::OBJECT, PROPERTY_HINT_RESOURCE_TYPE, "Texture2D");
  }
};

} // namespace test_module

#endif // MY_CUSTOM_NODE_H
