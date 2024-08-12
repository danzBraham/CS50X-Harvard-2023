package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	height, err := getInt("Height: ")
	if err != nil {
		fmt.Fprintf(os.Stderr, "error: %v\n", err)
	}

	for i := 0; i < height; i++ {
		for j := 0; j < i+1; j++ {
			fmt.Print("#")
		}
		fmt.Println()
	}
}

func getInt(prompt string) (int, error) {
	reader := bufio.NewReader(os.Stdin)

	for {
		fmt.Print(prompt)
		input, err := reader.ReadString('\n')
		if err != nil {
			return 0, fmt.Errorf("error reading input: %v", err)
		}

		num, err := strconv.Atoi(strings.TrimSpace(input))
		if err != nil {
			fmt.Println("invalid input. please input a valid integer")
			continue
		}

		return num, nil
	}
}
