add_executable(structbind main.cpp kredit.cpp kredit.h)

set_target_properties(structbind 
    PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    CXX_STANDARD_REQUIRED ON
  )


