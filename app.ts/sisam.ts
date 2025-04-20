// Define an interface for a User
interface User {
    name: string;
    age: number;
}

// Function to greet a user
function greet(user: User): string {
    return `Hello, ${user.name}! You are ${user.age} years old.`;
}

// Example usage
const user: User = { name: "Alice", age: 25 };
console.log(greet(user));