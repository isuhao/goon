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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/goon/features/Time.o \
	${OBJECTDIR}/src/goon/features/mask/Mask.o \
	${OBJECTDIR}/src/goon/features/motion/Motion.o \
	${OBJECTDIR}/src/goon/features/motion/Move.o \
	${OBJECTDIR}/src/goon/features/motion/Move2D.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/goon/features/Time.o: src/goon/features/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/Time.o src/goon/features/Time.cpp

${OBJECTDIR}/src/goon/features/mask/Mask.o: src/goon/features/mask/Mask.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features/mask
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/mask/Mask.o src/goon/features/mask/Mask.cpp

${OBJECTDIR}/src/goon/features/motion/Motion.o: src/goon/features/motion/Motion.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features/motion
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/motion/Motion.o src/goon/features/motion/Motion.cpp

${OBJECTDIR}/src/goon/features/motion/Move.o: src/goon/features/motion/Move.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features/motion
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/motion/Move.o src/goon/features/motion/Move.cpp

${OBJECTDIR}/src/goon/features/motion/Move2D.o: src/goon/features/motion/Move2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features/motion
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/motion/Move2D.o src/goon/features/motion/Move2D.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
