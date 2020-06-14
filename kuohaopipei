package main

import "fmt"

var (
	parentMap = map[byte]byte{')': '(', ']': '[', '}': '{'}
	result    = make([]byte, 0)
	checkElem = map[byte]bool{
		')': true, '(': true, ']': true, '[': true, '{': true, '}': true,
	}
)

// 看一下括号是不是匹配
// ())))), {{{{, (asdfas)[]{
func isValid(inputs string) bool {
	if inputs == "" {
		return false
	}

	for i := 0; i < len(inputs); i++ {
		if v, ok := parentMap[inputs[i]]; ok {
			if len(result) >= 1 && byte(v) == result[len(result)-1] {
				result = result[:len(result)-1]
			} else {
				return false
			}
		} else {
			if _, ok := checkElem[inputs[i]]; ok {
				result = append(result, inputs[i])
			}
		}
	}

	if len(result) == 0 {
		return true
	} else {
		return false
	}
}

func main() {
	fmt.Println(isValid("(*))"))
}
