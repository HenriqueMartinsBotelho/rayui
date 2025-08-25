const React = require("react");
exports.App = () => {
  const [count, setCount] = React.useState(0);
  function clickMe() {
    setCount(count + 1);
  }
  return /*#__PURE__*/React.createElement("button", {
    onClick: clickMe
  }, "Click Me ", count, " ");
};
