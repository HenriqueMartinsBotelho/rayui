# RayUI

**RayUI** is an experimental library that enables JavaScript developers to build desktop applications using [Raylib](https://www.raylib.com/) with React-like syntax. This project bridges the gap between web development patterns and native desktop graphics programming.

## 🚧 Project Status

**⚠️ Early Development Stage**

RayUI is currently in its early experimental phase. This project is focused on exploring concepts and testing the feasibility of combining:

- Native C++ Raylib graphics capabilities
- Node.js native addons (N-API)
- React-style component architecture
- Desktop application development

## ✨ Features

### Current Capabilities

- ✅ Native Raylib window creation and management
- ✅ C++ to JavaScript bindings via N-API
- ✅ Basic graphics rendering (text, shapes)
- ✅ Cross-platform support (Linux tested)
- ✅ Integration with Node.js ecosystem

### Planned Features

- 🔄 React-style component system
- 🔄 Event handling and user interactions
- 🔄 UI controls (buttons, inputs, etc.)
- 🔄 State management
- 🔄 Hot reload during development

## 🛠️ Prerequisites

Before using RayUI, ensure you have the following installed:

### System Dependencies

```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential cmake git
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

# Install Raylib
git clone https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED
sudo make install RAYLIB_LIBTYPE=SHARED
```

### Node.js Dependencies

- Node.js >= 12.0.0
- npm or yarn
- Python (for node-gyp)

## 📦 Installation

```bash
# Clone the repository
git clone <your-repo-url>
cd rayui

# Install dependencies and build native modules
npm install

# Test the installation
npm test
```

## 🚀 Quick Start

### Basic Window Creation

```javascript
const rayui = require("./rayui");

// Create a basic Raylib window
try {
  const result = rayui.initRayUI();
  console.log("Window result:", result);
} catch (error) {
  console.error("Error:", error);
}
```

### Testing Performance (Native vs JavaScript)

```javascript
const findPrime = require("./findPrime"); // Pure JavaScript
const findPrimeNative = require("./index"); // Native C++ implementation

const input = 200000;

// Compare performance
console.time("Native C++");
const nativeResult = findPrimeNative(input);
console.timeEnd("Native C++");

console.time("Pure JavaScript");
const jsResult = findPrime(input);
console.timeEnd("Pure JavaScript");
```

## 📁 Project Structure

```
rayui/
├── binding.gyp          # Node-gyp build configuration
├── package.json         # Project dependencies and scripts
├── index.js            # Main entry point for findprimes addon
├── rayui.js            # Entry point for raylib addon
├── terminal.js         # Terminal utility addon
├── findprimes.cc       # Native prime number calculation
├── util/
│   ├── hello.cc        # Main Raylib integration
│   └── open_terminal.cc # Terminal opening utility
├── ui/
│   ├── index.html      # Web UI (future React integration)
│   ├── app.js          # React components (in development)
│   └── bundle.js       # Browserified output
├── test.js             # Testing suite
└── build/              # Compiled native modules
    └── Release/
        ├── findprimes.node
        ├── rayui.node
        └── open_terminal.node
```

## 🔧 Development

### Building the Project

```bash
# Clean and rebuild all native modules
npm run clean
npm run build

# Or rebuild everything
npm install
```

### Available Scripts

```bash
npm run build       # Build native addons
npm run clean       # Clean build artifacts
npm test           # Run test suite
npm run http       # Serve UI files via HTTP server
npm run br         # Bundle React components with Browserify
```

### Testing

```bash
# Run all tests
npm test

# Test specific components
node test_rayui.js    # Test Raylib functionality
```

## 🎯 Architecture Goals

RayUI aims to provide a development experience similar to React for desktop applications:

```javascript
// Future API (conceptual)
import { Window, Text, Button } from "rayui";

function App() {
  const [count, setCount] = useState(0);

  return (
    <Window width={800} height={600} title="My App">
      <Text x={100} y={100}>
        Count: {count}
      </Text>
      <Button x={100} y={150} onClick={() => setCount(count + 1)}>
        Click me!
      </Button>
    </Window>
  );
}
```

## 🤝 Contributing

This project is in early experimental stages. Contributions, ideas, and feedback are welcome!

### Areas of Focus

1. **React Integration**: Implementing JSX-to-Raylib rendering
2. **Component System**: Creating reusable UI components
3. **Event Handling**: Mouse, keyboard, and window events
4. **State Management**: Efficient state updates and re-rendering
5. **Documentation**: Examples and API documentation

### Getting Started with Development

1. Fork the repository
2. Set up the development environment (see Prerequisites)
3. Make your changes
4. Test your changes with `npm test`
5. Submit a pull request

## 📋 Roadmap

### Phase 1: Foundation (Current)

- [x] Basic Raylib window creation
- [x] Native addon architecture
- [x] Build system setup
- [ ] Basic event handling

### Phase 2: React Integration

- [ ] JSX parsing and transformation
- [ ] Component lifecycle management
- [ ] Virtual DOM for Raylib
- [ ] Props and state handling

### Phase 3: UI Components

- [ ] Button, Input, Text components
- [ ] Layout management
- [ ] Styling system
- [ ] Animation support

### Phase 4: Developer Experience

- [ ] Hot reload
- [ ] DevTools integration
- [ ] Documentation and examples
- [ ] Package distribution

## ⚠️ Known Limitations

- Currently only tested on Linux
- No component system yet implemented
- Limited UI controls available
- React integration is planned but not implemented
- Documentation is minimal

## 📝 License

MIT License - see LICENSE file for details

## 🙏 Acknowledgments

- [Raylib](https://www.raylib.com/) - Amazing C library for game development
- [Node.js N-API](https://nodejs.org/api/n-api.html) - Native addon API
- [React](https://reactjs.org/) - UI library inspiration

---

**Note**: This project is experimental and not recommended for production use yet. The API is subject to significant changes as the project evolves.
