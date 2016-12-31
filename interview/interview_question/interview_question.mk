##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=interview_question
ConfigurationName      :=Debug
WorkspacePath          :=/home/jianwang/Documents/c-plus-plus/interview
ProjectPath            :=/home/jianwang/Documents/c-plus-plus/interview/interview_question
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jianwang
Date                   :=31/12/16
CodeLitePath           :=/home/jianwang/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="interview_question.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/transmarket_code_1.cpp$(ObjectSuffix) $(IntermediateDirectory)/transmarket_code_2.cpp$(ObjectSuffix) $(IntermediateDirectory)/transmarket_code_3.cpp$(ObjectSuffix) $(IntermediateDirectory)/transmarket_code_4.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/transmarket_code_1.cpp$(ObjectSuffix): transmarket/code/1.cpp $(IntermediateDirectory)/transmarket_code_1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jianwang/Documents/c-plus-plus/interview/interview_question/transmarket/code/1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/transmarket_code_1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/transmarket_code_1.cpp$(DependSuffix): transmarket/code/1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/transmarket_code_1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/transmarket_code_1.cpp$(DependSuffix) -MM transmarket/code/1.cpp

$(IntermediateDirectory)/transmarket_code_1.cpp$(PreprocessSuffix): transmarket/code/1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/transmarket_code_1.cpp$(PreprocessSuffix)transmarket/code/1.cpp

$(IntermediateDirectory)/transmarket_code_2.cpp$(ObjectSuffix): transmarket/code/2.cpp $(IntermediateDirectory)/transmarket_code_2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jianwang/Documents/c-plus-plus/interview/interview_question/transmarket/code/2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/transmarket_code_2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/transmarket_code_2.cpp$(DependSuffix): transmarket/code/2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/transmarket_code_2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/transmarket_code_2.cpp$(DependSuffix) -MM transmarket/code/2.cpp

$(IntermediateDirectory)/transmarket_code_2.cpp$(PreprocessSuffix): transmarket/code/2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/transmarket_code_2.cpp$(PreprocessSuffix)transmarket/code/2.cpp

$(IntermediateDirectory)/transmarket_code_3.cpp$(ObjectSuffix): transmarket/code/3.cpp $(IntermediateDirectory)/transmarket_code_3.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jianwang/Documents/c-plus-plus/interview/interview_question/transmarket/code/3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/transmarket_code_3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/transmarket_code_3.cpp$(DependSuffix): transmarket/code/3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/transmarket_code_3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/transmarket_code_3.cpp$(DependSuffix) -MM transmarket/code/3.cpp

$(IntermediateDirectory)/transmarket_code_3.cpp$(PreprocessSuffix): transmarket/code/3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/transmarket_code_3.cpp$(PreprocessSuffix)transmarket/code/3.cpp

$(IntermediateDirectory)/transmarket_code_4.cpp$(ObjectSuffix): transmarket/code/4.cpp $(IntermediateDirectory)/transmarket_code_4.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/jianwang/Documents/c-plus-plus/interview/interview_question/transmarket/code/4.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/transmarket_code_4.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/transmarket_code_4.cpp$(DependSuffix): transmarket/code/4.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/transmarket_code_4.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/transmarket_code_4.cpp$(DependSuffix) -MM transmarket/code/4.cpp

$(IntermediateDirectory)/transmarket_code_4.cpp$(PreprocessSuffix): transmarket/code/4.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/transmarket_code_4.cpp$(PreprocessSuffix)transmarket/code/4.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


