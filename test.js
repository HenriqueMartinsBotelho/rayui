const findPrime = require("./findPrime")
const findPrimeNative = require("./index")
const openTerminal = require("./terminal") 

const input = 200000

let result

console.time("Native")
result = findPrimeNative(input)
console.timeEnd("Native")
console.log("Native result:", result)

console.time("JS Find Primes")
result = findPrime(input)
console.timeEnd("JS Find Primes")
console.log("JS result:", result)

// Test the open terminal functionality
console.log("\nTesting open terminal functionality...")
try {
  const terminalResult = openTerminal.openTerminal()
  console.log("Terminal opened with result:", terminalResult)
} catch (err) {
  console.error("Error opening terminal:", err.message)
}
