set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project (meatMob)

enable_testing()

add_subdirectory(customer)
add_subdirectory(drink)
add_subdirectory(food)
add_subdirectory(helperFunctions)
add_subdirectory(main)
add_subdirectory(menuItem)