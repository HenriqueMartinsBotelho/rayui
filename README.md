# native-code-tutorial
Running Native Code (C++) in JS

## Overview
This project shows how to build and use a Node.js native addon (N-API) for:
- Finding the largest prime up to a given number (`findprimes` addon)
- Opening a terminal window from Node.js (`open_terminal` addon)

Main files:
- `binding.gyp` – build config for both addons
- `findprimes.cc` – C++ implementation of the prime finder
- `util/open_terminal.cc` – C++ implementation that launches a terminal
- `index.js` – loads the `findprimes` native addon
- `terminal.js` – loads the `open_terminal` native addon
- `test.js` – benchmarks JS vs native prime finder and tests opening a terminal

## Prerequisites
- Node.js >= 12
- node-gyp requirements (Linux):
  - Python 3
  - make and a C/C++ compiler toolchain (e.g., GCC)

On Debian/Ubuntu:
```bash
sudo apt-get update
sudo apt-get install -y python3 make g++ build-essential
```

Optional (for terminal demo): ensure a terminal emulator is installed. The sample uses `gnome-terminal`. If you don’t have it, install it or switch to another emulator like `xterm` or `konsole` (see Troubleshooting below).

## Install and Build
This project is configured to build on install via `node-gyp`.

```bash
npm install
```

You can also build explicitly:
```bash
npm run build    # node-gyp build
```

Clean build files:
```bash
npm run clean
```

Artifacts are placed under `build/Release/` (e.g., `findprimes.node`, `open_terminal.node`).

## Test / Run
Run the test script to compare native vs JS implementations and to try the terminal opener:
```bash
npm test
# or
node test.js
```
You should see timings for:
- Native (C++) prime search
- JS prime search
And an attempt to open a terminal window.

## Using the addons directly
- Prime finder (native):
```js
const findPrimeNative = require('./');
console.log(findPrimeNative(200000));
```
- Prime finder (JS, for comparison):
```js
const findPrime = require('./findPrime');
console.log(findPrime(200000));
```
- Open terminal:
```js
const openTerminal = require('./terminal');
openTerminal.openTerminal();
```

## Troubleshooting
- Native addon not built
  - Error: "Native addon not built. Run 'npm install' or 'node-gyp rebuild' first."
  - Fix: run `npm install` or `npm run build`. Ensure toolchain dependencies are installed.

- Build errors about Python/Compiler not found
  - Install Python 3 and build tools (see Prerequisites).

- Terminal does not open or command not found
  - The sample uses `gnome-terminal`. Install it:
    ```bash
    sudo apt-get install -y gnome-terminal
    ```
  - Or edit `util/open_terminal.cc` to use another emulator, e.g. replace `gnome-terminal` with `xterm` or `konsole`, then rebuild:
    ```bash
    npm run build
    ```

- Rebuild after Node version change
  - Run `npm rebuild` or `npm run build`.

## Notes
- The code uses N-API, making the native module ABI-stable across Node versions that support the used N-API level.
- For large inputs, the naive prime algorithm is intentionally simple to highlight the performance difference between JS and native C++.
