const React = require("react");

exports.App = () => {

  const [count, setCount] =  React.useState(0);
 
  function clickMe(){
    setCount(count + 1);
  }

  return <button onClick={clickMe}>Click Me {count} </button>;
}



