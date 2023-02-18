#include <bits/stdc++.h>
#include "../node/node.h"

using namespace std;

#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

namespace aux{
    void print(ListNode** ref){
        ListNode* head{*ref};
        while(head != nullptr){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    void pushAtFront(ListNode** ref, int data){
        ListNode* new_node = new ListNode();
        new_node->val = data;
        new_node->next = (*ref);
        (*ref) = new_node;
    }

    void insertAfter(ListNode* prev, int data){
        if(!prev){
            cout<<"Node not founded";
            return;
        }
        
        ListNode* actual = new ListNode();
        actual->val = data;
        actual->next = prev->next;
        prev->next = actual;
    }

    void insertAtEnd(ListNode** ref, int data){
        ListNode* actual = new ListNode();
        actual->val = data;
        actual->next = nullptr;

        if (!*ref){
            *ref = actual;
            return;
        }

        ListNode* tmp = *ref;
        while(tmp->next)
            tmp = tmp->next;

        tmp->next = actual;
    }

    void deleteNode(ListNode** ref, int key){
        ListNode* prev = nullptr;
        ListNode* head = *ref;

        if(head->val == key){
            *ref = head->next;
            delete head;
            return;
        }
        
        while(head != nullptr && head->val != key){
            prev = head;
            head = head->next;
        }

        if(head == nullptr){
            cout<<"Key not founded: "<<key<<endl;
            return;
        }

        prev->next = head->next;
        delete head;
    }

    void deleteNodeAtGivenPosition(ListNode** ref, int pos){
        ListNode* head = *ref;
        ListNode* prev = nullptr;

        if(pos == 0){
            (*ref) = head->next;
            delete head;
            return;
        }

        int cont = 0;
        while(head != nullptr && cont != pos){
            prev = head;
            head = head->next;
            cont++;
        }

        if(cont < pos){
            cout<<"Size of the linkedlist is smaller than the position"<<endl;
            return;
        }
        else {
            if(head){
               prev->next = head->next;
                delete head; 
            }
            else{
                prev->next = nullptr;
                delete head;
            }
            return;
        }
    }

    void deleteList(ListNode** ref){
        ListNode* head = *ref;
        ListNode* next = nullptr;

        while(head != nullptr){
            next = head->next;
            delete head;
            head = next;
        }
        *ref = nullptr;
    }

    int lengthListRecursive(ListNode** ref){
        if(*ref == nullptr)
            return 0;

        return 1 + lengthListRecursive(&(*ref)->next);
    }

    int lengthListIterative(ListNode** ref){
        int cont = 0;
        for(auto p=*ref; p!=nullptr; p=p->next)
            cont++;

        return cont;
    }

    bool findValueRecursive(ListNode** ref, int val){
        if(!*ref)
            return false;

        if((*ref)->val == val)
            return true;

        return findValueRecursive(&(*ref)->next, val);
    }

    bool findValueIterative(ListNode** ref, int val){
        for(auto p=*ref; p!=nullptr;p=p->next)
            if(p->val == val)
                return true;
        return false;
    }

    ListNode* findNthNode(ListNode* head, int pos, int cont){
        if(!head)
            return nullptr;

        if(pos == cont)
            return head;

        return findNthNode(head->next, pos, ++cont);
    }

    int findNthNode(ListNode* head, int pos){
        if(!head)
            return -1;

        if(pos == 0)
            return head->val;

        return findNthNode(head->next, --pos);
    }

    void printNthNodeBackward(ListNode* head, int pos){
        int len = lengthListRecursive(&head);
        ListNode* temp = head;
        for(auto p=1; p < len-pos+1; ++p)
            temp = temp->next;

        cout<<"The node in the "<<pos<<"rd position is: "<<temp->val<<endl;
    }

    void printNthNodeBackwardRecursively(ListNode* head, int pos){
        static int i =0;
        if(!head)
            return;
        printNthNodeBackwardRecursively(head->next, pos);
        if(++i == pos)
            cout<<head->val<<endl;
    }

    void getMiddleNode(ListNode* head){
        int cont = 0;
        ListNode* temp = nullptr, *current = head;

        while(current){
            cont++;
            if(cont % 2){
                if(temp){
                    temp = temp->next;
                    cout<<temp->val<<endl;
                    }
                else
                    temp = current;
            }
            current = current->next;
        }
        if(cont % 2 == 0)
            temp = temp->next;
        cout<<"The middle node contains as value: "<<temp->val;
    }

    int countGivenNode(ListNode* head, int value){
        int cont = 0;
        ListNode* temp = head;
        while(temp){
            if(temp->val == value)
                cont++;
            temp = temp->next;
        }
        return cont;
    }

    int countGivenNodeRecursively(ListNode* head, int value){
        static int freq = 0;
        if(!head)
            return freq;

        if(head->val == value)
            freq++;

        return countGivenNodeRecursively(head->next, value);
    }

    int countGivenNodeRecursively2Version(ListNode* head, int value){
        if(!head)
            return 0;

        if(head->val == value)
            return 1 + countGivenNodeRecursively2Version(head->next, value);

        return countGivenNodeRecursively2Version(head->next, value);
    }

    int countGivenNodeRecursively3Version(ListNode* head, int value){
        if(!head)
            return 0;

        int cont = countGivenNodeRecursively3Version(head->next, value);
        if(head->val == value)
            cont++;

        return cont;
    }

    bool detectLoopInLinkedList(ListNode* head){
        if(!head)
            return false;

        while(head){
            if(head->val == -1)
                return true;

            head->val = -1;
            head = head->next;
        }

        return false;

    }
}

#endif