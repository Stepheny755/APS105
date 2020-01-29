##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab3
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=D:/Repo's/APS105-Code/APS105
ProjectPath            :=D:/Repo's/APS105-Code/APS105/Lab3
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab3
OutDir                 :=../build-$(ConfigurationName)/Lab3
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stephen
Date                   :=29/01/2020
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
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
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Lab3/Lab3.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab3/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab3" mkdir "..\build-$(ConfigurationName)\Lab3"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab3" mkdir "..\build-$(ConfigurationName)\Lab3"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab3/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab3" mkdir "..\build-$(ConfigurationName)\Lab3"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab3/Lab3.c$(ObjectSuffix): Lab3.c ../build-$(ConfigurationName)/Lab3/Lab3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Repo's/APS105-Code/APS105/Lab3/Lab3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab3.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab3/Lab3.c$(DependSuffix): Lab3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab3/Lab3.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab3/Lab3.c$(DependSuffix) -MM Lab3.c

../build-$(ConfigurationName)/Lab3/Lab3.c$(PreprocessSuffix): Lab3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab3/Lab3.c$(PreprocessSuffix) Lab3.c


-include ../build-$(ConfigurationName)/Lab3//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


