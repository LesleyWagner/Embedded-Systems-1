#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=src/assignment1_4.c lib/src/lcd.c lib/src/utils.c lib/src/button_utils.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/src/assignment1_4.o ${OBJECTDIR}/lib/src/lcd.o ${OBJECTDIR}/lib/src/utils.o ${OBJECTDIR}/lib/src/button_utils.o
POSSIBLE_DEPFILES=${OBJECTDIR}/src/assignment1_4.o.d ${OBJECTDIR}/lib/src/lcd.o.d ${OBJECTDIR}/lib/src/utils.o.d ${OBJECTDIR}/lib/src/button_utils.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/src/assignment1_4.o ${OBJECTDIR}/lib/src/lcd.o ${OBJECTDIR}/lib/src/utils.o ${OBJECTDIR}/lib/src/button_utils.o

# Source Files
SOURCEFILES=src/assignment1_4.c lib/src/lcd.c lib/src/utils.c lib/src/button_utils.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX370F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/src/assignment1_4.o: src/assignment1_4.c  .generated_files/545f08e54f6402a834e3de093b14c9c33df78229.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/assignment1_4.o.d 
	@${RM} ${OBJECTDIR}/src/assignment1_4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/src/assignment1_4.o.d" -o ${OBJECTDIR}/src/assignment1_4.o src/assignment1_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/lcd.o: lib/src/lcd.c  .generated_files/fb63b8db8f52e1309d31a4b28ca01df2ae501f60.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/lcd.o.d 
	@${RM} ${OBJECTDIR}/lib/src/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/lcd.o.d" -o ${OBJECTDIR}/lib/src/lcd.o lib/src/lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/utils.o: lib/src/utils.c  .generated_files/efba8f8e96d8d858906ab158968b6109782e847b.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/utils.o.d 
	@${RM} ${OBJECTDIR}/lib/src/utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/utils.o.d" -o ${OBJECTDIR}/lib/src/utils.o lib/src/utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/button_utils.o: lib/src/button_utils.c  .generated_files/aa22b5e50f168cca5294fafceb9b0fefafab6c96.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/button_utils.o.d 
	@${RM} ${OBJECTDIR}/lib/src/button_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/button_utils.o.d" -o ${OBJECTDIR}/lib/src/button_utils.o lib/src/button_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/src/assignment1_4.o: src/assignment1_4.c  .generated_files/8b8b3e06eb8ba68adb42baf8acc9b2b11b0aa8d4.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/src" 
	@${RM} ${OBJECTDIR}/src/assignment1_4.o.d 
	@${RM} ${OBJECTDIR}/src/assignment1_4.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/src/assignment1_4.o.d" -o ${OBJECTDIR}/src/assignment1_4.o src/assignment1_4.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/lcd.o: lib/src/lcd.c  .generated_files/16c9ac7470604612d3e1495d736f1acf6c9eef6e.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/lcd.o.d 
	@${RM} ${OBJECTDIR}/lib/src/lcd.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/lcd.o.d" -o ${OBJECTDIR}/lib/src/lcd.o lib/src/lcd.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/utils.o: lib/src/utils.c  .generated_files/229ec056a00021bef7e024508d8992e1fef93687.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/utils.o.d 
	@${RM} ${OBJECTDIR}/lib/src/utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/utils.o.d" -o ${OBJECTDIR}/lib/src/utils.o lib/src/utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/lib/src/button_utils.o: lib/src/button_utils.c  .generated_files/323c76802dc1771525179ea9d6f24a97b4d88560.flag .generated_files/27f35a8012588aa0782606a8ea9e1f521326521d.flag
	@${MKDIR} "${OBJECTDIR}/lib/src" 
	@${RM} ${OBJECTDIR}/lib/src/button_utils.o.d 
	@${RM} ${OBJECTDIR}/lib/src/button_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"src" -I"inc" -I"lib/inc" -I"lib/src" -MP -MMD -MF "${OBJECTDIR}/lib/src/button_utils.o.d" -o ${OBJECTDIR}/lib/src/button_utils.o lib/src/button_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map" 
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Assignment_1.4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
