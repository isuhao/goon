#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/goon/retinal/ColorGrid.o \
	${OBJECTDIR}/src/goon/retinal/ColorNode.o \
	${OBJECTDIR}/src/goon/retinal/Exploration.o \
	${OBJECTDIR}/src/goon/retinal/Floodfiller.o \
	${OBJECTDIR}/src/goon/retinal/Grid.o \
	${OBJECTDIR}/src/goon/retinal/Segmenter.o \
	${OBJECTDIR}/src/goon/retinal/merge.o \
	${OBJECTDIR}/src/goon/retinal/retinal_vision.o \
	${OBJECTDIR}/src/goon/retinal/segmentation.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_retinal.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_retinal.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_retinal.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/goon/retinal/ColorGrid.o: src/goon/retinal/ColorGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/ColorGrid.o src/goon/retinal/ColorGrid.cpp

${OBJECTDIR}/src/goon/retinal/ColorNode.o: src/goon/retinal/ColorNode.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/ColorNode.o src/goon/retinal/ColorNode.cpp

${OBJECTDIR}/src/goon/retinal/Exploration.o: src/goon/retinal/Exploration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/Exploration.o src/goon/retinal/Exploration.cpp

${OBJECTDIR}/src/goon/retinal/Floodfiller.o: src/goon/retinal/Floodfiller.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/Floodfiller.o src/goon/retinal/Floodfiller.cpp

${OBJECTDIR}/src/goon/retinal/Grid.o: src/goon/retinal/Grid.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/Grid.o src/goon/retinal/Grid.cpp

${OBJECTDIR}/src/goon/retinal/Segmenter.o: src/goon/retinal/Segmenter.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/Segmenter.o src/goon/retinal/Segmenter.cpp

${OBJECTDIR}/src/goon/retinal/merge.o: src/goon/retinal/merge.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/merge.o src/goon/retinal/merge.cpp

${OBJECTDIR}/src/goon/retinal/retinal_vision.o: src/goon/retinal/retinal_vision.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/retinal_vision.o src/goon/retinal/retinal_vision.cpp

${OBJECTDIR}/src/goon/retinal/segmentation.o: src/goon/retinal/segmentation.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/retinal
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/retinal/segmentation.o src/goon/retinal/segmentation.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_retinal.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
