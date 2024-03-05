# Install script for directory: /home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/DEVELOPMENT.md")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/README")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/README")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/FuncSpec20.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/WhitePaper20.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/UserGuide20.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/SystemC_2_1_overview.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc/archived" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/archived/SystemC_2_1_features.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/sysc" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/sysc/SystemC_2011_New_Features.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm/release" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/release/TLM_2_0_requirements.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm/release" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/release/TLM_2_0_white_paper.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm/release" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/release/README.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm/release" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/release/TLM_2_0_presentation.ppt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm/release" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/release/TLM_2_0_presentation.pdf")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/SystemCLanguage/tlm" TYPE FILE FILES "/home/veronia/toHector/extern/dramSys/DRAMSys/library/src/common/third_party/systemc/docs/tlm/tlm_README")
endif()

