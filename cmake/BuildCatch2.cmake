#
# You can simply link against Catch2 as needed. Eg
#       target_link_libraries(example Catch2)

CPMAddPackage(
  NAME Catch2
  GITHUB_REPOSITORY catchorg/Catch2
  VERSION 2.13.2
)
