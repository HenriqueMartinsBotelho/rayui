try {
  const rayui = require("./rayui");

  console.log("Module loaded successfully:", rayui);
  console.log("Available functions:", Object.keys(rayui));

  console.log("Testing Raylib window...");
  const result = rayui.initRayUI();
  console.log("initRayUI result:", result);
} catch (error) {
  console.error("Error:", error);
}
