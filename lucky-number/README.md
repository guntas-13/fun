# Lucky Number Generator

A simple Go CLI application that generates your lucky number using a clean modular structure.

## Project Structure

```
lucky-number/
├── go.mod                      # Module definition and dependencies
├── README.md                   # Project documentation
├── cmd/                        # Application entry points
│   └── cli/
│       └── main.go            # CLI application entry point
└── internal/                   # Private application code
    └── random/
        └── number.go          # Random number generation logic
```

- **`cmd/cli`**: Contains the main CLI application that serves as the entry point
- **`internal/random`**: Internal package providing random number generation functionality
  - `Number()`: Returns a random integer between 0-9

## Dependencies

- **[fatih/color](https://github.com/fatih/color)** : For colored terminal output

```bash
go get github.com/fatih/color@latest
```

## Run

```bash
go run ./cmd/cli/
```
