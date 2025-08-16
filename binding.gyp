{
    "targets": [
        {
            "target_name": "findprimes",
            "sources": [
                "findprimes.cc"
            ]
        },
        {
            "target_name": "open_terminal",
            "sources": [
                "util/open_terminal.cc"
            ]
        },
        {
            "target_name": "rayui",
            "sources": [
                "util/hello.cc"
            ],
            "cflags_cc": ["-std=c++17", "-fPIC", "-Wno-cast-function-type"],
            "include_dirs": [
                "/usr/local/include"
            ],
            "conditions": [
                ["OS==\"linux\"", {
                    "libraries": [
                        "-lraylib",
                        "-lGL", "-lm", "-lpthread", "-ldl", "-lrt", "-lX11"
                    ],
                    "library_dirs": [
                        "/usr/local/lib"
                    ],
                    "cflags_cc": ["-std=c++17", "-fPIC", "-Wno-cast-function-type", "-D_DEFAULT_SOURCE"]
                }]
            ]
        }
    ]
}
