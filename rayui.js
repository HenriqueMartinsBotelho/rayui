// Export the native rayui addon
try {
  module.exports = require("./build/Release/rayui");
} catch (err) {
  throw new Error(
    "Native rayui addon not built. Run 'npm install' or 'node-gyp rebuild' first."
  );
}
