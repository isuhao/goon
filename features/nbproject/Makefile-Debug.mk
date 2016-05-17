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
	${OBJECTDIR}/src/goon/features/body/BodyUtils.o


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
LDLIBSOPTIONS=-Wl,-rpath,../vision_data/dist/Debug/GNU-Linux -L../vision_data/dist/Debug/GNU-Linux -lgoon_data

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}: ../vision_data/dist/Debug/GNU-Linux/libgoon_data.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/goon/features/Time.o: src/goon/features/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../vision_data/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/Time.o src/goon/features/Time.cpp

${OBJECTDIR}/src/goon/features/body/BodyUtils.o: src/goon/features/body/BodyUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/features/body
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../vision_data/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/features/body/BodyUtils.o src/goon/features/body/BodyUtils.cpp

# Subprojects
.build-subprojects:
	cd ../vision_data && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_features.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../vision_data && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
