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
	${OBJECTDIR}/src/goon/core/GoonBus.o \
	${OBJECTDIR}/src/goon/core/GoonModule.o \
	${OBJECTDIR}/src/goon/core/VisualData.o


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
LDLIBSOPTIONS=-Wl,-rpath,../goon_features/dist/Debug/GNU-Linux -L../goon_features/dist/Debug/GNU-Linux -lgoon_features -Wl,-rpath,../goon_data/dist/Debug/GNU-Linux -L../goon_data/dist/Debug/GNU-Linux -lgoon_data -Wl,-rpath,../../tron/tuly/dist/Debug/GNU-Linux -L../../tron/tuly/dist/Debug/GNU-Linux -ltron_tuly -Wl,-rpath,../../tron/maty/dist/Debug/GNU-Linux -L../../tron/maty/dist/Debug/GNU-Linux -ltron_maty

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}: ../goon_features/dist/Debug/GNU-Linux/libgoon_features.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}: ../goon_data/dist/Debug/GNU-Linux/libgoon_data.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}: ../../tron/tuly/dist/Debug/GNU-Linux/libtron_tuly.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}: ../../tron/maty/dist/Debug/GNU-Linux/libtron_maty.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/src/goon/core/GoonBus.o: src/goon/core/GoonBus.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../goon_features/src -I../goon_data/src -I../../tron/tuly/src -I../../tron/maty/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/core/GoonBus.o src/goon/core/GoonBus.cpp

${OBJECTDIR}/src/goon/core/GoonModule.o: src/goon/core/GoonModule.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../goon_features/src -I../goon_data/src -I../../tron/tuly/src -I../../tron/maty/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/core/GoonModule.o src/goon/core/GoonModule.cpp

${OBJECTDIR}/src/goon/core/VisualData.o: src/goon/core/VisualData.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/goon/core
	${RM} "$@.d"
	$(COMPILE.cc) -g -Isrc -I../goon_features/src -I../goon_data/src -I../../tron/tuly/src -I../../tron/maty/src -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/goon/core/VisualData.o src/goon/core/VisualData.cpp

# Subprojects
.build-subprojects:
	cd ../goon_features && ${MAKE}  -f Makefile CONF=Debug
	cd ../goon_data && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug
	cd ../../tron/maty && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgoon_core.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../goon_features && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../goon_data && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/tuly && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../tron/maty && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
