##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab2
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=D:/Repo's/APS105-Code/APS105
ProjectPath            :=D:/Repo's/APS105-Code/APS105/Lab2
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab2
OutDir                 :=../build-$(ConfigurationName)/Lab2
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
Objects0=../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(ObjectSuffix) ../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(ObjectSuffix) ../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab2/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab2" mkdir "..\build-$(ConfigurationName)\Lab2"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab2" mkdir "..\build-$(ConfigurationName)\Lab2"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab2/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab2" mkdir "..\build-$(ConfigurationName)\Lab2"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(ObjectSuffix): Lab2Part1.c ../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Repo's/APS105-Code/APS105/Lab2/Lab2Part1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab2Part1.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(DependSuffix): Lab2Part1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(DependSuffix) -MM Lab2Part1.c

../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(PreprocessSuffix): Lab2Part1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab2/Lab2Part1.c$(PreprocessSuffix) Lab2Part1.c

../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(ObjectSuffix): Lab2Part3.c ../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Repo's/APS105-Code/APS105/Lab2/Lab2Part3.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab2Part3.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(DependSuffix): Lab2Part3.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(DependSuffix) -MM Lab2Part3.c

../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(PreprocessSuffix): Lab2Part3.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab2/Lab2Part3.c$(PreprocessSuffix) Lab2Part3.c

../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(ObjectSuffix): Lab2Part2.c ../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(DependSuffix)
	$(CC) $(SourceSwitch) "D:/Repo's/APS105-Code/APS105/Lab2/Lab2Part2.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lab2Part2.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(DependSuffix): Lab2Part2.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(DependSuffix) -MM Lab2Part2.c

../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(PreprocessSuffix): Lab2Part2.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab2/Lab2Part2.c$(PreprocessSuffix) Lab2Part2.c


-include ../build-$(ConfigurationName)/Lab2//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


