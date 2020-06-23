package main

import "fmt"

type LRUCacheNode struct {
	key   int
	value int
	prev  *LRUCacheNode
	next  *LRUCacheNode
}

type LRUCache struct {
	len     int
	cap     int
	head    *LRUCacheNode
	tail    *LRUCacheNode
	nodeMap map[int]*LRUCacheNode
}

func InitLRUCache(cap int) LRUCache {
	lruCache := LRUCache{
		cap:     cap,
		nodeMap: make(map[int]*LRUCacheNode),
		len:     0,
	}

	lruCache.head = &LRUCacheNode{}
	lruCache.tail = &LRUCacheNode{}

	lruCache.head.prev = nil
	lruCache.head.next = lruCache.tail

	lruCache.tail.prev = lruCache.head
	lruCache.tail.next = nil

	return lruCache
}

func (l *LRUCache) Get(key int) int {
	if v, ok := l.nodeMap[key]; ok {
		l.MoveToHead(v)

		return v.value
	} else {
		return -1
	}
}

func (l *LRUCache) Put(key, value int) {
	if v, ok := l.nodeMap[key]; ok {
		if v.value != value {
			l.nodeMap[key].value = value
		}

		l.MoveToHead(l.nodeMap[key])
	} else {
		if l.len > l.cap {
			panic("LRUCache is full")
		}

		if l.len == l.cap {
			l.AbandonTail()
			l.len--
		}

		node := &LRUCacheNode{
			key:   key,
			value: value,
		}

		l.AddToHead(node)
		l.nodeMap[key] = node
		l.len++
	}
}

func (l *LRUCache) AddToHead(node *LRUCacheNode) {
	node.prev = l.head
	node.next = l.head.next

	l.head.next.prev = node
	l.head.next = node

}

func (l *LRUCache) AbandonTail() {
	if l.len > 0 {
		delete(l.nodeMap, l.tail.prev.key)
		l.RemoveNode(l.tail.prev)
	}
}

func (l *LRUCache) RemoveNode(node *LRUCacheNode) {
	node.prev.next = node.next
	node.next.prev = node.prev

	node.prev = nil
	node.next = nil
}

func (l *LRUCache) MoveToHead(node *LRUCacheNode) {
	l.RemoveNode(node)
	l.AddToHead(node)
}

func main() {
	newLRU := InitLRUCache(10)
	newLRU.Put(1,100)
	newLRU.Put(2,200)
	newLRU.Put(3,300)
	newLRU.Put(4,400)
	newLRU.Put(5,500)

	fmt.Println(newLRU.Get(6))

}
