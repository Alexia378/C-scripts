#include "SinglLinked.h"

template <typename T>

List<T>::List():m_head(NULL){}

void List<T>::append(const T &t){
    //создаем новый узел для значения
    //не забудем проверить, что память удалось выделить
    if(Node* node = new Node(t)){
        //новый узел привязывается к старому головному элементу
        node->m_next = m_head;

        //новый узел сам становится головным элементом
        m_head = node;
    }
}

void List<T>::remove() {
    if(m_head){
        //если список не пуст, сохраняем указатель на второй узел,
        // который станет новым головным элементом
        Node* newHead = m_head->m_next;

        //освобождаем память, выделенную для удаляемого головного элемента
        delete m_head;

        //назначаем новый головной элемент
        m_head = newHead;
    }//инааче исключение
}

List<T>::~List(){
    while(m_head){
        remove();
    }
}


class Iterator {
public:
    Iterator( Node* node ) : m_node( node ) { }

    // Переход к следующему узлу
    void operator++() {
        if( m_node ) {
            m_node = m_node->m_next;
        } // Иначе достигнут конец списка. Уместно возбудить исключение
    }

private:
    Node* m_node;
};

