package main

import (
	"github.com/guntas-13/fun/lucky-number/internal/random"
	"github.com/fatih/color"

)

func main() {
	cyan := color.New(color.FgCyan)
	cyan.Printf("Your lucky number is: %d\n", random.Number())
}
