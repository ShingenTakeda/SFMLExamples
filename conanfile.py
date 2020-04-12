from conans import ConanFile
from parktoma.vscconan import update_cpp_tools

class DepsConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "sfml/2.5.1@bincrafters/stable", "box2d/2.3.2.ef96a4f@conan/stable"
    generators = "premake"

    default_options = "sfml:audio=True","sfml:window=True","sfml:graphics=True","sfml:network=True"

    def imports(self):
        update_cpp_tools(self, conanfile_path=__file__)