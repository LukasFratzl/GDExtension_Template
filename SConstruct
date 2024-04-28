
module_name = "test_module"

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH="src/")

#env.Append(LIB="")
#env.Append(LIBPATH="")

src = Glob("src/**/*.cpp")

libpath = "godot-project/addons/{}/bin/lib{}{}{}".format(module_name, module_name, env["suffix"], env["SHLIBSUFFIX"])
sharedlib = env.SharedLibrary(libpath, src)
Default(sharedlib)

# include Path for Rider
# "$(ProjectDir)\src";"$(ProjectDir)\godot-cpp\gdextension"; "$(ProjectDir)\godot-cpp\include";"$(ProjectDir)\godot-cpp\gen\include"