##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab1
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=D:/Repo's/APS105-Code/APS105
ProjectPath            :=D:/Repo's/APS105-Code/APS105/Lab1
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab1
OutDir                 :=../build-$(ConfigurationName)/Lab1
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stephen
Date                   :=12/01/2020
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
Objects0=../build-$(ConfigurationName)/Lab1/Lab1.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab1/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab1" mkdir "..\build-$(ConfigurationName)\Lab1"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab1" mkdir "..\build-$(ConfigurationName)\Lab1"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab1/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab1" mkdir "..\build-$(ConfigurationName)\Lab1"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab1/Lab1.c$(ObjectSuffix): Lab1.c ../build-$(ConfigurationName)/Lab1/Lab1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Repo's/APS105-Code/APS105/Lab1/Lab1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab1.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab1/Lab1.c$(DependSuffix): Lab1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab1/Lab1.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab1/Lab1.c$(DependSuffix) -MM Lab1.c

../build-$(ConfigurationName)/Lab1/Lab1.c$(PreprocessSuffix): Lab1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab1/Lab1.c$(PreprocessSuffix) Lab1.c


-include ../build-$(ConfigurationName)/Lab1//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


