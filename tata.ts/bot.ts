// Simple program to add two numbers in TypeScript
function addNumbers(num1: number, num2: number): number {
    return num1 + num2;
}

const number1: number = 5;
const number2: number = 10;

const result: number = addNumbers(number1, number2);
console.log(`The sum of ${number1} and ${number2} is ${result}.`);