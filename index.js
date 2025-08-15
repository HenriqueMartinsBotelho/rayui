// Export the native addon as the main module
try {
  module.exports = require("./build/Release/findprimes");
} catch (err) {
  throw new Error("Native addon not built. Run 'npm install' or 'node-gyp rebuild' first.");
}