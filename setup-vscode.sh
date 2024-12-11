#!/bin/bash

mkdir -p ".vscode"

cd ".vscode"
cat > tasks.json <<EOL
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: clang build active file",
            "command": "/usr/bin/clang",
            "args": [
                "-fcolor-diagnostics",
                "-fansi-escape-codes",
                "-g",
                "\${file}",
                "-o",
                "\${fileDirname}/\${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "\${fileDirname}"
            },
            "problemMatcher": [
                "\$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ],
    "version": "2.0.0"
}
EOL

cat > launch.json <<EOL
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "\${fileDirname}/\${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "\${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb"
        }

    ]
}

EOL

cat > settings.json <<EOL
{
    "files.autoSave": "onFocusChange",
    "editor.formatOnSave": true,
    "editor.defaultFormatter": "ms-vscode.cpptools",
    "C_Cpp.default.compilerPath": "/usr/bin/clang",
    "C_Cpp.default.intelliSenseMode": "macos-clang-x64",
    "C_Cpp.clang_format_fallbackStyle": "google"
}

EOL

cat > extensions.json <<EOL
{
    "recommendations": [
        "ms-vscode.cpptools",
        "ms-vscode.cpptools-extension-pack"
    ]
}

EOL

cat > c_cpp_properties.json <<EOL

{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "\${workspaceFolder}/**"
            ],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "intelliSenseMode": "macos-clang-x64"
        }
    ],
    "version": 4
}

EOL

echo "Setup completed."


