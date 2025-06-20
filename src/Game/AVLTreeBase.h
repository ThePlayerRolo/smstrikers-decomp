#ifndef _AVLTREEBASE_H_
#define _AVLTREEBASE_H_

#include "dolphin/types.h"

// Forward declarations
template<typename KeyType, typename ValueType>
class AVLTreeEntry;

template<typename T>
class NewAdapter;

template<typename KeyType>
class DefaultKeyCompare;

// AVLTreeNode structure (from nlAVLTree.h)
typedef struct AVLTreeNode {
    struct AVLTreeNode* unk0;  // left child (offset 0x00)
    struct AVLTreeNode* unk4;  // right child (offset 0x04) 
    s8 unk8;                   // balance factor (offset 0x08)
    void* unk10;               // data (offset 0x10)
} AVLTreeNode, *AVLTreeNodePtr;

/**
 * AVLTreeBase - Templated AVL Tree implementation
 * 
 * Template Parameters:
 * - KeyType: The type of the key used for comparison
 * - ValueType: The type of the value stored in the tree
 * - AllocatorType: The allocator type for managing tree entries (e.g., NewAdapter<AVLTreeEntry<KeyType, ValueType>>)
 * - CompareType: The comparison function type (e.g., DefaultKeyCompare<KeyType>)
 */
template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
class AVLTreeBase
{
public:
    // Constructor and destructor
    AVLTreeBase();
    ~AVLTreeBase();

    // Tree management functions
    void Clear();
    void DeleteEntry(AVLTreeEntry<KeyType, ValueType>* entry);
    void DestroyTree(void (AVLTreeBase::*)(AVLTreeEntry<KeyType, ValueType>*));

    // Tree traversal functions
    void PostorderTraversal(AVLTreeEntry<KeyType, ValueType>* node, 
                           void (AVLTreeBase::*)(AVLTreeEntry<KeyType, ValueType>*));

    // Template traversal functions (for specific use cases)
    template<typename CallbackType>
    void Walk(CallbackType* callback, void (CallbackType::*)(const KeyType&, ValueType**));

    template<typename CallbackType>
    void InorderWalk(AVLTreeEntry<KeyType, ValueType>* node, CallbackType* callback, 
                     void (CallbackType::*)(const KeyType&, ValueType**));

    // Node comparison and allocation functions
    void CompareNodes(AVLTreeNode* node1, AVLTreeNode* node2);
    void CompareKey(void* key, AVLTreeNode* node);
    void AllocateEntry(void* key, void* value);

    // Type casting function
    void CastUp(AVLTreeNode* node) const;

protected:
    // Protected members for derived classes
    AVLTreeNode* m_root;
    AllocatorType m_allocator;
    CompareType m_comparator;
};

// Template implementations
template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::AVLTreeBase()
    : m_root(nullptr)
{
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::~AVLTreeBase()
{
    Clear();
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::Clear()
{
    if (m_root != nullptr) {
        DestroyTree(&AVLTreeBase::DeleteEntry);
        m_root = nullptr;
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::DeleteEntry(AVLTreeEntry<KeyType, ValueType>* entry)
{
    if (entry != nullptr) {
        // Generic deletion logic
        m_allocator.Free(entry);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::DestroyTree(void (AVLTreeBase::*deleteFunc)(AVLTreeEntry<KeyType, ValueType>*))
{
    if (m_root != nullptr) {
        // Cast m_root->unk10 to the correct AVLTreeEntry type
        AVLTreeEntry<KeyType, ValueType>* entry = static_cast<AVLTreeEntry<KeyType, ValueType>*>(m_root->unk10);
        PostorderTraversal(entry, deleteFunc);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::PostorderTraversal(AVLTreeEntry<KeyType, ValueType>* node, 
                                                                                     void (AVLTreeBase::*deleteFunc)(AVLTreeEntry<KeyType, ValueType>*))
{
    if (node != nullptr) {
        // Recursive postorder traversal
        PostorderTraversal(node->m_left, deleteFunc);
        PostorderTraversal(node->m_right, deleteFunc);
        (this->*deleteFunc)(node);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::CompareNodes(AVLTreeNode* node1, AVLTreeNode* node2)
{
    if (node1 != nullptr && node2 != nullptr) {
        // Generic node comparison using the comparator
        KeyType key1 = static_cast<AVLTreeEntry<KeyType, ValueType>*>(node1->unk10)->GetKey();
        KeyType key2 = static_cast<AVLTreeEntry<KeyType, ValueType>*>(node2->unk10)->GetKey();
        m_comparator(key1, key2);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::CompareKey(void* key, AVLTreeNode* node)
{
    if (key != nullptr && node != nullptr) {
        // Generic key comparison
        KeyType treeKey = static_cast<AVLTreeEntry<KeyType, ValueType>*>(node->unk10)->GetKey();
        m_comparator(*static_cast<KeyType*>(key), treeKey);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::AllocateEntry(void* key, void* value)
{
    if (key != nullptr && value != nullptr) {
        // Generic entry allocation
        AVLTreeEntry<KeyType, ValueType>* entry = m_allocator.Allocate();
        entry->SetKey(*static_cast<KeyType*>(key));
        entry->SetValue(*static_cast<ValueType*>(value));
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::CastUp(AVLTreeNode* node) const
{
    // Generic type casting - this might need adjustment based on actual usage
    if (node != nullptr) {
        // Cast the void* data back to the appropriate entry type
        AVLTreeEntry<KeyType, ValueType>* entry = static_cast<AVLTreeEntry<KeyType, ValueType>*>(node->unk10);
        // Handle the entry as needed
    }
}

// AVLTreeEntry template implementation
template<typename KeyType, typename ValueType>
class AVLTreeEntry
{
public:
    AVLTreeEntry() : m_key(), m_value(), m_left(nullptr), m_right(nullptr) {}
    
    void SetKey(const KeyType& key) { m_key = key; }
    void SetValue(const ValueType& value) { m_value = value; }
    
    const KeyType& GetKey() const { return m_key; }
    ValueType& GetValue() { return m_value; }
    const ValueType& GetValue() const { return m_value; }
    
    void SetLeft(AVLTreeEntry* left) { m_left = left; }
    void SetRight(AVLTreeEntry* right) { m_right = right; }

    AVLTreeEntry* m_left;
    AVLTreeEntry* m_right;

private:
    KeyType m_key;
    ValueType m_value;
};

// NewAdapter template implementation
template<typename T>
class NewAdapter
{
public:
    T* Allocate() { return new T(); }
    void Free(T* ptr) { delete ptr; }
};

// DefaultKeyCompare template implementation
template<typename KeyType>
class DefaultKeyCompare
{
public:
    int operator()(const KeyType& key1, const KeyType& key2) const
    {
        if (key1 < key2) return -1;
        if (key1 > key2) return 1;
        return 0;
    }
};

// Add the missing Walk template implementation
template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
template<typename CallbackType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::Walk(CallbackType* callback, 
    void (CallbackType::*callbackFunc)(const KeyType&, ValueType**))
{
    if (m_root != nullptr) {
        InorderWalk(static_cast<AVLTreeEntry<KeyType, ValueType>*>(m_root->unk10), callback, callbackFunc);
    }
}

template<typename KeyType, typename ValueType, typename AllocatorType, typename CompareType>
template<typename CallbackType>
void AVLTreeBase<KeyType, ValueType, AllocatorType, CompareType>::InorderWalk(AVLTreeEntry<KeyType, ValueType>* node, 
    CallbackType* callback, void (CallbackType::*callbackFunc)(const KeyType&, ValueType**))
{
    if (node != nullptr) {
        InorderWalk(node->m_left, callback, callbackFunc);
        (callback->*callbackFunc)(node->GetKey(), &node->GetValue());
        InorderWalk(node->m_right, callback, callbackFunc);
    }
}

#endif // _AVLTREEBASE_H_ 
