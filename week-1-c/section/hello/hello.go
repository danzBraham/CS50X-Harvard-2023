package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	name, err := getString("What's your name? ")
	if err != nil {
		fmt.Println(err)
	}

	fmt.Printf("Hello, %s!\n", name)
}

func getString(prompt string) (string, error) {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print(prompt)
	input, err := reader.ReadString('\n')
	if err != nil {
		return "", fmt.Errorf("error reading input: %v", err)
	}

	return strings.TrimSpace(input), nil
}
