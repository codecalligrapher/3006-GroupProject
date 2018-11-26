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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED="D:/ECNG 3006/LCDtest.X/_xlcd/busyxlcd.c" "D:/ECNG 3006/LCDtest.X/_xlcd/openxlcd.c" "D:/ECNG 3006/LCDtest.X/_xlcd/putrxlcd.c" "D:/ECNG 3006/LCDtest.X/_xlcd/putsxlcd.c" "D:/ECNG 3006/LCDtest.X/_xlcd/readaddr.c" "D:/ECNG 3006/LCDtest.X/_xlcd/readdata.c" "D:/ECNG 3006/LCDtest.X/_xlcd/setcgram.c" "D:/ECNG 3006/LCDtest.X/_xlcd/setddram.c" "D:/ECNG 3006/LCDtest.X/_xlcd/wcmdxlcd.c" "D:/ECNG 3006/LCDtest.X/_xlcd/writdata.c" "D:/ECNG 3006/LCDtest.X/_adc.c" "D:/ECNG 3006/LCDtest.X/_lcd.c" "D:/ECNG 3006/LCDtest.X/_counter.c" "D:/ECNG 3006/LCDtest.X/_interface.c" "D:/ECNG 3006/LCDtest.X/_kpad.c" "D:/ECNG 3006/LCDtest.X/_pNN50.c" "D:/ECNG 3006/LCDtest.X/_countv.c" "D:/ECNG 3006/LCDtest.X/_dbg.c" "D:/ECNG 3006/LCDtest.X/_eeprom.c" "D:/ECNG 3006/LCDtest.X/_speaker.c" "D:/ECNG 3006/LCDtest.X/_temp.c" "D:/ECNG 3006/LCDtest.X/_fram.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/474789440/busyxlcd.o ${OBJECTDIR}/_ext/474789440/openxlcd.o ${OBJECTDIR}/_ext/474789440/putrxlcd.o ${OBJECTDIR}/_ext/474789440/putsxlcd.o ${OBJECTDIR}/_ext/474789440/readaddr.o ${OBJECTDIR}/_ext/474789440/readdata.o ${OBJECTDIR}/_ext/474789440/setcgram.o ${OBJECTDIR}/_ext/474789440/setddram.o ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o ${OBJECTDIR}/_ext/474789440/writdata.o ${OBJECTDIR}/_ext/1761785317/_adc.o ${OBJECTDIR}/_ext/1761785317/_lcd.o ${OBJECTDIR}/_ext/1761785317/_counter.o ${OBJECTDIR}/_ext/1761785317/_interface.o ${OBJECTDIR}/_ext/1761785317/_kpad.o ${OBJECTDIR}/_ext/1761785317/_pNN50.o ${OBJECTDIR}/_ext/1761785317/_countv.o ${OBJECTDIR}/_ext/1761785317/_dbg.o ${OBJECTDIR}/_ext/1761785317/_eeprom.o ${OBJECTDIR}/_ext/1761785317/_speaker.o ${OBJECTDIR}/_ext/1761785317/_temp.o ${OBJECTDIR}/_ext/1761785317/_fram.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/474789440/busyxlcd.o.d ${OBJECTDIR}/_ext/474789440/openxlcd.o.d ${OBJECTDIR}/_ext/474789440/putrxlcd.o.d ${OBJECTDIR}/_ext/474789440/putsxlcd.o.d ${OBJECTDIR}/_ext/474789440/readaddr.o.d ${OBJECTDIR}/_ext/474789440/readdata.o.d ${OBJECTDIR}/_ext/474789440/setcgram.o.d ${OBJECTDIR}/_ext/474789440/setddram.o.d ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o.d ${OBJECTDIR}/_ext/474789440/writdata.o.d ${OBJECTDIR}/_ext/1761785317/_adc.o.d ${OBJECTDIR}/_ext/1761785317/_lcd.o.d ${OBJECTDIR}/_ext/1761785317/_counter.o.d ${OBJECTDIR}/_ext/1761785317/_interface.o.d ${OBJECTDIR}/_ext/1761785317/_kpad.o.d ${OBJECTDIR}/_ext/1761785317/_pNN50.o.d ${OBJECTDIR}/_ext/1761785317/_countv.o.d ${OBJECTDIR}/_ext/1761785317/_dbg.o.d ${OBJECTDIR}/_ext/1761785317/_eeprom.o.d ${OBJECTDIR}/_ext/1761785317/_speaker.o.d ${OBJECTDIR}/_ext/1761785317/_temp.o.d ${OBJECTDIR}/_ext/1761785317/_fram.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/474789440/busyxlcd.o ${OBJECTDIR}/_ext/474789440/openxlcd.o ${OBJECTDIR}/_ext/474789440/putrxlcd.o ${OBJECTDIR}/_ext/474789440/putsxlcd.o ${OBJECTDIR}/_ext/474789440/readaddr.o ${OBJECTDIR}/_ext/474789440/readdata.o ${OBJECTDIR}/_ext/474789440/setcgram.o ${OBJECTDIR}/_ext/474789440/setddram.o ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o ${OBJECTDIR}/_ext/474789440/writdata.o ${OBJECTDIR}/_ext/1761785317/_adc.o ${OBJECTDIR}/_ext/1761785317/_lcd.o ${OBJECTDIR}/_ext/1761785317/_counter.o ${OBJECTDIR}/_ext/1761785317/_interface.o ${OBJECTDIR}/_ext/1761785317/_kpad.o ${OBJECTDIR}/_ext/1761785317/_pNN50.o ${OBJECTDIR}/_ext/1761785317/_countv.o ${OBJECTDIR}/_ext/1761785317/_dbg.o ${OBJECTDIR}/_ext/1761785317/_eeprom.o ${OBJECTDIR}/_ext/1761785317/_speaker.o ${OBJECTDIR}/_ext/1761785317/_temp.o ${OBJECTDIR}/_ext/1761785317/_fram.o

# Source Files
SOURCEFILES=D:/ECNG 3006/LCDtest.X/_xlcd/busyxlcd.c D:/ECNG 3006/LCDtest.X/_xlcd/openxlcd.c D:/ECNG 3006/LCDtest.X/_xlcd/putrxlcd.c D:/ECNG 3006/LCDtest.X/_xlcd/putsxlcd.c D:/ECNG 3006/LCDtest.X/_xlcd/readaddr.c D:/ECNG 3006/LCDtest.X/_xlcd/readdata.c D:/ECNG 3006/LCDtest.X/_xlcd/setcgram.c D:/ECNG 3006/LCDtest.X/_xlcd/setddram.c D:/ECNG 3006/LCDtest.X/_xlcd/wcmdxlcd.c D:/ECNG 3006/LCDtest.X/_xlcd/writdata.c D:/ECNG 3006/LCDtest.X/_adc.c D:/ECNG 3006/LCDtest.X/_lcd.c D:/ECNG 3006/LCDtest.X/_counter.c D:/ECNG 3006/LCDtest.X/_interface.c D:/ECNG 3006/LCDtest.X/_kpad.c D:/ECNG 3006/LCDtest.X/_pNN50.c D:/ECNG 3006/LCDtest.X/_countv.c D:/ECNG 3006/LCDtest.X/_dbg.c D:/ECNG 3006/LCDtest.X/_eeprom.c D:/ECNG 3006/LCDtest.X/_speaker.c D:/ECNG 3006/LCDtest.X/_temp.c D:/ECNG 3006/LCDtest.X/_fram.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F452
MP_PROCESSOR_OPTION_LD=18f452
MP_LINKER_DEBUG_OPTION=-r=ROM@0x7DC0:0x7FFF -r=RAM@GPR:0x5F4:0x5FF -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/474789440/busyxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/busyxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/busyxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/openxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/openxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/openxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/putrxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/putrxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/putrxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/putsxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/putsxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/putsxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/readaddr.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/readaddr.o   "D:/ECNG 3006/LCDtest.X/_xlcd/readaddr.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/readdata.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/readdata.o   "D:/ECNG 3006/LCDtest.X/_xlcd/readdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/setcgram.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/setcgram.o   "D:/ECNG 3006/LCDtest.X/_xlcd/setcgram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/setddram.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/setddram.o   "D:/ECNG 3006/LCDtest.X/_xlcd/setddram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/wcmdxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/wcmdxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/writdata.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/writdata.o   "D:/ECNG 3006/LCDtest.X/_xlcd/writdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_adc.o: D:/ECNG\ 3006/LCDtest.X/_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_adc.o   "D:/ECNG 3006/LCDtest.X/_adc.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_lcd.o: D:/ECNG\ 3006/LCDtest.X/_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_lcd.o   "D:/ECNG 3006/LCDtest.X/_lcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_counter.o: D:/ECNG\ 3006/LCDtest.X/_counter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_counter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_counter.o   "D:/ECNG 3006/LCDtest.X/_counter.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_counter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_counter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_interface.o: D:/ECNG\ 3006/LCDtest.X/_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_interface.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_interface.o   "D:/ECNG 3006/LCDtest.X/_interface.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_interface.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_kpad.o: D:/ECNG\ 3006/LCDtest.X/_kpad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_kpad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_kpad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_kpad.o   "D:/ECNG 3006/LCDtest.X/_kpad.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_kpad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_kpad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_pNN50.o: D:/ECNG\ 3006/LCDtest.X/_pNN50.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_pNN50.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_pNN50.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_pNN50.o   "D:/ECNG 3006/LCDtest.X/_pNN50.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_pNN50.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_pNN50.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_countv.o: D:/ECNG\ 3006/LCDtest.X/_countv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_countv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_countv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_countv.o   "D:/ECNG 3006/LCDtest.X/_countv.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_countv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_countv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_dbg.o: D:/ECNG\ 3006/LCDtest.X/_dbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_dbg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_dbg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_dbg.o   "D:/ECNG 3006/LCDtest.X/_dbg.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_dbg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_dbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_eeprom.o: D:/ECNG\ 3006/LCDtest.X/_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_eeprom.o   "D:/ECNG 3006/LCDtest.X/_eeprom.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_speaker.o: D:/ECNG\ 3006/LCDtest.X/_speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_speaker.o   "D:/ECNG 3006/LCDtest.X/_speaker.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_temp.o: D:/ECNG\ 3006/LCDtest.X/_temp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_temp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_temp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_temp.o   "D:/ECNG 3006/LCDtest.X/_temp.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_temp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_temp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_fram.o: D:/ECNG\ 3006/LCDtest.X/_fram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_fram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_fram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_fram.o   "D:/ECNG 3006/LCDtest.X/_fram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_fram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_fram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/_ext/474789440/busyxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/busyxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/busyxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/busyxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/busyxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/busyxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/busyxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/busyxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/openxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/openxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/openxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/openxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/openxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/openxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/openxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/openxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/putrxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/putrxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/putrxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/putrxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/putrxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/putrxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/putrxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/putrxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/putsxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/putsxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/putsxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/putsxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/putsxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/putsxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/putsxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/putsxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/readaddr.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/readaddr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/readaddr.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/readaddr.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/readaddr.o   "D:/ECNG 3006/LCDtest.X/_xlcd/readaddr.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/readaddr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/readaddr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/readdata.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/readdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/readdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/readdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/readdata.o   "D:/ECNG 3006/LCDtest.X/_xlcd/readdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/readdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/readdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/setcgram.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/setcgram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/setcgram.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/setcgram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/setcgram.o   "D:/ECNG 3006/LCDtest.X/_xlcd/setcgram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/setcgram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/setcgram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/setddram.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/setddram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/setddram.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/setddram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/setddram.o   "D:/ECNG 3006/LCDtest.X/_xlcd/setddram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/setddram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/setddram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/wcmdxlcd.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/wcmdxlcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o   "D:/ECNG 3006/LCDtest.X/_xlcd/wcmdxlcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/wcmdxlcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/wcmdxlcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/474789440/writdata.o: D:/ECNG\ 3006/LCDtest.X/_xlcd/writdata.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/474789440" 
	@${RM} ${OBJECTDIR}/_ext/474789440/writdata.o.d 
	@${RM} ${OBJECTDIR}/_ext/474789440/writdata.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/474789440/writdata.o   "D:/ECNG 3006/LCDtest.X/_xlcd/writdata.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/474789440/writdata.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/474789440/writdata.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_adc.o: D:/ECNG\ 3006/LCDtest.X/_adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_adc.o   "D:/ECNG 3006/LCDtest.X/_adc.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_lcd.o: D:/ECNG\ 3006/LCDtest.X/_lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_lcd.o   "D:/ECNG 3006/LCDtest.X/_lcd.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_counter.o: D:/ECNG\ 3006/LCDtest.X/_counter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_counter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_counter.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_counter.o   "D:/ECNG 3006/LCDtest.X/_counter.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_counter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_counter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_interface.o: D:/ECNG\ 3006/LCDtest.X/_interface.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_interface.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_interface.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_interface.o   "D:/ECNG 3006/LCDtest.X/_interface.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_interface.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_interface.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_kpad.o: D:/ECNG\ 3006/LCDtest.X/_kpad.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_kpad.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_kpad.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_kpad.o   "D:/ECNG 3006/LCDtest.X/_kpad.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_kpad.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_kpad.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_pNN50.o: D:/ECNG\ 3006/LCDtest.X/_pNN50.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_pNN50.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_pNN50.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_pNN50.o   "D:/ECNG 3006/LCDtest.X/_pNN50.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_pNN50.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_pNN50.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_countv.o: D:/ECNG\ 3006/LCDtest.X/_countv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_countv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_countv.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_countv.o   "D:/ECNG 3006/LCDtest.X/_countv.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_countv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_countv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_dbg.o: D:/ECNG\ 3006/LCDtest.X/_dbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_dbg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_dbg.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_dbg.o   "D:/ECNG 3006/LCDtest.X/_dbg.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_dbg.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_dbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_eeprom.o: D:/ECNG\ 3006/LCDtest.X/_eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_eeprom.o   "D:/ECNG 3006/LCDtest.X/_eeprom.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_speaker.o: D:/ECNG\ 3006/LCDtest.X/_speaker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_speaker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_speaker.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_speaker.o   "D:/ECNG 3006/LCDtest.X/_speaker.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_speaker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_speaker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_temp.o: D:/ECNG\ 3006/LCDtest.X/_temp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_temp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_temp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_temp.o   "D:/ECNG 3006/LCDtest.X/_temp.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_temp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_temp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/1761785317/_fram.o: D:/ECNG\ 3006/LCDtest.X/_fram.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1761785317" 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_fram.o.d 
	@${RM} ${OBJECTDIR}/_ext/1761785317/_fram.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/1761785317/_fram.o   "D:/ECNG 3006/LCDtest.X/_fram.c" 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/1761785317/_fram.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1761785317/_fram.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  D:/ECNG\ 3006/LCDtest.X/p18f452.lib  D:/ECNG\ 3006/LCDtest.X/uc-18f452i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "D:\ECNG 3006\LCDtest.X\uc-18f452i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  "D:\ECNG 3006\LCDtest.X\p18f452.lib" 
else
dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  D:/ECNG\ 3006/LCDtest.X/p18f452.lib D:/ECNG\ 3006/LCDtest.X/uc-18f452i.lkr
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE) "D:\ECNG 3006\LCDtest.X\uc-18f452i.lkr"  -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/LCDtest.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}  "D:\ECNG 3006\LCDtest.X\p18f452.lib" 
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
