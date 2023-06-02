/** @file
 *
 *  @course CS1521
 *  @section 1
 *  @term Spring 2023
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  stack.
 *
 *  Adapted from pages 246-8 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 06 Feb 2023
 *
 *  @version 7.0 */

// #define NDEBUG

#include <new>
#include "LinkedStack.h"

#include <cassert>

template <typename ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack) {

   if (!aStack.topPtr) {
      topPtr = nullptr;
   }
   else {
      NodePtr origStackPtr(aStack.topPtr);

      try {
         topPtr = new Node<ItemType>(origStackPtr->getItem() );

         NodePtr newStackPtr(topPtr);

         origStackPtr = origStackPtr->getNext();

         while (origStackPtr) {
            newStackPtr->setNext(new Node<ItemType>(origStackPtr->getItem()) );

            newStackPtr = newStackPtr->getNext();
            origStackPtr = origStackPtr->getNext();
         }
      }
      catch (const std::bad_alloc&) {
         while (!isEmpty() ) {
            pop();
         }
         throw;
      }
   }
}

template <typename ItemType>
LinkedStack<ItemType>::~LinkedStack() {

   while (!isEmpty() ) {
      pop();
   }
}

template <typename ItemType>
bool LinkedStack<ItemType>::isEmpty() const {

   return !topPtr;
}

template <typename ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem) {

   try {
      topPtr = new Node<ItemType>(newItem,
                                  topPtr);
   }
   catch (const std::bad_alloc&) {
      return false;
   }

   return true;
}

template <typename ItemType>
bool LinkedStack<ItemType>::pop() {

   if (!isEmpty() ) {
      NodePtr nodeToDeletePtr(topPtr);

      topPtr = topPtr->getNext();

      delete nodeToDeletePtr;

      return true;
   }

   return false;
}

template <typename ItemType>
ItemType LinkedStack<ItemType>::peek() const {
   assert(!isEmpty() );

   return topPtr->getItem();
}
