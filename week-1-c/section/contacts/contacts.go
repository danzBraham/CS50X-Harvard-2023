package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	name, err := getString("What's your name? ")
	if err != nil {
		handleError(err)
		return
	}

	age, err := getInt("What's your age? ")
	if err != nil {
		handleError(err)
		return
	}

	phoneNumber, err := getString("What's your number? ")
	if err != nil {
		handleError(err)
		return
	}

	fmt.Println("========================================")
	fmt.Printf("Name: %s\n", name)
	fmt.Printf("Age: %d\n", age)
	fmt.Printf("Phone Number: %s\n", phoneNumber)
}

func getInput(prompt string) (string, error) {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print(prompt)
	input, err := reader.ReadString('\n')
	if err != nil {
		return "", fmt.Errorf("error reading input: %v", err)
	}

	return strings.TrimSpace(input), nil
}

func getString(prompt string) (string, error) {
	return getInput(prompt)
}

func getInt(prompt string) (int, error) {
	for {
		input, err := getInput(prompt)
		if err != nil {
			return 0, err
		}

		num, err := strconv.Atoi(input)
		if err != nil {
			fmt.Println("invalid input. please enter a valid integer")
			continue
		}

		return num, nil
	}
}

func handleError(err error) {
	fmt.Fprintf(os.Stderr, "Error: %v\n", err)
}
