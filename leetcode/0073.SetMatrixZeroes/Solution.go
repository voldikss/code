package main

import "fmt"

func setZeroes(matrix [][]int) {
	firstRowHasZero := false
	firstColumnHasZero := false
	for n := 0; n < len(matrix[0]); n++ {
		if matrix[0][n] == 0 {
			firstRowHasZero = true
		}
	}
	for n := 0; n < len(matrix); n++ {
		if matrix[n][0] == 0 {
			firstColumnHasZero = true
		}
	}
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if matrix[i][j] == 0 {
				matrix[i][0] = 0
				matrix[0][j] = 0
			}
		}
	}
	for i := 1; i < len(matrix); i++ {
		if matrix[i][0] == 0 {
			for j := 1; j < len(matrix[i]); j++ {
				matrix[i][j] = 0
			}
		}
	}
	for j := 1; j < len(matrix[0]); j++ {
		if matrix[0][j] == 0 {
			for i := 1; i < len(matrix); i++ {
				matrix[i][j] = 0
			}
		}
	}
	if firstRowHasZero == true {
		for n := 0; n < len(matrix[0]); n++ {
			matrix[0][n] = 0
		}
	}
	if firstColumnHasZero == true {
		for n := 0; n < len(matrix); n++ {
			matrix[n][0] = 0
		}
	}
}

func main() {
	// input := [][]int{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}
	input := [][]int{{0}, {1}}
	setZeroes(input)
	fmt.Println(input)
}
