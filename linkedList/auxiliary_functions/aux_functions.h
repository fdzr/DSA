#include <memory>
#include "../node/node.h"

using namespace std;

#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

namespace aux{
    void print(Node** ref){
        Node* head{*ref};
        while(head != nullptr){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    void pushAtFront(Node** ref, int data){
        Node* new_node = new Node();
        new_node->data = data;   
        new_node->next = (*ref);
        (*ref) = new_node;
    }

    void insertAfter(Node* prev, int data){
        if(!prev){
            cout<<"Node not founded";
            return;
        }
        
        Node* actual = new Node();
        actual->data = data;
        actual->next = prev->next;
        prev->next = actual;
    }

    void insertAtEnd(Node** ref, int data){
        Node* actual = new Node();
        actual->data = data;
        actual->next = nullptr;

        if (!*ref){
            *ref = actual;
            return;
        }

        Node* tmp = *ref;
        while(tmp->next)
            tmp = tmp->next;

        tmp->next = actual;
    }

    void deleteNode(Node** ref, int key){
        Node* prev = nullptr;
        Node* head = *ref;

        if(head->data == key){
            *ref = head->next;
            delete head;
            return;
        }
        
        while(head != nullptr && head->data != key){
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

    void deleteNodeAtGivenPosition(Node** ref, int pos){
        Node* head = *ref;
        Node* prev = nullptr;

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

    void deleteList(Node** ref){
        Node* head = *ref;
        Node* next = nullptr;

        while(head != nullptr){
            next = head->next;
            delete head;
            head = next;
        }
        *ref = nullptr;
    }

    int lengthListRecursive(Node** ref){
        if(*ref == nullptr)
            return 0;

        return 1 + lengthListRecursive(&(*ref)->next);
    }

    int lengthListIterative(Node** ref){
        int cont = 0;
        for(auto p=*ref; p!=nullptr; p=p->next)
            cont++;

        return cont;
    }

    bool findValueRecursive(Node** ref, int val){
        if(!*ref)
            return false;

        if((*ref)->data == val)
            return true;

        return findValueRecursive(&(*ref)->next, val);
    }

    bool findValueIterative(Node** ref, int val){
        for(auto p=*ref; p!=nullptr;p=p->next)
            if(p->data == val)
                return true;
        return false;
    }

    Node* findNthNode(Node* head, int pos, int cont){
        if(!head)
            return nullptr;

        if(pos == cont)
            return head;

        return findNthNode(head->next, pos, ++cont);
    }

    int findNthNode(Node* head, int pos){
        if(!head)
            return -1;

        if(pos == 0)
            return head->data;

        return findNthNode(head->next, --pos);
    }

    void printNthNodeBackward(Node* head, int pos){
        int len = lengthListRecursive(&head);
        Node* temp = head;
        for(auto p=1; p < len-pos+1; ++p)
            temp = temp->next;

        cout<<"The node in the "<<pos<<"rd position is: "<<temp->data<<endl;
    }

    void printNthNodeBackwardRecursively(Node* head, int pos){
        static int i =0;
        if(!head)
            return;
        printNthNodeBackwardRecursively(head->next, pos);
        if(++i == pos)
            cout<<head->data<<endl;
    }

    void getMiddleNode(Node* head){
        int cont = 0;
        Node* temp = nullptr, *current = head;

        while(current){
            cont++;
            if(cont % 2){
                if(temp){
                    temp = temp->next;
                    cout<<temp->data<<endl;
                    }
                else
                    temp = current;
            }
            current = current->next;
        }
        if(cont % 2 == 0)
            temp = temp->next;
        cout<<"The middle node contains as value: "<<temp->data;
    }

    int countGivenNode(Node* head, int value){
        int cont = 0;
        Node* temp = head;
        while(temp){
            if(temp->data == value)
                cont++;
            temp = temp->next;
        }
        return cont;
    }

    int countGivenNodeRecursively(Node* head, int value){
        static int freq = 0;
        if(!head)
            return freq;

        if(head->data == value)
            freq++;

        return countGivenNodeRecursively(head->next, value);
    }

    int countGivenNodeRecursively2Version(Node* head, int value){
        if(!head)
            return 0;

        if(head->data == value)
            return 1 + countGivenNodeRecursively2Version(head->next, value);

        return countGivenNodeRecursively2Version(head->next, value);
    }
}

#endif