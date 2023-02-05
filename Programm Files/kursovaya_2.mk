##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=kursovaya_2
ConfigurationName      :=Release
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/stud/C++Projects/Education
ProjectPath            :=/home/stud/C++Projects/Education/kursovaya_2
IntermediateDirectory  :=../build-$(ConfigurationName)/kursovaya_2
OutDir                 :=../build-$(ConfigurationName)/kursovaya_2
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=02/05/23
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++-10
SharedObjectLinkerName :=/usr/bin/g++-10 -shared -fPIC
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
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)crypto++ 
ArLibs                 :=  "crypto++" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-10
CC       := /usr/bin/gcc-10
CXXFLAGS :=  -O2 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/kursovaya_2/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/kursovaya_2/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/kursovaya_2"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/kursovaya_2"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/kursovaya_2/.d:
	@mkdir -p "../build-$(ConfigurationName)/kursovaya_2"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/kursovaya_2/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/kursovaya_2/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Education/kursovaya_2/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/kursovaya_2/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/kursovaya_2/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/kursovaya_2/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/kursovaya_2/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/kursovaya_2/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(ObjectSuffix): Client.cpp ../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Education/kursovaya_2/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Client.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(DependSuffix): Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(DependSuffix) -MM Client.cpp

../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(PreprocessSuffix): Client.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/kursovaya_2/Client.cpp$(PreprocessSuffix) Client.cpp

../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(ObjectSuffix): md5.cpp ../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/Education/kursovaya_2/md5.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/md5.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(DependSuffix): md5.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(DependSuffix) -MM md5.cpp

../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(PreprocessSuffix): md5.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/kursovaya_2/md5.cpp$(PreprocessSuffix) md5.cpp


-include ../build-$(ConfigurationName)/kursovaya_2//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


