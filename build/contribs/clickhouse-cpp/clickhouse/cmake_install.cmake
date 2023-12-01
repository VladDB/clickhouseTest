# Install script for directory: /home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse

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
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/entek/clickhouseTest/build/contribs/clickhouse-cpp/clickhouse/libclickhouse-cpp-lib.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/block.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/client.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/error_codes.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/exceptions.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/server_exception.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/protocol.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/query.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/buffer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/compressed.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/input.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/open_telemetry.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/output.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/platform.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/projected_iterator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/singleton.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/socket.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/string_utils.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/string_view.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/uuid.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/wire_format.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/base" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/base/endpoints_iterator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/array.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/column.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/date.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/decimal.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/enum.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/factory.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/geo.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/ip4.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/ip6.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/itemview.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/lowcardinality.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/nullable.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/numeric.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/map.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/string.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/tuple.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/utils.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/columns" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/columns/uuid.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/types" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/types/type_parser.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/clickhouse/types" TYPE FILE FILES "/home/entek/clickhouseTest/contribs/clickhouse-cpp/clickhouse/types/types.h")
endif()

