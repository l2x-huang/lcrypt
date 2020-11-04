
if (CMAKE_HOST_WIN32)
  return()
endif ()

include(cmake/CPM.cmake)

CPMAddPackage(
  NAME Ccache.cmake
  GITHUB_REPOSITORY TheLartians/Ccache.cmake
  VERSION 1.2
  )
