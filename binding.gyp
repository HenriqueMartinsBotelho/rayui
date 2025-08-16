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
            "conditions": [
                ["OS==\"linux\"", {}]
            ]
        }
    ]
}
