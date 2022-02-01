miok_dqueue_lib = static_library('miok-dqueue-c',
    'package.c',
    include_directories: inc_dir,
    gnu_symbol_visibility: 'hidden',
    install: true)

miok_dqueue_dep = declare_dependency(
    link_with: miok_dqueue_lib,
    include_directories: inc_dir)
