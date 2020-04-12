##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ExampleOne
ConfigurationName      :=Debug
WorkspacePath          :=/home/gustavotakeda/Documents/C++/SFMLExamples
ProjectPath            :=/home/gustavotakeda/Documents/C++/SFMLExamples/ExampleOne
IntermediateDirectory  :=../bin-int/Debug-linux-x86_64/ExampleOne
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=gustavo takeda
Date                   :=06/04/20
CodeLitePath           :=/home/gustavotakeda/.codelite
LinkerName             :=/bin/clang++-9
SharedObjectLinkerName :=/bin/clang++-9 -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../bin/Debug-linux-x86_64/ExampleOne/ExampleOne
Preprocessors          :=$(PreprocessorSwitch)FLAC__NO_DLL $(PreprocessorSwitch)AL_LIBTYPE_STATIC $(PreprocessorSwitch)STB_TEXTEDIT_KEYTYPE=unsigned $(PreprocessorSwitch)SFML_STATIC $(PreprocessorSwitch)ONE_DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ExampleOne.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -m64 -lsfml-graphics-s -lsfml-window-s -lsfml-network-s -lsfml-audio-s -lsfml-system-s -lXrandr -lXext -lXrender -lX11 -lxcb -lXau -lXdmcp -lGL -ludev -lBox2D -lfreetype -lopenal -lflac -lflac++ -lvorbisfile -lvorbisenc -lvorbis -lpng16 -lbz2 -lasound -logg -lz -ldl -lm -lrt -lpthread
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../../../../.conan/data/sfml/2.5.1/bincrafters/stable/package/a0d4df6f2fe8684f201829ed3c2909bfc15b6dd3/include $(IncludeSwitch)../../../../.conan/data/box2d/2.3.2.ef96a4f/conan/stable/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/include $(IncludeSwitch)../../../../.conan/data/freetype/2.10.1/_/_/package/387eb5152986b9b3cbc2ebb94607d96d90674d67/include $(IncludeSwitch)../../../../.conan/data/freetype/2.10.1/_/_/package/387eb5152986b9b3cbc2ebb94607d96d90674d67/include/freetype2 $(IncludeSwitch)../../../../.conan/data/stb/20180214/conan/stable/package/5ab84d6acfe1f23c4fae0ab88f26e3a396351ac9/include $(IncludeSwitch)../../../../.conan/data/openal/1.19.1/_/_/package/8f758c7d79f11e0791dfc187e19cd92dffabbd2b/include $(IncludeSwitch)../../../../.conan/data/openal/1.19.1/_/_/package/8f758c7d79f11e0791dfc187e19cd92dffabbd2b/include/AL $(IncludeSwitch)../../../../.conan/data/flac/1.3.2/bincrafters/stable/package/b9bd28193f63cd74fd2213b63c74017e7893c24d/include $(IncludeSwitch)../../../../.conan/data/vorbis/1.3.6/bincrafters/stable/package/033a9a186751ed382a6fa5fa2c844ad34b7c3302/include $(IncludeSwitch)../../../../.conan/data/libpng/1.6.37/_/_/package/f99afdbf2a1cc98ba2029817b35103455b6a9b77/include $(IncludeSwitch)../../../../.conan/data/bzip2/1.0.8/_/_/package/da606cf731e334010b0bf6e85a2a6f891b9f36b0/include $(IncludeSwitch)../../../../.conan/data/libalsa/1.1.9/_/_/package/d48130e0dd76369b1338deb3b2372c5a649f9f2d/include $(IncludeSwitch)../../../../.conan/data/ogg/1.3.4/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include $(IncludeSwitch)../../../../.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/include $(IncludeSwitch)src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../../../../.conan/data/sfml/2.5.1/bincrafters/stable/package/a0d4df6f2fe8684f201829ed3c2909bfc15b6dd3/lib $(LibraryPathSwitch)../../../../.conan/data/box2d/2.3.2.ef96a4f/conan/stable/package/b911f48570f9bb2902d9e83b2b9ebf9d376c8c56/lib $(LibraryPathSwitch)../../../../.conan/data/freetype/2.10.1/_/_/package/387eb5152986b9b3cbc2ebb94607d96d90674d67/lib $(LibraryPathSwitch)../../../../.conan/data/openal/1.19.1/_/_/package/8f758c7d79f11e0791dfc187e19cd92dffabbd2b/lib $(LibraryPathSwitch)../../../../.conan/data/flac/1.3.2/bincrafters/stable/package/b9bd28193f63cd74fd2213b63c74017e7893c24d/lib $(LibraryPathSwitch)../../../../.conan/data/vorbis/1.3.6/bincrafters/stable/package/033a9a186751ed382a6fa5fa2c844ad34b7c3302/lib $(LibraryPathSwitch)../../../../.conan/data/libpng/1.6.37/_/_/package/f99afdbf2a1cc98ba2029817b35103455b6a9b77/lib $(LibraryPathSwitch)../../../../.conan/data/bzip2/1.0.8/_/_/package/da606cf731e334010b0bf6e85a2a6f891b9f36b0/lib $(LibraryPathSwitch)../../../../.conan/data/libalsa/1.1.9/_/_/package/d48130e0dd76369b1338deb3b2372c5a649f9f2d/lib $(LibraryPathSwitch)../../../../.conan/data/ogg/1.3.4/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib $(LibraryPathSwitch)../../../../.conan/data/zlib/1.2.11/_/_/package/6af9cc7cb931c5ad942174fd7838eb655717c709/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /bin/llvm-ar-9 rcu
CXX      := /bin/clang++-9
CC       := /bin/clang-9
CXXFLAGS :=  -m64 -g $(Preprocessors)
CFLAGS   :=  -m64 -g $(Preprocessors)
ASFLAGS  := 
AS       := /bin/llvm-as-9


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ../bin-int/Debug-linux-x86_64/ExampleOne || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/ExampleOne


$(IntermediateDirectory)/.d:
	@test -d ../bin-int/Debug-linux-x86_64/ExampleOne || $(MakeDirCommand) ../bin-int/Debug-linux-x86_64/ExampleOne

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix): src/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.cpp$(DependSuffix) -MM src/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gustavotakeda/Documents/C++/SFMLExamples/ExampleOne/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix): src/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.cpp$(PreprocessSuffix) src/main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ../bin-int/Debug-linux-x86_64/ExampleOne/


