cmake_minimum_required(VERSION 3.16)
project(Chat)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(Test)

set(SOURCE_FILES Observer.h Subject.h Messaggio.cpp Messaggio.h Chat.cpp Chat.h Utente.cpp Utente.h NotificaMessaggio.cpp NotificaMessaggio.h TestNotifica.cpp TestNotifica.h)
add_executable(Chat main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Chat core)