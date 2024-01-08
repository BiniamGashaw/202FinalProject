set(Main_SRCS main.cpp
)
add_executable(meatMob main.cpp
${Main_SRCS}
)
target_link_libraries(meatMob
customer
drink
food
menuItem
)
install(TARGETS meatMob DESTINATION bin)