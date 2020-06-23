package main

import "fmt"

const BucketCount = 16

type KV struct {
	Key   string
	Value string
}

type LinkNode struct {
	Data     KV
	NextNode *LinkNode
}

type HashMap struct {
	Buckets [BucketCount]*LinkNode
}

func (l *LinkNode) AddNode(data KV) int {
	count, tail := 0, l

	for {
		count++

		if tail.NextNode == nil {
			break
		} else {
			tail = tail.NextNode
		}
	}

	tail.NextNode = &LinkNode{
		Data:     data,
		NextNode: nil,
	}

	return count
}

func (h *HashMap) CreateLink() *LinkNode {
	node := &LinkNode{
		Data: KV{Key:   "", Value: ""},
		NextNode: nil,
	}

	return node
}

func (h *HashMap) CreateHashMap() *HashMap {
	myMap := &HashMap{}

	for i := 0; i < len(myMap.Buckets); i++ {
		myMap.Buckets[i] = h.CreateLink()
	}

	return myMap
}

func (h *HashMap) HashCode(key string) int {
	sum := 0
	
	for i := 0; i < len(key); i++ {
		sum += int(key[i])
	}

	return sum % len(h.Buckets)
}

func (h *HashMap) AddKeyValue(key, value string) {
	mapIndex := h.HashCode(key)
	link := h.Buckets[mapIndex]

	if link.Data.Key == "" && link.NextNode == nil {
		link.Data.Key = key
		link.Data.Value = value
		fmt.Printf("Newly Added --> add key: %v to buckets[%d]\n", key, mapIndex)
	} else {
		link.AddNode(KV{key, value})
		fmt.Printf("Update --> update key: %v value for buckets[%d]\n", key, mapIndex)
	}
}

func (h *HashMap) GetValueByKey(key string) string {
	mapIndex := h.HashCode(key)
	var value string

	head := h.Buckets[mapIndex]
	for {
		if head.Data.Key == key {
			value = head.Data.Value

			break
		} else {
			head = head.NextNode
		}
	}

	return value
}

func main() {
	fmt.Println("In main")
	hMap := HashMap{}

	myMap := hMap.CreateHashMap()

	myMap.AddKeyValue("guan", "1")
	myMap.AddKeyValue("zhang", "2")
	myMap.AddKeyValue("liu", "3")
	myMap.AddKeyValue("sun", "4")
	myMap.AddKeyValue("wang", "3")

	fmt.Println(myMap.GetValueByKey("sun"))
}
