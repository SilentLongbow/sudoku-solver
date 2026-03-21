from conan import ConanFile
from conan.tools.cmake import cmake_layout

class SudokuSolverRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("glaze/7.2.0")

    def layout(self):
        cmake_layout(self)
		