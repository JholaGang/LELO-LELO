// EventEmitter class to handle custom events
class EventEmitter {
    constructor() {
        this.events = {};
    }

    // Register an event listener
    on(event, listener) {
        if (!this.events[event]) {
            this.events[event] = [];
        }
        this.events[event].push(listener);
    }

    // Emit an event and call all listeners
    emit(event, ...args) {
        if (this.events[event]) {
            this.events[event].forEach(listener => listener(...args));
        }
    }

    // Remove a specific listener for an event
    off(event, listenerToRemove) {
        if (!this.events[event]) return;

        this.events[event] = this.events[event].filter(listener => listener !== listenerToRemove);
    }
}

// Example usage
const emitter = new EventEmitter();

// Listener 1
const greetListener = (name) => {
    console.log(`Hello, ${name}!`);
};

// Listener 2
const farewellListener = (name) => {
    console.log(`Goodbye, ${name}!`);
};

// Register listeners
emitter.on('greet', greetListener);
emitter.on('farewell', farewellListener);

// Emit events
emitter.emit('greet', 'Alice');
emitter.emit('farewell', 'Alice');

// Remove a listener
emitter.off('greet', greetListener);

// Emit again to show the listener was removed
emitter.emit('greet', 'Alice'); // No output
emitter.emit('farewell', 'Alice'); // Goodbye, Alice!