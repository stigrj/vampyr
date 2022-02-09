# We save CMAKE_BUILD_TYPE, as we will set it to Release for externals
set(_build_type ${CMAKE_BUILD_TYPE})
set(CMAKE_BUILD_TYPE Release)

message(STATUS "Suitable MRChem could not be located. Fetching and building!")
include(FetchContent)
FetchContent_Declare(mrchem
  QUIET
  GIT_REPOSITORY
    https://github.com/stigrj/mrchem.git
  GIT_TAG
    libmrchem
)

set(CMAKE_CXX_COMPILER ${CMAKE_CXX_COMPILER})
# Always build with OpenMP and without MPI
set(ENABLE_OPENMP TRUE CACHE BOOL "")
set(ENABLE_MPI FALSE CACHE BOOL "")
set(ENABLE_TESTS FALSE CACHE BOOL "")

FetchContent_MakeAvailable(mrchem)

# reset CMAKE_BUILD_TYPE to whatever it was for VAMPyR
set(CMAKE_BUILD_TYPE ${_build_type})
