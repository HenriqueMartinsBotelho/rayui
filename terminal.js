// Export the native open_terminal addon
try {
  module.exports = require("./build/Release/open_terminal");
} catch (err) {
  throw new Error("Native open_terminal addon not built. Run 'npm install' or 'node-gyp rebuild' first.");
}
